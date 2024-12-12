#include "libsbmlnetwork_user_data.h"
#include "../../libsbmlnetwork_sbmldocument_layout.h"
#include "../../libsbmlnetwork_layout.h"
#include "../../libsbmlnetwork_layout_helpers.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

int user_data_freeUserData(SBMLDocument* document) {
    if (document) {
        ListOfLayouts* listOfLayouts = getListOfLayouts(document);
        if (user_data_freeUserData(listOfLayouts))
            return -1;
        const int numLayouts = getNumLayouts(document);
        for (int i = 0; i < numLayouts; i++) {
            if (user_data_freeUserData(getLayout(document, i)))
                return -1;
        }
    }

    return 0;
}

int user_data_freeUserData(Layout* layout) {
    if (layout->isSetUserData()) {
        auto userData = (std::map<std::string, std::string>*)layout->getUserData();
        if (userData) {
            delete userData;
        }
    }
    user_data_freeUserData(layout->getDimensions());
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        CompartmentGlyph* compartmentGlyph = layout->getCompartmentGlyph(i);
        if (user_data_freeUserData(compartmentGlyph) || user_data_freeUserData(compartmentGlyph->getBoundingBox()))
            return -1;
    }
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        SpeciesGlyph* speciesGlyph = layout->getSpeciesGlyph(i);
        if (user_data_freeUserData(speciesGlyph) || user_data_freeUserData(speciesGlyph->getBoundingBox()))
            return -1;
    }
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        ReactionGlyph* reactionGlyph = layout->getReactionGlyph(i);
        if (user_data_freeUserData(reactionGlyph) || user_data_freeUserData(reactionGlyph->getBoundingBox()) || user_data_freeUserData(reactionGlyph->getCurve()))
            return -1;
        for (unsigned int j = 0; j < reactionGlyph->getNumSpeciesReferenceGlyphs(); j++) {
            if (user_data_freeUserData(reactionGlyph->getSpeciesReferenceGlyph(j)) || user_data_freeUserData(reactionGlyph->getSpeciesReferenceGlyph(j)->getCurve()))
                return -1;
        }
    }

    return 0;
}

