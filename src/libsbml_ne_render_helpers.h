#ifndef __LIBSBML_NE_RENDER_HELPERS_H_
#define __LIBSBML_NE_RENDER_HELPERS_H_

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#include "sbml/packages/render/common/RenderExtensionTypes.h"
#endif

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

SBasePlugin* getRenderPlugin(SBMLDocument* document);

SBasePlugin* getRenderPlugin(Layout* layout);

SBasePlugin* getRenderPlugin(LayoutModelPlugin* layoutModelPlugin);

RenderListOfLayoutsPlugin* getRenderListOfLayoutsPlugin(SBasePlugin* renderBase);

RenderLayoutPlugin* getRenderLayoutPlugin(SBasePlugin* renderBase);

void enableRenderPlugin(SBMLDocument* document);

void enableRenderPlugin(Layout* layout);

void addStyles(Layout* layout, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces);

Style* findStyleByIdList(RenderInformationBase* renderInformationBase, const std::string& id);

Style* findStyleByIdList(LocalRenderInformation* localRenderInformation, const std::string& id);

Style* findStyleByRoleList(RenderInformationBase* renderInformationBase, const std::string& role);

Style* findStyleByRoleList(LocalRenderInformation* localRenderInformation, const std::string& role);

Style* findStyleByRoleList(GlobalRenderInformation* globalRenderInformation, const std::string& role);

Style* findStyleByTypeList(RenderInformationBase* renderInformationBase, const std::string& type);

Style* findStyleByTypeList(LocalRenderInformation* localRenderInformation, const std::string& type);

Style* findStyleByTypeList(GlobalRenderInformation* globalRenderInformation, const std::string& type);

const std::string getStyleType(GraphicalObject* graphicalObject);

