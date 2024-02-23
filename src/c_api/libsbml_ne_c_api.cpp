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

    const int c_api_getNumGlobalRenderInformation(SBMLDocument* document) {
        return getNumGlobalRenderInformation(document);
    }

    const int c_api_getNumLocalRenderInformation(SBMLDocument* document, int layoutIndex) {
        return getNumLocalRenderInformation(document, layoutIndex);
    }

    int c_api_removeRenderInformation(SBMLDocument* document) {
        if (removeAllGlobalRenderInformation(document), removeAllLocalRenderInformation(document))
        return 0;

        return 0;
    }

    int c_api_removeGlobalRenderInformation(SBMLDocument* document) {
        return removeAllGlobalRenderInformation(document);
    }

    int c_api_removeLocalRenderInformation(SBMLDocument* document, int layoutIndex) {
        return removeAllLocalRenderInformation(document, layoutIndex);
    }

    bool c_api_isSetBackgroundColor(SBMLDocument* document, int renderIndex) {
        return isSetBackgroundColor(document, renderIndex);
    }

    const char* c_api_getBackgroundColor(SBMLDocument* document, int renderIndex) {
        return strdup(getBackgroundColor(document, renderIndex).c_str());
    }

    int c_api_setBackgroundColor(SBMLDocument* document, const char* backgroundColor, int renderIndex) {
        return setBackgroundColor(document, renderIndex, backgroundColor);
    }

    const int c_api_getNumColors(SBMLDocument* document, int renderIndex) {
        return getNumColorDefinitions(document, renderIndex);
    }

    bool c_api_isSetColorValue(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetValue(document, renderIndex, id);
    }

    const char* c_api_getColorValue(SBMLDocument* document, const char* id, int renderIndex) {
        return strdup(getValue(document, renderIndex, id).c_str());
    }

    int c_api_setColorValue(SBMLDocument* document, const char* id, const char* value, int renderIndex) {
        return setValue(document, renderIndex, id, value);
    }

    bool c_api_isSetBorderColor(SBMLDocument* document, const char* id) {
        return isSetStrokeColor(document, id);
    }

    const char* c_api_getBorderColor(SBMLDocument* document, const char* id) {
        return strdup(getStrokeColor(document, id).c_str());
    }

    int c_api_setBorderColor(SBMLDocument* document, const char* id, const char* borderColor) {
        return setStrokeColor(document, id, borderColor);
    }

    bool c_api_isSetBorderWidth(SBMLDocument* document, const char* id) {
        return isSetStrokeWidth(document, id);
    }

    const double c_api_getBorderWidth(SBMLDocument* document, const char* id) {
        return getStrokeWidth(document, id);
    }

    int c_api_setBorderWidth(SBMLDocument* document, const char* id, const double borderWidth) {
        return setStrokeWidth(document, id, borderWidth);
    }

    bool c_api_isSetFillColor(SBMLDocument* document, const char* id) {
        return isSetFillColor(document, id);
    }

    const char* c_api_getFillColor(SBMLDocument* document, const char* id) {
        return strdup(getFillColor(document, id).c_str());
    }

    int c_api_setFillColor(SBMLDocument* document, const char* id, const char* fillColor) {
        return setFillColor(document, id, fillColor);
    }

    bool c_api_isSetFillRule(SBMLDocument* document, const char* id) {
        return isSetFillRule(document, id);
    }

    const char* c_api_getFillRule(SBMLDocument* document, const char* id) {
        return strdup(getFillRule(document, id).c_str());
    }

    int c_api_setFillRule(SBMLDocument* document, const char* id, const char* fillRule) {
        return setFillRule(document, id, fillRule);
    }

    bool c_api_isSetFontColor(SBMLDocument* document, const char* id) {
        return isSetFontColor(document, id);
    }

    const char* c_api_getFontColor(SBMLDocument* document, const char* id) {
        return strdup(getFontColor(document, id).c_str());
    }

    int c_api_setFontColor(SBMLDocument* document, const char* id, const char* fontColor) {
        return setFontColor(document, id, fontColor);
    }

    bool c_api_isSetFontFamily(SBMLDocument* document, const char* id) {
        return isSetFontFamily(document, id);
    }

    const char* c_api_getFontFamily(SBMLDocument* document, const char* id) {
        return strdup(getFontFamily(document, id).c_str());
    }

    int c_api_setFontFamily(SBMLDocument* document, const char* id, const char* fontFamily) {
        return setFontFamily(document, id, fontFamily);
    }

    bool c_api_isSetFontSize(SBMLDocument* document, const char* id) {
        return isSetFontSize(document, id);
    }

    const double c_api_getFontSize(SBMLDocument* document, const char* id) {
        RelAbsVector fontSizeVector = getFontSize(document, id);
        return fontSizeVector.getAbsoluteValue() + 0.5 * (c_api_getWidth(document, id) + c_api_getHeight(document, id)) * fontSizeVector.getRelativeValue();
    }

    int c_api_setFontSize(SBMLDocument* document, const char* id, const double fontSize) {
        RelAbsVector fontSizeVector;
        fontSizeVector.setAbsoluteValue(fontSize);
        return setFontSize(document, id, fontSizeVector);
    }

    bool c_api_isSetFontWeight(SBMLDocument* document, const char* id) {
        return isSetFontWeight(document, id);
    }

    const char* c_api_getFontWeight(SBMLDocument* document, const char* id) {
        return strdup(getFontWeight(document, id).c_str());
    }

    int c_api_setFontWeight(SBMLDocument* document, const char* id, const char* fontWeight) {
        return setFontWeight(document, id, fontWeight);
    }

    bool c_api_isSetFontStyle(SBMLDocument* document, const char* id) {
        return isSetFontStyle(document, id);
    }

    const char* c_api_getFontStyle(SBMLDocument* document, const char* id) {
        return strdup(getFontStyle(document, id).c_str());
    }

    int c_api_setFontStyle(SBMLDocument* document, const char* id, const char* fontStyle) {
        return setFontStyle(document, id, fontStyle);
    }

    bool c_api_isSetTextHorizontalAlignment(SBMLDocument* document, const char* id) {
        return isSetTextAnchor(document, id);
    }

    const char* c_api_getTextHorizontalAlignment(SBMLDocument* document, const char* id) {
        return strdup(getTextAnchor(document, id).c_str());
    }

    int c_api_setTextHorizontalAlignment(SBMLDocument* document, const char* id, const char* textHorizontalAlignment) {
        return setTextAnchor(document, id, textHorizontalAlignment);
    }

    bool c_api_isSetTextVerticalAlignment(SBMLDocument* document, const char* id) {
        return isSetVTextAnchor(document, id);
    }

    const char* c_api_getTextVerticalAlignment(SBMLDocument* document, const char* id) {
        return strdup(getVTextAnchor(document, id).c_str());
    }

    int c_api_setTextVerticalAlignment(SBMLDocument* document, const char* id, const char* textVerticalAlignment) {
        return setVTextAnchor(document, id, textVerticalAlignment);
    }

    bool c_api_isSetStartHead(SBMLDocument* document, const char* id) {
        return isSetStartHead(document, id);
    }

    const char* c_api_getStartHead(SBMLDocument* document, const char* id) {
        return strdup(getStartHead(document, id).c_str());
    }

    int c_api_setStartHead(SBMLDocument* document, const char* id, const char* startHead) {
        return setStartHead(document, id, startHead);
    }

    bool c_api_isSetEndHead(SBMLDocument* document, const char* id) {
        return isSetEndHead(document, id);
    }

    const char* c_api_getEndHead(SBMLDocument* document, const char* id) {
        return strdup(getEndHead(document, id).c_str());
    }

    int c_api_setEndHead(SBMLDocument* document, const char* id, const char* endHead) {
        return setEndHead(document, id, endHead);
    }

    int c_api_getNumGeometricShapes(SBMLDocument* document, const char* id) {
        return getNumGeometricShapes(document, id);
    }

    bool c_api_isRectangle(SBMLDocument* document, const char* id, int geometricShapeIndex) {
        return isRectangle(document, id, geometricShapeIndex);
    }

    bool c_api_isEllipse(SBMLDocument* document, const char* id, int geometricShapeIndex) {
        return isEllipse(document, id, geometricShapeIndex);
    }

    bool c_api_isPolygon(SBMLDocument* document, const char* id, int geometricShapeIndex) {
        return isPolygon(document, id, geometricShapeIndex);
    }

    bool c_api_isImage(SBMLDocument* document, const char* id, int geometricShapeIndex) {
        return isImage(document, id, geometricShapeIndex);
    }

    bool c_api_isRenderCurve(SBMLDocument* document, const char* id, int geometricShapeIndex) {
        return isRenderCurve(document, id, geometricShapeIndex);
    }

    bool c_api_isText(SBMLDocument* document, const char* id, int geometricShapeIndex) {
        return isText(document, id, geometricShapeIndex);
    }

    const double c_api_getGeometricShapeX(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex) {
        RelAbsVector xVector = getGeometricShapeX(document, id, geometricShapeIndex);
        return xVector.getAbsoluteValue() + 0.01 * c_api_getWidth(document, id) * xVector.getRelativeValue();
    }

    int c_api_setGeometricShapeX(SBMLDocument* document, const char* id, const double x, unsigned int geometricShapeIndex) {
        RelAbsVector xVector;
        xVector.setAbsoluteValue(x);
        return setGeometricShapeX(document, id, geometricShapeIndex, xVector);
    }

    const double c_api_getGeometricShapeY(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex) {
        RelAbsVector yVector = getGeometricShapeY(document, id, geometricShapeIndex);
        return yVector.getAbsoluteValue() + 0.01 * c_api_getHeight(document, id) * yVector.getRelativeValue();
    }

    int c_api_setGeometricShapeY(SBMLDocument* document, const char* id, const double y, unsigned int geometricShapeIndex) {
        RelAbsVector yVector;
        yVector.setAbsoluteValue(y);
        return setGeometricShapeY(document, id, geometricShapeIndex, yVector);
    }

    const double c_api_getGeometricShapeWidth(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex) {
        RelAbsVector widthVector = getGeometricShapeWidth(document, id, geometricShapeIndex);
        return widthVector.getAbsoluteValue() + 0.01 * c_api_getWidth(document, id) * widthVector.getRelativeValue();
    }

    int c_api_setGeometricShapeWidth(SBMLDocument* document, const char* id, const double width, unsigned int geometricShapeIndex) {
        RelAbsVector widthVector;
        widthVector.setAbsoluteValue(width);
        return setGeometricShapeWidth(document, id, geometricShapeIndex, widthVector);
    }

    const double c_api_getGeometricShapeHeight(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex) {
        RelAbsVector heightVector = getGeometricShapeHeight(document, id, geometricShapeIndex);
        return heightVector.getAbsoluteValue() + 0.01 * c_api_getHeight(document, id) * heightVector.getRelativeValue();
    }

    int c_api_setGeometricShapeHeight(SBMLDocument* document, const char* id, const double height, unsigned int geometricShapeIndex) {
        RelAbsVector heightVector;
        heightVector.setAbsoluteValue(height);
        return setGeometricShapeHeight(document, id, geometricShapeIndex, heightVector);
    }

    const double c_api_getGeometricShapeRatio(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex) {
        return getGeometricShapeRatio(document, id, geometricShapeIndex);
    }

    int c_api_setGeometricShapeRatio(SBMLDocument* document, const char* id, const double ratio, unsigned int geometricShapeIndex) {
        return setGeometricShapeRatio(document, id, geometricShapeIndex, ratio);
    }

    const double c_api_getGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex) {
        RelAbsVector borderRadiusXVector = getGeometricShapeCornerCurvatureRadiusX(document, id, geometricShapeIndex);
        return borderRadiusXVector.getAbsoluteValue() + 0.01 * c_api_getWidth(document, id) * borderRadiusXVector.getRelativeValue();
    }

    int c_api_setGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, const double borderRadiusX, unsigned int geometricShapeIndex) {
        RelAbsVector borderRadiusXVector;
        borderRadiusXVector.setAbsoluteValue(borderRadiusX);
        return setGeometricShapeCornerCurvatureRadiusX(document, id, geometricShapeIndex, borderRadiusXVector);
    }

    const double c_api_getGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex) {
        RelAbsVector borderRadiusYVector = getGeometricShapeCornerCurvatureRadiusY(document, id, geometricShapeIndex);
        return borderRadiusYVector.getAbsoluteValue() + 0.01 * c_api_getHeight(document, id) * borderRadiusYVector.getRelativeValue();
    }

    int c_api_setGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, const double borderRadiusY, unsigned int geometricShapeIndex) {
        RelAbsVector borderRadiusYVector;
        borderRadiusYVector.setAbsoluteValue(borderRadiusY);
        return setGeometricShapeCornerCurvatureRadiusY(document, id, geometricShapeIndex, borderRadiusYVector);
    }

    const double c_api_getGeometricShapeCenterX(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex) {
        RelAbsVector centerXVector = getGeometricShapeCenterX(document, id, geometricShapeIndex);
        return centerXVector.getAbsoluteValue() + 0.01 * c_api_getWidth(document, id) * centerXVector.getRelativeValue();
    }

    int c_api_setGeometricShapeCenterX(SBMLDocument* document, const char* id, const double centerX, unsigned int geometricShapeIndex) {
        RelAbsVector centerXVector;
        centerXVector.setAbsoluteValue(centerX);
        return setGeometricShapeCenterX(document, id, geometricShapeIndex, centerXVector);
    }

    const double c_api_getGeometricShapeCenterY(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex) {
        RelAbsVector centerYVector = getGeometricShapeCenterY(document, id, geometricShapeIndex);
        return centerYVector.getAbsoluteValue() + 0.01 * c_api_getHeight(document, id) * centerYVector.getRelativeValue();
    }

    int c_api_setGeometricShapeCenterY(SBMLDocument* document, const char* id, const double centerY, unsigned int geometricShapeIndex) {
        RelAbsVector centerYVector;
        centerYVector.setAbsoluteValue(centerY);
        return setGeometricShapeCenterY(document, id, geometricShapeIndex, centerYVector);
    }

    const double c_api_getGeometricShapeRadiusX(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex) {
        RelAbsVector radiusXVector = getGeometricShapeRadiusX(document, id, geometricShapeIndex);
        return radiusXVector.getAbsoluteValue() + 0.01 * c_api_getWidth(document, id) * radiusXVector.getRelativeValue();
    }

    int c_api_setGeometricShapeRadiusX(SBMLDocument* document, const char* id, const double radiusX, unsigned int geometricShapeIndex) {
        RelAbsVector radiusXVector;
        radiusXVector.setAbsoluteValue(radiusX);
        return setGeometricShapeRadiusX(document, id, geometricShapeIndex, radiusXVector);
    }

    const double c_api_getGeometricShapeRadiusY(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex) {
        RelAbsVector radiusYVector = getGeometricShapeRadiusY(document, id, geometricShapeIndex);
        return radiusYVector.getAbsoluteValue() + 0.01 * c_api_getHeight(document, id) * radiusYVector.getRelativeValue();
    }

    int c_api_setGeometricShapeRadiusY(SBMLDocument* document, const char* id, const double radiusY, unsigned int geometricShapeIndex) {
        RelAbsVector radiusYVector;
        radiusYVector.setAbsoluteValue(radiusY);
        return setGeometricShapeRadiusY(document, id, geometricShapeIndex, radiusYVector);
    }

    const unsigned int c_api_getGeometricShapeNumSegments(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex) {
        return getGeometricShapeNumElements(document, id, geometricShapeIndex);
    }

    const double c_api_getGeometricShapeSegmentX(SBMLDocument* document, const char* id, unsigned int segmentIndex, unsigned int geometricShapeIndex) {
        RelAbsVector segmentXVector = getGeometricShapeElementX(document, id, geometricShapeIndex, segmentIndex);
        return segmentXVector.getAbsoluteValue() + 0.01 * c_api_getWidth(document, id) * segmentXVector.getRelativeValue();
    }

    int c_api_setGeometricShapeSegmentX(SBMLDocument* document, const char* id, const double x, unsigned int segmentIndex, unsigned int geometricShapeIndex) {
        RelAbsVector segmentXVector;
        segmentXVector.setAbsoluteValue(x);
        return setGeometricShapeElementX(document, id, geometricShapeIndex, segmentIndex, segmentXVector);
    }

    const double c_api_getGeometricShapeSegmentY(SBMLDocument* document, const char* id, unsigned int segmentIndex, unsigned int geometricShapeIndex) {
        RelAbsVector segmentYVector = getGeometricShapeElementY(document, id, geometricShapeIndex, segmentIndex);
        return segmentYVector.getAbsoluteValue() + 0.5 * 0.01 * c_api_getHeight(document, id) * segmentYVector.getRelativeValue();
    }

    int c_api_setGeometricShapeSegmentY(SBMLDocument* document, const char* id, const double y, unsigned int segmentIndex, unsigned int geometricShapeIndex) {
        RelAbsVector segmentYVector;
        segmentYVector.setAbsoluteValue(y);
        return setGeometricShapeElementY(document, id, geometricShapeIndex, segmentIndex, segmentYVector);
    }

    const double c_api_getGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const char* id, unsigned int segmentIndex, unsigned int geometricShapeIndex) {
        RelAbsVector segmentStartXVector = getGeometricShapeBasePoint1X(document, id, geometricShapeIndex, segmentIndex);
        return segmentStartXVector.getAbsoluteValue() + 0.01 * c_api_getWidth(document, id) * segmentStartXVector.getRelativeValue();
    }

    int c_api_setGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const char* id, const double x, unsigned int segmentIndex, unsigned int geometricShapeIndex) {
        RelAbsVector segmentStartXVector;
        segmentStartXVector.setAbsoluteValue(x);
        return setGeometricShapeBasePoint1X(document, id, geometricShapeIndex, segmentIndex, segmentStartXVector);
    }

    const double c_api_getGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const char* id, unsigned int segmentIndex, unsigned int geometricShapeIndex) {
        RelAbsVector segmentStartYVector = getGeometricShapeBasePoint1Y(document, id, geometricShapeIndex, segmentIndex);
        return segmentStartYVector.getAbsoluteValue() + 0.01 * c_api_getHeight(document, id) * segmentStartYVector.getRelativeValue();
    }

    int c_api_setGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const char* id, const double y, unsigned int segmentIndex, unsigned int geometricShapeIndex) {
        RelAbsVector segmentStartYVector;
        segmentStartYVector.setAbsoluteValue(y);
        return setGeometricShapeBasePoint1Y(document, id, geometricShapeIndex, segmentIndex, segmentStartYVector);
    }

    const double c_api_getGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const char* id, unsigned int segmentIndex, unsigned int geometricShapeIndex) {
        RelAbsVector segmentBasePoint2XVector = getGeometricShapeBasePoint2X(document, id, geometricShapeIndex, segmentIndex);
        return segmentBasePoint2XVector.getAbsoluteValue() + 0.01 * c_api_getWidth(document, id) * segmentBasePoint2XVector.getRelativeValue();
    }

    int c_api_setGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const char* id, const double x, unsigned int segmentIndex, unsigned int geometricShapeIndex) {
        RelAbsVector segmentBasePoint2XVector;
        segmentBasePoint2XVector.setAbsoluteValue(x);
        return setGeometricShapeBasePoint2X(document, id, geometricShapeIndex, segmentIndex, segmentBasePoint2XVector);
    }

    const double c_api_getGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const char* id, unsigned int segmentIndex, unsigned int geometricShapeIndex) {
        RelAbsVector segmentBasePoint2YVector = getGeometricShapeBasePoint2Y(document, id, geometricShapeIndex, segmentIndex);
        return segmentBasePoint2YVector.getAbsoluteValue() + 0.01 * c_api_getHeight(document, id) * segmentBasePoint2YVector.getRelativeValue();
    }

    int c_api_setGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const char* id, const double y, unsigned int segmentIndex, unsigned int geometricShapeIndex) {
        RelAbsVector segmentBasePoint2YVector;
        segmentBasePoint2YVector.setAbsoluteValue(y);
        return setGeometricShapeBasePoint2Y(document, id, geometricShapeIndex, segmentIndex, segmentBasePoint2YVector);
    }

    bool c_api_isSetGeometricShapeHref(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex) {
        return isSetGeometricShapeHref(document, id, geometricShapeIndex);
    }

    const char* c_api_getGeometricShapeHref(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex) {
        return strdup(getGeometricShapeHref(document, id, geometricShapeIndex).c_str());
    }

    int c_api_setGeometricShapeHref(SBMLDocument* document, const char* id, const char* href, unsigned int geometricShapeIndex) {
        return setGeometricShapeHref(document, id, geometricShapeIndex, href);
    }
}

}