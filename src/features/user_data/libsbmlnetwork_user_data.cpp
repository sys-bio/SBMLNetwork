#include "libsbmlnetwork_user_data.h"
#include "../../libsbmlnetwork_sbmldocument_layout.h"
#include "../../libsbmlnetwork_layout.h"
#include "../../libsbmlnetwork_layout_helpers.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

void ud_freeUserData(SBMLDocument* document) {
    if (document) {
        ListOfLayouts* listOfLayouts = getListOfLayouts(document);
        ud_freeUserData(listOfLayouts);
        const int numLayouts = getNumLayouts(document);
        for (int i = 0; i < numLayouts; i++)
            ud_freeUserData(getLayout(document, i));
    }
}

void ud_freeUserData(Layout* layout) {
    if (layout->isSetUserData()) {
        auto userData = (std::map<std::string, std::string>*)layout->getUserData();
        if (userData) {
            delete userData;
        }
    }
    ud_freeUserData(layout->getDimensions());
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        CompartmentGlyph* compartmentGlyph = layout->getCompartmentGlyph(i);
        ud_freeUserData(compartmentGlyph);
        ud_freeUserData(compartmentGlyph->getBoundingBox());
    }
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        SpeciesGlyph* speciesGlyph = layout->getSpeciesGlyph(i);
        ud_freeUserData(speciesGlyph);
        ud_freeUserData(speciesGlyph->getBoundingBox());
    }
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        ReactionGlyph* reactionGlyph = layout->getReactionGlyph(i);
        ud_freeUserData(reactionGlyph);
        ud_freeUserData(reactionGlyph->getBoundingBox());
        ud_freeUserData(reactionGlyph->getCurve());
        for (unsigned int j = 0; j < reactionGlyph->getNumSpeciesReferenceGlyphs(); j++) {
            SpeciesReferenceGlyph* speciesReferenceGlyph = reactionGlyph->getSpeciesReferenceGlyph(j);
            ud_freeUserData(speciesReferenceGlyph);
            ud_freeUserData(speciesReferenceGlyph->getCurve());
        }
    }
}

