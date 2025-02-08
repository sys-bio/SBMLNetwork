#include "libsbmlnetwork_layout_helpers.h"
#include "libsbmlnetwork_common.h"
#include "libsbmlnetwork_layout.h"
#include "libsbmlnetwork_sbmldocument_layout.h"
#include "features/error_log/libsbmlnetwork_error_log.h"
#include "features/user_data/libsbmlnetwork_user_data.h"
#include "features/defaults/libsbmlnetwork_defaults_layout.h"
#include "features/hide_elements/libsbmlnetwork_hide_elements.h"
#include "features/set_layout_features/libsbmlnetwork_set_layout_features.h"

#include <cmath>
#include <climits>

namespace LIBSBMLNETWORK_CPP_NAMESPACE  {

LayoutModelPlugin* getLayoutModelPlugin(SBMLDocument* document) {
    SBasePlugin* layoutBase = getLayoutPlugin(document);
    if (layoutBase)
        return getLayoutModelPlugin(layoutBase);
    
    return NULL;
}

LayoutModelPlugin* enableAndGetLayoutModelPlugin(SBMLDocument* document) {
    SBasePlugin* layoutBase = getLayoutPlugin(document);
    if (!layoutBase) {
        enableLayoutPlugin(document);
        layoutBase = getLayoutPlugin(document);
    }
    if (layoutBase)
        return getLayoutModelPlugin(layoutBase);
    
    return NULL;
}

SBasePlugin* getLayoutPlugin(SBMLDocument* document) {
    Model* model = document->getModel();
    if (model)
        return model->getPlugin("layout");
    else
        error_log_addErrorToLog(document, "Failed to load model");
    
    return NULL;
}

LayoutModelPlugin* getLayoutModelPlugin(SBasePlugin* layoutBase) {
    LayoutModelPlugin* layoutModelPlugin = dynamic_cast<LayoutModelPlugin*>(layoutBase);
    return layoutModelPlugin;
}

void enableLayoutPlugin(SBMLDocument* document) {
    if (document->getLevel() == 2)
        document->enablePackage(LayoutExtension::getXmlnsL2(), "layout",  true);
    else if (document->getLevel() == 3)
        document->enablePackage(LayoutExtension::getXmlnsL3V1V1(), "layout",  true);
    document->setPackageRequired("layout", false);
}

bool isSetEmptySpeciesGlyph(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph) {
    if (layout && speciesReferenceGlyph) {
        SpeciesGlyph* speciesGlyph = layout->getSpeciesGlyph(speciesReferenceGlyph->getSpeciesGlyphId());
        return isEmptySpeciesGlyph(speciesGlyph);
    }

    return false;
}

const std::string getEmptySpeciesGlyphId(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph) {
    if (isSetEmptySpeciesGlyph(layout, speciesReferenceGlyph))
        return layout->getSpeciesGlyph(speciesReferenceGlyph->getSpeciesGlyphId())->getId();

    return "";
}

int setSpeciesGlyphIndexInReactionGlyph(Layout* layout, const std::string speciesId, ReactionGlyph* reactionGlyph, const unsigned int index) {
    std::vector<SpeciesGlyph*> speciesGlyphs = getAssociatedSpeciesGlyphsWithSpeciesId(layout, speciesId);
    std::vector<SpeciesReferenceGlyph*> speciesReferenceGlyphs = getSpeciesReferencesAssociatedWithSpecies(layout, reactionGlyph, speciesId);
    int originalSpeciesGlyphIndex = getIndexOfConnectedSpeciesGlyph(speciesReferenceGlyphs, speciesGlyphs);
    if (originalSpeciesGlyphIndex != -1 && originalSpeciesGlyphIndex != index && index < speciesGlyphs.size()) {
        SpeciesGlyph* originalSpeciesGlyph = speciesGlyphs.at(originalSpeciesGlyphIndex);
        SpeciesGlyph* newSpeciesGlyph = speciesGlyphs.at(index);
        for (unsigned int i = 0; i < speciesReferenceGlyphs.size(); i++) {
            SpeciesReferenceGlyph* speciesReferenceGlyph = speciesReferenceGlyphs.at(i);
            speciesReferenceGlyph->setId(getIdOfSpeciesReferenceGlyphConnectedToNewSpeciesGlyph(speciesReferenceGlyph->getId(), originalSpeciesGlyph->getId(), newSpeciesGlyph->getId()));
            speciesReferenceGlyph->setSpeciesGlyphId(newSpeciesGlyph->getId());
        }
        if (!getSpeciesReferencesAssociatedWithSpeciesGlyph(layout, originalSpeciesGlyph->getId()).size()) {
            user_data_freeUserData(originalSpeciesGlyph);
            layout->removeSpeciesGlyph(originalSpeciesGlyph->getId());
        }

        return 0;
    }

    return -1;
}

CompartmentGlyph* getCompartmentGlyphOfReactionGlyph(Model* model, Layout* layout, ReactionGlyph* reactionGlyph) {
    Compartment* compartment = findReactionGlyphCompartment(model, reactionGlyph);
    if (compartment) {
        std::vector<CompartmentGlyph*> compartmentGlyphs = getAssociatedCompartmentGlyphsWithCompartmentId(layout, compartment->getId());
        if (compartmentGlyphs.size() == 1)
            return compartmentGlyphs.at(0);
    }

    return defaults_getDefaultCompartmentGlyph(layout);
}

const int getNumSpeciesReferencesAssociatedWithSpecies(Reaction* reaction, const std::string& speciesId) {
    int numSpeciesReferencesAssociatedWithSpecies = 0;
    for (unsigned int i = 0; i < reaction->getNumReactants(); i++) {
        if (reaction->getReactant(i)->getSpecies() == speciesId)
            numSpeciesReferencesAssociatedWithSpecies++;
    }
    for (unsigned int i = 0; i < reaction->getNumProducts(); i++) {
        if (reaction->getProduct(i)->getSpecies() == speciesId)
            numSpeciesReferencesAssociatedWithSpecies++;
    }
    for (unsigned int i = 0; i < reaction->getNumModifiers(); i++) {
        if (reaction->getModifier(i)->getSpecies() == speciesId)
            numSpeciesReferencesAssociatedWithSpecies++;
    }

    return numSpeciesReferencesAssociatedWithSpecies;
}

const int getNumSpeciesReferencesGlyphsAssociatedWithSpecies(Layout* layout, ReactionGlyph* reactionGlyph, const std::string& speciesId) {
    std::vector<SpeciesGlyph*> speciesGlyphs = getAssociatedSpeciesGlyphsWithSpeciesId(layout, speciesId);
    int numSpeciesReferencesGlyphsAssociatedWithSpecies = 0;
    for (unsigned int i = 0; i < reactionGlyph->getNumSpeciesReferenceGlyphs(); i++) {
        for (unsigned int j = 0; j < speciesGlyphs.size(); j++) {
            if (reactionGlyph->getSpeciesReferenceGlyph(i)->getSpeciesGlyphId() == speciesGlyphs[j]->getId())
                numSpeciesReferencesGlyphsAssociatedWithSpecies++;
        }
    }

    return numSpeciesReferencesGlyphsAssociatedWithSpecies;
}

std::vector<SpeciesReferenceGlyph*> getSpeciesReferencesAssociatedWithSpecies(Layout* layout, const std::string& speciesId) {
    std::vector<SpeciesReferenceGlyph*> speciesReferencesAssociatedWithSpecies;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        ReactionGlyph* reactionGlyph = layout->getReactionGlyph(i);
        std::vector<SpeciesReferenceGlyph*> speciesReferences = getSpeciesReferencesAssociatedWithSpecies(layout, reactionGlyph, speciesId);
        speciesReferencesAssociatedWithSpecies.insert(speciesReferencesAssociatedWithSpecies.end(), speciesReferences.begin(), speciesReferences.end());
    }

