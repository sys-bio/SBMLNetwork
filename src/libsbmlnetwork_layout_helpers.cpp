#include "libsbmlnetwork_layout_helpers.h"
#include "libsbmlnetwork_common.h"
#include "libsbmlnetwork_layout.h"
#include "libsbmlnetwork_sbmldocument_layout.h"

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

void freeUserData(SBMLDocument* document) {
    if (document) {
        const int numLayouts = getNumLayouts(document);
        for (int i = 0; i < numLayouts; i++)
            freeUserData(getLayout(document, i));
    }
}

void freeUserData(Layout* layout) {
    if (layout->isSetUserData()) {
        auto userData = (std::map<std::string, std::string>*)layout->getUserData();
        if (userData) {
            delete userData;
        }
    }
    freeUserData(layout->getDimensions());
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++)
        freeUserData(layout->getCompartmentGlyph(i));
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++)
        freeUserData(layout->getSpeciesGlyph(i));
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++)
        freeUserData(layout->getReactionGlyph(i));
}

void freeUserData(SBase* sbase) {
    if (sbase->isSetUserData()) {
        auto userData = (std::map<std::string, std::string>*)sbase->getUserData();
        if (userData)
            delete userData;
    }
}

std::vector<std::map<std::string, std::string>> getUserData(Layout* layout) {
    std::vector<std::map<std::string, std::string>> userData;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        auto compartmentGlyphUserData = layout->getCompartmentGlyph(i)->getUserData();
        if (compartmentGlyphUserData)
            userData.push_back(*(std::map<std::string, std::string>*)compartmentGlyphUserData);
    }
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        auto speciesGlyphUserData = layout->getSpeciesGlyph(i)->getUserData();
        if (speciesGlyphUserData)
            userData.push_back(*(std::map<std::string, std::string>*)speciesGlyphUserData);
    }
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        auto reactionGlyphUserData = layout->getReactionGlyph(i)->getUserData();
        if (reactionGlyphUserData)
            userData.push_back(*(std::map<std::string, std::string>*)reactionGlyphUserData);
    }

    return userData;
}

const std::string getUserData(SBase* sbase, const std::string& key) {
    if (sbase->isSetUserData()) {
        auto userData = (std::map<std::string, std::string>*)sbase->getUserData();
        if (userData->find(key) != userData->end())
            return (*userData)[key];
    }

    return "";
}

void setUserData(SBase* sBase, const std::string& key, const std::string& value) {
    if (!sBase->isSetUserData()) {
        sBase->setUserData(new std::map<std::string, std::string>());
        GraphicalObject* castedGraphicalObject = dynamic_cast<GraphicalObject*>(sBase);
        if (castedGraphicalObject) {
            setUserData(sBase, "id", castedGraphicalObject->getId());
            setUserData(sBase, "entity_id", getEntityId(castedGraphicalObject));
        }
    }
    auto userData = (std::map<std::string, std::string>*)sBase->getUserData();
    (*userData)[key] = value;
}

void setDefaultLayoutId(Layout* layout) {
    if (!layout->isSetId())
        layout->setId(getDefaultLayoutId());
}

const std::string getDefaultLayoutId() {
    return  "libSBMLNetwork_Layout";
}

void setDefaultLayoutDimensions(Layout* layout) {
    Dimensions* dimensions = layout->getDimensions();
    if (!dimensions) {
        dimensions = new Dimensions(layout->getLevel(), layout->getVersion(), layout->getPackageVersion());
        layout->setDimensions(dimensions);
    }
    if (dimensions->getWidth() < 0.0001)
        dimensions->setWidth(1024.0);
    if (dimensions->getHeight() < 0.0001)
        dimensions->setHeight(1024.0);
}

const double getSpeciesDefaultWidth() {
    return 60.0;
}

const double getSpeciesDefaultHeight() {
    return 36.0;
}

const double getReactionDefaultWidth() {
    return 30.0;
}

const double getReactionDefaultHeight() {
    return 20.0;
}

void lockGraphicalObjects(Layout* layout, std::set<std::pair<std::string, int> > lockedNodesSet, const bool resetLockedNodes) {
    lockSpeciesGlyphs(layout, lockedNodesSet, resetLockedNodes);
    lockReactionGlyphs(layout, lockedNodesSet, resetLockedNodes);
}

void lockSpeciesGlyphs(Layout* layout, std::set<std::pair<std::string, int> > lockedNodesSet, const bool resetLockedNodes) {
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        SpeciesGlyph* speciesGlyph = layout->getSpeciesGlyph(i);
        if (resetLockedNodes && getUserData(speciesGlyph, "locked") == "true")
            unlockGraphicalObject(speciesGlyph);
    }

    for (std::set<std::pair<std::string, int> >::const_iterator lockedNodeIt = lockedNodesSet.cbegin(); lockedNodeIt != lockedNodesSet.cend(); lockedNodeIt++) {
        std::vector<SpeciesGlyph*> speciesGlyphs = getAssociatedSpeciesGlyphsWithSpeciesId(layout, lockedNodeIt->first);
        if (lockedNodeIt->second < speciesGlyphs.size()) {
            lockGraphicalObject(speciesGlyphs.at(lockedNodeIt->second));
        }
    }
}

