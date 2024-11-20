#include "libsbmlnetwork_layout_helpers.h"
#include "libsbmlnetwork_common.h"
#include "libsbmlnetwork_layout.h"
#include "libsbmlnetwork_sbmldocument_layout.h"
#include "features/error_log/libsbmlnetwork_error_log.h"
#include "features/user_data/libsbmlnetwork_user_data.h"
#include "features/defaults/libsbmlnetwork_defaults_layout.h"
#include "features/hide_elements/libsbmlnetwork_hide_species.h"

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

void clearGraphicalObjects(Layout* layout) {
    clearCompartmentGlyphs(layout);
    clearSpeciesGlyphs(layout);
    clearReactionGlyphs(layout);
    clearTextGlyphs(layout);
}

void clearCompartmentGlyphs(Layout* layout) {
    while (layout->getNumCompartmentGlyphs()) {
        user_data_freeUserData(layout->getCompartmentGlyph(0));
        delete layout->removeCompartmentGlyph(0);
    }
}

void clearSpeciesGlyphs(Layout* layout) {
    while (layout->getNumSpeciesGlyphs()) {
        user_data_freeUserData(layout->getSpeciesGlyph(0));
        delete layout->removeSpeciesGlyph(0);
    }
}

void clearReactionGlyphs(Layout* layout) {
    while (layout->getNumReactionGlyphs()) {
        clearReactionGlyphSpeciesReferenceGlyphs(layout->getReactionGlyph(0));
        user_data_freeUserData(layout->getReactionGlyph(0));
        delete layout->removeReactionGlyph(0);
    }

}

void clearReactionGlyphSpeciesReferenceGlyphs(ReactionGlyph* reactionGlyph) {
    while (reactionGlyph->getNumSpeciesReferenceGlyphs()) {
        user_data_freeUserData(reactionGlyph->getSpeciesReferenceGlyph(0));
        delete reactionGlyph->removeSpeciesReferenceGlyph(0);
    }
}

void clearTextGlyphs(Layout* layout) {
    while (layout->getNumTextGlyphs()) {
        user_data_freeUserData(layout->getTextGlyph(0));
        delete layout->removeTextGlyph(0);
    }
}

void clearReactionTextGlyphs(Layout* layout) {
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        ReactionGlyph* reactionGlyph = layout->getReactionGlyph(i);
        std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, reactionGlyph);
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            user_data_freeUserData(textGlyphs.at(j));
            delete layout->removeTextGlyph(textGlyphs.at(j)->getId());
        }
    }
}

void setCompartmentGlyphs(Model* model, Layout* layout, const std::vector<std::map<std::string, std::string>>& userData) {
    for (unsigned int i = 0; i < model->getNumCompartments(); i++) {
        Compartment *compartment = model->getCompartment(i);
        CompartmentGlyph *compartmentGlyph = createCompartmentGlyph(layout, compartment->getId(), userData);
        setGraphicalObjectBoundingBox(compartmentGlyph);
    }
}

void setReactionGlyphs(Model* model, Layout* layout, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData) {
    for (unsigned int i = 0; i < model->getNumReactions(); i++) {
        Reaction* reaction = model->getReaction(i);
        ReactionGlyph* reactionGlyph = createReactionGlyph(layout, reaction->getId(), userData);
        setReactantGlyphs(layout, reaction, reactionGlyph, maxNumConnectedEdges, userData);
        setProductGlyphs(layout, reaction, reactionGlyph, maxNumConnectedEdges, userData);
        setModifierGlyphs(layout, reaction, reactionGlyph, maxNumConnectedEdges, userData);
        setEmptySpeciesReferenceGlyphs(model, layout, reactionGlyph, userData);
    }
}

void setReactantGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData) {
    for (unsigned int i = 0; i < reaction->getNumReactants(); i++) {
        SimpleSpeciesReference* speciesReference = reaction->getReactant(i);
        if (!hide_elements_isSpeciesGlyphHidden(layout, reactionGlyph, speciesReference->getSpecies())) {
            int stoichiometry = getStoichiometryAsInteger(speciesReference);
            for (unsigned int stoichiometryIndex = 0; stoichiometryIndex < stoichiometry; stoichiometryIndex++) {
                SpeciesReferenceGlyph *speciesReferenceGlyph = createSpeciesReferenceGlyph(layout, reactionGlyph, speciesReference->getSpecies(), stoichiometryIndex, maxNumConnectedEdges, userData);
                speciesReferenceGlyph->setRole(SPECIES_ROLE_SUBSTRATE);
            }
        }
    }
}

void setProductGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData) {
    for (unsigned int i = 0; i < reaction->getNumProducts(); i++) {
        SimpleSpeciesReference* speciesReference = reaction->getProduct(i);
        if (!hide_elements_isSpeciesGlyphHidden(layout, reactionGlyph, speciesReference->getSpecies())) {
            int stoichiometry = getStoichiometryAsInteger(speciesReference);
            for (unsigned int stoichiometryIndex = 0; stoichiometryIndex < stoichiometry; stoichiometryIndex++) {
                SpeciesReferenceGlyph* speciesReferenceGlyph = createSpeciesReferenceGlyph(layout, reactionGlyph, speciesReference->getSpecies(), stoichiometryIndex, maxNumConnectedEdges, userData);
                speciesReferenceGlyph->setRole(SPECIES_ROLE_PRODUCT);
            }
        }
    }
}

void setModifierGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData) {
    for (unsigned int i = 0; i < reaction->getNumModifiers(); i++) {
        SimpleSpeciesReference* speciesReference = reaction->getModifier(i);
        if (!hide_elements_isSpeciesGlyphHidden(layout, reactionGlyph, speciesReference->getSpecies())) {
            SpeciesReferenceGlyph* speciesReferenceGlyph = createSpeciesReferenceGlyph(layout, reactionGlyph, speciesReference->getSpecies(), 0, maxNumConnectedEdges, userData);
            if (speciesReference->getSBOTermID() == "SBO:0000020")
                speciesReferenceGlyph->setRole(SPECIES_ROLE_INHIBITOR);
            else
                speciesReferenceGlyph->setRole(SPECIES_ROLE_MODIFIER);
        }
    }
}

void setEmptySpeciesReferenceGlyphs(Model* model, Layout* layout, ReactionGlyph* reactionGlyph, const std::vector<std::map<std::string, std::string>>& userData) {
    Reaction* reaction = findReactionGlyphReaction(model, reactionGlyph);
    if (reaction->getNumReactants() == 0) {
        SpeciesReferenceGlyph* emptyReactantGlyph = createEmptySpeciesReferenceGlyph(model, layout, reactionGlyph);
        emptyReactantGlyph->setRole(SPECIES_ROLE_SUBSTRATE);
        user_data_setGraphicalObjectUserData(emptyReactantGlyph, userData);
    }
    else if (reaction->getNumProducts() == 0) {
        SpeciesReferenceGlyph* emptyProductGlyph = createEmptySpeciesReferenceGlyph(model, layout, reactionGlyph);
        emptyProductGlyph->setRole(SPECIES_ROLE_PRODUCT);
        user_data_setGraphicalObjectUserData(emptyProductGlyph, userData);
    }
}

SpeciesReferenceGlyph* createEmptySpeciesReferenceGlyph(Model* model, Layout* layout, ReactionGlyph* reactionGlyph) {
    SpeciesGlyph* emptySpeciesGlyph = createEmptySpeciesGlyph(model, layout, reactionGlyph);
    return createEmptySpeciesReferenceGlyph(layout, reactionGlyph, emptySpeciesGlyph);
}

SpeciesGlyph* createEmptySpeciesGlyph(Model* model, Layout* layout, ReactionGlyph* reactionGlyph) {
    SpeciesGlyph* emptySpeciesGlyph = createEmptySpeciesGlyph(layout, reactionGlyph->getId());
    CompartmentGlyph* compartmentGlyph = getCompartmentGlyphOfReactionGlyph(model, layout, reactionGlyph);
    if (compartmentGlyph)
        user_data_setUserData(emptySpeciesGlyph, "compartment", compartmentGlyph->getCompartmentId());
    user_data_setUserData(emptySpeciesGlyph, "width", std::to_string(2* defaults_getEmptySpeciesDefaultRadius()));
    user_data_setUserData(emptySpeciesGlyph, "height", std::to_string(2* defaults_getEmptySpeciesDefaultRadius()));
    setGraphicalObjectBoundingBox(emptySpeciesGlyph);

    return emptySpeciesGlyph;
}

