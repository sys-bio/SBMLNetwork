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

const std::string getTextGlyphStyleType(GraphicalObject* graphicalObject);

const std::string getCompartmentGlyphStyleType();

const std::string getSpeciesGlyphStyleType();

const std::string getReactionGlyphStyleType();

const std::string getSpeciesReferenceGlyphStyleType();

const std::string getSpeciesReferenceGlyphStyleType();

const std::string getTextGlyphStyleType();

const std::string getCompartmentGlyphTextGlyphStyleType();

const std::string getSpeciesGlyphTextGlyphStyleType();

const std::string getReactionGlyphTextGlyphStyleType();

const std::string getGraphicalObjectStyleType();

std::vector<std::pair<SpeciesReferenceRole_t, std::string>> getStyleRoles();

void setGeneralTextGlyphRenderGroupFeatures(RenderGroup* renderGroup);

void addDefaultColors(GlobalRenderInformation* globalRenderInformation);

void addColorsOfDefaultGeometricShapes(SBMLDocument* document, Style* style);

void addColorsOfDefaultGeometricShapes(GlobalRenderInformation* globalRenderInformation);

const std::string getColorValue(RenderInformationBase* renderInformationBase, const std::string &colorId);

const std::string getColorId(RenderInformationBase* renderInformationBase, const std::string &colorValue);

const std::string addColor(SBMLDocument* document, Style* style, const std::string &color);

const std::string addColor(SBMLDocument* document, LineEnding* lineEnding, const std::string &color);

const std::string addColor(RenderInformationBase* renderInformationBase, const std::string &color);

const std::string addColor(RenderInformationBase* renderInformationBase, const std::string &colorId, const std::string &colorValue);

const std::string addGradient(SBMLDocument* document, Style* style, const std::string type, std::vector<std::pair<std::string, double>> stopsVector);

const std::string addGradient(SBMLDocument* document, LineEnding* lineEnding, const std::string type, std::vector<std::pair<std::string, double>> stopsVector);

const std::string addGradient(RenderInformationBase* renderInformationBase, const std::string type, std::vector<std::pair<std::string, double>> stopsVector);

const std::string getColorIdFromHexColorCode(RenderInformationBase* renderInformationBase, const std::string &hexColorCode);

const std::string getUniqueColorId(RenderInformationBase* renderInformationBase);

ColorDefinition* createColorDefinition(RenderPkgNamespaces* renderPkgNamespaces, const std::string &id, unsigned char r, unsigned char g, unsigned char b, unsigned char a);

ColorDefinition* createColorDefinition(RenderPkgNamespaces* renderPkgNamespaces, const std::string &id, const std::string &value);

GradientBase* createGradient(RenderPkgNamespaces* renderPkgNamespaces, const std::string &id, const std::string type, std::vector<std::pair<std::string, double>> stopsVector);

GradientBase* createLinearGradient(RenderPkgNamespaces* renderPkgNamespaces, const std::string &id, std::vector<std::pair<std::string, double>> stopsVector);

GradientBase* createRadialGradient(RenderPkgNamespaces* renderPkgNamespaces, const std::string &id, std::vector<std::pair<std::string, double>> stopsVector);

GradientStop* createGradientStop(RenderPkgNamespaces* renderPkgNamespaces, const std::string &stopColor, const RelAbsVector& offset);

const std::string getUniqueGradientId(RenderInformationBase* renderInformationBase);

LineEnding* createLocalLineEnding(RenderInformationBase* localRenderInformation, LineEnding* globalLineEnding, SpeciesReferenceGlyph* speciesReferenceGlyph);

LineEnding* createLocalLineEnding(SBMLDocument* document, RenderInformationBase* localRenderInformation, SpeciesReferenceGlyph* speciesReferenceGlyph);

const bool isLocal(SBMLDocument* document, LineEnding* lineEnding, SpeciesReferenceGlyph* speciesReferenceGlyph);

const std::string getLocalLineEndingId(SBMLDocument* document, SpeciesReferenceGlyph* speciesReferenceGlyph);

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

void addTextGlyphsGlobalStyles(GlobalRenderInformation* globalRenderInformation);