void lockReactionGlyphs(Layout* layout, std::set<std::pair<std::string, int> > lockedNodesSet, const bool resetLockedNodes) {
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        ReactionGlyph* reactionGlyph = layout->getReactionGlyph(i);
        if (resetLockedNodes && getUserData(reactionGlyph, "locked") == "true")
            unlockGraphicalObject(reactionGlyph);
    }

    for (std::set<std::pair<std::string, int> >::const_iterator lockedNodeIt = lockedNodesSet.cbegin(); lockedNodeIt != lockedNodesSet.cend(); lockedNodeIt++) {
        std::vector<ReactionGlyph*> reactionGlyphs = getAssociatedReactionGlyphsWithReactionId(layout, lockedNodeIt->first);
        if (lockedNodeIt->second < reactionGlyphs.size()) {
            lockGraphicalObject(reactionGlyphs.at(lockedNodeIt->second));
        }
    }
}

void lockGraphicalObject(GraphicalObject* graphicalObject) {
    setUserData(graphicalObject, "locked", "true");
    setUserData(graphicalObject, "x", std::to_string(getPositionX(graphicalObject)));
    setUserData(graphicalObject, "y", std::to_string(getPositionY(graphicalObject)));
}

void unlockGraphicalObject(GraphicalObject* graphicalObject) {
    setUserData(graphicalObject, "locked", "false");
    setUserData(graphicalObject, "x", "");
    setUserData(graphicalObject, "y", "");
}

std::vector<GraphicalObject*> getLockedGraphicalObjects(std::vector<GraphicalObject*> graphicalObjects) {
    std::vector<GraphicalObject*> lockedGraphicalObjects;
    for (unsigned int i = 0; i < graphicalObjects.size(); i++)
        if (getUserData(graphicalObjects.at(i), "locked") == "true")
            lockedGraphicalObjects.push_back(graphicalObjects.at(i));

    return lockedGraphicalObjects;
}

void fixGraphicalObjectWidth(GraphicalObject* graphicalObject) {
    setUserData(graphicalObject, "width", std::to_string(graphicalObject->getBoundingBox()->width()));
}

void fixGraphicalObjectHeight(GraphicalObject* graphicalObject) {
    setUserData(graphicalObject, "height", std::to_string(graphicalObject->getBoundingBox()->height()));
}

void clearGraphicalObjects(Layout* layout) {
    clearCompartmentGlyphs(layout);
    clearSpeciesGlyphs(layout);
    clearReactionGlyphs(layout);
    clearTextGlyphs(layout);
}

void clearCompartmentGlyphs(Layout* layout) {
    while (layout->getNumCompartmentGlyphs()) {
        freeUserData(layout->getCompartmentGlyph(0));
        delete layout->removeCompartmentGlyph(0);
    }
}

void clearSpeciesGlyphs(Layout* layout) {
    while (layout->getNumSpeciesGlyphs()) {
        freeUserData(layout->getSpeciesGlyph(0));
        delete layout->removeSpeciesGlyph(0);
    }
}

void clearReactionGlyphs(Layout* layout) {
    while (layout->getNumReactionGlyphs()) {
        freeUserData(layout->getReactionGlyph(0));
        delete layout->removeReactionGlyph(0);
    }

}

void clearReactionGlyphSpeciesReferenceGlyphs(ReactionGlyph* reactionGlyph) {
    while (reactionGlyph->getNumSpeciesReferenceGlyphs()) {
        freeUserData(reactionGlyph->getSpeciesReferenceGlyph(0));
        delete reactionGlyph->removeSpeciesReferenceGlyph(0);
    }
}

void clearTextGlyphs(Layout* layout) {
    while (layout->getNumTextGlyphs()) {
        freeUserData(layout->getTextGlyph(0));
        delete layout->removeTextGlyph(0);
    }
}

void clearReactionTextGlyphs(Layout* layout) {
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        ReactionGlyph* reactionGlyph = layout->getReactionGlyph(i);
        std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, reactionGlyph);
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            freeUserData(textGlyphs.at(j));
            delete layout->removeTextGlyph(textGlyphs.at(j)->getId());
        }
    }
}

void setCompartmentGlyphs(Model* model, Layout* layout, const std::vector<std::map<std::string, std::string>>& userData) {
    for (unsigned int i = 0; i < model->getNumCompartments(); i++) {
        Compartment *compartment = model->getCompartment(i);
        CompartmentGlyph *compartmentGlyph = createCompartmentGlyph(layout, compartment);
        setGraphicalObjectBoundingBox(compartmentGlyph);
        setGraphicalObjectUserData(compartmentGlyph, userData);
    }
}

void setSpeciesGlyphs(Model* model, Layout* layout, const std::vector<std::map<std::string, std::string>>& userData) {
    for (unsigned int i = 0; i < model->getNumSpecies(); i++) {
        Species* species = model->getSpecies(i);
        SpeciesGlyph* speciesGlyph = createSpeciesGlyph(layout, species);
        setGraphicalObjectBoundingBox(speciesGlyph);
        setGraphicalObjectUserData(speciesGlyph, userData);
    }
}

void setReactionGlyphs(Model* model, Layout* layout, const std::vector<std::map<std::string, std::string>>& userData) {
    for (unsigned int i = 0; i < model->getNumReactions(); i++) {
        Reaction* reaction = model->getReaction(i);
        ReactionGlyph* reactionGlyph = createReactionGlyph(layout, reaction);
        setReactionGlyphCurve(reactionGlyph);
        setGraphicalObjectUserData(reactionGlyph, userData);
        clearReactionGlyphSpeciesReferenceGlyphs(reactionGlyph);
        setReactantGlyphs(layout, reaction, reactionGlyph);
        setProductGlyphs(layout, reaction, reactionGlyph);
        setModifierGlyphs(layout, reaction, reactionGlyph);
        setDummySpeciesReferenceGlyphs(model, layout, reactionGlyph);
    }
}