SpeciesReferenceGlyph* createEmptySpeciesReferenceGlyph(Layout* layout, ReactionGlyph* reactionGlyph, SpeciesGlyph* emptySpeciesGlyph) {
    SpeciesReferenceGlyph* emptySpeciesReferenceGlyph = layout->createSpeciesReferenceGlyph();
    emptySpeciesReferenceGlyph->setId(reactionGlyph->getId() + "_EmptySpeciesReferenceGlyph");
    emptySpeciesReferenceGlyph->setSpeciesGlyphId(emptySpeciesGlyph->getId());
    setSpeciesReferenceGlyphCurve(emptySpeciesReferenceGlyph);

    return emptySpeciesReferenceGlyph;
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

SpeciesGlyph* getSpeciesGlyph(Layout* layout, const std::string& speciesId, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData) {
    std::vector<SpeciesGlyph*> speciesGlyphs = getAssociatedSpeciesGlyphsWithSpeciesId(layout, speciesId);
    if (speciesGlyphs.size()) {
        if (getConnectedSpeciesGlyphReferences(layout, speciesGlyphs.back()).size() >= maxNumConnectedEdges)
            return createSpeciesGlyph(layout, speciesId, userData);

        return speciesGlyphs.back();
    }

    return createSpeciesGlyph(layout, speciesId, userData);
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

std::vector<SpeciesReferenceGlyph*> getConnectedSpeciesGlyphReferences(Layout* layout, SpeciesGlyph* speciesGlyph) {
    std::vector<SpeciesReferenceGlyph*> speciesGlyphReferences;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        ReactionGlyph* reactionGlyph = layout->getReactionGlyph(i);
        for (unsigned int j = 0; j < reactionGlyph->getNumSpeciesReferenceGlyphs(); j++) {
            SpeciesReferenceGlyph* speciesReferenceGlyph = reactionGlyph->getSpeciesReferenceGlyph(j);
            if (speciesReferenceGlyph->getSpeciesGlyphId() == speciesGlyph->getId())
                speciesGlyphReferences.push_back(speciesReferenceGlyph);
        }
    }

    return speciesGlyphReferences;
}

void setTextGlyphs(Layout* layout) {
    setCompartmentTextGlyphs(layout);
    setSpeciesTextGlyphs(layout);
    setReactionTextGlyphs(layout);
}

void setCompartmentTextGlyphs(Layout* layout) {
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        TextGlyph* textGlyph = createAssociatedTextGlyph(layout, layout->getCompartmentGlyph(i));
        setTextGlyphBoundingBox(textGlyph, layout->getCompartmentGlyph(i));
    }
}

void setSpeciesTextGlyphs(Layout* layout) {
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        TextGlyph* textGlyph = createAssociatedTextGlyph(layout, layout->getSpeciesGlyph(i));
        setTextGlyphBoundingBox(textGlyph, layout->getSpeciesGlyph(i));
    }
}

void setReactionTextGlyphs(Layout* layout) {
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        double padding = 5.0;
        TextGlyph* textGlyph = createAssociatedTextGlyph(layout, layout->getReactionGlyph(i));
        setTextGlyphBoundingBox(textGlyph, layout->getReactionGlyph(i), padding);
    }
}

CompartmentGlyph* createCompartmentGlyph(Layout* layout, const std::string& compartmentId, const std::vector<std::map<std::string, std::string>>& userData) {
    CompartmentGlyph* compartmentGlyph = layout->createCompartmentGlyph();
    compartmentGlyph->setId(getCompartmentGlyphId(layout, compartmentId));
    compartmentGlyph->setCompartmentId(compartmentId);
    setGraphicalObjectBoundingBox(compartmentGlyph);
    user_data_setGraphicalObjectUserData(compartmentGlyph, userData);
    
    return compartmentGlyph;
}