    return speciesReferencesAssociatedWithSpecies;
}

std::vector<SpeciesReferenceGlyph*> getSpeciesReferencesAssociatedWithSpeciesGlyph(Layout* layout, const std::string& speciesGlyphId) {
    std::vector<SpeciesReferenceGlyph*> speciesReferencesAssociatedWithSpeciesGlyph;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        ReactionGlyph* reactionGlyph = layout->getReactionGlyph(i);
        std::vector<SpeciesReferenceGlyph*> speciesReferences = getSpeciesReferencesAssociatedWithSpeciesGlyph(layout, reactionGlyph, speciesGlyphId);
        speciesReferencesAssociatedWithSpeciesGlyph.insert(speciesReferencesAssociatedWithSpeciesGlyph.end(), speciesReferences.begin(), speciesReferences.end());
    }

    return speciesReferencesAssociatedWithSpeciesGlyph;
}

std::vector<SpeciesReferenceGlyph*> getSpeciesReferencesAssociatedWithSpecies(Layout* layout, ReactionGlyph* reactionGlyph, const std::string& speciesId) {
    std::vector<SpeciesReferenceGlyph*> speciesReferencesAssociatedWithSpecies;
    if (reactionGlyph) {
        for (unsigned int i = 0; i < reactionGlyph->getNumSpeciesReferenceGlyphs(); i++) {
            SpeciesGlyph* speciesGlyph = layout->getSpeciesGlyph(reactionGlyph->getSpeciesReferenceGlyph(i)->getSpeciesGlyphId());
            if (speciesGlyph && (speciesGlyph->getSpeciesId() == speciesId || speciesGlyph->getId() == speciesId))
                speciesReferencesAssociatedWithSpecies.push_back(reactionGlyph->getSpeciesReferenceGlyph(i));
        }
    }

    return speciesReferencesAssociatedWithSpecies;
}

