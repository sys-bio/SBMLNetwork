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

Style* findStyle(LocalRenderInformation* localRednderInformation, const std::string& objectIdOrRole);

Style* findStyle(GlobalRenderInformation* globalRednderInformation, const std::string& objectRoleOrType);

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

void addDefaultColors(GlobalRenderInformation* globalRednderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void addWhiteColor(GlobalRenderInformation* globalRednderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void addBlackColor(GlobalRenderInformation* globalRednderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void addLightGrayColor(GlobalRenderInformation* globalRednderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void addDarkCyanColor(GlobalRenderInformation* globalRednderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void addTealColor(GlobalRenderInformation* globalRednderInformation, RenderPkgNamespaces* renderPkgNamespaces);

void addSilverColor(GlobalRenderInformation* globalRednderInformation, RenderPkgNamespaces* renderPkgNamespaces);

ColorDefinition* createColorDefintion(RenderPkgNamespaces* renderPkgNamespaces, const std::string &id, unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255);

void addDefaultLineEndings(GlobalRenderInformation* globalRednderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

void addProductHeadLineEnding(GlobalRenderInformation* globalRednderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

LineEnding* createProductHeadLineEnding(LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

void setProductHeadLineEndingExcluseFeatures(LineEnding* lineEnding, RenderPkgNamespaces* renderPkgNamespaces);

void addModifierHeadLineEnding(GlobalRenderInformation* globalRednderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

LineEnding* createModifierHeadLineEnding(LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

void setModifierHeadLineEndingExcluseFeatures(LineEnding* lineEnding, RenderPkgNamespaces* renderPkgNamespaces);

void addActivatorHeadLineEnding(GlobalRenderInformation* globalRednderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

LineEnding* createActivatorHeadLineEnding(LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

void setActivatorHeadLineEndingExcluseFeatures(LineEnding* lineEnding, RenderPkgNamespaces* renderPkgNamespaces);

void addInhibitorHeadLineEnding(GlobalRenderInformation* globalRednderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces);

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

}

#endif