SpeciesGlyph* createSpeciesGlyph(Layout* layout, const std::string& speciesId, const std::vector<std::map<std::string, std::string>>& userData) {
    SpeciesGlyph *speciesGlyph = layout->createSpeciesGlyph();
    speciesGlyph->setId(getSpeciesGlyphId(layout, speciesId));
    speciesGlyph->setSpeciesId(speciesId);
    setGraphicalObjectBoundingBox(speciesGlyph);
    user_data_setGraphicalObjectUserData(speciesGlyph, userData);

    return speciesGlyph;
}

SpeciesGlyph* createEmptySpeciesGlyph(Layout* layout, const std::string& reactionGlyphId) {
    SpeciesGlyph *speciesGlyph = layout->createSpeciesGlyph();
    speciesGlyph->setId(reactionGlyphId + "_EmptySpeciesGlyph");
    setGraphicalObjectBoundingBox(speciesGlyph);

    return speciesGlyph;
}

ReactionGlyph* createReactionGlyph(Layout* layout, const std::string& reactionId, const std::vector<std::map<std::string, std::string>>& userData) {
    ReactionGlyph* reactionGlyph = layout->createReactionGlyph();
    reactionGlyph->setId(getReactionGlyphId(layout, reactionId));
    reactionGlyph->setReactionId(reactionId);
    setReactionGlyphCurve(reactionGlyph);
    user_data_setGraphicalObjectUserData(reactionGlyph, userData);
    
    return reactionGlyph;
}

SpeciesReferenceGlyph* createSpeciesReferenceGlyph(Layout* layout, ReactionGlyph* reactionGlyph, const std::string& speciesId, unsigned int stoichiometryIndex, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData) {
    SpeciesReferenceGlyph* speciesReferenceGlyph = reactionGlyph->createSpeciesReferenceGlyph();
    SpeciesGlyph* speciesGlyph = getSpeciesGlyph(layout, speciesId, maxNumConnectedEdges, userData);
    speciesReferenceGlyph->setId(getSpeciesReferenceGlyphId(reactionGlyph, speciesGlyph->getId(), stoichiometryIndex));
    speciesReferenceGlyph->setSpeciesGlyphId(speciesGlyph->getId());
    setSpeciesReferenceGlyphCurve(speciesReferenceGlyph);
    user_data_setGraphicalObjectUserData(speciesReferenceGlyph, userData);

    return speciesReferenceGlyph;
}