std::vector<SpeciesReferenceGlyph*> getSpeciesReferencesAssociatedWithSpeciesGlyph(Layout* layout, ReactionGlyph* reactionGlyph, const std::string& speciesGlyphId) {
    std::vector<SpeciesReferenceGlyph*> speciesReferencesAssociatedWithSpeciesGlyph;
    if (reactionGlyph) {
        for (unsigned int i = 0; i < reactionGlyph->getNumSpeciesReferenceGlyphs(); i++) {
            if (reactionGlyph->getSpeciesReferenceGlyph(i)->getSpeciesGlyphId() == speciesGlyphId)
                speciesReferencesAssociatedWithSpeciesGlyph.push_back(reactionGlyph->getSpeciesReferenceGlyph(i));
        }
    }

    return speciesReferencesAssociatedWithSpeciesGlyph;
}

const int getSpeciesReferenceIndex(Layout* layout, ReactionGlyph* reactionGlyph, SpeciesReferenceGlyph* speciesReferenceGlyph) {
    if (reactionGlyph && speciesReferenceGlyph) {
        for (unsigned int i = 0; i < reactionGlyph->getNumSpeciesReferenceGlyphs(); i++) {
            if (reactionGlyph->getSpeciesReferenceGlyph(i) == speciesReferenceGlyph)
                return i;
        }
    }

    return -1;
}

const int getIndexOfConnectedSpeciesGlyph(std::vector<SpeciesReferenceGlyph*> speciesReferenceGlyphs, std::vector<SpeciesGlyph*> speciesGlyphs) {
    for (unsigned int i = 0; i < speciesReferenceGlyphs.size(); i++) {
        std::string speciesGlyphId = speciesReferenceGlyphs.at(i)->getSpeciesGlyphId();
        for (unsigned int j = 0; j < speciesGlyphs.size(); j++) {
            if (speciesGlyphs.at(j)->getId() == speciesGlyphId)
                return j;
        }
    }

    return -1;
}

TextGlyph* createAssociatedTextGlyph(Layout* layout, GraphicalObject* graphicalObject) {
    TextGlyph* textGlyph = layout->createTextGlyph();
    textGlyph->setId(getTextGlyphUniqueId(layout, graphicalObject));
    textGlyph->setGraphicalObjectId(graphicalObject->getId());
    textGlyph->setOriginOfTextId(getEntityId(graphicalObject));
    
    return textGlyph;
}

void setReactionGlyphCurve(ReactionGlyph* reactionGlyph) {
    if (!reactionGlyph->isSetCurve()) {
        double x = reactionGlyph->getBoundingBox()->x();
        double y = reactionGlyph->getBoundingBox()->y();
        double width = reactionGlyph->getBoundingBox()->width();
        double height = reactionGlyph->getBoundingBox()->height();
        set_layout_features_setCurveCubicBezier(reactionGlyph->getCurve(), x + 0.5 * width, y + 0.5 * height);
    }
}

int removeReactionGlyphCurve(ReactionGlyph* reactionGlyph) {
    setReactionGlyphBoundingBox(reactionGlyph);
    while (reactionGlyph->getCurve()->getNumCurveSegments())
        reactionGlyph->getCurve()->getCurveSegment(0)->removeFromParentAndDelete();

    return 0;
}

void setReactionGlyphBoundingBox(ReactionGlyph* reactionGlyph) {
    if (reactionGlyph->isSetCurve()) {
        double x1 = reactionGlyph->getCurve()->getCurveSegment(0)->getStart()->x();
        double y1 = reactionGlyph->getCurve()->getCurveSegment(0)->getStart()->y();
        double x2 = reactionGlyph->getCurve()->getCurveSegment(0)->getEnd()->x();
        double y2 = reactionGlyph->getCurve()->getCurveSegment(0)->getEnd()->y();
        double x = std::min(x1, x2);
        double y = std::min(y1, y2);
        double width = std::abs(x1 - x2);
        double height = std::abs(y1 - y2);
        if (width < defaults_getReactionDefaultWidth()) {
            x -= 0.5 * (defaults_getReactionDefaultWidth() - width);
            width = defaults_getReactionDefaultWidth();
        }
        if (height < defaults_getReactionDefaultHeight()) {
            y -= 0.5 * (defaults_getReactionDefaultHeight() - height);
            height = defaults_getReactionDefaultHeight();
        }
        reactionGlyph->getBoundingBox()->setX(x);
        reactionGlyph->getBoundingBox()->setY(y);
        reactionGlyph->getBoundingBox()->setWidth(width);
        reactionGlyph->getBoundingBox()->setHeight(height);
    }
}