void addCompartmentGlyphTextGlyphGlobalStyle(GlobalRenderInformation* globalRenderInformation);

void addSpeciesGlyphTextGlyphGlobalStyle(GlobalRenderInformation* globalRenderInformation);

void addReactionGlyphTextGlyphGlobalStyle(GlobalRenderInformation* globalRenderInformation);

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

void setCompartmentGlyphTextGlyphRenderGroupFeatures(RenderGroup* renderGroup);

void setSpeciesGlyphRenderGroupFeatures(RenderGroup* renderGroup);

void setSpeciesGlyphTextGlyphRenderGroupFeatures(RenderGroup* renderGroup);

void setReactionGlyphRenderGroupFeatures(RenderGroup* renderGroup);

void setReactionGlyphTextGlyphRenderGroupFeatures(RenderGroup* renderGroup);

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

const bool canHaveStrokeColor(GraphicalObject* graphicalObject);

const bool canHaveStrokeWidth(GraphicalObject* graphicalObject);

const bool canHaveStrokeDashArray(GraphicalObject* graphicalObject);

const bool canHaveFillColor(GraphicalObject* graphicalObject);

const bool canHaveFillRule(GraphicalObject* graphicalObject);

const bool canHaveFontColor(TextGlyph* textGlyph);

const bool canHaveFontFamily(TextGlyph* textGlyph);

const bool canHaveFontSize(TextGlyph* textGlyph);

const bool canHaveFontWeight(TextGlyph* textGlyph);

const bool canHaveFontStyle(TextGlyph* textGlyph);

const bool canHaveTextAnchor(TextGlyph* textGlyph);

const bool canHaveVTextAnchor(TextGlyph* textGlyph);

const bool canHaveStartHead(GraphicalObject* graphicalObject);

const bool canHaveEndHead(GraphicalObject* graphicalObject);

const bool canHaveGeometricShape(GraphicalObject* graphicalObject);

std::string getErrorLog(RenderInformationBase* renderInformation);

std::string getErrorLog(ColorDefinition* colorDefinition);

std::string getErrorLog(GradientBase* gradientBase);

std::string getErrorLog(GradientStop* gradientStop);

std::string getErrorLog(LineEnding* lineEnding);

std::string getErrorLog(Style* style);

std::string getErrorLog(RenderGroup* renderGroup);

std::string getErrorLog(Transformation2D* transformation2D);

void clearErrorLog(RenderInformationBase* renderInformation);

void clearErrorLog(ColorDefinition* colorDefinition);

void clearErrorLog(GradientBase* gradientBase);

void clearErrorLog(GradientStop* gradientStop);

void clearErrorLog(LineEnding* lineEnding);

void clearErrorLog(Style* style);

void clearErrorLog(RenderGroup* renderGroup);

void clearErrorLog(Transformation2D* transformation2D);

void freeUserData(RenderInformationBase* renderInformation);

std::vector<std::map<std::string, std::string>> getUserData(RenderInformationBase* renderInformationBase);

const bool isValidBackgroundColorValue(SBase* sBase, const std::string& backgroundColor);

const bool isValidSpreadMethodValue(SBase* sBase, const std::string& spreadMethod);

const bool isValidGradientStopsVector(SBase* sBase, std::vector<std::pair<std::string, double>> stopsVector);

const bool isValidOffsetValue(SBase* sBase, const double& offset);

const bool isValidOffsetValue(SBase* sBase, const RelAbsVector& offset);

const bool isValidStopColorValue(SBase* sBase, const std::string& stopColor);

const bool isValidGradientX1Value(SBase* sBase, const RelAbsVector& x1);

const bool isValidGradientX2Value(SBase* sBase, const RelAbsVector& x2);

const bool isValidGradientY1Value(SBase* sBase, const RelAbsVector& y1);

const bool isValidGradientY2Value(SBase* sBase, const RelAbsVector& y2);

const bool isValidGradientCxValue(SBase* sBase, const RelAbsVector& cx);

const bool isValidGradientCyValue(SBase* sBase, const RelAbsVector& cy);

const bool isValidGradientFxValue(SBase* sBase, const RelAbsVector& fx);

const bool isValidGradientFyValue(SBase* sBase, const RelAbsVector& fy);