void setReactionGlyphCurve(ReactionGlyph* reactionGlyph) {
    if (!reactionGlyph->isSetCurve())
        setCurveCubicBezier(reactionGlyph->getCurve());
}

void setReactantGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph) {
    for (unsigned int i = 0; i < reaction->getNumReactants(); i++) {
        SimpleSpeciesReference* speciesReference = reaction->getReactant(i);
        for (unsigned int stoichiometryIndex = 0; stoichiometryIndex < getStoichiometryAsInteger(speciesReference); stoichiometryIndex++) {
            SpeciesReferenceGlyph* speciesReferenceGlyph = createAssociatedSpeciesReferenceGlyph(layout, reaction, reactionGlyph, speciesReference, stoichiometryIndex);
            speciesReferenceGlyph->setRole(SPECIES_ROLE_SUBSTRATE);
            setSpeciesReferenceGlyphCurve(speciesReferenceGlyph);
        }
    }
}

void setProductGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph) {
    for (unsigned int i = 0; i < reaction->getNumProducts(); i++) {
        SimpleSpeciesReference* speciesReference = reaction->getProduct(i);
        for (unsigned int stoichiometryIndex = 0; stoichiometryIndex < getStoichiometryAsInteger(speciesReference); stoichiometryIndex++) {
            SpeciesReferenceGlyph* speciesReferenceGlyph = createAssociatedSpeciesReferenceGlyph(layout, reaction, reactionGlyph, speciesReference, stoichiometryIndex);
            speciesReferenceGlyph->setRole(SPECIES_ROLE_PRODUCT);
            setSpeciesReferenceGlyphCurve(speciesReferenceGlyph);
        }
    }
}

void setModifierGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph) {
    for (unsigned int i = 0; i < reaction->getNumModifiers(); i++) {
        SimpleSpeciesReference* speciesReference = reaction->getModifier(i);
        SpeciesReferenceGlyph* speciesReferenceGlyph = createAssociatedSpeciesReferenceGlyph(layout, reaction, reactionGlyph, speciesReference);
        if (speciesReference->getSBOTermID() == "SBO:0000020")
            speciesReferenceGlyph->setRole(SPECIES_ROLE_INHIBITOR);
        else
            speciesReferenceGlyph->setRole(SPECIES_ROLE_MODIFIER);
        setSpeciesReferenceGlyphCurve(speciesReferenceGlyph);
    }
}

void setDummySpeciesReferenceGlyphs(Model* model, Layout* layout, ReactionGlyph* reactionGlyph) {
    Reaction* reaction = findReactionGlyphReaction(model, reactionGlyph);
    if (reaction->getNumReactants() == 0) {
        SpeciesReferenceGlyph* dummyReactantGlyph = createDummySpeciesReferenceGlyph(model, layout, reactionGlyph);
        dummyReactantGlyph->setRole(SPECIES_ROLE_SUBSTRATE);
    }
    else if (reaction->getNumProducts() == 0) {
        SpeciesReferenceGlyph* dummyProductGlyph = createDummySpeciesReferenceGlyph(model, layout, reactionGlyph);
        dummyProductGlyph->setRole(SPECIES_ROLE_PRODUCT);
    }
}

SpeciesReferenceGlyph* createDummySpeciesReferenceGlyph(Model* model, Layout* layout, ReactionGlyph* reactionGlyph) {
    SpeciesGlyph* dummySpeciesGlyph = createDummySpeciesGlyph(model, layout, reactionGlyph);
    return createDummySpeciesReferenceGlyph(layout, reactionGlyph, dummySpeciesGlyph);
}

SpeciesGlyph* createDummySpeciesGlyph(Model* model, Layout* layout, ReactionGlyph* reactionGlyph) {
    std::string dummySpeciesGlyphId = reactionGlyph->getId() + "_DummySpeciesGlyph";
    SpeciesGlyph* dummySpeciesGlyph = layout->createSpeciesGlyph();
    dummySpeciesGlyph->setId(dummySpeciesGlyphId);
    CompartmentGlyph* compartmentGlyph = getCompartmentGlyphOfReactionGlyph(model, layout, reactionGlyph);
    if (compartmentGlyph)
        setUserData(dummySpeciesGlyph, "compartment", compartmentGlyph->getCompartmentId());
    setGraphicalObjectBoundingBox(dummySpeciesGlyph);

    return dummySpeciesGlyph;
}

SpeciesReferenceGlyph* createDummySpeciesReferenceGlyph(Layout* layout, ReactionGlyph* reactionGlyph, SpeciesGlyph* dummySpeciesGlyph) {
    SpeciesReferenceGlyph* dummySpeciesReferenceGlyph = layout->createSpeciesReferenceGlyph();
    dummySpeciesReferenceGlyph->setId(reactionGlyph->getId() + "_DummySpeciesReferenceGlyph");
    dummySpeciesReferenceGlyph->setSpeciesGlyphId(dummySpeciesGlyph->getId());
    setSpeciesReferenceGlyphCurve(dummySpeciesReferenceGlyph);

    return dummySpeciesReferenceGlyph;
}

void setAliasSpeciesGlyphs(Layout* layout, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData) {
    if (maxNumConnectedEdges < 1) {
        std::cerr << "error: Maximum number of connected edges must be greater than 0\n";
        return;
    }
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        SpeciesGlyph* speciesGlyph = layout->getSpeciesGlyph(i);
        std::vector<SpeciesReferenceGlyph*> connectedSpeciesGlyphReferences = getConnectedSpeciesGlyphReferences(layout, speciesGlyph);
        int numRequiredAliasSpeciesGlyphs = getNumRequiredAliasSpeciesGlyphs(connectedSpeciesGlyphReferences.size(), maxNumConnectedEdges);
        if (numRequiredAliasSpeciesGlyphs > 0)
            createAliasSpeciesGlyphs(layout, speciesGlyph, connectedSpeciesGlyphReferences, maxNumConnectedEdges, numRequiredAliasSpeciesGlyphs, userData);
    }
}