void addCompartmentGlyphsStyles(Layout* layout, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void addCompartmentGlyphStyle(CompartmentGlyph* compartmentGlyph, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void setCompartmentGlyphRenderGroupFeatures(RenderGroup* renderGroup, RenderPkgNamespaces* renderPkgNamespaces);

void addCompartmentTextGlyphsStyles(Layout* layout, LocalRenderInformation* localRenderInformation, CompartmentGlyph* compartmentGlyph, RenderPkgNamespaces* renderPkgNamespaces);

void addCompartmentTextGlyphStyle(TextGlyph* textGlyph, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void setCompartmentTextGlyphRenderGroupFeatures(RenderGroup* renderGroup, RenderPkgNamespaces* renderPkgNamespaces);

void addSpeciesGlyphsStyles(Layout* layout, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void addSpeciesGlyphStyle(SpeciesGlyph* speciesGlyph, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void setSpeciesGlyphRenderGroupFeatures(RenderGroup* renderGroup, RenderPkgNamespaces* renderPkgNamespaces);

void addSpeciesTextGlyphsStyles(Layout* layout, LocalRenderInformation* localRenderInformation, SpeciesGlyph* speciesGlyph, RenderPkgNamespaces* renderPkgNamespaces);

void addSpeciesTextGlyphStyle(TextGlyph* textGlyph, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void setSpeciesTextGlyphRenderGroupFeatures(RenderGroup* renderGroup, RenderPkgNamespaces* renderPkgNamespaces);

void addReactionGlyphsStyles(Layout* layout, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void addReactionGlyphStyle(ReactionGlyph* reactionGlyph, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void setReactionGlyphRenderGroupFeatures(RenderGroup* renderGroup, RenderPkgNamespaces* renderPkgNamespaces);

void addSpeciesReferenceGlyphsStyles(ReactionGlyph* reactionGlyph, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void addSpeciesReferenceGlyphStyle(SpeciesReferenceGlyph* speciesReferenceGlyph, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void setSpeciesReferenceGlyphRenderGroupFeatures(RenderGroup* renderGroup, SpeciesReferenceRole_t role, RenderPkgNamespaces* renderPkgNamespaces);

LocalStyle* createLocalStyle(LocalRenderInformation* localRenderInformation, GraphicalObject* graphicalObject);

void setGeneralTextGlyphRenderGroupFeatures(RenderGroup* renderGroup, RenderPkgNamespaces* renderPkgNamespaces);

void addDefaultColors(GlobalRenderInformation* globalRenderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void addWhiteColor(GlobalRenderInformation* globalRenderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void addBlackColor(GlobalRenderInformation* globalRenderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void addLightGrayColor(GlobalRenderInformation* globalRenderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void addDarkCyanColor(GlobalRenderInformation* globalRenderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void addTealColor(GlobalRenderInformation* globalRenderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void addSilverColor(GlobalRenderInformation* globalRenderInformation, RenderPkgNamespaces* renderPkgNamespaces);

ColorDefinition* createColorDefintion(RenderPkgNamespaces* renderPkgNamespaces, const std::string &id, unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255);

void addDefaultLineEndings(GlobalRenderInformation* globalRenderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

void addProductHeadLineEnding(GlobalRenderInformation* globalRenderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

LineEnding* createProductHeadLineEnding(LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

void setProductHeadLineEndingExcluseFeatures(LineEnding* lineEnding, RenderPkgNamespaces* renderPkgNamespaces);

void addModifierHeadLineEnding(GlobalRenderInformation* globalRenderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

LineEnding* createModifierHeadLineEnding(LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

void setModifierHeadLineEndingExcluseFeatures(LineEnding* lineEnding, RenderPkgNamespaces* renderPkgNamespaces);

void addActivatorHeadLineEnding(GlobalRenderInformation* globalRenderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

LineEnding* createActivatorHeadLineEnding(LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

void setActivatorHeadLineEndingExcluseFeatures(LineEnding* lineEnding, RenderPkgNamespaces* renderPkgNamespaces);

void addInhibitorHeadLineEnding(GlobalRenderInformation* globalRenderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

LineEnding* createInhibitorHeadLineEnding(LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

void setInhibitorHeadLineEndingExcluseFeatures(LineEnding* lineEnding, RenderPkgNamespaces* renderPkgNamespaces);

void setLineEndingGeneralFeatures(LineEnding* lineEnding, LayoutPkgNamespaces* layoutPkgNamespaces);

void setDefaultRectangleShapeFeatures(Rectangle* rectangle);

void setDefaultEllipseShapeFeatures(Ellipse* ellipse);

void setDefaultTriangleShapeFeatures(Polygon* triangle);

void setDefaultDiamondShapeFeatures(Polygon* diamond);

void setDefaultPentagonShapeFeatures(Polygon* pentagon);

void setDefaultHexagonShapeFeatures(Polygon* pentagon);

void setDefaultOctagonShapeFeatures(Polygon* pentagon);

void setDefaultRenderCurveShapeFeatures(RenderCurve* renderCurve);

void setDefaultImageShapeFeatures(Image* image);

const bool isValidBackgroundColorValue(backgroundColor);

const bool isValidColorValue(value);

const bool isValidSpredMethodValue(spreadMethod);

const bool isValidOffsetValue(offset);

const bool isValidStopColorValue(stopColor);

const bool isValidGradientX1Value(x1);

const bool isValidGradientX2Value(x2);

const bool isValidGradientY1Value(y1);

const bool isValidGradientY2Value(y2);

const bool isValidGradientCxValue(cx);

const bool isValidGradientCyValue(cy);

const bool isValidGradientFxValue(fx);

const bool isValidGradientFyValue(fy);

const bool isValidGradientRValue(r);

const bool isValidEnableRotationalMappingValue(enableRotationalMapping);

const bool isValidStrokeColorValue(stroke);

const bool isValidStrokeWidthValue(strokeWidth);

const bool isValidStrokeDashArrayValue(strokeDashArray);

const bool isValidStrokeDashValue(dash);

const bool isValidFontColorValue(fontColor);

const bool isValidFontFamilyValue(fontFamily);

const bool isValidFontSizeValue(fontSize);

const bool isValidFontWeightValue(fontWeight);

const bool isValidFontStyleValue(fontStyle);

const bool isValidTextAnchorValue(textAnchor);

const bool isValidVTextAnchorValue(vtextAnchor);

const bool isValidFillColorValue(fillColor);

const bool isValidFillRuleValue(fillRule);

const bool isValidStartHeadValue(startHead);

const bool isValidEndHeadValue(endHead);

const bool isValidGeometricShapeXValue(x);

const bool isValidGeometricShapeYValue(y);

const bool isValidGeometricShapeWidthValue(width);

const bool isValidGeometricShapeHeightValue(height);

const bool isValidGeometricShapeRatioValue(ratio);

const bool isValidGeometricShapeCornerCurvatureRadiusX(rx);

const bool isValidGeometricShapeCornerCurvatureRadiusY(ry);

const bool isValidGeometricShapeCenterX(cx);

const bool isValidGeometricShapeCenterY(cy);

const bool isValidGeometricShapeRadiusX(rx);

const bool isValidGeometricShapeRadiusY(ry);

const bool isValidGeometricShapeElementX(x);

const bool isValidGeometricShapeElementY(y);

const bool isValidGeometricShapeBasePoint1X(x);

const bool isValidGeometricShapeBasePoint1Y(y);

const bool isValidGeometricShapeBasePoint1Y(y);

const bool isValidGeometricShapeBasePoint2Y(y);

const bool isValidGeometricShapeHref(href);

}

#endif

