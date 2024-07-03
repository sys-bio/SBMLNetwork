#include "libsbmlnetwork_layout_helpers.h"
#include "libsbmlnetwork_common.h"

#include <cmath>
#include <climits>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

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
        std::cerr << "error: Failed to load model\n";
    
    return NULL;
}

LayoutModelPlugin* getLayoutModelPlugin(SBasePlugin* layoutBase) {
    LayoutModelPlugin* layoutModelPlugin = NULL;
    try {
        layoutModelPlugin = dynamic_cast<LayoutModelPlugin*>(layoutBase); }
    catch(std::bad_cast) {
        std::cerr << "error: Unable to get layout information\n"; }
    
    return layoutModelPlugin;
}

void enableLayoutPlugin(SBMLDocument* document) {
    if (document->getLevel() == 2)
        document->enablePackage(LayoutExtension::getXmlnsL2(), "layout",  true);
    else if (document->getLevel() == 3)
        document->enablePackage(LayoutExtension::getXmlnsL3V1V1(), "layout",  true);
    document->setPackageRequired("layout", false);
}

void setDefaultLayoutId(Layout* layout) {
    if (!layout->isSetId())
        layout->setId("libSBMLNetwork_Layout");
}

void setDefaultLayoutDimensions(Layout* layout) {
    Dimensions* dimensions = layout->getDimensions();
    if (!dimensions)
        dimensions = new Dimensions(layout->getLevel(), layout->getVersion(), layout->getPackageVersion());
    if (dimensions->getWidth() < 0.0001)
        dimensions->setWidth(1024.0);
    if (dimensions->getHeight() < 0.0001)
        dimensions->setHeight(1024.0);
}

void setCompartmentGlyphs(Model* model, Layout* layout) {
    for (unsigned int i = 0; i < model->getNumCompartments(); i++) {
        Compartment* compartment = model->getCompartment(i);
        CompartmentGlyph* compartmentGlyph = getCompartmentGlyph(layout, compartment);
        setGraphicalObjectBoundingBox(compartmentGlyph);
    }
}

void setSpeciesGlyphs(Model* model, Layout* layout) {
    for (unsigned int i = 0; i < model->getNumSpecies(); i++) {
        Species* species = model->getSpecies(i);
        SpeciesGlyph* speciesGlyph = getSpeciesGlyph(layout, species);
        setGraphicalObjectBoundingBox(speciesGlyph);
    }
}

void setReactionGlyphs(Model* model, Layout* layout) {
    for (unsigned int i = 0; i < model->getNumReactions(); i++) {
        Reaction* reaction = model->getReaction(i);
        ReactionGlyph* reactionGlyph = getReactionGlyph(layout, reaction);
        setReactionGlyphCurve(reactionGlyph);
        clearReactionGlyphSpeciesReferenceGlyphs(reactionGlyph);
        setReactantGlyphs(layout, reaction, reactionGlyph);
        setProductGlyphs(layout, reaction, reactionGlyph);
        setModifierGlyphs(layout, reaction, reactionGlyph);
        if (reaction->getNumReactants() == 0) {
            SpeciesReferenceGlyph* dummyReactantGlyph = getDummySpeciesReferenceGlyph(model, layout, reactionGlyph);
            dummyReactantGlyph->setRole(SPECIES_ROLE_SUBSTRATE);
        }
        else if (reaction->getNumProducts() == 0) {
            SpeciesReferenceGlyph* dummyProductGlyph = getDummySpeciesReferenceGlyph(model, layout, reactionGlyph);
            dummyProductGlyph->setRole(SPECIES_ROLE_PRODUCT);
        }
    }
}

void setReactantGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph) {
    for (unsigned int i = 0; i < reaction->getNumReactants(); i++) {
        SimpleSpeciesReference* speciesReference = reaction->getReactant(i);
        SpeciesReferenceGlyph* speciesReferenceGlyph = getAssociatedSpeciesReferenceGlyph(layout, reaction, reactionGlyph, speciesReference);
        speciesReferenceGlyph->setRole(SPECIES_ROLE_SUBSTRATE);
        setSpeciesReferenceGlyphCurve(speciesReferenceGlyph);
    }
}

void setProductGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph) {
    for (unsigned int i = 0; i < reaction->getNumProducts(); i++) {
        SimpleSpeciesReference* speciesReference = reaction->getProduct(i);
        SpeciesReferenceGlyph* speciesReferenceGlyph = getAssociatedSpeciesReferenceGlyph(layout, reaction, reactionGlyph, speciesReference);
        speciesReferenceGlyph->setRole(SPECIES_ROLE_PRODUCT);
        setSpeciesReferenceGlyphCurve(speciesReferenceGlyph);
    }
}

void setModifierGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph) {
    for (unsigned int i = 0; i < reaction->getNumModifiers(); i++) {
        SimpleSpeciesReference* speciesReference = reaction->getModifier(i);
        SpeciesReferenceGlyph* speciesReferenceGlyph = getAssociatedSpeciesReferenceGlyph(layout, reaction, reactionGlyph, speciesReference);
        if (speciesReference->getSBOTermID() == "SBO:0000020")
            speciesReferenceGlyph->setRole(SPECIES_ROLE_INHIBITOR);
        else
            speciesReferenceGlyph->setRole(SPECIES_ROLE_MODIFIER);
        setSpeciesReferenceGlyphCurve(speciesReferenceGlyph);
    }
}

SpeciesReferenceGlyph* getDummySpeciesReferenceGlyph(Model* model, Layout* layout, ReactionGlyph* reactionGlyph) {
    SpeciesGlyph* dummySpeciesGlyph = getDummySpeciesGlyph(model, layout, reactionGlyph);
    return getDummySpeciesReferenceGlyph(layout, reactionGlyph, dummySpeciesGlyph);
}

SpeciesGlyph* getDummySpeciesGlyph(Model* model, Layout* layout, ReactionGlyph* reactionGlyph) {
    SpeciesGlyph* dummySpeciesGlyph = layout->createSpeciesGlyph();
    dummySpeciesGlyph->setId(reactionGlyph->getId() + "_DummySpeciesGlyph");
    CompartmentGlyph* compartmentGlyph = getCompartmentGlyphOfReactionGlyph(model, layout, reactionGlyph);
    // we store the compartment id of dummy species glyphs in the metaid of the species glyph
    if (compartmentGlyph)
        dummySpeciesGlyph->setMetaId(compartmentGlyph->getCompartmentId());
    setGraphicalObjectBoundingBox(dummySpeciesGlyph);

    return dummySpeciesGlyph;
}

SpeciesReferenceGlyph* getDummySpeciesReferenceGlyph(Layout* layout, ReactionGlyph* reactionGlyph, SpeciesGlyph* dummySpeciesGlyph) {
    SpeciesReferenceGlyph* dummySpeciesReferenceGlyph = layout->createSpeciesReferenceGlyph();
    dummySpeciesReferenceGlyph->setId(reactionGlyph->getId() + "_DummySpeciesReferenceGlyph");
    dummySpeciesReferenceGlyph->setSpeciesGlyphId(dummySpeciesGlyph->getId());
    setSpeciesReferenceGlyphCurve(dummySpeciesReferenceGlyph);

    return dummySpeciesReferenceGlyph;
}

void setCompartmentTextGlyphs(Layout* layout) {
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        TextGlyph* textGlyph = getAssociatedTextGlyph(layout, layout->getCompartmentGlyph(i));
        setTextGlyphBoundingBox(textGlyph, layout->getCompartmentGlyph(i));
    }
}

void setSpeciesTextGlyphs(Layout* layout) {
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        TextGlyph* textGlyph = getAssociatedTextGlyph(layout, layout->getSpeciesGlyph(i));
        setTextGlyphBoundingBox(textGlyph, layout->getSpeciesGlyph(i));
    }
}

void setReactionTextGlyphs(Layout* layout) {
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        double padding = 5.0;
        TextGlyph* textGlyph = getAssociatedTextGlyph(layout, layout->getReactionGlyph(i));
        setTextGlyphBoundingBox(textGlyph, layout->getReactionGlyph(i), padding);
    }
}

