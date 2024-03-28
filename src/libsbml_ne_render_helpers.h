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

const bool addColor(SBMLDocument* document, Style* style, const std::string &color);

const bool addColor(SBMLDocument* document, LineEnding* lineEnding, const std::string &color);

const bool addColor(RenderInformationBase* renderInformationBase, const std::string &color);

ColorDefinition* createColorDefinition(RenderPkgNamespaces* renderPkgNamespaces, const std::string &id, unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255);

ColorDefinition* createColorDefinition(RenderPkgNamespaces* renderPkgNamespaces, const std::string &id, const std::string &value);

void addDefaultLineEndings(GlobalRenderInformation* globalRenderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

void addProductHeadLineEnding(GlobalRenderInformation* globalRenderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

LineEnding* createProductHeadLineEnding(LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

void setProductHeadLineEndingExclusiveFeatures(LineEnding* lineEnding, RenderPkgNamespaces* renderPkgNamespaces);

void addModifierHeadLineEnding(GlobalRenderInformation* globalRenderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

LineEnding* createModifierHeadLineEnding(LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

void setModifierHeadLineEndingExclusiveFeatures(LineEnding* lineEnding, RenderPkgNamespaces* renderPkgNamespaces);

void addActivatorHeadLineEnding(GlobalRenderInformation* globalRenderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

LineEnding* createActivatorHeadLineEnding(LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

void setActivatorHeadLineEndingExclusiveFeatures(LineEnding* lineEnding, RenderPkgNamespaces* renderPkgNamespaces);

void addInhibitorHeadLineEnding(GlobalRenderInformation* globalRenderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

LineEnding* createInhibitorHeadLineEnding(LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

void setInhibitorHeadLineEndingExclusiveFeatures(LineEnding* lineEnding, RenderPkgNamespaces* renderPkgNamespaces);

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

const bool isValidBackgroundColorValue(const std::string& backgroundColor);

const bool isValidColorValue(const std::string& value);

const bool isValidSpreadMethodValue(const std::string& spreadMethod);

const bool isValidOffsetValue(const RelAbsVector& offset);

const bool isValidStopColorValue(const std::string& stopColor);

const bool isValidGradientX1Value(const RelAbsVector& x1);

const bool isValidGradientX2Value(const RelAbsVector& x2);

const bool isValidGradientY1Value(const RelAbsVector& y1);

const bool isValidGradientY2Value(const RelAbsVector& y2);

const bool isValidGradientCxValue(const RelAbsVector& cx);

const bool isValidGradientCyValue(const RelAbsVector& cy);

const bool isValidGradientFxValue(const RelAbsVector& fx);

const bool isValidGradientFyValue(const RelAbsVector& fy);

const bool isValidGradientRValue(const RelAbsVector& r);

const bool isValidEnableRotationalMappingValue(const bool& enableRotationalMapping);

const bool isValidStrokeColorValue(const std::string& stroke);

const bool isValidStrokeWidthValue(const double& strokeWidth);

const bool isValidStrokeDashArrayValue(const std::vector<unsigned int>& strokeDashArray);

const bool isValidStrokeDashValue(unsigned int dash);

const bool isValidFontColorValue(const std::string& fontColor);

const bool isValidFontFamilyValue(const std::string& fontFamily);

const bool isValidFontSizeValue(const RelAbsVector& fontSize);

const bool isValidFontWeightValue(const std::string& fontWeight);

const bool isValidFontStyleValue(const std::string& fontStyle);

const bool isValidTextAnchorValue(const std::string& textAnchor);

const bool isValidVTextAnchorValue(const std::string& vtextAnchor);

const bool isValidFillColorValue(const std::string& fillColor);

const bool isValidFillRuleValue(const std::string& fillRule);

const bool isValidStartHeadValue(const std::string& startHead);

const bool isValidEndHeadValue(const std::string& endHead);

const bool isValidGeometricShapeName(const std::string& geometricShapeName);

const bool isValidGeometricShapeXValue(const RelAbsVector& x);

const bool isValidGeometricShapeYValue(const RelAbsVector& y);

const bool isValidGeometricShapeWidthValue(const RelAbsVector& width);

const bool isValidGeometricShapeHeightValue(const RelAbsVector& height);

const bool isValidGeometricShapeRatioValue(const double& ratio);

const bool isValidGeometricShapeCornerCurvatureRadiusX(const RelAbsVector& rx);

const bool isValidGeometricShapeCornerCurvatureRadiusY(const RelAbsVector& ry);

const bool isValidGeometricShapeCenterX(const RelAbsVector& cx);

const bool isValidGeometricShapeCenterY(const RelAbsVector& cy);

const bool isValidGeometricShapeRadiusX(const RelAbsVector& rx);

const bool isValidGeometricShapeRadiusY(const RelAbsVector& ry);

const bool isValidGeometricShapeElementX(const RelAbsVector& x);

const bool isValidGeometricShapeElementY(const RelAbsVector& y);

const bool isValidGeometricShapeBasePoint1X(const RelAbsVector& x);

const bool isValidGeometricShapeBasePoint1Y(const RelAbsVector& y);

const bool isValidGeometricShapeBasePoint2X(const RelAbsVector& y);

const bool isValidGeometricShapeBasePoint2Y(const RelAbsVector& y);

const bool isValidGeometricShapeHref(const std::string& href);

const bool isValidRelAbsVectorPositiveValue(const RelAbsVector& relAbsVectorValue);

std::vector<std::pair<std::string, std::string>> colorData();

const std::string getHexColorCodeFromHtmlColorName(const std::string& htmlColorName);

const std::string getHtmlColorNameFromHexColorCode(const std::string& hexColorCode);

std::vector<std::string> getValidHtmlColorNames();

std::vector<std::string> getValidHexColorCodes();

std::vector<std::string> getValidSpreadMethodValues();

std::vector<std::string> getValidFontWeightValues();

std::vector<std::string> getValidFontStyleValues();

std::vector<std::string> getValidTextAnchorValues();

std::vector<std::string> getValidVTextAnchorValues();

std::vector<std::string> getValidFillRuleValues();

std::vector<std::string> getValidGeometricShapeNameValues();

}

#endif

