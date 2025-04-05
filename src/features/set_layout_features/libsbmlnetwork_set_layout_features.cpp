#include "libsbmlnetwork_set_layout_features.h"
#include "../../libsbmlnetwork_layout.h"
#include "../../libsbmlnetwork_layout_helpers.h"
#include "../../features/autolayout/libsbmlnetwork_autolayout.h"
#include "../../features/user_data/libsbmlnetwork_user_data.h"
#include "../../features/defaults/libsbmlnetwork_defaults_layout.h"
#include "../../features/fix_elements/libsbmlnetwork_fix_element_position.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

int set_layout_features_setDefaultLayoutFeatures(SBMLDocument* document, Layout* layout, const int maxNumConnectedEdges) {
    if (document && layout) {
        user_data_passUserData(document, layout);
        defaults_setDefaultLayoutId(layout);
        defaults_setDefaultLayoutDimensions(layout);
        Model* model = document->getModel();
        if (model) {
            set_layout_features_clearGraphicalObjects(layout);
            set_layout_features_setCompartmentGlyphs(model, layout);
            set_layout_features_setReactionGlyphs(model, layout, maxNumConnectedEdges);
            set_layout_features_setTextGlyphs(layout);
            user_data_setUserData(layout, "max_num_connected_edges", std::to_string(maxNumConnectedEdges));
            return 0;
        }
    }

    return -1;
}

int set_layout_features_setDefaultLayoutLocations(SBMLDocument* document, Layout* layout, const int maxNumConnectedEdges,
                      bool resetFixedPositionElements, const std::set<std::pair<std::string, int> > fixedPositionNodesSet) {
    if (document && layout) {
        user_data_passUserData(document, layout);
        defaults_setDefaultLayoutId(layout);
        defaults_setDefaultLayoutDimensions(layout);
        Model* model = document->getModel();
        if (model) {
            fix_elements_fixGraphicalObjectsPosition(layout, fixedPositionNodesSet, resetFixedPositionElements);
            std::vector<std::map<std::string, std::string>> userData = user_data_getUserData(layout);
            set_layout_features_clearGraphicalObjects(layout);
            set_layout_features_setCompartmentGlyphs(model, layout, userData);
            set_layout_features_setReactionGlyphs(model, layout, maxNumConnectedEdges, userData);
            autolayout_locateGlyphs(model, layout);
            set_layout_features_setTextGlyphs(layout);
            user_data_setUserData(layout, "max_num_connected_edges", std::to_string(maxNumConnectedEdges));
            return 0;
        }
}

return -1;
}

void set_layout_features_clearGraphicalObjects(Layout* layout) {
    set_layout_features_clearCompartmentGlyphs(layout);
    set_layout_features_clearSpeciesGlyphs(layout);
    set_layout_features_clearReactionGlyphs(layout);
    set_layout_features_clearTextGlyphs(layout);
    set_layout_clearAdditionalGraphicalObjects(layout);
}

void set_layout_features_clearCompartmentGlyphs(Layout* layout) {
    while (layout->getNumCompartmentGlyphs()) {
        user_data_freeUserData(layout->getCompartmentGlyph(0));
        delete layout->removeCompartmentGlyph(0);
    }
}

void set_layout_features_clearSpeciesGlyphs(Layout* layout) {
    while (layout->getNumSpeciesGlyphs()) {
        user_data_freeUserData(layout->getSpeciesGlyph(0));
        delete layout->removeSpeciesGlyph(0);
    }
}

void set_layout_features_clearReactionGlyphs(Layout* layout) {
    while (layout->getNumReactionGlyphs()) {
        set_layout_features_clearReactionGlyphSpeciesReferenceGlyphs(layout->getReactionGlyph(0));
        user_data_freeUserData(layout->getReactionGlyph(0));
        delete layout->removeReactionGlyph(0);
    }

}

void set_layout_features_clearReactionGlyphSpeciesReferenceGlyphs(ReactionGlyph* reactionGlyph) {
    while (reactionGlyph->getNumSpeciesReferenceGlyphs()) {
        user_data_freeUserData(reactionGlyph->getSpeciesReferenceGlyph(0));
        delete reactionGlyph->removeSpeciesReferenceGlyph(0);
    }
}

void set_layout_features_clearTextGlyphs(Layout* layout) {
    while (layout->getNumTextGlyphs()) {
        user_data_freeUserData(layout->getTextGlyph(0));
        delete layout->removeTextGlyph(0);
    }
}