CompartmentGlyph* getCompartmentGlyph(Layout* layout, Compartment* compartment) {
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        if (compartmentGlyphBelongs(layout->getCompartmentGlyph(i), compartment))
            return layout->getCompartmentGlyph(i);
    }
    CompartmentGlyph* compartmentGlyph = layout->createCompartmentGlyph();
    compartmentGlyph->setId(compartment->getId() + "_Glyph_1");
    compartmentGlyph->setCompartmentId(compartment->getId());
    
    return compartmentGlyph;
}

SpeciesGlyph* getSpeciesGlyph(Layout* layout, Species* species) {
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        if (speciesGlyphBelongs(layout->getSpeciesGlyph(i), species))
            return layout->getSpeciesGlyph(i);
    }
    SpeciesGlyph* speciesGlyph = layout->createSpeciesGlyph();
    speciesGlyph->setId(species->getId() + "_Glyph_1");
    speciesGlyph->setSpeciesId(species->getId());
    
    return speciesGlyph;
}

ReactionGlyph* getReactionGlyph(Layout* layout, Reaction* reaction) {
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        if (reactionGlyphBelongs(layout->getReactionGlyph(i), reaction))
            return layout->getReactionGlyph(i);
    }
    ReactionGlyph* reactionGlyph = layout->createReactionGlyph();
    reactionGlyph->setId(reaction->getId() + "_Glyph_1");
    reactionGlyph->setReactionId(reaction->getId());
    
    return reactionGlyph;
}

CompartmentGlyph* getCompartmentGlyphOfReactionGlyph(Model* model, Layout* layout, ReactionGlyph* reactionGlyph) {
    Compartment* compartment = findReactionGlyphCompartment(model, reactionGlyph);
    if (compartment) {
        CompartmentGlyph* compartmentGlyph =  getCompartmentGlyph(layout, compartment);
        if (compartmentGlyph)
            return compartmentGlyph;
    }

    return getDefaultCompartmentGlyph(layout);
}

CompartmentGlyph* getDefaultCompartmentGlyph(Layout* layout) {
    if (layout->getNumCompartmentGlyphs() == 1 && layout->getCompartmentGlyph(0)->getCompartmentId() == "default_compartment")
        return layout->getCompartmentGlyph(0);

    return NULL;
}