const bool isValidGradientRValue(SBase* sBase, const RelAbsVector& r);

const bool isValidEnableRotationalMappingValue(SBase* sBase, const bool& enableRotationalMapping);

const bool isValidStrokeColorValue(SBase* sBase, const std::string& strokeColor);

const bool isValidStrokeWidthValue(SBase* sBase, const double& strokeWidth);

const bool isValidStrokeDashArrayValue(SBase* sBase, const std::vector<unsigned int>& strokeDashArray);

const bool isValidStrokeDashValue(SBase* sBase, const unsigned int& strokeDash);

const bool isValidFontColorValue(SBase* sBase, const std::string& fontColor);

const bool isValidFontFamilyValue(SBase* sBase, const std::string& fontFamily);

const bool isValidFontSizeValue(SBase* sBase, const RelAbsVector& fontSize);

const bool isValidFontWeightValue(SBase* sBase, const std::string& fontWeight);

const bool isValidFontStyleValue(SBase* sBase, const std::string& fontStyle);

const bool isValidTextAnchorValue(SBase* sBase, const std::string& textAnchor);

const bool isValidVTextAnchorValue(SBase* sBase, const std::string& vTextAnchor);

const bool isValidFillColorValue(SBase* sBase, const std::string& fillColor);

const bool isValidFillRuleValue(SBase* sBase, const std::string& fillRule);

const bool isValidStartHeadValue(SBase* sBase, const std::string& startHead);

const bool isValidEndHeadValue(SBase* sBase, const std::string& endHead);

const bool isValidGeometricShapeName(SBase* sBase, const std::string& geometricShapeName);

const bool isValidGeometricShapeXValue(SBase* sBase, const RelAbsVector& x);

const bool isValidGeometricShapeYValue(SBase* sBase, const RelAbsVector& y);

const bool isValidGeometricShapeWidthValue(SBase* sBase, const RelAbsVector& width);

const bool isValidGeometricShapeHeightValue(SBase* sBase, const RelAbsVector& height);

const bool isValidGeometricShapeRatioValue(SBase* sBase, const double& ratio);

const bool isValidGeometricShapeCornerCurvatureRadiusX(SBase* sBase, const RelAbsVector& rx);

const bool isValidGeometricShapeCornerCurvatureRadiusY(SBase* sBase, const RelAbsVector& ry);

const bool isValidGeometricShapeCenterX(SBase* sBase, const RelAbsVector& cx);

const bool isValidGeometricShapeCenterY(SBase* sBase, const RelAbsVector& cy);

const bool isValidGeometricShapeRadiusX(SBase* sBase, const RelAbsVector& rx);

const bool isValidGeometricShapeRadiusY(SBase* sBase, const RelAbsVector& ry);

const bool isValidGeometricShapeElementX(SBase* sBase, const RelAbsVector& x);

const bool isValidGeometricShapeElementY(SBase* sBase, const RelAbsVector& y);

const bool isValidGeometricShapeBasePoint1X(SBase* sBase, const RelAbsVector& x);

const bool isValidGeometricShapeBasePoint1Y(SBase* sBase, const RelAbsVector& y);

const bool isValidGeometricShapeBasePoint2X(SBase* sBase, const RelAbsVector& x);

const bool isValidGeometricShapeBasePoint2Y(SBase* sBase, const RelAbsVector& y);

const bool isValidGeometricShapeHref(SBase* sBase, const std::string& href);

const bool isValidRelAbsVectorPositiveValue(SBase* sBase, const RelAbsVector& relAbsVectorValue);

const bool isValidRelAbsVectorValue(SBase* sBase, const RelAbsVector& relAbsVectorValue);

const bool isValidRelAbsVectorRelativeValue(SBase* sBase, const double& value);

std::vector<std::string> getValidSpreadMethodValues();

std::vector<std::string> getValidFontWeightValues();

std::vector<std::string> getValidFontStyleValues();

std::vector<std::string> getValidTextAnchorValues();

std::vector<std::string> getValidVTextAnchorValues();

std::vector<std::string> getValidFillRuleValues();

std::vector<std::string> getValidGeometricShapeNameValues();

}

#endif

