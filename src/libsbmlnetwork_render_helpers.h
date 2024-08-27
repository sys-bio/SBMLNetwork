#ifndef __LIBSBMLNETWORK_RENDER_HELPERS_H_
#define __LIBSBMLNETWORK_RENDER_HELPERS_H_

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#include "sbml/packages/render/common/RenderExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE  {

SBasePlugin* getRenderPlugin(SBMLDocument* document);

SBasePlugin* getRenderPlugin(Layout* layout);

SBasePlugin* getRenderPlugin(LayoutModelPlugin* layoutModelPlugin);

RenderListOfLayoutsPlugin* getRenderListOfLayoutsPlugin(SBasePlugin* renderBase);

RenderLayoutPlugin* getRenderLayoutPlugin(SBasePlugin* renderBase);

void enableRenderPlugin(SBMLDocument* document);

void enableRenderPlugin(Layout* layout);

Style* findStyleByIdList(RenderInformationBase* renderInformationBase, const std::string& id);

Style* findStyleByIdList(LocalRenderInformation* localRenderInformation, const std::string& id);

Style* findStyleByRoleList(RenderInformationBase* renderInformationBase, const std::string& role);

Style* findStyleByRoleList(LocalRenderInformation* localRenderInformation, const std::string& role);

Style* findStyleByRoleList(GlobalRenderInformation* globalRenderInformation, const std::string& role);

Style* findStyleByTypeList(RenderInformationBase* renderInformationBase, const std::string& type);

Style* findStyleByTypeList(LocalRenderInformation* localRenderInformation, const std::string& type);

Style* findStyleByTypeList(GlobalRenderInformation* globalRenderInformation, const std::string& type);

const std::string getStyleType(GraphicalObject* graphicalObject);

const std::string getCompartmentGlyphStyleType();

const std::string getSpeciesGlyphStyleType();

const std::string getReactionGlyphStyleType();

const std::string getSpeciesReferenceGlyphStyleType();

const std::string getSpeciesReferenceGlyphStyleType();

const std::string getTextGlyphStyleType();

const std::string getGraphicalObjectStyleType();

std::vector<std::pair<SpeciesReferenceRole_t, std::string>> getStyleRoles();

void setGeneralTextGlyphRenderGroupFeatures(RenderGroup* renderGroup);

void addDefaultColors(GlobalRenderInformation* globalRenderInformation);

void addColorsOfDefaultGeometricShapes(SBMLDocument* document, Style* style);

void addColorsOfDefaultGeometricShapes(GlobalRenderInformation* globalRenderInformation);

const bool addColor(SBMLDocument* document, Style* style, const std::string &color);

const bool addColor(SBMLDocument* document, LineEnding* lineEnding, const std::string &color);

const bool addColor(RenderInformationBase* renderInformationBase, const std::string &color);

const bool addColor(RenderInformationBase* renderInformationBase, const std::string &colorId, const std::string &colorValue);

const std::string getColorIdFromHexColorCode(RenderInformationBase* renderInformationBase, const std::string &hexColorCode);

const std::string getUniqueColorId(RenderInformationBase* renderInformationBase);

ColorDefinition* createColorDefinition(RenderPkgNamespaces* renderPkgNamespaces, const std::string &id, unsigned char r, unsigned char g, unsigned char b, unsigned char a);

ColorDefinition* createColorDefinition(RenderPkgNamespaces* renderPkgNamespaces, const std::string &id, const std::string &value);

void addTextGlyphGlobalStyle(GlobalRenderInformation* globalRenderInformation);

void addDefaultLineEndings(GlobalRenderInformation* globalRenderInformation);

void addProductHeadLineEnding(GlobalRenderInformation* globalRenderInformation);

LineEnding* createProductHeadLineEnding(RenderPkgNamespaces* renderPkgNamespaces);

void setProductHeadLineEndingExclusiveFeatures(LineEnding* lineEnding);

void addModifierHeadLineEnding(GlobalRenderInformation* globalRenderInformation);

LineEnding* createModifierHeadLineEnding(RenderPkgNamespaces* renderPkgNamespaces);

void setModifierHeadLineEndingExclusiveFeatures(LineEnding* lineEnding);

void addActivatorHeadLineEnding(GlobalRenderInformation* globalRenderInformation);

LineEnding* createActivatorHeadLineEnding(RenderPkgNamespaces* renderPkgNamespaces);

void setActivatorHeadLineEndingExclusiveFeatures(LineEnding* lineEnding);

void addInhibitorHeadLineEnding(GlobalRenderInformation* globalRenderInformation);

LineEnding* createInhibitorHeadLineEnding(RenderPkgNamespaces* renderPkgNamespaces);

void setInhibitorHeadLineEndingExclusiveFeatures(LineEnding* lineEnding);

void setLineEndingGeneralFeatures(LineEnding* lineEnding);

void addGlobalStyles(GlobalRenderInformation* globalRenderInformation);

GlobalStyle* createGlobalStyleByType(GlobalRenderInformation* globalRenderInformation, const std::string& type);

GlobalStyle* createGlobalStyleByRole(GlobalRenderInformation* globalRenderInformation, const std::string& role);

void addCompartmentGlyphGlobalStyle(GlobalRenderInformation* globalRenderInformation);

void addSpeciesGlyphGlobalStyle(GlobalRenderInformation* globalRenderInformation);