SpeciesReferenceGlyph* getAssociatedSpeciesReferenceGlyph(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, SimpleSpeciesReference* speciesReference) {
    SpeciesReferenceGlyph* speciesReferenceGlyph = reactionGlyph->createSpeciesReferenceGlyph();
    if (!speciesReference->getId().empty()) {
        speciesReferenceGlyph->setId(speciesReference->getId() + "_Glyph_1");
        speciesReferenceGlyph->setSpeciesReferenceId(speciesReference->getId());
    }
    else
        speciesReferenceGlyph->setId(speciesReference->getSpecies() + "_Glyph_1_" + reactionGlyph->getId() + "_SpeciesReference" + std::to_string(reactionGlyph->getNumSpeciesReferenceGlyphs()));
    speciesReferenceGlyph->setSpeciesGlyphId(speciesReference->getSpecies() + "_Glyph_1");
    
    return speciesReferenceGlyph;
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


TextGlyph* getAssociatedTextGlyph(Layout* layout, GraphicalObject* graphicalObject) {
    for (unsigned int i = 0; i < layout->getNumTextGlyphs(); i++) {
        if (textGlyphBelongs(layout->getTextGlyph(i), graphicalObject))
            return layout->getTextGlyph(i);
    }
    TextGlyph* textGlyph = layout->createTextGlyph();
    textGlyph->setId(getTextGlyphUniqueId(layout, graphicalObject));
    textGlyph->setGraphicalObjectId(graphicalObject->getId());
    textGlyph->setOriginOfTextId(getEntityId(layout, graphicalObject));
    
    return textGlyph;
}


void setGraphicalObjectBoundingBox(GraphicalObject* graphicalObject) {
    if  (!graphicalObject->getBoundingBox()->isSetId())
        graphicalObject->getBoundingBox()->setId(graphicalObject->getId() + "_bb");
}

void setTextGlyphBoundingBox(TextGlyph* textGlyph, GraphicalObject* graphicalObject, const double& padding) {
    textGlyph->getBoundingBox()->setId(textGlyph->getId() + "_bb");
    textGlyph->getBoundingBox()->setX(graphicalObject->getBoundingBox()->x() + padding);
    textGlyph->getBoundingBox()->setY(graphicalObject->getBoundingBox()->y() + padding);
    textGlyph->getBoundingBox()->setWidth(graphicalObject->getBoundingBox()->width());
    textGlyph->getBoundingBox()->setHeight(graphicalObject->getBoundingBox()->height());
}

void setReactionGlyphCurve(ReactionGlyph* reactionGlyph) {
    if (!reactionGlyph->isSetCurve())
        setCurveCubicBezier(reactionGlyph->getCurve());
}

void clearReactionGlyphSpeciesReferenceGlyphs(ReactionGlyph* reactionGlyph) {
    while (reactionGlyph->getNumSpeciesReferenceGlyphs())
        reactionGlyph->removeSpeciesReferenceGlyph(0);
}

void setSpeciesReferenceGlyphCurve(SpeciesReferenceGlyph* speciesReferenceGlyph) {
    if (!speciesReferenceGlyph->isSetCurve())
        setCurveCubicBezier(speciesReferenceGlyph->getCurve());
}

void removeReactionGlyphCurve(ReactionGlyph* reactionGlyph) {
    while (reactionGlyph->getCurve()->getNumCurveSegments())
        reactionGlyph->getCurve()->getCurveSegment(0)->removeFromParentAndDelete();
}

void setCurveCubicBezier(Curve* curve) {
    CubicBezier* cubicBezier = curve->createCubicBezier();
}

Compartment* findCompartmentGlyphCompartment(Model* model, CompartmentGlyph* compartmentGlyph) {
    return model->getCompartment(compartmentGlyph->getCompartmentId());
}

Compartment* findSpeciesGlyphCompartment(Model* model, SpeciesGlyph* speciesGlyph) {
    Species* species = model->getSpecies(speciesGlyph->getSpeciesId());
    if (species)
        return model->getCompartment(species->getCompartment());
    // we store the compartment id of dummy species glyphs in the metaid of the species glyph
    else if (speciesGlyph->isSetMetaId())
        return model->getCompartment(speciesGlyph->getMetaId());

    return NULL;
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

bool containsSpecies(Model* model, Layout* layout, CompartmentGlyph* compartmentGlyph) {
    std::string compartmentId = compartmentGlyph->getCompartmentId();
    for (unsigned int i = 0; i < model->getNumSpecies(); i++)
        if (model->getSpecies(i)->getCompartment() == compartmentId)
            return true;
    
    return false;
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
    return textGlyph->getGraphicalObjectId() == graphicalObject->getId() ? true : false;
}

bool graphicalObjectBelongsToReactionGlyph(ReactionGlyph* reactionGlyph, GraphicalObject* graphicalObject) {
    if (graphicalObject) {
        for (unsigned int i = 0; i < reactionGlyph->getNumSpeciesReferenceGlyphs(); i++) {
            if (reactionGlyph->getSpeciesReferenceGlyph(i) == graphicalObject)
                return true;
            else if (reactionGlyph->getSpeciesReferenceGlyph(i)->getSpeciesGlyphId() == graphicalObject->getId())
                return true;
        }
    }

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

    return NULL;
}

std::vector<std::string> getGraphicalObjectsIdsWhosePositionIsNotDependentOnGraphicalObject(Layout* layout, std::vector<GraphicalObject*> graphicalObjects) {
    std::vector<std::string> graphicalObjectsIds;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++)
        graphicalObjectsIds.push_back(layout->getSpeciesGlyph(i)->getId());
    /*
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        bool isIndependentReaction = true;
        for (unsigned int j = 0; j < graphicalObjects.size(); j++) {
            if (graphicalObjectBelongsToReactionGlyph(layout->getReactionGlyph(i), graphicalObjects.at(j))) {
                isIndependentReaction = false;
                break;
            }
        }
        if (isIndependentReaction)
            graphicalObjectsIds.push_back(layout->getReactionGlyph(i)->getId());
    }
     */

    return graphicalObjectsIds;
}

std::vector<std::string> getGraphicalObjectsIdsWhosePositionIsNotDependentOnGraphicalObject(Layout* layout, GraphicalObject* graphicalObject) {
    std::vector<std::string> graphicalObjectsIds;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++)
        graphicalObjectsIds.push_back(layout->getSpeciesGlyph(i)->getId());
    //for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        //if (!graphicalObjectBelongsToReactionGlyph(layout->getReactionGlyph(i), graphicalObject))
            //graphicalObjectsIds.push_back(layout->getReactionGlyph(i)->getId());
    //}

    return graphicalObjectsIds;
}