void setTextGlyphBoundingBox(TextGlyph* textGlyph, GraphicalObject* graphicalObject, const double& padding) {
    textGlyph->getBoundingBox()->setId(textGlyph->getId() + "_bb");
    textGlyph->getBoundingBox()->setX(graphicalObject->getBoundingBox()->x() + padding);
    textGlyph->getBoundingBox()->setY(graphicalObject->getBoundingBox()->y() + padding);
    textGlyph->getBoundingBox()->setWidth(graphicalObject->getBoundingBox()->width());
    textGlyph->getBoundingBox()->setHeight(graphicalObject->getBoundingBox()->height());
}

Compartment* findCompartmentGlyphCompartment(Model* model, CompartmentGlyph* compartmentGlyph) {
    return model->getCompartment(compartmentGlyph->getCompartmentId());
}

Compartment* findSpeciesGlyphCompartment(Model* model, SpeciesGlyph* speciesGlyph) {
    Species* species = model->getSpecies(speciesGlyph->getSpeciesId());
    if (species)
        return model->getCompartment(species->getCompartment());
    else
        return model->getCompartment(user_data_getUserData(speciesGlyph, "compartment"));
}

Species* findSpeciesGlyphSpecies(Model* model, SpeciesGlyph* speciesGlyph) {
    return model->getSpecies(speciesGlyph->getSpeciesId());
}

Compartment* findReactionGlyphCompartment(Model* model, ReactionGlyph* reactionGlyph) {
    Reaction* reaction = model->getReaction(reactionGlyph->getReactionId());
    if (reaction)
        return model->getCompartment(reaction->getCompartment());

    return NULL;
}

Reaction* findReactionGlyphReaction(Model* model, ReactionGlyph* reactionGlyph) {
    return model->getReaction(reactionGlyph->getReactionId());
}

SimpleSpeciesReference* findSpeciesReference(Model* model, Layout* layout, ReactionGlyph* reactionGlyph, SpeciesGlyph* speciesGlyph) {
    if (model) {
        SpeciesGlyph* speciesGlyph = (SpeciesGlyph*)getGraphicalObjectUsingItsOwnId(layout, speciesGlyph->getId());
        if (speciesGlyph) {
            Reaction* reaction = findReactionGlyphReaction(model, reactionGlyph);
            if (reaction) {
                for (unsigned int i = 0; i < reaction->getNumReactants(); i++) {
                    if (reaction->getReactant(i)->getSpecies() == speciesGlyph->getSpeciesId())
                        return reaction->getReactant(i);
                }
                for (unsigned int i = 0; i < reaction->getNumProducts(); i++) {
                    if (reaction->getProduct(i)->getSpecies() == speciesGlyph->getSpeciesId())
                        return reaction->getProduct(i);
                }
                for (unsigned int i = 0; i < reaction->getNumModifiers(); i++) {
                    if (reaction->getModifier(i)->getSpecies() == speciesGlyph->getSpeciesId())
                        return reaction->getModifier(i);
                }
            }
        }
    }

    return NULL;
}

ReactionGlyph* findSpeciesReferenceReactionGlyph(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph) {
    if (layout) {
        for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
            ReactionGlyph* reactionGlyph = layout->getReactionGlyph(i);
            for (unsigned int j = 0; j < reactionGlyph->getNumSpeciesReferenceGlyphs(); j++) {
                if (reactionGlyph->getSpeciesReferenceGlyph(j) == speciesReferenceGlyph)
                    return reactionGlyph;
            }
        }
    }

    return NULL;
}

bool compartmentGlyphBelongs(CompartmentGlyph* compartmentGlyph, Compartment* compartment) {
    return compartmentGlyph->getCompartmentId() == compartment->getId() ? true : false;
}
    
bool speciesGlyphBelongs(SpeciesGlyph* speciesGlyph, Species* species) {
    return speciesGlyph->getSpeciesId() == species->getId() ? true : false;
}

bool reactionGlyphBelongs(ReactionGlyph* reactionGlyph, Reaction* reaction) {
    return reactionGlyph->getReactionId() == reaction->getId() ? true : false;
}

const std::string getSpeciesReferenceGlyphSpeciesId(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph) {
    if (layout && speciesReferenceGlyph) {
        SpeciesGlyph* speciesGlyph = layout->getSpeciesGlyph(speciesReferenceGlyph->getSpeciesGlyphId());
        if (speciesGlyph)
            return speciesGlyph->getSpeciesId();
    }

    return "";
}

bool textGlyphBelongs(TextGlyph* textGlyph, GraphicalObject* graphicalObject) {
    if (textGlyph && graphicalObject)
        return textGlyph->getGraphicalObjectId() == graphicalObject->getId() ? true : false;

    return false;
}

std::vector<TextGlyph*> getAssociatedTextGlyphsWithGraphicalObject(Layout* layout, GraphicalObject* graphicalObject) {
    std::vector<TextGlyph*> textGlyphs;
    for (unsigned int i = 0; i < layout->getNumTextGlyphs(); i++) {
        if (textGlyphBelongs(layout->getTextGlyph(i), graphicalObject))
            textGlyphs.push_back(layout->getTextGlyph(i));
    }

    return textGlyphs;
}