void set_layout_features_clearReactionTextGlyphs(Layout* layout) {
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        ReactionGlyph* reactionGlyph = layout->getReactionGlyph(i);
        std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, reactionGlyph);
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            user_data_freeUserData(textGlyphs.at(j));
            delete layout->removeTextGlyph(textGlyphs.at(j)->getId());
        }
    }
}

void set_layout_clearAdditionalGraphicalObjects(Layout* layout) {
    for (unsigned int i = 0; i < layout->getNumAdditionalGraphicalObjects(); i++) {
        user_data_freeUserData(layout->getAdditionalGraphicalObject(i));
        delete layout->removeAdditionalGraphicalObject(i);
    }
}

void set_layout_features_setCompartmentGlyphs(Model* model, Layout* layout, const std::vector<std::map<std::string, std::string>>& userData) {
    for (unsigned int i = 0; i < model->getNumCompartments(); i++) {
        Compartment *compartment = model->getCompartment(i);
        CompartmentGlyph *compartmentGlyph = set_layout_features_createCompartmentGlyph(layout, compartment->getId(), userData);
        set_layout_features_setGraphicalObjectBoundingBox(compartmentGlyph);
    }
}

void set_layout_features_setReactionGlyphs(Model* model, Layout* layout, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData) {
    for (unsigned int i = 0; i < model->getNumReactions(); i++) {
        Reaction* reaction = model->getReaction(i);
        ReactionGlyph* reactionGlyph = set_layout_features_createReactionGlyph(layout, reaction->getId(), userData);
        set_layout_features_setReactantGlyphs(layout, reaction, reactionGlyph, maxNumConnectedEdges, userData);
        set_layout_features_setProductGlyphs(layout, reaction, reactionGlyph, maxNumConnectedEdges, userData);
        set_layout_features_setModifierGlyphs(layout, reaction, reactionGlyph, maxNumConnectedEdges, userData);
        set_layout_features_setEmptySpeciesReferenceGlyphs(model, layout, reactionGlyph, userData);
    }
}

void set_layout_features_setReactantGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData) {
    for (unsigned int i = 0; i < reaction->getNumReactants(); i++) {
        SimpleSpeciesReference* speciesReference = reaction->getReactant(i);
        int stoichiometry = getStoichiometryAsInteger(layout, speciesReference);
        for (unsigned int stoichiometryIndex = 0; stoichiometryIndex < stoichiometry; stoichiometryIndex++) {
            SpeciesReferenceGlyph *speciesReferenceGlyph = set_layout_features_createSpeciesReferenceGlyph(layout, reactionGlyph, speciesReference->getSpecies(), stoichiometryIndex, maxNumConnectedEdges, userData);
            speciesReferenceGlyph->setRole(SPECIES_ROLE_SUBSTRATE);
        }
    }
}

void set_layout_features_setProductGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData) {
    for (unsigned int i = 0; i < reaction->getNumProducts(); i++) {
        SimpleSpeciesReference* speciesReference = reaction->getProduct(i);
        int stoichiometry = getStoichiometryAsInteger(layout, speciesReference);
        for (unsigned int stoichiometryIndex = 0; stoichiometryIndex < stoichiometry; stoichiometryIndex++) {
            SpeciesReferenceGlyph* speciesReferenceGlyph = set_layout_features_createSpeciesReferenceGlyph(layout, reactionGlyph, speciesReference->getSpecies(), stoichiometryIndex, maxNumConnectedEdges, userData);
            speciesReferenceGlyph->setRole(SPECIES_ROLE_PRODUCT);
        }
    }
}

void set_layout_features_setModifierGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData) {
    for (unsigned int i = 0; i < reaction->getNumModifiers(); i++) {
        SimpleSpeciesReference* speciesReference = reaction->getModifier(i);
        SpeciesReferenceGlyph* speciesReferenceGlyph = set_layout_features_createSpeciesReferenceGlyph(layout, reactionGlyph, speciesReference->getSpecies(), 0, maxNumConnectedEdges, userData);
        if (speciesReference->getSBOTermID() == "SBO:0000020")
            speciesReferenceGlyph->setRole(SPECIES_ROLE_INHIBITOR);
        else
            speciesReferenceGlyph->setRole(SPECIES_ROLE_MODIFIER);
    }
}

void set_layout_features_setEmptySpeciesReferenceGlyphs(Model* model, Layout* layout, ReactionGlyph* reactionGlyph, const std::vector<std::map<std::string, std::string>>& userData) {
    Reaction* reaction = findReactionGlyphReaction(model, reactionGlyph);
    if (reaction->getNumReactants() == 0) {
        SpeciesReferenceGlyph* emptyReactantGlyph = set_layout_features_createEmptySpeciesReferenceGlyph(model, layout, reactionGlyph, userData);
        emptyReactantGlyph->setRole(SPECIES_ROLE_SUBSTRATE);
    }
    else if (reaction->getNumProducts() == 0) {
        SpeciesReferenceGlyph* emptyProductGlyph = set_layout_features_createEmptySpeciesReferenceGlyph(model, layout, reactionGlyph, userData);
        emptyProductGlyph->setRole(SPECIES_ROLE_PRODUCT);
    }
}

