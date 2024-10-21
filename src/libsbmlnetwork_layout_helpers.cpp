#include "libsbmlnetwork_layout_helpers.h"
#include "libsbmlnetwork_common.h"
#include "libsbmlnetwork_layout.h"
#include "libsbmlnetwork_sbmldocument_layout.h"
#include "libsbmlnetwork_sbmldocument_helpers.h"

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
        addErrorToLog(document, "Failed to load model");
    
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

std::string getErrorLog(Layout* layout) {
    std::string errorLog = "";
    if (layout) {
        errorLog += prepareErrorMessage(getUserData(layout, "error_log"), errorLog);
        for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++)
            errorLog += prepareErrorMessage(getErrorLog(layout->getCompartmentGlyph(i)), errorLog);
        for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++)
            errorLog += prepareErrorMessage(getErrorLog(layout->getSpeciesGlyph(i)), errorLog);
        for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
            errorLog += prepareErrorMessage(getErrorLog(layout->getReactionGlyph(i)), errorLog);
            for (unsigned int j = 0; j < layout->getReactionGlyph(i)->getNumSpeciesReferenceGlyphs(); j++)
                errorLog += prepareErrorMessage(getErrorLog(layout->getReactionGlyph(i)->getSpeciesReferenceGlyph(j)), errorLog);
        }
        for (unsigned int i = 0; i < layout->getNumTextGlyphs(); i++)
            errorLog += prepareErrorMessage(getErrorLog(layout->getTextGlyph(i)), errorLog);
    }

    return errorLog;
}

std::string getErrorLog(GraphicalObject* graphicalObject) {
    std::string errorLog = "";
    if (graphicalObject)
        errorLog += prepareErrorMessage(getUserData(graphicalObject, "error_log"), errorLog);
    if (graphicalObject->getBoundingBox())
        errorLog += prepareErrorMessage(getErrorLog(graphicalObject->getBoundingBox()), errorLog);
    if (isSetCurve(graphicalObject))
        errorLog += prepareErrorMessage(getErrorLog(getCurve(graphicalObject)), errorLog);

    return errorLog;
}

std::string getErrorLog(BoundingBox* boundingBox) {
    std::string errorLog = "";
    if (boundingBox)
        errorLog += prepareErrorMessage(getUserData(boundingBox, "error_log"), errorLog);

    return errorLog;
}

std::string getErrorLog(Curve* curve) {
    std::string errorLog = "";
    if (curve)
        errorLog += prepareErrorMessage(getUserData(curve, "error_log"), errorLog);
    for (unsigned int i = 0; i < getNumCurveSegments(curve); i++)
        errorLog += prepareErrorMessage(getErrorLog(getCurveSegment(curve, i)), errorLog);

    return errorLog;
}

std::string getErrorLog(LineSegment* lineSegment) {
    std::string errorLog = "";
    if (lineSegment)
        errorLog += prepareErrorMessage(getUserData(lineSegment, "error_log"), errorLog);

    return errorLog;
}

void clearErrorLog(Layout* layout) {
    if (layout) {
        setUserData(layout, "error_log", "");
        for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++)
            clearErrorLog(layout->getCompartmentGlyph(i));
        for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++)
            clearErrorLog(layout->getSpeciesGlyph(i));
        for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
            clearErrorLog(layout->getReactionGlyph(i));
            for (unsigned int j = 0; j < layout->getReactionGlyph(i)->getNumSpeciesReferenceGlyphs(); j++)
                clearErrorLog(layout->getReactionGlyph(i)->getSpeciesReferenceGlyph(j));
        }
        for (unsigned int i = 0; i < layout->getNumTextGlyphs(); i++)
            clearErrorLog(layout->getTextGlyph(i));
    }
}

void clearErrorLog(GraphicalObject* graphicalObject) {
    if (graphicalObject) {
        setUserData(graphicalObject, "error_log", "");
        if (graphicalObject->getBoundingBox())
            clearErrorLog(graphicalObject->getBoundingBox());
        if (isSetCurve(graphicalObject))
            clearErrorLog(getCurve(graphicalObject));
    }
}

void clearErrorLog(BoundingBox* boundingBox) {
    if (boundingBox)
        setUserData(boundingBox, "error_log", "");
}

void clearErrorLog(Curve* curve) {
    if (curve) {
        setUserData(curve, "error_log", "");
        for (unsigned int i = 0; i < getNumCurveSegments(curve); i++)
            clearErrorLog(getCurveSegment(curve, i));
    }
}

void clearErrorLog(LineSegment* lineSegment) {
    if (lineSegment)
        setUserData(lineSegment, "error_log", "");
}