GraphicalObject* getGraphicalObjectUsingItsOwnId(Layout* layout, const std::string& graphicalObjectId) {
    CompartmentGlyph* compartmentGlyph = layout->getCompartmentGlyph(graphicalObjectId);
    if (compartmentGlyph)
        return compartmentGlyph;
    SpeciesGlyph* speciesGlyph = layout->getSpeciesGlyph(graphicalObjectId);
    if (speciesGlyph)
        return speciesGlyph;
    ReactionGlyph* reactionGlyph = layout->getReactionGlyph(graphicalObjectId);
    if (reactionGlyph)
        return reactionGlyph;
    GraphicalObject* additionalGraphicalObject = layout->getAdditionalGraphicalObject(graphicalObjectId);
    if (additionalGraphicalObject)
        return additionalGraphicalObject;

    return NULL;
}

int removeGraphicalObjectUsingItsOwnId(Layout* layout, const std::string& graphicalObjectId) {
    CompartmentGlyph* compartmentGlyph = layout->getCompartmentGlyph(graphicalObjectId);
    if (compartmentGlyph) {
        user_data_freeUserData(compartmentGlyph);
        delete layout->removeCompartmentGlyph(graphicalObjectId);
        return 0;
    }
    SpeciesGlyph* speciesGlyph = layout->getSpeciesGlyph(graphicalObjectId);
    if (speciesGlyph) {
        user_data_freeUserData(speciesGlyph);
        delete layout->removeSpeciesGlyph(graphicalObjectId);
        return 0;
    }
    ReactionGlyph* reactionGlyph = layout->getReactionGlyph(graphicalObjectId);
    if (reactionGlyph) {
        user_data_freeUserData(reactionGlyph);
        delete layout->removeReactionGlyph(graphicalObjectId);
        return 0;
    }
    GraphicalObject* additionalGraphicalObject = layout->getAdditionalGraphicalObject(graphicalObjectId);
    if (additionalGraphicalObject) {
        user_data_freeUserData(additionalGraphicalObject);
        delete layout->removeAdditionalGraphicalObject(graphicalObjectId);
        return 0;
    }

    return -1;
}

const std::string getEntityId(GraphicalObject* graphicalObject) {
    GraphicalObject* castedGraphicalObject = dynamic_cast<CompartmentGlyph*>(graphicalObject);
    if (castedGraphicalObject)
        return ((CompartmentGlyph*)castedGraphicalObject)->getCompartmentId();
    castedGraphicalObject = dynamic_cast<SpeciesGlyph*>(graphicalObject);
    if (castedGraphicalObject)
        return ((SpeciesGlyph*)castedGraphicalObject)->getSpeciesId();
    castedGraphicalObject = dynamic_cast<ReactionGlyph*>(graphicalObject);
    if (castedGraphicalObject)
        return ((ReactionGlyph*)castedGraphicalObject)->getReactionId();
    castedGraphicalObject = dynamic_cast<SpeciesReferenceGlyph*>(graphicalObject);
    if (castedGraphicalObject)
        return ((SpeciesReferenceGlyph*)castedGraphicalObject)->getSpeciesReferenceId();

    return "";
}

std::vector<CompartmentGlyph*> getCompartmentGlyphs(Layout* layout) {
    std::vector<CompartmentGlyph*> compartmentGlyphs;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++)
            compartmentGlyphs.push_back(layout->getCompartmentGlyph(i));

    return compartmentGlyphs;
}

std::vector<CompartmentGlyph*> getAssociatedCompartmentGlyphsWithCompartmentId(Layout* layout, const std::string& compartmentId) {
    std::vector<CompartmentGlyph*> compartmentGlyphs;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        if (layout->getCompartmentGlyph(i)->getCompartmentId() == compartmentId)
            compartmentGlyphs.push_back(layout->getCompartmentGlyph(i));
    }

    return compartmentGlyphs;
}

std::vector<SpeciesGlyph*> getSpeciesGlyphs(Layout* layout) {
    std::vector<SpeciesGlyph*> speciesGlyphs;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++)
        speciesGlyphs.push_back(layout->getSpeciesGlyph(i));

    return speciesGlyphs;
}

std::vector<SpeciesGlyph*> getAssociatedSpeciesGlyphsWithSpeciesId(Layout* layout, const std::string& speciesId) {
    std::vector<SpeciesGlyph*> speciesGlyphs;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        if (layout->getSpeciesGlyph(i)->getSpeciesId() == speciesId)
            speciesGlyphs.push_back(layout->getSpeciesGlyph(i));
    }

    return speciesGlyphs;
}

std::vector<ReactionGlyph*> getReactionGlyphs(Layout* layout) {
    std::vector<ReactionGlyph*> reactionGlyphs;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++)
        reactionGlyphs.push_back(layout->getReactionGlyph(i));

    return reactionGlyphs;
}