int createAliasSpeciesGlyphs(Layout* layout, SpeciesGlyph* speciesGlyph, std::vector<SpeciesReferenceGlyph*> speciesGlyphReferences, const int maxNumConnectedEdges, const int numRequiredAliasSpeciesGlyphs, const std::vector<std::map<std::string, std::string>>& userData) {
    if (numRequiredAliasSpeciesGlyphs) {
        for (int i = 0; i < numRequiredAliasSpeciesGlyphs; i++) {
            SpeciesGlyph* aliasSpeciesGlyph = createAliasSpeciesGlyph(layout, speciesGlyph->getSpeciesId());
            setGraphicalObjectUserData(aliasSpeciesGlyph, userData);
            while (speciesGlyphReferences.size() > (numRequiredAliasSpeciesGlyphs - i) * maxNumConnectedEdges) {
                SpeciesReferenceGlyph* speciesReferenceGlyph = speciesGlyphReferences.back();
                speciesReferenceGlyph->setSpeciesGlyphId(aliasSpeciesGlyph->getId());
                speciesGlyphReferences.pop_back();
            }
        }

        return 0;
    }

    return -1;
}

int createAliasSpeciesGlyph(Layout* layout, const std::string speciesId, ReactionGlyph* reactionGlyph) {
    if (reactionGlyph) {
        std::vector<SpeciesReferenceGlyph*> speciesGlyphReferences = getSpeciesReferencesAssociatedWithSpecies(layout, reactionGlyph, speciesId);
        if (canHaveAlias(layout, speciesGlyphReferences)) {
            SpeciesGlyph* aliasSpeciesGlyph = createAliasSpeciesGlyph(layout, speciesId, speciesGlyphReferences);
            if (aliasSpeciesGlyph) {
                setAliasSpeciesGlyphPosition(aliasSpeciesGlyph, reactionGlyph);
                setAliasSpeciesGlyphDimensions(aliasSpeciesGlyph);
                setAliasSpeciesGlyphTextGlyph(layout, aliasSpeciesGlyph);
                return 0;
            }
        }
    }


    return -1;
}

SpeciesGlyph* createAliasSpeciesGlyph(Layout* layout, const std::string& speciesId, std::vector<SpeciesReferenceGlyph*> speciesGlyphReferences) {
    SpeciesGlyph* aliasSpeciesGlyph = NULL;
    if (speciesGlyphReferences.size()) {
        aliasSpeciesGlyph = createAliasSpeciesGlyph(layout, speciesId);
        while (speciesGlyphReferences.size()) {
            SpeciesReferenceGlyph* speciesReferenceGlyph = speciesGlyphReferences.back();
            speciesReferenceGlyph->setId(getIdOfSpeciesReferenceGlyphConnectedToAliasSpeciesGlyph(speciesReferenceGlyph->getId(), speciesReferenceGlyph->getSpeciesGlyphId(), aliasSpeciesGlyph->getId()));
            speciesReferenceGlyph->setSpeciesGlyphId(aliasSpeciesGlyph->getId());
            speciesGlyphReferences.pop_back();
        }
    }

    return aliasSpeciesGlyph;
}

SpeciesGlyph* createAliasSpeciesGlyph(Layout* layout, const std::string& speciesId) {
    SpeciesGlyph* aliasSpeciesGlyph = layout->createSpeciesGlyph();
    aliasSpeciesGlyph->setId(getAliasSpeciesGlyphId(layout, speciesId));
    aliasSpeciesGlyph->setSpeciesId(speciesId);
    setGraphicalObjectBoundingBox(aliasSpeciesGlyph);

    return aliasSpeciesGlyph;
}

const bool canHaveAlias(Layout* layout, std::vector<SpeciesReferenceGlyph*> connectedSpeciesGlyphReferencesOfReactionGlyph) {
    if (connectedSpeciesGlyphReferencesOfReactionGlyph.size()) {
        SpeciesGlyph* speciesGlyph = layout->getSpeciesGlyph(connectedSpeciesGlyphReferencesOfReactionGlyph.at(0)->getSpeciesGlyphId());
        std::vector<SpeciesReferenceGlyph*> connectedSpeciesGlyphReferencesOfSpeciesGlyph = getConnectedSpeciesGlyphReferences(layout, speciesGlyph);
        if (connectedSpeciesGlyphReferencesOfSpeciesGlyph.size() > connectedSpeciesGlyphReferencesOfReactionGlyph.size())
            return true;
    }

    return false;
}

void setAliasSpeciesGlyphPosition(SpeciesGlyph* aliasSpeciesGlyph, ReactionGlyph* reactionGlyph) {
    double x = getPositionX(reactionGlyph);
    double y = getPositionY(reactionGlyph);
    aliasSpeciesGlyph->getBoundingBox()->setX(x);
    aliasSpeciesGlyph->getBoundingBox()->setY(y);
}

void setAliasSpeciesGlyphDimensions(SpeciesGlyph* aliasSpeciesGlyph) {
    aliasSpeciesGlyph->getBoundingBox()->setWidth(getSpeciesDefaultWidth());
    aliasSpeciesGlyph->getBoundingBox()->setHeight(getSpeciesDefaultHeight());
}