SpeciesReferenceGlyph* set_layout_features_createEmptySpeciesReferenceGlyph(Model* model, Layout* layout, ReactionGlyph* reactionGlyph, const std::vector<std::map<std::string, std::string>>& userData) {
    SpeciesGlyph* emptySpeciesGlyph = set_layout_features_createEmptySpeciesGlyph(model, layout, reactionGlyph, userData);
    return set_layout_features_createEmptySpeciesReferenceGlyph(layout, reactionGlyph, emptySpeciesGlyph, userData);
}

SpeciesGlyph* set_layout_features_createEmptySpeciesGlyph(Model* model, Layout* layout, ReactionGlyph* reactionGlyph, const std::vector<std::map<std::string, std::string>>& userData) {
    SpeciesGlyph* emptySpeciesGlyph = set_layout_features_createEmptySpeciesGlyph(layout, reactionGlyph->getId(), userData);
    std::string compartmentId = user_data_getUserData(emptySpeciesGlyph, "compartment");
    if (compartmentId.empty()) {
        CompartmentGlyph* compartmentGlyph = getCompartmentGlyphOfReactionGlyph(model, layout, reactionGlyph);
        if (compartmentGlyph)
            user_data_setUserData(emptySpeciesGlyph, "compartment", compartmentGlyph->getCompartmentId());
    }
    std::string fixedWidth = user_data_getUserData(emptySpeciesGlyph, "width");
    if (fixedWidth.empty())
        user_data_setUserData(emptySpeciesGlyph, "width", std::to_string(defaults_getEmptySpeciesDefaultWidth()));
    std::string fixedHeight = user_data_getUserData(emptySpeciesGlyph, "height");
    if (fixedHeight.empty())
        user_data_setUserData(emptySpeciesGlyph, "height", std::to_string(defaults_getEmptySpeciesDefaultHeight()));

    return emptySpeciesGlyph;
}

SpeciesReferenceGlyph* set_layout_features_createEmptySpeciesReferenceGlyph(Layout* layout, ReactionGlyph* reactionGlyph, SpeciesGlyph* emptySpeciesGlyph, const std::vector<std::map<std::string, std::string>>& userData) {
    SpeciesReferenceGlyph* emptySpeciesReferenceGlyph = layout->createSpeciesReferenceGlyph();
    emptySpeciesReferenceGlyph->setId(reactionGlyph->getId() + "_EmptySpeciesReferenceGlyph");
    emptySpeciesReferenceGlyph->setSpeciesGlyphId(emptySpeciesGlyph->getId());
    set_layout_features_setSpeciesReferenceGlyphCurve(emptySpeciesReferenceGlyph);
    user_data_setGraphicalObjectUserData(emptySpeciesReferenceGlyph, userData);

    return emptySpeciesReferenceGlyph;
}

void set_layout_features_setReactionBoundingBoxes(Layout* layout) {
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++)
        setReactionGlyphBoundingBox(layout->getReactionGlyph(i));
}

SpeciesGlyph* set_layout_features_getSpeciesGlyph(Layout* layout, const std::string& speciesId, const std::string& speciesGlyphId, const std::vector<std::map<std::string, std::string>>& userData) {
    if (!speciesGlyphId.empty()) {
        if (layout->getSpeciesGlyph(speciesGlyphId))
            return layout->getSpeciesGlyph(speciesGlyphId);

        return set_layout_features_createSpeciesGlyph(layout, speciesId, speciesGlyphId, userData);
    }

    return NULL;
}

SpeciesGlyph* set_layout_features_getSpeciesGlyph(Layout* layout, const std::string& speciesId, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData) {
    std::string speciesGlyphId;
    int speciesGlyphIndex = 0;
    while(true) {
        speciesGlyphId = speciesId + "_Glyph_" + std::to_string(speciesGlyphIndex);
        if (!layout->getSpeciesGlyph(speciesGlyphId))
            return set_layout_features_createSpeciesGlyph(layout, speciesId, speciesGlyphId, userData);
        else if (set_layout_features_getConnectedSpeciesGlyphReferences(layout, layout->getSpeciesGlyph(speciesGlyphId)).size() < maxNumConnectedEdges)
            return layout->getSpeciesGlyph(speciesGlyphId);

        speciesGlyphIndex++;
    }
}