std::vector<ReactionGlyph*> getAssociatedReactionGlyphsWithReactionId(Layout* layout, const std::string& reactionId) {
    std::vector<ReactionGlyph*> reactionGlyphs;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        if (layout->getReactionGlyph(i)->getReactionId() == reactionId)
            reactionGlyphs.push_back(layout->getReactionGlyph(i));
    }

    return reactionGlyphs;
}

std::vector<SpeciesReferenceGlyph*> getSpeciesReferenceGlyphs(ReactionGlyph* reactionGlyph) {
    std::vector<SpeciesReferenceGlyph*> speciesReferenceGlyphs;
    if (reactionGlyph) {
        for (unsigned int i = 0; i < reactionGlyph->getNumSpeciesReferenceGlyphs(); i++)
            speciesReferenceGlyphs.push_back(reactionGlyph->getSpeciesReferenceGlyph(i));
    }

    return speciesReferenceGlyphs;
}

const std::string getTextGlyphUniqueId(Layout* layout, GraphicalObject* graphicalObject) {
    std::string textGlyphUniqueId = "";
    int textGlyphIndex = 0;
    std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
    while (true) {
        textGlyphUniqueId = graphicalObject->getId() + "_TextGlyph_" + std::to_string(textGlyphIndex++);
        bool isUniqueId = true;
        for (unsigned int i = 0; i < textGlyphs.size(); i++) {
            if (textGlyphUniqueId == textGlyphs.at(i)->getId()) {
                isUniqueId = false;
                break;
            }
        }
        if (isUniqueId)
            break;
    }

    return textGlyphUniqueId;
}

const std::string getIdOfSpeciesReferenceGlyphConnectedToNewSpeciesGlyph(std::string speciesReferenceGlyphId, const std::string& originalSpeciesGlyphId, const std::string& newSpeciesGlyphId) {
    std::string::size_type pos = speciesReferenceGlyphId.find(originalSpeciesGlyphId);
    if (pos != std::string::npos)
        speciesReferenceGlyphId.replace(pos, originalSpeciesGlyphId.length(), newSpeciesGlyphId);

    return speciesReferenceGlyphId;
}

const bool layoutContainsGlyphs(Layout* layout) {
    return (layout->getNumCompartmentGlyphs() > 0) ||
           (layout->getNumSpeciesGlyphs() > 0) ||
           (layout->getNumReactionGlyphs() > 0);
}

const bool isGraphicalObject(SBase* sBase) {
    return dynamic_cast<GraphicalObject*>(sBase) != nullptr;
}

const bool isUniUniReaction(Model* model, ReactionGlyph* reactionGlyph) {
    return isUniUniReaction(findReactionGlyphReaction(model, reactionGlyph));
}

const bool isUniUniReaction(Reaction* reaction) {
    return reaction && reaction->getNumReactants() == 1 && reaction->getNumProducts() == 1;
}

const int getStoichiometryAsInteger(Layout* layout, SimpleSpeciesReference* speciesReference) {
    if (!speciesReference)
        return 1;

    std::string userData = user_data_getUserData(layout, "stoichiometric_species_reference");
    if (userData != "false") {
        SpeciesReference* speciesRef = dynamic_cast<SpeciesReference*>(speciesReference);
        if (speciesRef && speciesRef->isSetStoichiometry())
            return int(speciesRef->getStoichiometry());
    }

    return 1;
}

void updateAssociatedTextGlyphsPositionX(Layout* layout, GraphicalObject* graphicalObject, const double& movedDistanceX) {
    std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
    for (unsigned int i = 0; i < textGlyphs.size(); i++)
        textGlyphs.at(i)->getBoundingBox()->setX(textGlyphs.at(i)->getBoundingBox()->x() + movedDistanceX);
}

void updateAssociatedTextGlyphsPositionY(Layout* layout, GraphicalObject* graphicalObject, const double& movedDistanceY) {
    std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
    for (unsigned int i = 0; i < textGlyphs.size(); i++)
        textGlyphs.at(i)->getBoundingBox()->setY(textGlyphs.at(i)->getBoundingBox()->y() + movedDistanceY);
}

void updateAssociatedTextGlyphsPosition(Layout* layout, GraphicalObject* graphicalObject, const double& movedDistanceX, const double& movedDistanceY) {
    updateAssociatedTextGlyphsPositionX(layout, graphicalObject, movedDistanceX);
    updateAssociatedTextGlyphsPositionY(layout, graphicalObject, movedDistanceY);
}

void updateAssociatedTextGlyphsDimensionWidth(Layout* layout, GraphicalObject* graphicalObject, const double& changedWidth) {
    std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
    for (unsigned int i = 0; i < textGlyphs.size(); i++)
        textGlyphs.at(i)->getBoundingBox()->setWidth(textGlyphs.at(i)->getBoundingBox()->width() + changedWidth);
}