void addReactionGlyphGlobalStyle(GlobalRenderInformation* globalRenderInformation);

void addSpeciesReferenceGlyphGlobalStyles(GlobalRenderInformation* globalRenderInformation);

void addLocalStyles(Layout* layout, LocalRenderInformation* localRenderInformation);

Style* createLocalStyle(RenderInformationBase* localRenderInformation, Style* globalStyle, GraphicalObject* graphicalObject);

Style* createLocalStyle(RenderInformationBase* localRenderInformation, GraphicalObject* graphicalObject);

void addCompartmentGlyphsLocalStyles(Layout* layout, LocalRenderInformation* localRenderInformation);

void addCompartmentGlyphLocalStyle(CompartmentGlyph* compartmentGlyph, LocalRenderInformation* localRenderInformation);

void setCompartmentGlyphRenderGroupFeatures(RenderGroup* renderGroup);

void addCompartmentTextGlyphsLocalStyles(Layout* layout, LocalRenderInformation* localRenderInformation, CompartmentGlyph* compartmentGlyph);

void addCompartmentTextGlyphLocalStyle(TextGlyph* textGlyph, LocalRenderInformation* localRenderInformation);

void setCompartmentTextGlyphRenderGroupFeatures(RenderGroup* renderGroup);

void addSpeciesGlyphsLocalStyles(Layout* layout, LocalRenderInformation* localRenderInformation);

void addSpeciesGlyphLocalStyle(SpeciesGlyph* speciesGlyph, LocalRenderInformation* localRenderInformation);

void addSpeciesTextGlyphsLocalStyles(Layout* layout, LocalRenderInformation* localRenderInformation, SpeciesGlyph* speciesGlyph);

void addSpeciesTextGlyphLocalStyle(TextGlyph* textGlyph, LocalRenderInformation* localRenderInformation);

void addReactionGlyphsLocalStyles(Layout* layout, LocalRenderInformation* localRenderInformation);

void addReactionGlyphLocalStyle(ReactionGlyph* reactionGlyph, LocalRenderInformation* localRenderInformation);

void addReactionTextGlyphsLocalStyles(Layout* layout, LocalRenderInformation* localRenderInformation, ReactionGlyph* reactionGlyph);

void addReactionTextGlyphLocalStyle(TextGlyph* textGlyph, LocalRenderInformation* localRenderInformation);

void addSpeciesReferenceGlyphsLocalStyles(ReactionGlyph* reactionGlyph, LocalRenderInformation* localRenderInformation);

void addSpeciesReferenceGlyphLocalStyle(SpeciesReferenceGlyph* speciesReferenceGlyph, LocalRenderInformation* localRenderInformation);

void setCompartmentGlyphRenderGroupFeatures(RenderGroup* renderGroup);

void setCompartmentTextGlyphRenderGroupFeatures(RenderGroup* renderGroup);

void setSpeciesGlyphRenderGroupFeatures(RenderGroup* renderGroup);

void setSpeciesTextGlyphRenderGroupFeatures(RenderGroup* renderGroup);

void setReactionGlyphRenderGroupFeatures(RenderGroup* renderGroup);

void setReactionTextGlyphRenderGroupFeatures(RenderGroup* renderGroup);

void setSpeciesReferenceGlyphRenderGroupFeatures(RenderGroup* renderGroup, SpeciesReferenceRole_t role);

void setDefault1DShapeFeatures(GraphicalPrimitive1D* graphicalPrimitive1D);

void setDefault2DShapeFeatures(GraphicalPrimitive2D* graphicalPrimitive2D);

void setDefaultRectangleShapeFeatures(Rectangle* rectangle);

void setDefaultSquareShapeFeatures(Rectangle* square);

void setDefaultEllipseShapeFeatures(Ellipse* ellipse);

void setDefaultCircleShapeFeatures(Ellipse* circle);

void setDefaultTriangleShapeFeatures(Polygon* triangle);

void setDefaultDiamondShapeFeatures(Polygon* diamond);

void setDefaultPentagonShapeFeatures(Polygon* pentagon);

void setDefaultHexagonShapeFeatures(Polygon* pentagon);

void setDefaultOctagonShapeFeatures(Polygon* pentagon);

void setDefaultRenderCurveShapeFeatures(RenderCurve* renderCurve);

void setDefaultImageShapeFeatures(Image* image);

void unifyGeometricShapeMutualFeatures(RenderGroup* renderGroup);

const std::string getGlobalStyleUniqueId(GlobalRenderInformation* globalRenderInformation, const std::string& type);

const bool isValidBackgroundColorValue(const std::string& backgroundColor);

const bool isValidSpreadMethodValue(const std::string& spreadMethod);

const bool isValidOffsetValue(const RelAbsVector& offset);

const bool isValidOffsetValue(const double& offset);

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

const bool isValidEnableRotationalMappingValue(bool enableRotationalMapping);

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

const bool isValidRelAbsVectorRelativeValue(const double& value);

std::vector<std::string> getValidSpreadMethodValues();

std::vector<std::string> getValidFontWeightValues();

std::vector<std::string> getValidFontStyleValues();

std::vector<std::string> getValidTextAnchorValues();

std::vector<std::string> getValidVTextAnchorValues();

std::vector<std::string> getValidFillRuleValues();

std::vector<std::string> getValidGeometricShapeNameValues();

}

#endif