void freeUserData(Layout* layout) {
    if (layout->isSetUserData()) {
        auto userData = (std::map<std::string, std::string>*)layout->getUserData();
        if (userData) {
            delete userData;
        }
    }
    freeUserData(layout->getDimensions());
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        CompartmentGlyph* compartmentGlyph = layout->getCompartmentGlyph(i);
        freeUserData(compartmentGlyph);
        freeUserData(compartmentGlyph->getBoundingBox());
    }
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        SpeciesGlyph* speciesGlyph = layout->getSpeciesGlyph(i);
        freeUserData(speciesGlyph);
        freeUserData(speciesGlyph->getBoundingBox());
    }
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        ReactionGlyph* reactionGlyph = layout->getReactionGlyph(i);
        freeUserData(reactionGlyph);
        freeUserData(reactionGlyph->getBoundingBox());
        freeUserData(reactionGlyph->getCurve());
        for (unsigned int j = 0; j < reactionGlyph->getNumSpeciesReferenceGlyphs(); j++) {
            SpeciesReferenceGlyph* speciesReferenceGlyph = reactionGlyph->getSpeciesReferenceGlyph(j);
            freeUserData(speciesReferenceGlyph);
            freeUserData(speciesReferenceGlyph->getCurve());
        }
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
        for (unsigned int j = 0; j < layout->getReactionGlyph(i)->getNumSpeciesReferenceGlyphs(); j++) {
            auto speciesReferenceGlyphUserData = layout->getReactionGlyph(i)->getSpeciesReferenceGlyph(j)->getUserData();
            if (speciesReferenceGlyphUserData)
                userData.push_back(*(std::map<std::string, std::string>*)speciesReferenceGlyphUserData);
        }
    }

    return userData;
}

void setUserData(GraphicalObject* graphicalObject, const std::string& key, const std::string& value) {
    if (!graphicalObject->isSetUserData()) {
        std::map<std::string, std::string> userData;
        graphicalObject->setUserData(&userData);
        setUserData(graphicalObject, "id", graphicalObject->getId());
        setUserData(graphicalObject, "entity_id", getEntityId(graphicalObject));
    }
    auto userData = (std::map<std::string, std::string>*)graphicalObject->getUserData();
    (*userData)[key] = value;
}

void setPositionData(GraphicalObject* graphicalObject) {
    setUserData(graphicalObject, "x", std::to_string(getPositionX(graphicalObject)));
    setUserData(graphicalObject, "y", std::to_string(getPositionY(graphicalObject)));
}

void unsetPositionData(GraphicalObject* graphicalObject) {
    setUserData(graphicalObject, "x", "");
    setUserData(graphicalObject, "y", "");
}

void setPositionData(SpeciesReferenceGlyph* speciesReferenceGlyph) {
    if (speciesReferenceGlyph) {
        Curve* curve = getCurve(speciesReferenceGlyph);
        for (unsigned int i = 0; i < getNumCurveSegments(curve); i++) {
            setUserData(speciesReferenceGlyph, std::to_string(i) + ":start_x", std::to_string(getCurveSegmentStartPointX(curve, i)));
            setUserData(speciesReferenceGlyph, std::to_string(i) + ":start_y", std::to_string(getCurveSegmentStartPointY(curve, i)));
            setUserData(speciesReferenceGlyph, std::to_string(i) + ":end_x", std::to_string(getCurveSegmentEndPointX(curve, i)));
            setUserData(speciesReferenceGlyph, std::to_string(i) + ":end_y", std::to_string(getCurveSegmentEndPointY(curve, i)));
            if (isCubicBezier(curve, i)) {
                setUserData(speciesReferenceGlyph, std::to_string(i) + ":b1_x", std::to_string(getCurveSegmentBasePoint1X(curve, i)));
                setUserData(speciesReferenceGlyph, std::to_string(i) + ":b1_y", std::to_string(getCurveSegmentBasePoint1Y(curve, i)));
                setUserData(speciesReferenceGlyph, std::to_string(i) + ":b2_x", std::to_string(getCurveSegmentBasePoint2X(curve, i)));
                setUserData(speciesReferenceGlyph, std::to_string(i) + ":b2_y", std::to_string(getCurveSegmentBasePoint2Y(curve, i)));
            }
        }
    }
}