void set_layout_features_setTextGlyphs(Layout* layout) {
    set_layout_features_setCompartmentTextGlyphs(layout);
    set_layout_features_setSpeciesTextGlyphs(layout);
    set_layout_features_setReactionTextGlyphs(layout);
}

void set_layout_features_setCompartmentTextGlyphs(Layout* layout) {
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        TextGlyph* textGlyph = createAssociatedTextGlyph(layout, layout->getCompartmentGlyph(i));
        setTextGlyphBoundingBox(textGlyph, layout->getCompartmentGlyph(i));
    }
}

void set_layout_features_setSpeciesTextGlyphs(Layout* layout) {
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        TextGlyph* textGlyph = createAssociatedTextGlyph(layout, layout->getSpeciesGlyph(i));
        setTextGlyphBoundingBox(textGlyph, layout->getSpeciesGlyph(i));
    }
}

void set_layout_features_setReactionTextGlyphs(Layout* layout) {
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        double padding = 5.0;
        TextGlyph* textGlyph = createAssociatedTextGlyph(layout, layout->getReactionGlyph(i));
        setTextGlyphBoundingBox(textGlyph, layout->getReactionGlyph(i), padding);
    }
}

CompartmentGlyph* set_layout_features_createCompartmentGlyph(Layout* layout, const std::string& compartmentId, const std::vector<std::map<std::string, std::string>>& userData) {
    CompartmentGlyph* compartmentGlyph = layout->createCompartmentGlyph();
    compartmentGlyph->setId(set_layout_features_getCompartmentGlyphId(layout, compartmentId));
    compartmentGlyph->setCompartmentId(compartmentId);
    set_layout_features_setGraphicalObjectBoundingBox(compartmentGlyph);
    user_data_setGraphicalObjectUserData(compartmentGlyph, userData);

    return compartmentGlyph;
}

SpeciesGlyph* set_layout_features_createSpeciesGlyph(Layout* layout, const std::string& speciesId, const std::string& speciesGlyphId, const std::vector<std::map<std::string, std::string>>& userData) {
    SpeciesGlyph *speciesGlyph = layout->createSpeciesGlyph();
    speciesGlyph->setId(speciesGlyphId);
    speciesGlyph->setSpeciesId(speciesId);
    set_layout_features_setGraphicalObjectBoundingBox(speciesGlyph);
    user_data_setGraphicalObjectUserData(speciesGlyph, userData);

    return speciesGlyph;
}

SpeciesGlyph* set_layout_features_createEmptySpeciesGlyph(Layout* layout, const std::string& reactionGlyphId, const std::vector<std::map<std::string, std::string>>& userData) {
    SpeciesGlyph *speciesGlyph = layout->createSpeciesGlyph();
    speciesGlyph->setId(reactionGlyphId + "_EmptySpeciesGlyph");
    set_layout_features_setGraphicalObjectBoundingBox(speciesGlyph);
    user_data_setGraphicalObjectUserData(speciesGlyph, userData);

    return speciesGlyph;
}

ReactionGlyph* set_layout_features_createReactionGlyph(Layout* layout, const std::string& reactionId, const std::vector<std::map<std::string, std::string>>& userData) {
    ReactionGlyph* reactionGlyph = layout->createReactionGlyph();
    reactionGlyph->setId(set_layout_features_getReactionGlyphId(layout, reactionId));
    reactionGlyph->setReactionId(reactionId);
    setReactionGlyphCurve(reactionGlyph);
    user_data_setGraphicalObjectUserData(reactionGlyph, userData);

    return reactionGlyph;
}

SpeciesReferenceGlyph* set_layout_features_createSpeciesReferenceGlyph(Layout* layout, ReactionGlyph* reactionGlyph, const std::string& speciesId, unsigned int stoichiometryIndex, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData) {
    SpeciesGlyph* speciesGlyph = set_layout_features_getSpeciesGlyph(layout, speciesId, user_data_getUserData(reactionGlyph, "alias_" + speciesId), userData);
    if (!speciesGlyph)
        speciesGlyph = set_layout_features_getSpeciesGlyph(layout, speciesId, maxNumConnectedEdges, userData);
    SpeciesReferenceGlyph* speciesReferenceGlyph = reactionGlyph->createSpeciesReferenceGlyph();
    speciesReferenceGlyph->setId(set_layout_features_getSpeciesReferenceGlyphId(reactionGlyph, speciesGlyph->getId(), stoichiometryIndex));
    speciesReferenceGlyph->setSpeciesGlyphId(speciesGlyph->getId());
    set_layout_features_setSpeciesReferenceGlyphCurve(speciesReferenceGlyph);
    user_data_setGraphicalObjectUserData(speciesReferenceGlyph, userData);

    return speciesReferenceGlyph;
}