SpeciesReferenceGlyph* createSpeciesReferenceGlyph(ReactionGlyph* reactionGlyph, const std::string& speciesGlyphId, unsigned int stoichiometryIndex) {
    SpeciesReferenceGlyph* speciesReferenceGlyph = reactionGlyph->createSpeciesReferenceGlyph();
    speciesReferenceGlyph->setId(getSpeciesReferenceGlyphId(reactionGlyph, speciesGlyphId, stoichiometryIndex));
    speciesReferenceGlyph->setSpeciesGlyphId(speciesGlyphId);

    return speciesReferenceGlyph;
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
            if (speciesGlyph && speciesGlyph->getSpeciesId() == speciesId)
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

void setGraphicalObjectBoundingBox(GraphicalObject* graphicalObject) {
    if  (!graphicalObject->getBoundingBox()->isSetId())
        graphicalObject->getBoundingBox()->setId(graphicalObject->getId() + "_bb");
}

void setReactionGlyphCurve(ReactionGlyph* reactionGlyph) {
    if (!reactionGlyph->isSetCurve()) {
        double x = reactionGlyph->getBoundingBox()->x();
        double y = reactionGlyph->getBoundingBox()->y();
        double width = reactionGlyph->getBoundingBox()->width();
        double height = reactionGlyph->getBoundingBox()->height();
        setCurveCubicBezier(reactionGlyph->getCurve(), x + 0.5 * width, y + 0.5 * height);
    }
}

void setSpeciesReferenceGlyphCurve(SpeciesReferenceGlyph* speciesReferenceGlyph, SpeciesReferenceGlyph* referenceSpeciesReferenceGlyph) {
    if (referenceSpeciesReferenceGlyph->isSetCurve()) {
        Curve* referenceCurve = referenceSpeciesReferenceGlyph->getCurve();
        Curve* curve = speciesReferenceGlyph->getCurve();
        for (unsigned int i = 0; i < referenceCurve->getNumCurveSegments(); i++)
            addCurveSegment(curve, referenceCurve->getCurveSegment(i), defaults_getAliasReactionGlyphPadding());
    }
}

void setSpeciesReferenceGlyphCurve(SpeciesReferenceGlyph* speciesReferenceGlyph) {
    if (!speciesReferenceGlyph->isSetCurve())
        setCurveCubicBezier(speciesReferenceGlyph->getCurve());
}

int removeReactionGlyphCurve(ReactionGlyph* reactionGlyph) {
    double x = getPositionX(reactionGlyph);
    double y = getPositionY(reactionGlyph);
    double width = getDimensionWidth(reactionGlyph);
    double height = getDimensionHeight(reactionGlyph);
    while (reactionGlyph->getCurve()->getNumCurveSegments())
        reactionGlyph->getCurve()->getCurveSegment(0)->removeFromParentAndDelete();
    setPositionX(reactionGlyph->getBoundingBox(), x);
    setPositionY(reactionGlyph->getBoundingBox(), y);
    setDimensionWidth(reactionGlyph->getBoundingBox(), width);
    setDimensionHeight(reactionGlyph->getBoundingBox(), height);
    return 0;
}

void setTextGlyphBoundingBox(TextGlyph* textGlyph, GraphicalObject* graphicalObject, const double& padding) {
    textGlyph->getBoundingBox()->setId(textGlyph->getId() + "_bb");
    textGlyph->getBoundingBox()->setX(graphicalObject->getBoundingBox()->x() + padding);
    textGlyph->getBoundingBox()->setY(graphicalObject->getBoundingBox()->y() + padding);
    textGlyph->getBoundingBox()->setWidth(graphicalObject->getBoundingBox()->width());
    textGlyph->getBoundingBox()->setHeight(graphicalObject->getBoundingBox()->height());
}

void addCurveSegment(Curve* curve, LineSegment* referenceLineSegment, const double& padding) {
    if (isCubicBezier(referenceLineSegment)) {
        CubicBezier* referenceCubicBezier = static_cast<CubicBezier*>(referenceLineSegment);
        CubicBezier* cubicBezier = curve->createCubicBezier();
        cubicBezier->getStart()->setX(referenceCubicBezier->getStart()->x() + padding);
        cubicBezier->getStart()->setY(referenceCubicBezier->getStart()->y() + padding);
        cubicBezier->getBasePoint1()->setX(referenceCubicBezier->getBasePoint1()->x() + padding);
        cubicBezier->getBasePoint1()->setY(referenceCubicBezier->getBasePoint1()->y() + padding);
        cubicBezier->getBasePoint2()->setX(referenceCubicBezier->getBasePoint2()->x() + padding);
        cubicBezier->getBasePoint2()->setY(referenceCubicBezier->getBasePoint2()->y() + padding);
        cubicBezier->getEnd()->setX(referenceCubicBezier->getEnd()->x() + padding);
        cubicBezier->getEnd()->setY(referenceCubicBezier->getEnd()->y() + padding);
    }
    else {
        LineSegment* lineSegment = curve->createLineSegment();
        lineSegment->getStart()->setX(referenceLineSegment->getStart()->x() + padding);
        lineSegment->getStart()->setY(referenceLineSegment->getStart()->y() + padding);
        lineSegment->getEnd()->setX(referenceLineSegment->getEnd()->x() + padding);
        lineSegment->getEnd()->setY(referenceLineSegment->getEnd()->y() + padding);
    }
}

void setCurveCubicBezier(Curve* curve, const double& x, const double& y) {
    CubicBezier* cubicBezier = curve->createCubicBezier();
    cubicBezier->getStart()->setX(x);
    cubicBezier->getStart()->setY(y);
    cubicBezier->getBasePoint1()->setX(x);
    cubicBezier->getBasePoint1()->setY(y);
    cubicBezier->getBasePoint2()->setX(x);
    cubicBezier->getBasePoint2()->setY(y);
    cubicBezier->getEnd()->setX(x);
    cubicBezier->getEnd()->setY(y);
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
    if (textGlyph && graphicalObject)
        return textGlyph->getGraphicalObjectId() == graphicalObject->getId() ? true : false;

    return false;
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

const std::string getCompartmentGlyphId(Layout* layout, const std::string compartmentId) {
    std::string compartmentGlyphId = "";
    int compartmentGlyphIndex = 1;
    std::vector<CompartmentGlyph*> compartmentGlyphs = getAssociatedCompartmentGlyphsWithCompartmentId(layout, compartmentId);
    while (true) {
        compartmentGlyphId = compartmentId + "_Glyph_" + std::to_string(compartmentGlyphIndex++);
        bool isUniqueId = true;
        for (unsigned int i = 0; i < compartmentGlyphs.size(); i++) {
            if (compartmentGlyphId == compartmentGlyphs.at(i)->getId()) {
                isUniqueId = false;
                break;
            }
        }
        if (isUniqueId)
            break;
    }

    return compartmentGlyphId;
}

const std::string getSpeciesGlyphId(Layout* layout, const std::string speciesId) {
    std::string speciesGlyphId = "";
    int speciesGlyphIndex = 1;
    std::vector<SpeciesGlyph*> speciesGlyphs = getAssociatedSpeciesGlyphsWithSpeciesId(layout, speciesId);
    while (true) {
        speciesGlyphId = speciesId + "_Glyph_" + std::to_string(speciesGlyphIndex++);
        bool isUniqueId = true;
        for (unsigned int i = 0; i < speciesGlyphs.size(); i++) {
            if (speciesGlyphId == speciesGlyphs.at(i)->getId()) {
                isUniqueId = false;
                break;
            }
        }
        if (isUniqueId)
            break;
    }

    return speciesGlyphId;
}

const std::string getReactionGlyphId(Layout* layout, const std::string reactionId) {
    std::string reactionGlyphId = "";
    int reactionGlyphIndex = 1;
    std::vector<ReactionGlyph*> reactionGlyphs = getAssociatedReactionGlyphsWithReactionId(layout, reactionId);
    while (true) {
        reactionGlyphId = reactionId + "_Glyph_" + std::to_string(reactionGlyphIndex++);
        bool isUniqueId = true;
        for (unsigned int i = 0; i < reactionGlyphs.size(); i++) {
            if (reactionGlyphId == reactionGlyphs.at(i)->getId()) {
                isUniqueId = false;
                break;
            }
        }
        if (isUniqueId)
            break;
    }

    return reactionGlyphId;
}

const std::string getSpeciesReferenceGlyphId(ReactionGlyph* reactionGlyph, const std::string speciesGlyphId, unsigned int stoichiometryIndex) {
    std::string speciesReferenceGlyphId = "";
    int speciesReferenceGlyphIndex = 1;
    std::vector<SpeciesReferenceGlyph*> speciesReferenceGlyphs = getSpeciesReferenceGlyphs(reactionGlyph);
    std::string stoichiometryPhrase = "_Stoichiometry_" + std::to_string(stoichiometryIndex + 1);
    while (true) {
        speciesReferenceGlyphId = speciesGlyphId + "_" + reactionGlyph->getId() + stoichiometryPhrase + "_Glyph_" + std::to_string(speciesReferenceGlyphIndex++);
        bool isUniqueId = true;
        for (unsigned int i = 0; i < speciesReferenceGlyphs.size(); i++) {
            if (speciesReferenceGlyphId == speciesReferenceGlyphs.at(i)->getId()) {
                isUniqueId = false;
                break;
            }
        }
        if (isUniqueId)
            break;
    }

    return speciesReferenceGlyphId;
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

const bool isGraphicalObject(SBase* sbase) {
    return dynamic_cast<GraphicalObject*>(sbase) ? true : false;
}

const int getStoichiometryAsInteger(SimpleSpeciesReference* speciesReference) {
    if (speciesReference && dynamic_cast<SpeciesReference*>(speciesReference) && ((SpeciesReference*)speciesReference)->isSetStoichiometry())
        return int(((SpeciesReference*)speciesReference)->getStoichiometry());

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