void unsetPositionData(SpeciesReferenceGlyph* speciesReferenceGlyph) {
    if (speciesReferenceGlyph) {
        Curve* curve = getCurve(speciesReferenceGlyph);
        for (unsigned int i = 0; i < getNumCurveSegments(curve); i++) {
            setUserData(curve, std::to_string(i) + ":start_x", "");
            setUserData(curve, std::to_string(i) + ":start_y", "");
            setUserData(curve, std::to_string(i) + ":end_x", "");
            setUserData(curve, std::to_string(i) + ":end_y", "");
            setUserData(curve, std::to_string(i) + ":b1_x", "");
            setUserData(curve, std::to_string(i) + ":b1_y", "");
            setUserData(curve, std::to_string(i) + ":b2_x", "");
            setUserData(curve, std::to_string(i) + ":b2_y", "");
        }
    }
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

void lockGraphicalObjects(Layout* layout, std::set<std::pair<std::string, int> > lockedNodesSet, const bool resetLockedElements) {
    lockCompartmentGlyphs(layout, resetLockedElements);
    lockSpeciesGlyphs(layout, lockedNodesSet, resetLockedElements);
    lockReactionGlyphs(layout, lockedNodesSet, resetLockedElements);
}

void lockCompartmentGlyphs(Layout* layout, const bool resetLockedElements) {
    if (resetLockedElements) {
        for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
            CompartmentGlyph* compartmentGlyph = layout->getCompartmentGlyph(i);
            if (getUserData(compartmentGlyph, "locked") == "true")
                unlockGraphicalObject(compartmentGlyph);
            if (getUserData(compartmentGlyph, "fixed_width") == "true")
                unfixGraphicalObjectWidth(compartmentGlyph);
            if (getUserData(compartmentGlyph, "fixed_height") == "true")
                unfixGraphicalObjectHeight(compartmentGlyph);
        }
    }
}

void lockSpeciesGlyphs(Layout* layout, std::set<std::pair<std::string, int> > lockedNodesSet, const bool resetLockedElements) {
    if (resetLockedElements) {
        for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
            SpeciesGlyph* speciesGlyph = layout->getSpeciesGlyph(i);
            if (getUserData(speciesGlyph, "locked") == "true")
                unlockGraphicalObject(speciesGlyph);
            if (getUserData(speciesGlyph, "fixed_width") == "true")
                unfixGraphicalObjectWidth(speciesGlyph);
            if (getUserData(speciesGlyph, "fixed_height") == "true")
                unfixGraphicalObjectHeight(speciesGlyph);
        }
    }

    for (std::set<std::pair<std::string, int> >::const_iterator lockedNodeIt = lockedNodesSet.cbegin(); lockedNodeIt != lockedNodesSet.cend(); lockedNodeIt++) {
        std::vector<SpeciesGlyph*> speciesGlyphs = getAssociatedSpeciesGlyphsWithSpeciesId(layout, lockedNodeIt->first);
        if (lockedNodeIt->second < speciesGlyphs.size()) {
            lockGraphicalObject(speciesGlyphs.at(lockedNodeIt->second));
        }
    }
}

void lockReactionGlyphs(Layout* layout, std::set<std::pair<std::string, int> > lockedNodesSet, const bool resetLockedElements) {
    if (resetLockedElements) {
        for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
            ReactionGlyph* reactionGlyph = layout->getReactionGlyph(i);
            if (getUserData(reactionGlyph, "locked") == "true")
                unlockGraphicalObject(reactionGlyph);
            if (getUserData(reactionGlyph, "fixed_width") == "true")
                unfixGraphicalObjectWidth(reactionGlyph);
            if (getUserData(reactionGlyph, "fixed_height") == "true")
                unfixGraphicalObjectHeight(reactionGlyph);
            for (unsigned int j = 0; j < reactionGlyph->getNumSpeciesReferenceGlyphs(); j++) {
                SpeciesReferenceGlyph *speciesReferenceGlyph = reactionGlyph->getSpeciesReferenceGlyph(j);
                if (getUserData(speciesReferenceGlyph, "locked") == "true")
                    unlockGraphicalObject(speciesReferenceGlyph);
            }
        }
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
    if (isSpeciesReferenceGlyph(graphicalObject))
        setPositionData((SpeciesReferenceGlyph*)graphicalObject);
    else
        setPositionData(graphicalObject);
}

void unlockGraphicalObject(GraphicalObject* graphicalObject) {
    setUserData(graphicalObject, "locked", "false");
    if (isSpeciesReferenceGlyph(graphicalObject))
        unsetPositionData((SpeciesReferenceGlyph*)graphicalObject);
    else
        unsetPositionData(graphicalObject);
}