void setAliasSpeciesGlyphTextGlyph(Layout* layout, SpeciesGlyph* aliasSpeciesGlyph) {
    TextGlyph* textGlyph = createAssociatedTextGlyph(layout, aliasSpeciesGlyph);
    setTextGlyphBoundingBox(textGlyph, aliasSpeciesGlyph);
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

int getNumRequiredAliasSpeciesGlyphs(const int numConnectedEdges, const int maxNumConnectedEdges) {
    int numRequiredAliasSpeciesGlyphs = 0;
    if (numConnectedEdges > maxNumConnectedEdges)
        numRequiredAliasSpeciesGlyphs = numConnectedEdges / maxNumConnectedEdges;
    if (numConnectedEdges % maxNumConnectedEdges == 0)
        numRequiredAliasSpeciesGlyphs--;

    return numRequiredAliasSpeciesGlyphs;
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

CompartmentGlyph* createCompartmentGlyph(Layout* layout, Compartment* compartment) {
    CompartmentGlyph* compartmentGlyph = layout->createCompartmentGlyph();
    compartmentGlyph->setId(compartment->getId() + "_Glyph_1");
    compartmentGlyph->setCompartmentId(compartment->getId());
    
    return compartmentGlyph;
}

SpeciesGlyph* createSpeciesGlyph(Layout* layout, Species* species) {
    SpeciesGlyph *speciesGlyph = layout->createSpeciesGlyph();
    speciesGlyph->setId(species->getId() + "_Glyph_1");
    speciesGlyph->setSpeciesId(species->getId());

    return speciesGlyph;
}

ReactionGlyph* createReactionGlyph(Layout* layout, Reaction* reaction) {
    ReactionGlyph* reactionGlyph = layout->createReactionGlyph();
    reactionGlyph->setId(reaction->getId() + "_Glyph_1");
    reactionGlyph->setReactionId(reaction->getId());
    
    return reactionGlyph;
}

CompartmentGlyph* getCompartmentGlyphOfReactionGlyph(Model* model, Layout* layout, ReactionGlyph* reactionGlyph) {
    Compartment* compartment = findReactionGlyphCompartment(model, reactionGlyph);
    if (compartment) {
        std::vector<CompartmentGlyph*> compartmentGlyphs = getAssociatedCompartmentGlyphsWithCompartmentId(layout, compartment->getId());
        if (compartmentGlyphs.size() == 1)
            return compartmentGlyphs.at(0);
    }

    return getDefaultCompartmentGlyph(layout);
}

CompartmentGlyph* getDefaultCompartmentGlyph(Layout* layout) {
    if (layout->getNumCompartmentGlyphs() == 1 && layout->getCompartmentGlyph(0)->getCompartmentId() == "default_compartment")
        return layout->getCompartmentGlyph(0);

    return NULL;
}

SpeciesReferenceGlyph* createAssociatedSpeciesReferenceGlyph(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, SimpleSpeciesReference* speciesReference, unsigned int stoichiometryIndex) {
    SpeciesReferenceGlyph* speciesReferenceGlyph = reactionGlyph->createSpeciesReferenceGlyph();
    if (!speciesReference->getId().empty()) {
        speciesReferenceGlyph->setId(speciesReference->getId() + "_Glyph_1" + "_Stoichiometry_" + std::to_string(stoichiometryIndex + 1));
        speciesReferenceGlyph->setSpeciesReferenceId(speciesReference->getId());
    }
    else
        speciesReferenceGlyph->setId(speciesReference->getSpecies() + "_Glyph_1_" + reactionGlyph->getId() + "_SpeciesReference" + std::to_string(reactionGlyph->getNumSpeciesReferenceGlyphs()) + "_Stoichiometry_" + std::to_string(stoichiometryIndex + 1));
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

const int getSpeciesReferenceIndex(Layout* layout, ReactionGlyph* reactionGlyph, SpeciesReferenceGlyph* speciesReferenceGlyph) {
    if (reactionGlyph && speciesReferenceGlyph) {
        for (unsigned int i = 0; i < reactionGlyph->getNumSpeciesReferenceGlyphs(); i++) {
            if (reactionGlyph->getSpeciesReferenceGlyph(i) == speciesReferenceGlyph)
                return i;
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

void setGraphicalObjectUserData(GraphicalObject* graphicalObject, const std::vector<std::map<std::string, std::string>>& userData) {
    for (unsigned int i = 0; i < userData.size(); i++) {
        if (userData.at(i).at("id") == graphicalObject->getId()) {
            for (auto it = userData.at(i).begin(); it != userData.at(i).end(); it++)
                setUserData(graphicalObject, it->first, it->second);
            break;
        }
    }
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
    else
        return model->getCompartment(getUserData(speciesGlyph, "compartment"));
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

const std::string getAliasSpeciesGlyphId(Layout* layout, const std::string speciesId) {
    std::string aliasSpeciesGlyphId = "";
    int aliasSpeciesGlyphIndex = 1;
    std::vector<SpeciesGlyph*> speciesGlyphs = getAssociatedSpeciesGlyphsWithSpeciesId(layout, speciesId);
    while (true) {
        aliasSpeciesGlyphId = speciesId + "_Glyph_" + std::to_string(aliasSpeciesGlyphIndex++);
        bool isUniqueId = true;
        for (unsigned int i = 0; i < speciesGlyphs.size(); i++) {
            if (aliasSpeciesGlyphId == speciesGlyphs.at(i)->getId()) {
                isUniqueId = false;
                break;
            }
        }
        if (isUniqueId)
            break;
    }

    return aliasSpeciesGlyphId;
}

const std::string getIdOfSpeciesReferenceGlyphConnectedToAliasSpeciesGlyph(std::string speciesReferenceGlyphId, const std::string& originalSpeciesGlyphId, const std::string& aliasSpeciesGlyphId) {
    std::string::size_type pos = speciesReferenceGlyphId.find(originalSpeciesGlyphId);
    if (pos != std::string::npos)
        speciesReferenceGlyphId.replace(pos, originalSpeciesGlyphId.length(), aliasSpeciesGlyphId);

    return speciesReferenceGlyphId;
}

const bool layoutContainsGlyphs(Layout* layout) {
    return (layout->getNumCompartmentGlyphs() > 0) ||
           (layout->getNumSpeciesGlyphs() > 0) ||
           (layout->getNumReactionGlyphs() > 0);
}

const int getStoichiometryAsInteger(SimpleSpeciesReference* speciesReference) {
    if (dynamic_cast<SpeciesReference*>(speciesReference) && ((SpeciesReference*)speciesReference)->isSetStoichiometry())
        return int(((SpeciesReference*)speciesReference)->getStoichiometry());
    else
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

void alignGraphicalObjects(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const std::string& alignment, const bool ignoreLockedNodes) {
    if (isValidAlignment(alignment)) {
        if (stringCompare(alignment, "top"))
            alignGraphicalObjectsToTop(layout, graphicalObjects, ignoreLockedNodes);
        else if (stringCompare(alignment, "vCenter"))
            alignGraphicalObjectsToVerticalCenter(layout, graphicalObjects, ignoreLockedNodes);
        else if (stringCompare(alignment, "bottom"))
            alignGraphicalObjectsToBottom(layout, graphicalObjects, ignoreLockedNodes);
        else if (stringCompare(alignment, "left"))
            alignGraphicalObjectsToLeft(layout, graphicalObjects, ignoreLockedNodes);
        else if (stringCompare(alignment, "hCenter"))
            alignGraphicalObjectsToHorizontalCenter(layout, graphicalObjects, ignoreLockedNodes);
        else if (stringCompare(alignment, "right"))
            alignGraphicalObjectsToRight(layout, graphicalObjects, ignoreLockedNodes);
        else if (stringCompare(alignment, "circular") || stringCompare(alignment, "circle"))
            alignGraphicalObjectsCircularly(layout, graphicalObjects, ignoreLockedNodes);
    }
}

void alignGraphicalObjectsToTop(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const bool ignoreLockedNodes) {
    try {
        double minY = getTopAlignmentPosition(graphicalObjects, ignoreLockedNodes);
        for (unsigned int i = 0; i < graphicalObjects.size(); i++)
            setPositionY(layout, graphicalObjects.at(i), minY);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what();
    }
}

const double getTopAlignmentPosition(std::vector<GraphicalObject*> graphicalObjects, const bool ignoreLockedNodes) {
    if (ignoreLockedNodes)
        return getMinPositionY(graphicalObjects);
    std::vector<GraphicalObject*> lockedGraphicalObjects = getLockedGraphicalObjects(graphicalObjects);
    if (lockedGraphicalObjects.size() == 0)
        return getMinPositionY(graphicalObjects);
    else if (lockedGraphicalObjects.size() == 1)
        return lockedGraphicalObjects.at(0)->getBoundingBox()->y();
    else
        throw std::invalid_argument("error: Multiple graphical objects in your align list are locked, so the alignment cannot be applied. Use the ignoreLockedNodes option to ignore locked nodes.\n");
}

void alignGraphicalObjectsToHorizontalCenter(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const bool ignoreLockedNodes) {
    try {
        double centerX = getHorizontalCenterAlignmentPosition(graphicalObjects, ignoreLockedNodes);
        for (unsigned int i = 0; i < graphicalObjects.size(); i++)
            setPositionX(layout, graphicalObjects.at(i), centerX);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what();
    }
}

const double getHorizontalCenterAlignmentPosition(std::vector<GraphicalObject*> graphicalObjects, const bool ignoreLockedNodes) {
    if (ignoreLockedNodes)
        return 0.5 * (getMinPositionX(graphicalObjects) + getMaxPositionX(graphicalObjects));
    std::vector<GraphicalObject*> lockedGraphicalObjects = getLockedGraphicalObjects(graphicalObjects);
    if (lockedGraphicalObjects.size() == 0)
        return 0.5 * (getMinPositionX(graphicalObjects) + getMaxPositionX(graphicalObjects));
    else if (lockedGraphicalObjects.size() == 1)
        return lockedGraphicalObjects.at(0)->getBoundingBox()->x();
    else
        throw std::invalid_argument("error: Multiple graphical objects in your align list are locked, so the alignment cannot be applied. Use the ignoreLockedNodes option to ignore locked nodes.\n");
}

void alignGraphicalObjectsToBottom(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const bool ignoreLockedNodes) {
    try {
        double maxY = getBottomAlignmentPosition(graphicalObjects, ignoreLockedNodes);
        for (unsigned int i = 0; i < graphicalObjects.size(); i++)
            setPositionY(layout, graphicalObjects.at(i), maxY);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what();
    }
}

const double getBottomAlignmentPosition(std::vector<GraphicalObject*> graphicalObjects, const bool ignoreLockedNodes) {
    if (ignoreLockedNodes)
        return getMaxPositionY(graphicalObjects);
    std::vector<GraphicalObject*> lockedGraphicalObjects = getLockedGraphicalObjects(graphicalObjects);
    if (lockedGraphicalObjects.size() == 0)
        return getMaxPositionY(graphicalObjects);
    else if (lockedGraphicalObjects.size() == 1)
        return lockedGraphicalObjects.at(0)->getBoundingBox()->y();
    else
        throw std::invalid_argument("error: Multiple graphical objects in your align list are locked, so the alignment cannot be applied. Use the ignoreLockedNodes option to ignore locked nodes.\n");
}

void alignGraphicalObjectsToLeft(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const bool ignoreLockedNodes) {
    try {
        double minX = getLeftAlignmentPosition(graphicalObjects, ignoreLockedNodes);
        for (unsigned int i = 0; i < graphicalObjects.size(); i++)
            setPositionX(layout, graphicalObjects.at(i), minX);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what();
    }
}

const double getLeftAlignmentPosition(std::vector<GraphicalObject*> graphicalObjects, const bool ignoreLockedNodes) {
    if (ignoreLockedNodes)
        return getMinPositionX(graphicalObjects);
    std::vector<GraphicalObject*> lockedGraphicalObjects = getLockedGraphicalObjects(graphicalObjects);
    if (lockedGraphicalObjects.size() == 0)
        return getMinPositionX(graphicalObjects);
    else if (lockedGraphicalObjects.size() == 1)
        return lockedGraphicalObjects.at(0)->getBoundingBox()->x();
    else
        throw std::invalid_argument("error: Multiple graphical objects in your align list are locked, so the alignment cannot be applied. Use the ignoreLockedNodes option to ignore locked nodes.\n");
}

void alignGraphicalObjectsToVerticalCenter(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const bool ignoreLockedNodes) {
    try {
        double centerY = getVerticalCenterAlignmentPosition(graphicalObjects, ignoreLockedNodes);
        for (unsigned int i = 0; i < graphicalObjects.size(); i++)
            setPositionY(layout, graphicalObjects.at(i), centerY);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what();
    }
}

const double getVerticalCenterAlignmentPosition(std::vector<GraphicalObject*> graphicalObjects, const bool ignoreLockedNodes) {
    if (ignoreLockedNodes)
        return 0.5 * (getMinPositionY(graphicalObjects) + getMaxPositionY(graphicalObjects));
    std::vector<GraphicalObject*> lockedGraphicalObjects = getLockedGraphicalObjects(graphicalObjects);
    if (lockedGraphicalObjects.size() == 0)
        return 0.5 * (getMinPositionY(graphicalObjects) + getMaxPositionY(graphicalObjects));
    else if (lockedGraphicalObjects.size() == 1)
        return lockedGraphicalObjects.at(0)->getBoundingBox()->y();
    else
        throw std::invalid_argument("error: Multiple graphical objects in your align list are locked, so the alignment cannot be applied. Use the ignoreLockedNodes option to ignore locked nodes.\n");
}

void alignGraphicalObjectsToRight(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const bool ignoreLockedNodes) {
    try {
        double maxX = getRightAlignmentPosition(graphicalObjects, ignoreLockedNodes);
        for (unsigned int i = 0; i < graphicalObjects.size(); i++)
            setPositionX(layout, graphicalObjects.at(i), maxX);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what();
    }
}

const double getRightAlignmentPosition(std::vector<GraphicalObject*> graphicalObjects, const bool ignoreLockedNodes) {
    if (ignoreLockedNodes)
        return getMaxPositionX(graphicalObjects);
    std::vector<GraphicalObject*> lockedGraphicalObjects = getLockedGraphicalObjects(graphicalObjects);
    if (lockedGraphicalObjects.size() == 0)
        return getMaxPositionX(graphicalObjects);
    else if (lockedGraphicalObjects.size() == 1)
        return lockedGraphicalObjects.at(0)->getBoundingBox()->x();
    else
        throw std::invalid_argument("error: Multiple graphical objects in your align list are locked, so the alignment cannot be applied. Use the ignoreLockedNodes option to ignore locked nodes.\n");
}

void alignGraphicalObjectsCircularly(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const bool ignoreLockedNodes) {
    double radius = graphicalObjects.size() * 50.0;
    double angle = 2 * M_PI / graphicalObjects.size();
    double centerX = std::max(radius, 0.5 * (getMinCenterX(graphicalObjects) + getMaxCenterX(graphicalObjects)));
    double centerY = std::max(radius, 0.5 * (getMinCenterY(graphicalObjects) + getMaxCenterY(graphicalObjects)));
    for (unsigned int i = 0; i < graphicalObjects.size(); i++) {
        setPositionX(layout, graphicalObjects.at(i), centerX + radius * cos(i * angle) - 0.5 * graphicalObjects.at(i)->getBoundingBox()->width());
        setPositionY(layout, graphicalObjects.at(i), centerY + radius * sin(i * angle) - 0.5 * graphicalObjects.at(i)->getBoundingBox()->height());
    }
}

void distributeGraphicalObjects(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const std::string& direction, const double& spacing) {
    if (isValidDistributionDirection(direction)) {
        if (stringCompare(direction, "horizontal"))
            distributeGraphicalObjectsHorizontally(layout, graphicalObjects, spacing);
        else if (stringCompare(direction, "vertical"))
            distributeGraphicalObjectsVertically(layout, graphicalObjects, spacing);
    }
}

void distributeGraphicalObjectsHorizontally(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const double& spacing) {
    if (graphicalObjects.size() < 2)
        return;
    double minX = getMinPositionX(graphicalObjects);
    double maxX = getMaxPositionX(graphicalObjects);
    double minY = getMinPositionY(graphicalObjects);
    double maxY = getMaxPositionY(graphicalObjects);
    double distance = findDistributionDistance(minX, maxX, graphicalObjects.size(), spacing);
    if (graphicalObjects.size() % 2 == 0) {
        for (unsigned int i = 0; i < graphicalObjects.size(); i++) {
            setPositionX(layout, graphicalObjects.at(i), minX + i * distance);
            setPositionY(layout, graphicalObjects.at(i), 0.5 * (minY + maxY));
        }
    }
    else {
        for (unsigned int i = 0; i < graphicalObjects.size(); i++) {
            setPositionX(layout, graphicalObjects.at(i),
                         0.5 * (minX + maxX) + (i - 0.5 * (graphicalObjects.size() - 1)) * distance);
            setPositionY(layout, graphicalObjects.at(i), 0.5 * (minY + maxY));
        }
    }
}

void distributeGraphicalObjectsVertically(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const double& spacing) {
    if (graphicalObjects.size() < 2)
        return;
    double minX = getMinPositionX(graphicalObjects);
    double maxX = getMaxPositionX(graphicalObjects);
    double minY = getMinPositionY(graphicalObjects);
    double maxY = getMaxPositionY(graphicalObjects);
    double distance = findDistributionDistance(minY, maxY, graphicalObjects.size(), spacing);

    if (graphicalObjects.size() % 2 == 0) {
        for (unsigned int i = 0; i < graphicalObjects.size(); i++) {
            setPositionX(layout, graphicalObjects.at(i), 0.5 * (minX + maxX));
            setPositionY(layout, graphicalObjects.at(i), minY + i * distance);
        }
    }
    else {
        for (unsigned int i = 0; i < graphicalObjects.size(); i++) {
            setPositionX(layout, graphicalObjects.at(i), 0.5 * (minX + maxX));
            setPositionY(layout, graphicalObjects.at(i),
                         0.5 * (minY + maxY) + (i - 0.5 * (graphicalObjects.size() - 1)) * distance);
        }
    }
}

const double findDistributionDistance(const double& minPosition, const double& maxPosition, const unsigned int& numGraphicalObjects, const double& spacing) {
    double distance = 0;
    if (spacing > 0)
        distance = spacing;
    else
        distance = (maxPosition - minPosition) / (numGraphicalObjects - 1);

    return distance;
}

std::vector<std::string> getSortedNodeIdsVector(std::set <std::pair<std::string, unsigned int>> nodeIds) {
    std::vector<std::string> sortedNodeIdsVector;
    for (unsigned int nodeIdIndex = 0; nodeIdIndex < nodeIds.size(); nodeIdIndex++) {
        for (std::set<std::pair<std::string, unsigned int>>::const_iterator nodeIt = nodeIds.cbegin(); nodeIt != nodeIds.cend(); nodeIt++) {
            if (nodeIt->second == nodeIdIndex) {
                sortedNodeIdsVector.push_back(nodeIt->first);
                break;
            }
        }
    }

    return sortedNodeIdsVector;
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

const double getDefaultAutoLayoutPadding() {
    return 30.0;
}

const bool isValidLayoutDimensionWidthValue(const double& width) {
    if (isValidDimensionValue(width) && width > 6 * getDefaultAutoLayoutPadding())
        return true;

    return false;
}

const bool isValidLayoutDimensionHeightValue(const double& height) {
    if (isValidDimensionValue(height) && height > 6 * getDefaultAutoLayoutPadding())
        return true;

    return false;
}

const bool isValidRoleValue(const std::string& role) {
    return isValueValid(role, getValidRoleValues());
}

const bool isValidBoundingBoxXValue(const double& x) {
    return isValidDoubleValue(x);
}

const bool isValidBoundingBoxYValue(const double& y) {
    return isValidDoubleValue(y);
}

const bool isValidBoundingBoxWidthValue(const double& width) {
    return isValidDimensionValue(width);
}

const bool isValidBoundingBoxHeightValue(const double& height) {
    return isValidDimensionValue(height);
}

const bool isValidCurveSegmentStartPointXValue(const double& x) {
    return isValidDoubleValue(x);
}

const bool isValidCurveSegmentStartPointYValue(const double& y) {
    return isValidDoubleValue(y);
}

const bool isValidCurveSegmentEndPointXValue(const double& x) {
    return isValidDoubleValue(x);
}

const bool isValidCurveSegmentEndPointYValue(const double& y) {
    return isValidDoubleValue(y);
}

const bool isValidCurveSegmentBasePoint1XValue(const double& x) {
    return isValidDoubleValue(x);
}

const bool isValidCurveSegmentBasePoint1YValue(const double& y) {
    return isValidDoubleValue(y);
}

const bool isValidCurveSegmentBasePoint2XValue(const double& x) {
    return isValidDoubleValue(x);
}

const bool isValidCurveSegmentBasePoint2YValue(const double& y) {
    return isValidDoubleValue(y);
}

const bool isValidDimensionValue(const double& dimensionValue) {
    if (isValidDoubleValue(dimensionValue) && dimensionValue > 0.000)
        return true;

    std::cerr << "error: A dimension value must be greater than 0" << std::endl;
    return false;
}

const bool isValidDoubleValue(const double& doubleValue) {
    if (!std::isnan(doubleValue) && !std::isinf(doubleValue))
        return true;

    std::cerr << "error: A double value must be a valid number" << std::endl;
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
    alignmentValues.push_back("vCenter");
    alignmentValues.push_back("bottom");
    alignmentValues.push_back("left");
    alignmentValues.push_back("hCenter");
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