void updateAssociatedTextGlyphsDimensionHeight(Layout* layout, GraphicalObject* graphicalObject, const double& changedHeight) {
    std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
    for (unsigned int i = 0; i < textGlyphs.size(); i++)
        textGlyphs.at(i)->getBoundingBox()->setHeight(textGlyphs.at(i)->getBoundingBox()->height() + changedHeight);
}

const double getCurveMiddlePositionX(Curve* curve) {
    if (curve->getNumCurveSegments() == 1) {
        LineSegment* lineSegment = curve->getCurveSegment(0);
        return 0.5 * (lineSegment->getStart()->x() + lineSegment->getEnd()->x());
    }

    return 0.0;
}

const double getCurveMiddlePositionY(Curve* curve) {
    if (curve->getNumCurveSegments() == 1) {
        LineSegment* lineSegment = curve->getCurveSegment(0);
        return 0.5 * (lineSegment->getStart()->y() + lineSegment->getEnd()->y());
    }

    return 0.0;
}

int setCurveMiddlePositionX(Curve* curve, const double& x) {
    if (curve->getNumCurveSegments() == 1) {
        LineSegment *lineSegment = curve->getCurveSegment(0);
        lineSegment->getStart()->setX(x);
        lineSegment->getEnd()->setX(x);
        if (isCubicBezier(lineSegment)) {
            ((CubicBezier *) lineSegment)->getBasePoint1()->setX(x);
            ((CubicBezier *) lineSegment)->getBasePoint2()->setX(x);
        }

        return 0;
    }

    return -1;
}

int setCurveMiddlePositionY(Curve* curve, const double& y) {
    if (curve->getNumCurveSegments() == 1) {
        LineSegment *lineSegment = curve->getCurveSegment(0);
        lineSegment->getStart()->setY(y);
        lineSegment->getEnd()->setY(y);
        if (isCubicBezier(lineSegment)) {
            ((CubicBezier *) lineSegment)->getBasePoint1()->setY(y);
            ((CubicBezier *) lineSegment)->getBasePoint2()->setY(y);
        }

        return 0;
    }

    return -1;
}

int updateGraphicalObjectId(Layout* layout, GraphicalObject* graphicalObject, const std::string& newId) {
    if (graphicalObject && !newId.empty() && getGraphicalObjectUsingItsOwnId(layout, newId) == NULL) {
        if (isSpeciesGlyph(graphicalObject)) {
            std::vector<SpeciesReferenceGlyph*> speciesReferenceGlyphs = getSpeciesReferencesAssociatedWithSpeciesGlyph(layout, graphicalObject->getId());
            for (unsigned int i = 0; i < speciesReferenceGlyphs.size(); i++)
                updateSpeciesReferenceGlyphSpeciesGlyphId(speciesReferenceGlyphs.at(i), graphicalObject->getId(), newId);
            std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
            for (unsigned int i = 0; i < textGlyphs.size(); i++)
                updateTextGlyphGraphicalObjectId(textGlyphs.at(i), graphicalObject->getId(), newId);
            BoundingBox* boundingBox = graphicalObject->getBoundingBox();
            if (boundingBox)
                boundingBox->setId(newId + "_bb");
        }
        else if (isReactionGlyph(graphicalObject)) {
            std::vector<SpeciesReferenceGlyph*> speciesReferenceGlyphs = getSpeciesReferenceGlyphs((ReactionGlyph*)graphicalObject);
            for (unsigned int i = 0; i < speciesReferenceGlyphs.size(); i++)
                updateSpeciesReferenceGlyphReactionGlyphId(speciesReferenceGlyphs.at(i), graphicalObject->getId(), newId);
            std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
            for (unsigned int i = 0; i < textGlyphs.size(); i++)
                updateTextGlyphGraphicalObjectId(textGlyphs.at(i), graphicalObject->getId(), newId);
            BoundingBox* boundingBox = graphicalObject->getBoundingBox();
            if (boundingBox)
                boundingBox->setId(newId + "_bb");
        }
        graphicalObject->setId(newId);

        return 0;
    }

    return -1;
}

int updateSpeciesReferenceGlyphSpeciesGlyphId(SpeciesReferenceGlyph* speciesReferenceGlyph, const std::string& originalSpeciesGlyphId, const std::string& newSpeciesGlyphId) {
    if (speciesReferenceGlyph) {
        std::string speciesReferenceGlyphId = speciesReferenceGlyph->getId();
        std::string::size_type pos = speciesReferenceGlyphId.find(originalSpeciesGlyphId);
        if (pos != std::string::npos)
            speciesReferenceGlyphId.replace(pos, originalSpeciesGlyphId.length(), newSpeciesGlyphId);
        speciesReferenceGlyph->setId(speciesReferenceGlyphId);
        if (speciesReferenceGlyph->getSpeciesGlyphId() == originalSpeciesGlyphId)
            speciesReferenceGlyph->setSpeciesGlyphId(newSpeciesGlyphId);

        return 0;
    }

    return -1;
}