std::vector<GraphicalObject*> getLockedGraphicalObjects(std::vector<GraphicalObject*> graphicalObjects) {
    std::vector<GraphicalObject*> lockedGraphicalObjects;
    for (unsigned int i = 0; i < graphicalObjects.size(); i++)
        if (getUserData(graphicalObjects.at(i), "locked") == "true")
            lockedGraphicalObjects.push_back(graphicalObjects.at(i));

    return lockedGraphicalObjects;
}

void fixGraphicalObjectWidth(GraphicalObject* graphicalObject) {
    setUserData(graphicalObject, "fixed_width", "true");
    setUserData(graphicalObject, "width", std::to_string(graphicalObject->getBoundingBox()->width()));
}

void unfixGraphicalObjectWidth(GraphicalObject* graphicalObject) {
    setUserData(graphicalObject, "fixed_width", "false");
    setUserData(graphicalObject, "width", "");
}

void fixGraphicalObjectHeight(GraphicalObject* graphicalObject) {
    setUserData(graphicalObject, "fixed_height", "true");
    setUserData(graphicalObject, "height", std::to_string(graphicalObject->getBoundingBox()->height()));
}

void unfixGraphicalObjectHeight(GraphicalObject* graphicalObject) {
    setUserData(graphicalObject, "fixed_height", "false");
    setUserData(graphicalObject, "height", "");
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
        setReactantGlyphs(layout, reaction, reactionGlyph, userData);
        setProductGlyphs(layout, reaction, reactionGlyph, userData);
        setModifierGlyphs(layout, reaction, reactionGlyph, userData);
        setDummySpeciesReferenceGlyphs(model, layout, reactionGlyph, userData);
    }
}

void setReactionGlyphCurve(ReactionGlyph* reactionGlyph) {
    if (!reactionGlyph->isSetCurve())
        setCurveCubicBezier(reactionGlyph->getCurve());
}

void setReactantGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, const std::vector<std::map<std::string, std::string>>& userData) {
    for (unsigned int i = 0; i < reaction->getNumReactants(); i++) {
        SimpleSpeciesReference* speciesReference = reaction->getReactant(i);
        for (unsigned int stoichiometryIndex = 0; stoichiometryIndex < getStoichiometryAsInteger(speciesReference); stoichiometryIndex++) {
            SpeciesReferenceGlyph* speciesReferenceGlyph = createAssociatedSpeciesReferenceGlyph(layout, reaction, reactionGlyph, speciesReference, stoichiometryIndex);
            speciesReferenceGlyph->setRole(SPECIES_ROLE_SUBSTRATE);
            setSpeciesReferenceGlyphCurve(speciesReferenceGlyph);
            setGraphicalObjectUserData(speciesReferenceGlyph, userData);
        }
    }
}

void setProductGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, const std::vector<std::map<std::string, std::string>>& userData) {
    for (unsigned int i = 0; i < reaction->getNumProducts(); i++) {
        SimpleSpeciesReference* speciesReference = reaction->getProduct(i);
        for (unsigned int stoichiometryIndex = 0; stoichiometryIndex < getStoichiometryAsInteger(speciesReference); stoichiometryIndex++) {
            SpeciesReferenceGlyph* speciesReferenceGlyph = createAssociatedSpeciesReferenceGlyph(layout, reaction, reactionGlyph, speciesReference, stoichiometryIndex);
            speciesReferenceGlyph->setRole(SPECIES_ROLE_PRODUCT);
            setSpeciesReferenceGlyphCurve(speciesReferenceGlyph);
            setGraphicalObjectUserData(speciesReferenceGlyph, userData);
        }
    }
}

void setModifierGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, const std::vector<std::map<std::string, std::string>>& userData) {
    for (unsigned int i = 0; i < reaction->getNumModifiers(); i++) {
        SimpleSpeciesReference* speciesReference = reaction->getModifier(i);
        SpeciesReferenceGlyph* speciesReferenceGlyph = createAssociatedSpeciesReferenceGlyph(layout, reaction, reactionGlyph, speciesReference);
        if (speciesReference->getSBOTermID() == "SBO:0000020")
            speciesReferenceGlyph->setRole(SPECIES_ROLE_INHIBITOR);
        else
            speciesReferenceGlyph->setRole(SPECIES_ROLE_MODIFIER);
        setSpeciesReferenceGlyphCurve(speciesReferenceGlyph);
        setGraphicalObjectUserData(speciesReferenceGlyph, userData);
    }
}