std::vector<std::map<std::string, std::string>> user_data_getUserData(const Layout* layout) {
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

int user_data_setUserData(GraphicalObject* graphicalObject, const std::string& key, const std::string& value) {
    if (graphicalObject) {
        if (!graphicalObject->isSetUserData()) {
            graphicalObject->setUserData(new std::map<std::string, std::string>());
            user_data_setUserData(graphicalObject, "id", graphicalObject->getId());
            user_data_setUserData(graphicalObject, "entity_id", getEntityId(graphicalObject));
        }
        auto userData = (std::map<std::string, std::string>*)graphicalObject->getUserData();
        (*userData)[key] = value;

        return 0;
    }

    return -1;
}

int user_data_setPositionData(GraphicalObject* graphicalObject) {
    if (user_data_setUserData(graphicalObject, "x", std::to_string(getPositionX(graphicalObject))) || user_data_setUserData(graphicalObject, "y", std::to_string(getPositionY(graphicalObject))))
        return -1;

    return 0;
}

int user_data_unsetPositionData(GraphicalObject* graphicalObject) {
    if (user_data_setUserData(graphicalObject, "x", "") || user_data_setUserData(graphicalObject, "y", ""))
        return -1;

    return 0;
}

int user_data_setPositionData(SpeciesReferenceGlyph* speciesReferenceGlyph) {
    if (speciesReferenceGlyph) {
        Curve* curve = getCurve(speciesReferenceGlyph);
        for (unsigned int i = 0; i < getNumCurveSegments(curve); i++) {
            user_data_setUserData(speciesReferenceGlyph, std::to_string(i) + ":start_x", std::to_string(getCurveSegmentStartPointX(curve, i)));
            user_data_setUserData(speciesReferenceGlyph, std::to_string(i) + ":start_y", std::to_string(getCurveSegmentStartPointY(curve, i)));
            user_data_setUserData(speciesReferenceGlyph, std::to_string(i) + ":end_x", std::to_string(getCurveSegmentEndPointX(curve, i)));
            user_data_setUserData(speciesReferenceGlyph, std::to_string(i) + ":end_y", std::to_string(getCurveSegmentEndPointY(curve, i)));
            if (isCubicBezier(curve, i)) {
                user_data_setUserData(speciesReferenceGlyph, std::to_string(i) + ":b1_x", std::to_string(getCurveSegmentBasePoint1X(curve, i)));
                user_data_setUserData(speciesReferenceGlyph, std::to_string(i) + ":b1_y", std::to_string(getCurveSegmentBasePoint1Y(curve, i)));
                user_data_setUserData(speciesReferenceGlyph, std::to_string(i) + ":b2_x", std::to_string(getCurveSegmentBasePoint2X(curve, i)));
                user_data_setUserData(speciesReferenceGlyph, std::to_string(i) + ":b2_y", std::to_string(getCurveSegmentBasePoint2Y(curve, i)));
            }
        }

        return 0;
    }

    return -1;
}

int user_data_unsetPositionData(SpeciesReferenceGlyph* speciesReferenceGlyph) {
    if (speciesReferenceGlyph) {
        Curve* curve = getCurve(speciesReferenceGlyph);
        for (unsigned int i = 0; i < getNumCurveSegments(curve); i++) {
            user_data_setUserData(curve, std::to_string(i) + ":start_x", "");
            user_data_setUserData(curve, std::to_string(i) + ":start_y", "");
            user_data_setUserData(curve, std::to_string(i) + ":end_x", "");
            user_data_setUserData(curve, std::to_string(i) + ":end_y", "");
            user_data_setUserData(curve, std::to_string(i) + ":b1_x", "");
            user_data_setUserData(curve, std::to_string(i) + ":b1_y", "");
            user_data_setUserData(curve, std::to_string(i) + ":b2_x", "");
            user_data_setUserData(curve, std::to_string(i) + ":b2_y", "");
        }

        return 0;
    }

    return -1;
}

int user_data_setGraphicalObjectUserData(GraphicalObject* graphicalObject, const std::vector<std::map<std::string, std::string>>& userData) {
    for (unsigned int i = 0; i < userData.size(); i++) {
        if (userData.at(i).find("id") != userData.at(i).end() && userData.at(i).at("id") == graphicalObject->getId()) {
            for (auto it = userData.at(i).begin(); it != userData.at(i).end(); it++) {
                if (user_data_setUserData(graphicalObject, it->first, it->second))
                    return -1;
            }

            return 0;
        }
    }

    return -1;
}

int user_data_freeUserData(RenderInformationBase* renderInformation) {
    for (unsigned int i = 0; i < renderInformation->getNumColorDefinitions(); i++) {
        if (user_data_freeUserData(renderInformation->getColorDefinition(i)))
            return -1;
    }
    for (unsigned int i = 0; i < renderInformation->getNumGradientDefinitions(); i++) {
        GradientBase* gradientBase = renderInformation->getGradientDefinition(i);
        if (user_data_freeUserData(gradientBase))
            return -1;
        for (unsigned int j = 0; j < gradientBase->getNumGradientStops(); j++) {
            if (user_data_freeUserData(gradientBase->getGradientStop(j)))
                return -1;
        }
    }
    for (unsigned int i = 0; i < renderInformation->getNumLineEndings(); i++) {
        if (user_data_freeUserData(renderInformation->getLineEnding(i)))
            return -1;
    }
    if (renderInformation->isGlobalRenderInformation()) {
        for (unsigned int i = 0; i < ((GlobalRenderInformation*)renderInformation)->getNumGlobalStyles(); i++) {
            if (user_data_freeUserData(((GlobalRenderInformation*)renderInformation)->getGlobalStyle(i)))
                return -1;
        }
    }
    else if (renderInformation->isLocalRenderInformation()) {
        for (unsigned int i = 0; i < ((LocalRenderInformation*)renderInformation)->getNumLocalStyles(); i++) {
            if (user_data_freeUserData(((LocalRenderInformation*)renderInformation)->getLocalStyle(i)))
                return -1;
        }
    }

    return 0;
}

std::vector<std::map<std::string, std::string>> user_data_getUserData(const RenderInformationBase* renderInformation) {
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

const std::string user_data_getUserData(SBase* sBase, const std::string& key) {
    if (sBase && sBase->isSetUserData()) {
        auto userData = (std::map<std::string, std::string>*)sBase->getUserData();
        if (userData->find(key) != userData->end())
            return (*userData)[key];
    }

    return "";
}

int user_data_setUserData(SBase* sBase, const std::string& key, const std::string& value) {
    if (sBase) {
        if (!sBase->isSetUserData())
            sBase->setUserData(new std::map<std::string, std::string>());
        auto userData = (std::map<std::string, std::string>*)sBase->getUserData();
        (*userData)[key] = value;

        return 0;
    }

    return -1;
}

int user_data_freeUserData(SBase* sBase) {
    if (sBase) {
        if (sBase->isSetUserData()) {
            auto userData = (std::map<std::string, std::string>*)sBase->getUserData();
            delete userData;
            sBase->unsetUserData();
        }

        return 0;
    }

    return -1;
}
    
}