std::vector<std::map<std::string, std::string>> ud_getUserData(Layout* layout) {
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

void ud_setUserData(GraphicalObject* graphicalObject, const std::string& key, const std::string& value) {
    if (!graphicalObject->isSetUserData()) {
        graphicalObject->setUserData(new std::map<std::string, std::string>());
        ud_setUserData(graphicalObject, "id", graphicalObject->getId());
        ud_setUserData(graphicalObject, "entity_id", getEntityId(graphicalObject));
    }
    auto userData = (std::map<std::string, std::string>*)graphicalObject->getUserData();
    (*userData)[key] = value;
}

void ud_setPositionData(GraphicalObject* graphicalObject) {
    ud_setUserData(graphicalObject, "x", std::to_string(getPositionX(graphicalObject)));
    ud_setUserData(graphicalObject, "y", std::to_string(getPositionY(graphicalObject)));
}

void ud_unsetPositionData(GraphicalObject* graphicalObject) {
    ud_setUserData(graphicalObject, "x", "");
    ud_setUserData(graphicalObject, "y", "");
}

void ud_setPositionData(SpeciesReferenceGlyph* speciesReferenceGlyph) {
    if (speciesReferenceGlyph) {
        Curve* curve = getCurve(speciesReferenceGlyph);
        for (unsigned int i = 0; i < getNumCurveSegments(curve); i++) {
            ud_setUserData(speciesReferenceGlyph, std::to_string(i) + ":start_x", std::to_string(getCurveSegmentStartPointX(curve, i)));
            ud_setUserData(speciesReferenceGlyph, std::to_string(i) + ":start_y", std::to_string(getCurveSegmentStartPointY(curve, i)));
            ud_setUserData(speciesReferenceGlyph, std::to_string(i) + ":end_x", std::to_string(getCurveSegmentEndPointX(curve, i)));
            ud_setUserData(speciesReferenceGlyph, std::to_string(i) + ":end_y", std::to_string(getCurveSegmentEndPointY(curve, i)));
            if (isCubicBezier(curve, i)) {
                ud_setUserData(speciesReferenceGlyph, std::to_string(i) + ":b1_x", std::to_string(getCurveSegmentBasePoint1X(curve, i)));
                ud_setUserData(speciesReferenceGlyph, std::to_string(i) + ":b1_y", std::to_string(getCurveSegmentBasePoint1Y(curve, i)));
                ud_setUserData(speciesReferenceGlyph, std::to_string(i) + ":b2_x", std::to_string(getCurveSegmentBasePoint2X(curve, i)));
                ud_setUserData(speciesReferenceGlyph, std::to_string(i) + ":b2_y", std::to_string(getCurveSegmentBasePoint2Y(curve, i)));
            }
        }
    }
}

void ud_unsetPositionData(SpeciesReferenceGlyph* speciesReferenceGlyph) {
    if (speciesReferenceGlyph) {
        Curve* curve = getCurve(speciesReferenceGlyph);
        for (unsigned int i = 0; i < getNumCurveSegments(curve); i++) {
            ud_setUserData(curve, std::to_string(i) + ":start_x", "");
            ud_setUserData(curve, std::to_string(i) + ":start_y", "");
            ud_setUserData(curve, std::to_string(i) + ":end_x", "");
            ud_setUserData(curve, std::to_string(i) + ":end_y", "");
            ud_setUserData(curve, std::to_string(i) + ":b1_x", "");
            ud_setUserData(curve, std::to_string(i) + ":b1_y", "");
            ud_setUserData(curve, std::to_string(i) + ":b2_x", "");
            ud_setUserData(curve, std::to_string(i) + ":b2_y", "");
        }
    }
}

void ud_setGraphicalObjectUserData(GraphicalObject* graphicalObject, const std::vector<std::map<std::string, std::string>>& userData) {
    for (unsigned int i = 0; i < userData.size(); i++) {
        if (userData.at(i).find("id") != userData.at(i).end() && userData.at(i).at("id") == graphicalObject->getId()) {
            for (auto it = userData.at(i).begin(); it != userData.at(i).end(); it++)
                ud_setUserData(graphicalObject, it->first, it->second);
            break;
        }
    }
}

void ud_freeUserData(RenderInformationBase* renderInformation) {
    for (unsigned int i = 0; i < renderInformation->getNumColorDefinitions(); i++)
        ud_freeUserData(renderInformation->getColorDefinition(i));
    for (unsigned int i = 0; i < renderInformation->getNumGradientDefinitions(); i++) {
        GradientBase* gradientBase = renderInformation->getGradientDefinition(i);
        ud_freeUserData(gradientBase);
        for (unsigned int j = 0; j < gradientBase->getNumGradientStops(); j++)
            ud_freeUserData(gradientBase->getGradientStop(j));
    }
    for (unsigned int i = 0; i < renderInformation->getNumLineEndings(); i++)
        ud_freeUserData(renderInformation->getLineEnding(i));
    if (renderInformation->isGlobalRenderInformation()) {
        for (unsigned int i = 0; i < ((GlobalRenderInformation*)renderInformation)->getNumGlobalStyles(); i++)
            ud_freeUserData(((GlobalRenderInformation*)renderInformation)->getGlobalStyle(i));
    }
    else if (renderInformation->isLocalRenderInformation()) {
        for (unsigned int i = 0; i < ((LocalRenderInformation*)renderInformation)->getNumLocalStyles(); i++)
            ud_freeUserData(((LocalRenderInformation*)renderInformation)->getLocalStyle(i));
    }
}

std::vector<std::map<std::string, std::string>> ud_getUserData(RenderInformationBase* renderInformation) {
    std::vector<std::map<std::string, std::string>> userData;
    for (unsigned int i = 0; i < renderInformation->getNumColorDefinitions(); i++) {
        auto colorDefinitionUserData = renderInformation->getColorDefinition(i)->getUserData();
        if (colorDefinitionUserData)
            userData.push_back(*(std::map<std::string, std::string>*)colorDefinitionUserData);
    }
    for (unsigned int i = 0; i < renderInformation->getNumGradientDefinitions(); i++) {
        auto gradientDefinitionUserData = renderInformation->getGradientDefinition(i)->getUserData();
        if (gradientDefinitionUserData)
            userData.push_back(*(std::map<std::string, std::string>*)gradientDefinitionUserData);
    }
    for (unsigned int i = 0; i < renderInformation->getNumLineEndings(); i++) {
        auto lineEndingUserData = renderInformation->getLineEnding(i)->getUserData();
        if (lineEndingUserData)
            userData.push_back(*(std::map<std::string, std::string>*)lineEndingUserData);
    }
    if (renderInformation->isGlobalRenderInformation()) {
        for (unsigned int i = 0; i < ((GlobalRenderInformation*)renderInformation)->getNumGlobalStyles(); i++) {
            auto globalStyleUserData = ((GlobalRenderInformation*)renderInformation)->getGlobalStyle(i)->getUserData();
            if (globalStyleUserData)
                userData.push_back(*(std::map<std::string, std::string>*)globalStyleUserData);
        }
    }
    else if (renderInformation->isLocalRenderInformation()) {
        for (unsigned int i = 0; i < ((LocalRenderInformation*)renderInformation)->getNumLocalStyles(); i++) {
            auto localStyleUserData = ((LocalRenderInformation*)renderInformation)->getLocalStyle(i)->getUserData();
            if (localStyleUserData)
                userData.push_back(*(std::map<std::string, std::string>*)localStyleUserData);
        }
    }

    return userData;
}

const std::string ud_getUserData(SBase* sBase, const std::string& key) {
    if (sBase->isSetUserData()) {
        auto userData = (std::map<std::string, std::string>*)sBase->getUserData();
        if (userData->find(key) != userData->end())
            return (*userData)[key];
    }

    return "";
}

void ud_setUserData(SBase* sBase, const std::string& key, const std::string& value) {
    if (!sBase->isSetUserData())
        sBase->setUserData(new std::map<std::string, std::string>());
    auto userData = (std::map<std::string, std::string>*)sBase->getUserData();
    (*userData)[key] = value;
}

void ud_freeUserData(SBase* sBase) {
    if (sBase) {
        if (sBase->isSetUserData()) {
            auto userData = (std::map<std::string, std::string>*)sBase->getUserData();
            delete userData;
            sBase->unsetUserData();
        }
    }
}
    
}