void setDummySpeciesReferenceGlyphs(Model* model, Layout* layout, ReactionGlyph* reactionGlyph, const std::vector<std::map<std::string, std::string>>& userData) {
    Reaction* reaction = findReactionGlyphReaction(model, reactionGlyph);
    if (reaction->getNumReactants() == 0) {
        SpeciesReferenceGlyph* dummyReactantGlyph = createDummySpeciesReferenceGlyph(model, layout, reactionGlyph);
        dummyReactantGlyph->setRole(SPECIES_ROLE_SUBSTRATE);
        setGraphicalObjectUserData(dummyReactantGlyph, userData);
    }
    else if (reaction->getNumProducts() == 0) {
        SpeciesReferenceGlyph* dummyProductGlyph = createDummySpeciesReferenceGlyph(model, layout, reactionGlyph);
        dummyProductGlyph->setRole(SPECIES_ROLE_PRODUCT);
        setGraphicalObjectUserData(dummyProductGlyph, userData);
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
        addErrorToLog(layout, "Maximum number of connected edges must be greater than 0");
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
    if (isValidAlignment(layout, alignment)) {
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
        addErrorToLog(layout, e.what());
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
        addErrorToLog(layout, e.what());
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
        addErrorToLog(layout, e.what());
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
        addErrorToLog(layout, e.what());
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
        addErrorToLog(layout, e.what());
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
        addErrorToLog(layout, e.what());
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
    if (isValidDistributionDirection(layout, direction)) {
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

const bool isValidLayoutDimensionWidthValue(SBase* sBase, const double& width) {
    if (isValidDimensionValue(sBase, width) && width > 6 * getDefaultAutoLayoutPadding())
        return true;

    return false;
}

const bool isValidLayoutDimensionHeightValue(SBase* sBase, const double& height) {
    if (isValidDimensionValue(sBase, height) && height > 6 * getDefaultAutoLayoutPadding())
        return true;

    return false;
}

const bool isValidRoleValue(SBase* sBase, const std::string& role) {
    if (isValueValid(role, getValidRoleValues()))
        return true;

    addErrorToLog(sBase, createErrorMessage(role, getValidRoleValues()));
    return false;
}

const bool isValidBoundingBoxXValue(SBase* sBase, const double& x) {
    return isValidDoubleValue(sBase, x);
}

const bool isValidBoundingBoxYValue(SBase* sBase, const double& y) {
    return isValidDoubleValue(sBase, y);
}

const bool isValidBoundingBoxWidthValue(SBase* sBase, const double& width) {
    return isValidDimensionValue(sBase, width);
}

const bool isValidBoundingBoxHeightValue(SBase* sBase, const double& height) {
    return isValidDimensionValue(sBase, height);
}

const bool isValidCurveSegmentStartPointXValue(SBase* sBase, const double& x) {
    return isValidDoubleValue(sBase, x);
}

const bool isValidCurveSegmentStartPointYValue(SBase* sBase, const double& y) {
    return isValidDoubleValue(sBase, y);
}

const bool isValidCurveSegmentEndPointXValue(SBase* sBase, const double& x) {
    return isValidDoubleValue(sBase, x);
}

const bool isValidCurveSegmentEndPointYValue(SBase* sBase, const double& y) {
    return isValidDoubleValue(sBase, y);
}

const bool isValidCurveSegmentBasePoint1XValue(SBase* sBase, const double& x) {
    return isValidDoubleValue(sBase, x);
}

const bool isValidCurveSegmentBasePoint1YValue(SBase* sBase, const double& y) {
    return isValidDoubleValue(sBase, y);
}

const bool isValidCurveSegmentBasePoint2XValue(SBase* sBase, const double& x) {
    return isValidDoubleValue(sBase, x);
}

const bool isValidCurveSegmentBasePoint2YValue(SBase* sBase, const double& y) {
    return isValidDoubleValue(sBase, y);
}

const bool isValidDimensionValue(SBase* sBase, const double& dimensionValue) {
    if (isValidDoubleValue(sBase, dimensionValue) && dimensionValue > 0.000)
        return true;

    addErrorToLog(sBase, "A dimension value must be greater than 0");
    return false;
}

const bool isValidDoubleValue(SBase* sBase, const double& doubleValue) {
    if (!std::isnan(doubleValue) && !std::isinf(doubleValue))
        return true;

    addErrorToLog(sBase, "A double value must be a valid number");
    return false;
}

const bool isValidAlignment(SBase* sBase, const std::string& alignment) {
    if (isValueValid(alignment, getValidAlignmentValues()))
        return true;

    addErrorToLog(sBase, createErrorMessage(alignment, getValidAlignmentValues()));
    return false;
}

const bool isValidDistributionDirection(SBase* sBase, const std::string& direction) {
    if (isValueValid(direction, getValidDistributionDirectionValues()))
        return true;

    addErrorToLog(sBase, createErrorMessage(direction, getValidDistributionDirectionValues()));
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