const std::string getEntityId(Layout* layout, GraphicalObject* graphicalObject) {
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
    std::vector<SpeciesReferenceGlyph*> speceisReferenceGlyphs;
    for (unsigned int i = 0; i < reactionGlyph->getNumSpeciesReferenceGlyphs(); i++)
        speceisReferenceGlyphs.push_back(reactionGlyph->getSpeciesReferenceGlyph(i));

    return speceisReferenceGlyphs;
}

std::vector<SpeciesReferenceGlyph*> getAssociatedSpeciesReferenceGlyphsWithReactionGlyph(ReactionGlyph* reactionGlyph) {
    std::vector<SpeciesReferenceGlyph*> speciesReferenceGlyphs;
    for (unsigned int i = 0; i < reactionGlyph->getNumSpeciesReferenceGlyphs(); i++)
        speciesReferenceGlyphs.push_back(reactionGlyph->getSpeciesReferenceGlyph(i));

    return speciesReferenceGlyphs;
}

const std::string getTextGlyphUniqueId(Layout* layout, GraphicalObject* graphicalObject) {
    std::string textGlyphUniqueId = "";
    int textGlyphIndex = 1;
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

const bool layoutContainsGlyphs(Layout* layout) {
    return layout->getNumCompartmentGlyphs() + layout->getNumSpeciesGlyphs() + layout->getNumReactionGlyphs() > 0 ? true : false;
}

void alignGraphicalObjects(std::vector<GraphicalObject*> graphicalObjects, const std::string& alignment) {
    if (isValidAlignment(alignment)) {
        if (stringCompare(alignment, "top"))
            alignGraphicalObjectsToTop(graphicalObjects);
        else if (stringCompare(alignment, "center"))
            alignGraphicalObjectsToCenter(graphicalObjects);
        else if (stringCompare(alignment, "bottom"))
            alignGraphicalObjectsToBottom(graphicalObjects);
        else if (stringCompare(alignment, "left"))
            alignGraphicalObjectsToLeft(graphicalObjects);
        else if (stringCompare(alignment, "middle"))
            alignGraphicalObjectsToMiddle(graphicalObjects);
        else if (stringCompare(alignment, "right"))
            alignGraphicalObjectsToRight(graphicalObjects);
        else if (stringCompare(alignment, "circular"))
            alignGraphicalObjectsCircularly(graphicalObjects);
    }
}

void alignGraphicalObjectsToTop(std::vector<GraphicalObject*> graphicalObjects) {
    double minY = getMinPositionY(graphicalObjects);
    for (unsigned int i = 0; i < graphicalObjects.size(); i++)
        graphicalObjects.at(i)->getBoundingBox()->setY(minY);
}

void alignGraphicalObjectsToCenter(std::vector<GraphicalObject*> graphicalObjects) {
    double centerX = 0.5 * (getMinPositionX(graphicalObjects) + getMaxPositionX(graphicalObjects));
    for (unsigned int i = 0; i < graphicalObjects.size(); i++)
        graphicalObjects.at(i)->getBoundingBox()->setX(centerX);
}

void alignGraphicalObjectsToBottom(std::vector<GraphicalObject*> graphicalObjects) {
    double maxY = getMaxPositionY(graphicalObjects);
    for (unsigned int i = 0; i < graphicalObjects.size(); i++)
        graphicalObjects.at(i)->getBoundingBox()->setY(maxY);
}

void alignGraphicalObjectsToLeft(std::vector<GraphicalObject*> graphicalObjects) {
    double minX = getMinPositionX(graphicalObjects);
    for (unsigned int i = 0; i < graphicalObjects.size(); i++)
        graphicalObjects.at(i)->getBoundingBox()->setX(minX);
}

void alignGraphicalObjectsToMiddle(std::vector<GraphicalObject*> graphicalObjects) {
    double centerY = 0.5 * (getMinPositionY(graphicalObjects) + getMaxPositionY(graphicalObjects));
    for (unsigned int i = 0; i < graphicalObjects.size(); i++)
        graphicalObjects.at(i)->getBoundingBox()->setY(centerY);
}

void alignGraphicalObjectsToRight(std::vector<GraphicalObject*> graphicalObjects) {
    double maxX = getMaxPositionX(graphicalObjects);
    for (unsigned int i = 0; i < graphicalObjects.size(); i++)
        graphicalObjects.at(i)->getBoundingBox()->setX(maxX);
}

void alignGraphicalObjectsCircularly(std::vector<GraphicalObject*> graphicalObjects) {
    double radius = graphicalObjects.size() * 50.0;
    double angle = 2 * M_PI / graphicalObjects.size();
    double centerX = std::max(radius, 0.5 * (getMinCenterX(graphicalObjects) + getMaxCenterX(graphicalObjects)));
    double centerY = std::max(radius, 0.5 * (getMinCenterY(graphicalObjects) + getMaxCenterY(graphicalObjects)));
    for (unsigned int i = 0; i < graphicalObjects.size(); i++) {
        graphicalObjects.at(i)->getBoundingBox()->setX(centerX + radius * cos(1.5 * M_PI + i * angle) - 0.5 * graphicalObjects.at(i)->getBoundingBox()->width());
        graphicalObjects.at(i)->getBoundingBox()->setY(centerY + radius * sin(1.5 * M_PI + i * angle) - 0.5 * graphicalObjects.at(i)->getBoundingBox()->height());
    }
}

void distributeGraphicalObjects(std::vector<GraphicalObject*> graphicalObjects, const std::string& direction, const double& spacing) {
    if (isValidDistributionDirection(direction)) {
        if (stringCompare(direction, "horizontal"))
            distributeGraphicalObjectsHorizontally(graphicalObjects, spacing);
        else if (stringCompare(direction, "vertical"))
            distributeGraphicalObjectsVertically(graphicalObjects, spacing);
    }
}

void distributeGraphicalObjectsHorizontally(std::vector<GraphicalObject*> graphicalObjects, const double& spacing) {
    if (graphicalObjects.size() < 2)
        return;
    double minX = getMinPositionX(graphicalObjects);
    double maxX = getMaxPositionX(graphicalObjects);
    double distance = findDistributionDistance(minX, maxX, graphicalObjects.size(), spacing);
    if (graphicalObjects.size() % 2 == 0)
        distributeEvenGraphicalObjectsHorizontally(graphicalObjects, minX, maxX, distance);
    else
        distributeOddGraphicalObjectsHorizontally(graphicalObjects, minX, maxX, distance);
}

void distributeEvenGraphicalObjectsHorizontally(std::vector<GraphicalObject*> graphicalObjects, const double& minX, const double& maxX, const double& distance) {
    for (unsigned int i = 0; i < graphicalObjects.size(); i++)
        graphicalObjects.at(i)->getBoundingBox()->setX(minX + i * distance);
}

void distributeOddGraphicalObjectsHorizontally(std::vector<GraphicalObject*> graphicalObjects, const double& minX, const double& maxX, const double& distance) {
    for (unsigned int i = 0; i < graphicalObjects.size(); i++)
        graphicalObjects.at(i)->getBoundingBox()->setX(0.5 * (minX + maxX) + (i - 0.5 * (graphicalObjects.size() - 1)) * distance);
}

void distributeGraphicalObjectsVertically(std::vector<GraphicalObject*> graphicalObjects, const double& spacing) {
    if (graphicalObjects.size() < 2)
        return;
    double minY = getMinPositionY(graphicalObjects);
    double maxY = getMaxPositionY(graphicalObjects);
    double distance = findDistributionDistance(minY, maxY, graphicalObjects.size(), spacing);
    if (graphicalObjects.size() % 2 == 0)
        distributeEvenGraphicalObjectsVertically(graphicalObjects, minY, maxY, distance);
    else
        distributeOddGraphicalObjectsVertically(graphicalObjects, minY, maxY, distance);
}

void distributeEvenGraphicalObjectsVertically(std::vector<GraphicalObject*> graphicalObjects, const double& minY, const double& maxY, const double& distance) {
    for (unsigned int i = 0; i < graphicalObjects.size(); i++)
        graphicalObjects.at(i)->getBoundingBox()->setY(minY + i * distance);
}

void distributeOddGraphicalObjectsVertically(std::vector<GraphicalObject*> graphicalObjects, const double& minY, const double& maxY, const double& distance) {
    for (unsigned int i = 0; i < graphicalObjects.size(); i++)
        graphicalObjects.at(i)->getBoundingBox()->setY(0.5 * (minY + maxY) + (i - 0.5 * (graphicalObjects.size() - 1)) * distance);
}

const double findDistributionDistance(const double& minPosition, const double& maxPosition, const unsigned int& numGraphicalObjects, const double& spacing) {
    double distance = 0;
    if (spacing > 0)
        distance = spacing;
    else
        distance = (maxPosition - minPosition) / (numGraphicalObjects - 1);

    return distance;
}

const double getMinPositionX(std::vector<GraphicalObject*> graphicalObjects) {
    if (graphicalObjects.size()) {
        double minX = INT_MAX;
        for (unsigned int i = 0; i < graphicalObjects.size(); i++)
            if (graphicalObjects.at(i)->getBoundingBox()->x() < minX)
                minX = graphicalObjects.at(i)->getBoundingBox()->x();

        return minX;
    }

    return 0.0;
}

const double getMinPositionY(std::vector<GraphicalObject*> graphicalObjects) {
    if (graphicalObjects.size()) {
        double minY = INT_MAX;
        for (unsigned int i = 0; i < graphicalObjects.size(); i++)
            if (graphicalObjects.at(i)->getBoundingBox()->y() < minY)
                minY = graphicalObjects.at(i)->getBoundingBox()->y();

        return minY;
    }

    return 0.0;
}

const double getMaxPositionX(std::vector<GraphicalObject*> graphicalObjects) {
    if (graphicalObjects.size()) {
        double maxX = INT_MIN;
        for (unsigned int i = 0; i < graphicalObjects.size(); i++)
            if (graphicalObjects.at(i)->getBoundingBox()->x() > maxX)
                maxX = graphicalObjects.at(i)->getBoundingBox()->x();

        return maxX;
    }

    return 0.0;
}

const double getMaxPositionY(std::vector<GraphicalObject*> graphicalObjects) {
    if (graphicalObjects.size()) {
        double maxY = INT_MIN;
        for (unsigned int i = 0; i < graphicalObjects.size(); i++)
            if (graphicalObjects.at(i)->getBoundingBox()->y() > maxY)
                maxY = graphicalObjects.at(i)->getBoundingBox()->y();

        return maxY;
    }

    return 0.0;
}

const double getMinCenterX(std::vector<GraphicalObject*> graphicalObjects) {
    if (graphicalObjects.size()) {
        double minX = INT_MAX;
        for (unsigned int i = 0; i < graphicalObjects.size(); i++)
            if (graphicalObjects.at(i)->getBoundingBox()->x() + 0.5 * graphicalObjects.at(i)->getBoundingBox()->width() < minX)
                minX = graphicalObjects.at(i)->getBoundingBox()->x() + 0.5 * graphicalObjects.at(i)->getBoundingBox()->width();

        return minX;
    }

    return 0.0;
}

const double getMinCenterY(std::vector<GraphicalObject*> graphicalObjects) {
    if (graphicalObjects.size()) {
        double minY = INT_MAX;
        for (unsigned int i = 0; i < graphicalObjects.size(); i++)
            if (graphicalObjects.at(i)->getBoundingBox()->y() + 0.5 * graphicalObjects.at(i)->getBoundingBox()->height() < minY)
                minY = graphicalObjects.at(i)->getBoundingBox()->y() + 0.5 * graphicalObjects.at(i)->getBoundingBox()->height();

        return minY;
    }

    return 0.0;
}

const double getMaxCenterX(std::vector<GraphicalObject*> graphicalObjects) {
    if (graphicalObjects.size()) {
        double maxX = INT_MIN;
        for (unsigned int i = 0; i < graphicalObjects.size(); i++)
            if (graphicalObjects.at(i)->getBoundingBox()->x() + 0.5 * graphicalObjects.at(i)->getBoundingBox()->width() > maxX)
                maxX = graphicalObjects.at(i)->getBoundingBox()->x() + 0.5 * graphicalObjects.at(i)->getBoundingBox()->width();

        return maxX;
    }

    return 0.0;
}

const double getMaxCenterY(std::vector<GraphicalObject*> graphicalObjects) {
    if (graphicalObjects.size()) {
        double maxY = INT_MIN;
        for (unsigned int i = 0; i < graphicalObjects.size(); i++)
            if (graphicalObjects.at(i)->getBoundingBox()->y() + 0.5 * graphicalObjects.at(i)->getBoundingBox()->height() > maxY)
                maxY = graphicalObjects.at(i)->getBoundingBox()->y() + 0.5 * graphicalObjects.at(i)->getBoundingBox()->height();

        return maxY;
    }

    return 0.0;
}

const bool isValidLayoutDimensionWidthValue(const double& width) {
    return isValidDimensionValue(width);
}

const bool isValidLayoutDimensionHeightValue(const double& height) {
    return isValidDimensionValue(height);
}

const bool isValidRoleValue(const std::string& role) {
    return isValueValid(role, getValidRoleValues());
}

const bool isValidBoundingBoxXValue(const double& x) {
    return true;
}

const bool isValidBoundingBoxYValue(const double& y) {
    return true;
}

const bool isValidBoundingBoxWidthValue(const double& width) {
    return isValidDimensionValue(width);
}

const bool isValidBoundingBoxHeightValue(const double& height) {
    return isValidDimensionValue(height);
}

const bool isValidCurveSegmentStartPointXValue(const double& x) {
    return true;
}

const bool isValidCurveSegmentStartPointYValue(const double& y) {
    return true;
}

const bool isValidCurveSegmentEndPointXValue(const double& x) {
    return true;
}

const bool isValidCurveSegmentEndPointYValue(const double& y) {
    return true;
}

const bool isValidCurveSegmentBasePoint1XValue(const double& x) {
    return true;
}

const bool isValidCurveSegmentBasePoint1YValue(const double& y) {
    return true;
}

const bool isValidCurveSegmentBasePoint2XValue(const double& x) {
    return true;
}

const bool isValidCurveSegmentBasePoint2YValue(const double& y) {
    return true;
}

const bool isValidDimensionValue(const double& dimensionValue) {
    if (dimensionValue > 0.000)
        return true;

    std::cerr << "error: A dimension value must be greater than 0" << std::endl;
    return false;
}

const bool isValidAlignment(const std::string& alignment) {
    return isValueValid(alignment, getValidAlignmentValues());
}

const bool isValidDistributionDirection(const std::string& direction) {
    return isValueValid(direction, getValidDistributionDirectionValues());
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

std::vector<std::string> getValidAlignmentValues() {
    std::vector <std::string> alignmentValues;
    alignmentValues.push_back("top");
    alignmentValues.push_back("center");
    alignmentValues.push_back("bottom");
    alignmentValues.push_back("left");
    alignmentValues.push_back("middle");
    alignmentValues.push_back("right");
    alignmentValues.push_back("circular");

    return alignmentValues;
}

std::vector<std::string> getValidDistributionDirectionValues() {
    std::vector <std::string> distributionDirectionValues;
    distributionDirectionValues.push_back("horizontal");
    distributionDirectionValues.push_back("vertical");

    return distributionDirectionValues;
}

}
