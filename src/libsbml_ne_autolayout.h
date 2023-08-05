#ifndef __LIBSBML_NE_AUTOLAYOUT_H_
#define __LIBSBML_NE_AUTOLAYOUT_H_

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#include "graphviz/gvc.h"
#endif

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

void locateGlyphs(Model* model, Layout* layout);

Agraph_s* createGraph();

void addGlyphsToGraph(Model* model, Layout* layout, Agraph_s* graph);

void addCompartmentGlyphsToGraph(Model* model, Layout* layout, Agraph_s* graph);

void addSpeciesGlyphsToSubGraph(Model* model, Layout* layout, CompartmentGlyph* compartmentGlyph, Agraph_s* subgraph);

void addSpeciesGlyphToSubGraph(SpeciesGlyph* speciesGlyph, Agraph_s* subgraph);

void addReactionGlyphsToGraph(Layout* layout, Agraph_s* graph);

void addReactinGlyphToGraph(Layout* layout, ReactionGlyph* reactionGlyph, Agraph_s* graph);

void addSpeciesReferenceGlyphsToGraph(Layout* layout, ReactionGlyph* reactionGlyph, Agraph_s* graph, Agnode_s* reactionNode);

void addSpeciesReferenceGlyphToGraph(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph, Agraph_s* graph, Agnode_s* reactionNode);

void applyAutoLayoutOnGraph(Layout* layout, GVC_s* gvc, Agraph_s* graph);

void extractGlyphsFeaturesFromGraph(Model* model, Layout* layout, Agraph_s* graph);

void extractCompartmentGlyphsFromGraph(Model* model, Layout* layout, Agraph_s* graph, double& minXLayout, double& minYLayout, double& maxXLayout, double& maxYLayout);

void extractSpeciesGlyphFromGraph(SpeciesGlyph* speciesGlyph, Agraph_s* graph, double &minXLayout, double& minYLayout, double& maxXLayout, double& maxYLayout, double& minXCompartment, double& minYCompartment, double& maxXCompartment, double& maxYCompartment);

void extractReactionGlyphsFromGraph(Layout* layout, Agraph_s* graph, double& minXLayout, double& minYLayout, double& maxXLayout, double& maxYLayout);

void extractReactionGlyphFromGraph(Layout* layout, ReactionGlyph* reactionGlyph, Agraph_s* graph, double& minXLayout, double& minYLayout, double& maxXLayout, double& maxYLayout);

void extractSpeciesReferenceGlyphsFromGraph(Layout* layout, ReactionGlyph* reactionGlyph, Agraph_s* graph, Agnode_s* reactionNode, double& minXLayout, double& minYLayout, double& maxXLayout, double& maxYLayout);

void extractSpeciesReferenceGlyphFromGraph(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph, Agraph_s* graph, Agnode_s* reactionNode, double& minXLayout, double& minYLayout, double& maxXLayout, double& maxYLayout);

void updateBoundingBox(BoundingBox* box, Agnode_s* node);

void updateBoundingBox(BoundingBox* box, const double minX, const double minY, const double maxX, const double maxY);

void updateLineSegment(LineSegment* lineSegment, Agedge_s* edge);

void updateExtetns(double& minX, double& minY, double& maxX, double& maxY, BoundingBox* box);

void updateExtetns(double& minX, double& minY, double& maxX, double& maxY, LineSegment* lineSegment);

void updateExtetns(double& minX, double& minY, double& maxX, double& maxY, const double x, const double y);

void updateDimensions(Layout* layout, const double minXLayout, const double minYLayout, const double maxXLayout, const double maxYLayout);

void deleteGraph(GVC_s* gvc, Agraph_s* graph);

}

#endif

