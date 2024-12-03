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

const std::string getEmptySpeciesGlyphStyleType();

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

void addEmptySpeciesGlyphGlobalStyle(GlobalRenderInformation* globalRenderInformation);

void addReactionGlyphGlobalStyle(GlobalRenderInformation* globalRenderInformation);

void addSpeciesReferenceGlyphGlobalStyles(GlobalRenderInformation* globalRenderInformation);

void addTextGlyphsGlobalStyles(GlobalRenderInformation* globalRenderInformation);

void addCompartmentGlyphTextGlyphGlobalStyle(GlobalRenderInformation* globalRenderInformation);

void addSpeciesGlyphTextGlyphGlobalStyle(GlobalRenderInformation* globalRenderInformation);

void addReactionGlyphTextGlyphGlobalStyle(GlobalRenderInformation* globalRenderInformation);

void addGraphicalObjectGlobalStyle(GlobalRenderInformation* globalRenderInformation);

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

void setEmptySpeciesGlyphRenderGroupFeatures(RenderGroup* renderGroup);

void setSpeciesGlyphTextGlyphRenderGroupFeatures(RenderGroup* renderGroup);

void setReactionGlyphRenderGroupFeatures(RenderGroup* renderGroup);

void setReactionGlyphTextGlyphRenderGroupFeatures(RenderGroup* renderGroup);

void setSpeciesReferenceGlyphRenderGroupFeatures(RenderGroup* renderGroup, SpeciesReferenceRole_t role);

void setGraphicalObjectRenderGroupFeatures(RenderGroup* renderGroup);

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

const bool canPotentiallyHaveGeometricShape(GraphicalObject* graphicalObject);

const bool isValidBackgroundColorValue(const std::string& backgroundColor, SBase* sBase = NULL);

const bool isValidSpreadMethodValue(const std::string& spreadMethod, SBase* sBase = NULL);

const bool isValidGradientStopsVector(std::vector<std::pair<std::string, double>> stopsVector, SBase* sBase = NULL);

const bool isValidOffsetValue(const double& offset, SBase* sBase = NULL);

const bool isValidOffsetValue(const RelAbsVector& offset, SBase* sBase = NULL);

const bool isValidStopColorValue(const std::string& stopColor, SBase* sBase = NULL);

const bool isValidGradientX1Value(const RelAbsVector& x1, SBase* sBase = NULL);

const bool isValidGradientX2Value(const RelAbsVector& x2, SBase* sBase = NULL);

const bool isValidGradientY1Value(const RelAbsVector& y1, SBase* sBase = NULL);

const bool isValidGradientY2Value(const RelAbsVector& y2, SBase* sBase = NULL);

const bool isValidGradientCxValue(const RelAbsVector& cx, SBase* sBase = NULL);

const bool isValidGradientCyValue(const RelAbsVector& cy, SBase* sBase = NULL);

const bool isValidGradientFxValue(const RelAbsVector& fx, SBase* sBase = NULL);

const bool isValidGradientFyValue(const RelAbsVector& fy, SBase* sBase = NULL);

const bool isValidGradientRValue(const RelAbsVector& r, SBase* sBase = NULL);

const bool isValidEnableRotationalMappingValue(const bool& enableRotationalMapping, SBase* sBase = NULL);

const bool isValidStrokeColorValue(const std::string& strokeColor, SBase* sBase = NULL);

const bool isValidStrokeWidthValue(const double& strokeWidth, SBase* sBase = NULL);

const bool isValidStrokeDashArrayValue(const std::vector<unsigned int>& strokeDashArray, SBase* sBase = NULL);

const bool isValidStrokeDashValue(const unsigned int& strokeDash, SBase* sBase = NULL);

const bool isValidFontColorValue(const std::string& fontColor, SBase* sBase = NULL);

const bool isValidFontFamilyValue(const std::string& fontFamily, SBase* sBase = NULL);

const bool isValidFontSizeValue(const RelAbsVector& fontSize, SBase* sBase = NULL);

const bool isValidFontWeightValue(const std::string& fontWeight, SBase* sBase = NULL);

const bool isValidFontStyleValue(const std::string& fontStyle, SBase* sBase = NULL);

const bool isValidTextAnchorValue(const std::string& textAnchor, SBase* sBase = NULL);

const bool isValidVTextAnchorValue(const std::string& vTextAnchor, SBase* sBase = NULL);

const bool isValidFillColorValue(const std::string& fillColor, SBase* sBase = NULL);

const bool isValidFillRuleValue(const std::string& fillRule, SBase* sBase = NULL);

const bool isValidStartHeadValue(const std::string& startHead, SBase* sBase = NULL);

const bool isValidEndHeadValue(const std::string& endHead, SBase* sBase = NULL);

const bool isValidGeometricShapeName(const std::string& geometricShapeName, SBase* sBase = NULL);

const bool isValidGeometricShapeXValue(const RelAbsVector& x, SBase* sBase = NULL);

const bool isValidGeometricShapeYValue(const RelAbsVector& y, SBase* sBase = NULL);

const bool isValidGeometricShapeWidthValue(const RelAbsVector& width, SBase* sBase = NULL);

const bool isValidGeometricShapeHeightValue(const RelAbsVector& height, SBase* sBase = NULL);

const bool isValidGeometricShapeRatioValue(const double& ratio, SBase* sBase = NULL);

const bool isValidGeometricShapeCornerCurvatureRadiusX(const RelAbsVector& rx, SBase* sBase = NULL);

const bool isValidGeometricShapeCornerCurvatureRadiusY(const RelAbsVector& ry, SBase* sBase = NULL);

const bool isValidGeometricShapeCenterX(const RelAbsVector& cx, SBase* sBase = NULL);

const bool isValidGeometricShapeCenterY(const RelAbsVector& cy, SBase* sBase = NULL);

const bool isValidGeometricShapeRadiusX(const RelAbsVector& rx, SBase* sBase = NULL);

const bool isValidGeometricShapeRadiusY(const RelAbsVector& ry, SBase* sBase = NULL);

const bool isValidGeometricShapeElementX(const RelAbsVector& x, SBase* sBase = NULL);

const bool isValidGeometricShapeElementY(const RelAbsVector& y, SBase* sBase = NULL);

const bool isValidGeometricShapeBasePoint1X(const RelAbsVector& x, SBase* sBase = NULL);

const bool isValidGeometricShapeBasePoint1Y(const RelAbsVector& y, SBase* sBase = NULL);

const bool isValidGeometricShapeBasePoint2X(const RelAbsVector& x, SBase* sBase = NULL);

const bool isValidGeometricShapeBasePoint2Y(const RelAbsVector& y, SBase* sBase = NULL);

const bool isValidGeometricShapeHref(const std::string& href, SBase* sBase = NULL);

const bool isValidRelAbsVectorPositiveValue(const RelAbsVector& relAbsVectorValue, SBase* sBase = NULL);

const bool isValidRelAbsVectorValue(const RelAbsVector& relAbsVectorValue, SBase* sBase = NULL);

const bool isValidRelAbsVectorRelativeValue(const double& value, SBase* sBase = NULL);

std::vector<std::string> getValidSpreadMethodValues();

std::vector<std::string> getValidFontWeightValues();

std::vector<std::string> getValidFontStyleValues();

std::vector<std::string> getValidTextAnchorValues();

std::vector<std::string> getValidVTextAnchorValues();

std::vector<std::string> getValidFillRuleValues();

std::vector<std::string> getValidGeometricShapeNameValues();

}

#endif