SpeciesReferenceGlyph* set_layout_features_createSpeciesReferenceGlyph(ReactionGlyph* reactionGlyph, const std::string& speciesGlyphId, unsigned int stoichiometryIndex) {
    SpeciesReferenceGlyph* speciesReferenceGlyph = reactionGlyph->createSpeciesReferenceGlyph();
    speciesReferenceGlyph->setId(set_layout_features_getSpeciesReferenceGlyphId(reactionGlyph, speciesGlyphId, stoichiometryIndex));
    speciesReferenceGlyph->setSpeciesGlyphId(speciesGlyphId);

    return speciesReferenceGlyph;
}

GraphicalObject* set_layout_features_createAdditionalGraphicalObject(Layout* layout, const std::string& id) {
    GraphicalObject* graphicalObject = layout->createAdditionalGraphicalObject();
    graphicalObject->setId(id);
    set_layout_features_setGraphicalObjectBoundingBox(graphicalObject);

    return graphicalObject;
}

int set_layout_features_removeAdditionalGraphicalObject(Layout* layout, const std::string& id) {
    if (layout->removeAdditionalGraphicalObject(id))
        return 0;

    return -1;
}

int set_layout_features_removeAdditionalGraphicalObject(Layout* layout, const unsigned int graphicalObjectIndex) {
    if (layout && graphicalObjectIndex < layout->getNumAdditionalGraphicalObjects()) {
        user_data_freeUserData(layout->getAdditionalGraphicalObject(graphicalObjectIndex));
        delete layout->removeAdditionalGraphicalObject(graphicalObjectIndex);
        return 0;
    }

    return -1;
}

std::vector<SpeciesReferenceGlyph*> set_layout_features_getConnectedSpeciesGlyphReferences(Layout* layout, SpeciesGlyph* speciesGlyph) {
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

const std::string set_layout_features_getCompartmentGlyphId(Layout* layout, const std::string compartmentId) {
    std::string compartmentGlyphId = "";
    int compartmentGlyphIndex = 0;
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

const std::string set_layout_features_getSpeciesGlyphId(Layout* layout, const std::string speciesId) {
    std::string speciesGlyphId = "";
    int speciesGlyphIndex = 0;
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

const std::string set_layout_features_getReactionGlyphId(Layout* layout, const std::string reactionId) {
    std::string reactionGlyphId = "";
    int reactionGlyphIndex = 0;
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

const std::string set_layout_features_getSpeciesReferenceGlyphId(ReactionGlyph* reactionGlyph, const std::string speciesGlyphId, unsigned int stoichiometryIndex) {
    std::string speciesReferenceGlyphId = "";
    int speciesReferenceGlyphIndex = 0;
    std::vector<SpeciesReferenceGlyph*> speciesReferenceGlyphs = getSpeciesReferenceGlyphs(reactionGlyph);
    std::string stoichiometryPhrase = "_Stoichiometry_" + std::to_string(stoichiometryIndex);
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

void set_layout_features_setGraphicalObjectBoundingBox(GraphicalObject* graphicalObject) {
    if  (!graphicalObject->getBoundingBox()->isSetId())
        graphicalObject->getBoundingBox()->setId(graphicalObject->getId() + "_bb");
}

void set_layout_features_setSpeciesReferenceGlyphCurve(SpeciesReferenceGlyph* speciesReferenceGlyph, SpeciesReferenceGlyph* referenceSpeciesReferenceGlyph, const double& padding) {
    if (referenceSpeciesReferenceGlyph->isSetCurve()) {
        Curve* referenceCurve = referenceSpeciesReferenceGlyph->getCurve();
        Curve* curve = speciesReferenceGlyph->getCurve();
        for (unsigned int i = 0; i < referenceCurve->getNumCurveSegments(); i++)
            set_layout_features_addCurveSegment(curve, referenceCurve->getCurveSegment(i), padding);
    }
}

void set_layout_features_setSpeciesReferenceGlyphCurve(SpeciesReferenceGlyph* speciesReferenceGlyph) {
    if (!speciesReferenceGlyph->isSetCurve())
        set_layout_features_setCurveCubicBezier(speciesReferenceGlyph->getCurve());
}

void set_layout_features_addCurveSegment(Curve* curve, LineSegment* referenceLineSegment, const double& padding) {
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

void set_layout_features_setCurveCubicBezier(Curve* curve, const double& x, const double& y) {
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

}