int updateSpeciesReferenceGlyphReactionGlyphId(SpeciesReferenceGlyph* speciesReferenceGlyph, const std::string& originalReactionGlyphId, const std::string& newReactionGlyphId) {
    if (speciesReferenceGlyph) {
        std::string speciesReferenceGlyphId = speciesReferenceGlyph->getId();
        std::string::size_type pos = speciesReferenceGlyphId.find(originalReactionGlyphId);
        if (pos != std::string::npos)
            speciesReferenceGlyphId.replace(pos, originalReactionGlyphId.length(), newReactionGlyphId);
        speciesReferenceGlyph->setId(speciesReferenceGlyphId);

        return 0;
    }

    return -1;
}

int updateTextGlyphGraphicalObjectId(TextGlyph* textGlyph, const std::string& originalGraphicalObjectId, const std::string& newGraphicalObjectId) {
    if (textGlyph) {
        std::string textGlyphId = textGlyph->getId();
        std::string::size_type pos = textGlyphId.find(originalGraphicalObjectId);
        if (pos != std::string::npos)
            textGlyphId.replace(pos, originalGraphicalObjectId.length(), newGraphicalObjectId);
        textGlyph->setId(textGlyphId);
        if (textGlyph->getGraphicalObjectId() == originalGraphicalObjectId)
            textGlyph->setGraphicalObjectId(newGraphicalObjectId);

        return 0;
    }

    return -1;
}

const bool isValidLayoutDimensionWidthValue(const double& width, SBase* sBase) {
    if (isValidDimensionValue(width, sBase) && width > 6 * defaults_getDefaultAutoLayoutPadding())
        return true;

    return false;
}

const bool isValidLayoutDimensionHeightValue(const double& height, SBase* sBase) {
    if (isValidDimensionValue(height, sBase) && height > 6 * defaults_getDefaultAutoLayoutPadding())
        return true;

    return false;
}

const bool isValidRoleValue(const std::string& role, SBase* sBase) {
    if (isValueValid(role, getValidRoleValues()))
        return true;

    error_log_addErrorToLog(sBase, error_log_createErrorMessage(role, getValidRoleValues()));
    return false;
}

const bool isValidBoundingBoxXValue(const double& x, SBase* sBase) {
    return isValidDoubleValue(x, sBase);
}

const bool isValidBoundingBoxYValue(const double& y, SBase* sBase) {
    return isValidDoubleValue(y, sBase);
}

const bool isValidBoundingBoxWidthValue(const double& width, SBase* sBase) {
    return isValidDimensionValue(width, sBase);
}

const bool isValidBoundingBoxHeightValue(const double& height, SBase* sBase) {
    return isValidDimensionValue(height, sBase);
}

const bool isValidCurveSegmentStartPointXValue(const double& x, SBase* sBase) {
    return isValidDoubleValue(x, sBase);
}

const bool isValidCurveSegmentStartPointYValue(const double& y, SBase* sBase) {
    return isValidDoubleValue(y, sBase);
}

const bool isValidCurveSegmentEndPointXValue(const double& x, SBase* sBase) {
    return isValidDoubleValue(x, sBase);
}

const bool isValidCurveSegmentEndPointYValue(const double& y, SBase* sBase) {
    return isValidDoubleValue(y, sBase);
}

const bool isValidCurveSegmentBasePoint1XValue(const double& x, SBase* sBase) {
    return isValidDoubleValue(x, sBase);
}

const bool isValidCurveSegmentBasePoint1YValue(const double& y, SBase* sBase) {
    return isValidDoubleValue(y, sBase);
}

const bool isValidCurveSegmentBasePoint2XValue(const double& x, SBase* sBase) {
    return isValidDoubleValue(x, sBase);
}

const bool isValidCurveSegmentBasePoint2YValue(const double& y, SBase* sBase) {
    return isValidDoubleValue(y, sBase);
}

const bool isValidDimensionValue(const double& dimensionValue, SBase* sBase) {
    if (isValidDoubleValue(dimensionValue, sBase) && dimensionValue > 0.000)
        return true;

    error_log_addErrorToLog(sBase, "A dimension value must be greater than 0");
    return false;
}

const bool isValidDoubleValue(const double& doubleValue, SBase* sBase) {
    if (!std::isnan(doubleValue) && !std::isinf(doubleValue))
        return true;

    error_log_addErrorToLog(sBase, "A double value must be a valid number");
    return false;
}

std::vector<std::string> getValidRoleValues() {
    std::vector <std::string> roleValues;
    roleValues.push_back("substrate");
    roleValues.push_back("sidesubstrate");
    roleValues.push_back("modifier");
    roleValues.push_back("inhibitor");
    roleValues.push_back("product");
    roleValues.push_back("sideproduct");
    roleValues.push_back("activator");
    roleValues.push_back("undefined");

    return roleValues;
}

}
