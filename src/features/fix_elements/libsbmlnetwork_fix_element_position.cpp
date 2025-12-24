#include "libsbmlnetwork_fix_element_position.h"
#include "../../libsbmlnetwork_layout.h"
#include "../../libsbmlnetwork_layout_helpers.h"
#include "../../features/fix_elements/libsbmlnetwork_fix_element_dimensions.h"
#include "../../features/user_data/libsbmlnetwork_user_data.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

void fix_elements_fixGraphicalObjectsPosition(Layout* layout, std::set<std::pair<std::string, int> > fixedPositionNodesSet, const bool resetFixedPositionElements) {
    fix_elements_fixCompartmentGlyphsPosition(layout, resetFixedPositionElements);
    fix_elements_fixSpeciesGlyphsPosition(layout, fixedPositionNodesSet, resetFixedPositionElements);
    fix_elements_fixReactionGlyphsPosition(layout, fixedPositionNodesSet, resetFixedPositionElements);
}

void fix_elements_fixCompartmentGlyphsPosition(Layout* layout, const bool resetFixedPositionElements) {
    if (resetFixedPositionElements) {
        for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
            CompartmentGlyph* compartmentGlyph = layout->getCompartmentGlyph(i);
            if (user_data_getUserData(compartmentGlyph, "fixed_position") == "true")
                fix_elements_unfixGraphicalObjectPosition(compartmentGlyph);
            if (user_data_getUserData(compartmentGlyph, "fixed_width") == "true")
                fix_elements_unfixGraphicalObjectWidth(compartmentGlyph);
            if (user_data_getUserData(compartmentGlyph, "fixed_height") == "true")
                fix_elements_unfixGraphicalObjectHeight(compartmentGlyph);
        }
    }
}

void fix_elements_fixSpeciesGlyphsPosition(Layout* layout, std::set<std::pair<std::string, int> > fixedPositionNodesSet, const bool resetFixedPositionElements) {
    if (resetFixedPositionElements) {
        for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
            SpeciesGlyph* speciesGlyph = layout->getSpeciesGlyph(i);
            if (user_data_getUserData(speciesGlyph, "fixed_position") == "true")
                fix_elements_unfixGraphicalObjectPosition(speciesGlyph);
            if (user_data_getUserData(speciesGlyph, "fixed_width") == "true")
                fix_elements_unfixGraphicalObjectWidth(speciesGlyph);
            if (user_data_getUserData(speciesGlyph, "fixed_height") == "true")
                fix_elements_unfixGraphicalObjectHeight(speciesGlyph);
        }
    }

    for (std::set<std::pair<std::string, int> >::const_iterator fixedPositionNodeIt = fixedPositionNodesSet.cbegin(); fixedPositionNodeIt != fixedPositionNodesSet.cend(); fixedPositionNodeIt++) {
        std::vector<SpeciesGlyph*> speciesGlyphs = getAssociatedSpeciesGlyphsWithSpeciesId(layout, fixedPositionNodeIt->first);
        if (fixedPositionNodeIt->second < speciesGlyphs.size()) {
            fix_elements_fixGraphicalObjectPosition(speciesGlyphs.at(fixedPositionNodeIt->second));
        }
    }
}

void fix_elements_fixReactionGlyphsPosition(Layout* layout, std::set<std::pair<std::string, int> > fixedPositionNodesSet, const bool resetFixedPositionElements) {
    if (resetFixedPositionElements) {
        for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
            ReactionGlyph* reactionGlyph = layout->getReactionGlyph(i);
            if (user_data_getUserData(reactionGlyph, "fixed_position") == "true")
                fix_elements_unfixGraphicalObjectPosition(reactionGlyph);
            if (user_data_getUserData(reactionGlyph, "fixed_width") == "true")
                fix_elements_unfixGraphicalObjectWidth(reactionGlyph);
            if (user_data_getUserData(reactionGlyph, "fixed_height") == "true")
                fix_elements_unfixGraphicalObjectHeight(reactionGlyph);
            for (unsigned int j = 0; j < reactionGlyph->getNumSpeciesReferenceGlyphs(); j++) {
                SpeciesReferenceGlyph *speciesReferenceGlyph = reactionGlyph->getSpeciesReferenceGlyph(j);
                if (user_data_getUserData(speciesReferenceGlyph, "fixed_position") == "true")
                    fix_elements_unfixGraphicalObjectPosition(speciesReferenceGlyph);
            }
        }
    }

    for (std::set<std::pair<std::string, int> >::const_iterator fixedPositionNodeIt = fixedPositionNodesSet.cbegin(); fixedPositionNodeIt != fixedPositionNodesSet.cend(); fixedPositionNodeIt++) {
        std::vector<ReactionGlyph*> reactionGlyphs = getAssociatedReactionGlyphsWithReactionId(layout, fixedPositionNodeIt->first);
        if (fixedPositionNodeIt->second < reactionGlyphs.size()) {
            fix_elements_fixGraphicalObjectPosition(reactionGlyphs.at(fixedPositionNodeIt->second));
        }
    }
}

void fix_elements_fixGraphicalObjectPosition(GraphicalObject* graphicalObject) {
    user_data_setUserData(graphicalObject, "fixed_position", "true");
    if (isSpeciesReferenceGlyph(graphicalObject))
        user_data_setPositionData((SpeciesReferenceGlyph*)graphicalObject);
    else
        user_data_setPositionData(graphicalObject);
}

void fix_elements_unfixGraphicalObjectPosition(GraphicalObject* graphicalObject) {
    user_data_setUserData(graphicalObject, "fixed_position", "false");
    if (isSpeciesReferenceGlyph(graphicalObject))
        user_data_unsetPositionData((SpeciesReferenceGlyph*)graphicalObject);
    else
        user_data_unsetPositionData(graphicalObject);
}

void fix_elements_unfixCurveSegmentPosition(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex) {
    if (isSpeciesReferenceGlyph(graphicalObject)) {
        user_data_unsetPositionData((SpeciesReferenceGlyph*)graphicalObject, curveSegmentIndex);
    }
}

void fix_elements_updateFixedCurveSegmentsIndicesAfterRemoval(GraphicalObject* graphicalObject, unsigned int removedCurveSegmentIndex) {
    if (isSpeciesReferenceGlyph(graphicalObject)) {
        user_data_updateFixedCurveSegmentsIndicesAfterRemoval((SpeciesReferenceGlyph*)graphicalObject, removedCurveSegmentIndex);
    }
}

std::vector<GraphicalObject*> fix_elements_getFixedPositionGraphicalObjects(std::vector<GraphicalObject*> graphicalObjects) {
    std::vector<GraphicalObject*> fixedPositionGraphicalObjects;
    for (unsigned int i = 0; i < graphicalObjects.size(); i++)
        if (user_data_getUserData(graphicalObjects.at(i), "fixed_position") == "true")
            fixedPositionGraphicalObjects.push_back(graphicalObjects.at(i));

    return fixedPositionGraphicalObjects;
}

}
