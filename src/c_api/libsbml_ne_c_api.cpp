#include "libsbml_ne_c_api.h"

extern "C" {

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE {

    SBMLDocument* c_api_readSBML(const char* sbml) {
        return readSBML(sbml);
    }

    bool c_api_writeSBMLToFile(SBMLDocument* document, const char* fileName) {
        return writeSBMLToFile(document, fileName);
    }

    const char* c_api_writeSBMLToString(SBMLDocument* document) {
        return writeSBMLToString(document);
    }

    int c_api_autolayout(SBMLDocument *document, const double stiffness, const double gravity, const bool useMagnetism,
                   const bool useBoundary, const bool useGrid, const char **lockedNodeIds) {
        std::vector <std::string> lockedNodeIdsVector = std::vector<std::string>();
        if (lockedNodeIds) {
            for (int i; lockedNodeIds[i] != nullptr; i++)
                lockedNodeIdsVector.emplace_back(lockedNodeIds[i]);
        }

        return autolayout(document, stiffness, gravity, useMagnetism, useBoundary, useGrid, lockedNodeIdsVector);
    }

    const int c_api_getNumLayouts(SBMLDocument* document) {
        return getNumLayouts(document);
    }

    int c_api_removeLayouts(SBMLDocument* document) {
        return removeAllLayouts(document);
    }

    double c_api_getCanvasWidth(SBMLDocument* document, int layoutIndex) {
        return getDimensionWidth(document, layoutIndex);
    }

    int c_api_setCanvasWidth(SBMLDocument* document, const double width, int layoutIndex) {
        return setDimensionWidth(document, layoutIndex, width);
    }

    double c_api_getCanvasHeight(SBMLDocument* document, int layoutIndex) {
        return getDimensionHeight(document, layoutIndex);
    }

    int c_api_setCanvasHeight(SBMLDocument* document, const double height, int layoutIndex) {
        return setDimensionHeight(document, layoutIndex, height);
    }

    const int c_api_getNumAllGraphicalObjects(SBMLDocument* document, int layoutIndex) {
        return getNumGraphicalObjects(document, layoutIndex);
    }

    const int c_api_getNumGraphicalObjects(SBMLDocument* document, const char* id, int layoutIndex) {
        return getNumGraphicalObjects(document, layoutIndex, id);
    }

    const int c_api_getNumAllCompartmentGlyphs(SBMLDocument* document, int layoutIndex) {
        return getNumCompartmentGlyphs(document, layoutIndex);
    }

    const int c_api_getNumCompartmentGlyphs(SBMLDocument* document, const char* compartmentId, int layoutIndex) {
        return getNumCompartmentGlyphs(document, layoutIndex, compartmentId);
    }

    bool c_api_isCompartmentGlyph(SBMLDocument* document, const char* compartmentId, int layoutIndex) {
        return isCompartmentGlyph(document, layoutIndex, compartmentId);
    }

    const int c_api_getNumAllSpeciesGlyphs(SBMLDocument* document, int layoutIndex) {
        return getNumSpeciesGlyphs(document, layoutIndex);
    }

    const int c_api_getNumSpeciesGlyphs(SBMLDocument* document, const char* speciesId, int layoutIndex) {
        return getNumSpeciesGlyphs(document, layoutIndex, speciesId);
    }

    bool c_api_isSpeciesGlyph(SBMLDocument* document, const char* speciesId, int layoutIndex) {
        return isSpeciesGlyph(document, layoutIndex, speciesId);
    }

    const int c_api_getNumAllReactionGlyphs(SBMLDocument* document, int layoutIndex) {
        return getNumReactionGlyphs(document, layoutIndex);
    }

    const int c_api_getNumReactionGlyphs(SBMLDocument* document, const char* reactionId, int layoutIndex) {
        return getNumReactionGlyphs(document, layoutIndex, reactionId);
    }

    bool c_api_isReactionGlyph(SBMLDocument* document, const char* reactionId, int layoutIndex) {
        return isReactionGlyph(document, layoutIndex, reactionId);
    }

    const int c_api_getNumSpeciesReferenceGlyphs(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int layoutIndex) {
        return getNumSpeciesReferenceGlyphs(document, layoutIndex, reactionId, reactionGlyphIndex);
    }

    bool c_api_isSetRole(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return isSetRole(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex);
    }

    const char* c_api_getRole(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return strdup(getRole(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex).c_str());
    }

    int c_api_setRole(SBMLDocument* document, const char* reactionId, const char* role, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return setRole(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, role);
    }

    const int c_api_getNumAllTextGlyphs(SBMLDocument* document, int layoutIndex) {
        return getNumTextGlyphs(document, layoutIndex);
    }

    const int c_api_getNumTextGlyphs(SBMLDocument* document, const char* id, int layoutIndex) {
        return getNumTextGlyphs(document, layoutIndex, id);
    }

    const char* c_api_getText(SBMLDocument* document, const char* id, int textGlyphIndex, int layoutIndex) {
        std::string text = getText(document, layoutIndex, id, textGlyphIndex);
        if (!text.empty()) {
           return strdup(text.c_str());
        }
        text = getOriginOfTextId(document, layoutIndex, id, textGlyphIndex);
        if (!text.empty()) {
            return strdup(text.c_str());
        }
        text = getGraphicalObjectId(document, layoutIndex, id, textGlyphIndex);
        if (!text.empty()) {
            return strdup(text.c_str());
        }

        return "";
    }

    int c_api_setText(SBMLDocument* document, const char* id, const char* text, int textGlyphIndex, int layoutIndex) {
        return setText(document, layoutIndex, id, textGlyphIndex, text);
    }

    const double  c_api_getX(SBMLDocument* document, const char* id, const int graphicalObjectIndex, int layoutIndex) {
        return getPositionX(document, layoutIndex, id, graphicalObjectIndex);
    }

    int c_api_setX(SBMLDocument* document, const char* id, const double x, const int graphicalObjectIndex, int layoutIndex) {
        return setPositionX(document, layoutIndex, id, graphicalObjectIndex, x);
    }

    const double c_api_getY(SBMLDocument* document, const char* id, const int graphicalObjectIndex, int layoutIndex) {
        return getPositionY(document, layoutIndex, id, graphicalObjectIndex);
    }

    int c_api_setY(SBMLDocument* document, const char* id, const double y, const int graphicalObjectIndex, int layoutIndex) {
        return setPositionY(document, layoutIndex, id, graphicalObjectIndex, y);
    }

    const double c_api_getWidth(SBMLDocument* document, const char* id, const int graphicalObjectIndex, int layoutIndex) {
        return getDimensionWidth(document, layoutIndex, id, graphicalObjectIndex);
    }

    int c_api_setWidth(SBMLDocument* document, const char* id, const double width, const int graphicalObjectIndex, int layoutIndex) {
        return setDimensionWidth(document, layoutIndex, id, graphicalObjectIndex, width);
    }

    const double c_api_getHeight(SBMLDocument* document, const char* id, const int graphicalObjectIndex, int layoutIndex) {
        return getDimensionHeight(document, layoutIndex, id, graphicalObjectIndex);
    }

    int c_api_setHeight(SBMLDocument* document, const char* id, const double height, const int graphicalObjectIndex, int layoutIndex) {
        return setDimensionHeight(document, layoutIndex, id, graphicalObjectIndex, height);
    }

    bool c_api_isSetCurve(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        return isSetCurve(document, layoutIndex, id, graphicalObjectIndex);
    }

    const int c_api_getNumCurveSegments(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        return getNumCurveSegments(document, layoutIndex, id, graphicalObjectIndex);
    }

    const double c_api_getCurveStartPointX(SBMLDocument* document, const char* id, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return getCurveSegmentStartPointX(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex);
    }
    
    int c_api_setCurveStartPointX(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return setCurveSegmentStartPointX(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex, x);
    }
    
    const double c_api_getCurveStartPointY(SBMLDocument* document, const char* id, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return getCurveSegmentStartPointY(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex);
    }
    
    int c_api_setCurveStartPointY(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return setCurveSegmentStartPointY(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex, y);
    }
    
    const double c_api_getCurveEndPointX(SBMLDocument* document, const char* id, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return getCurveSegmentEndPointX(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex);
    }
    
    int c_api_setCurveEndPointX(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return setCurveSegmentEndPointX(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex, x);
    }
    
    const double c_api_getCurveEndPointY(SBMLDocument* document, const char* id, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return getCurveSegmentEndPointY(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex);
    }
    
    int c_api_setCurveEndPointY(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return setCurveSegmentEndPointY(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex, y);
    }
    
    const double c_api_getCurveBasePoint1X(SBMLDocument* document, const char* id, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return getCurveSegmentBasePoint1X(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex);
    }
    
    int c_api_setCurveBasePoint1X(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return setCurveSegmentBasePoint1X(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex, x);
    }
    
    const double c_api_getCurveBasePoint1Y(SBMLDocument* document, const char* id, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return getCurveSegmentBasePoint1Y(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex);
    }
    
    int c_api_setCurveBasePoint1Y(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return setCurveSegmentBasePoint1Y(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex, y);
    }
    
    const double c_api_getCurveBasePoint2X(SBMLDocument* document, const char* id, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return getCurveSegmentBasePoint2X(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex);
    }
    
    int c_api_setCurveBasePoint2X(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return setCurveSegmentBasePoint2X(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex, x);
    }
    
    const double c_api_getCurveBasePoint2Y(SBMLDocument* document, const char* id, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return getCurveSegmentBasePoint2Y(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex);
    }
    
    int c_api_setCurveBasePoint2Y(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return setCurveSegmentBasePoint2Y(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex, y);
    }
}

}