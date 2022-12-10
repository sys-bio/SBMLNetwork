#ifndef __LIBSBML_NE_AUTOLAYOUT_H_
#define __LIBSBML_NE_AUTOLAYOUT_H_

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#include "graphviz/gvc.h"
#endif

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

void locateGlyphs(Model* model, Layout* layout);

Agraph_t* createGraph();

void addGlyphsToGraph(Model* model, Layout* layout, Agraph_t* graph);

void addCompartmentGlyphsToGraph(Model* model, Layout* layout, Agraph_t* graph);

void addSpeciesGlyphsToSubGraph(Model* model, Layout* layout, CompartmentGlyph* compartmentGlyph, Agraph_t* subgraph);

void addSpeciesGlyphToSubGraph(SpeciesGlyph* speciesGlyph, Agraph_t* subgraph);

void addReactionGlyphsToGraph(Layout* layout, Agraph_t* graph);

void addReactinGlyphToGraph(ReactionGlyph* reactionGlyph, Agraph_t* graph);

void addSpeciesReferenceGlyphsToGraph(ReactionGlyph* reactionGlyph, Agraph_t* graph, Agnode_t* reactionNode);

void addSpeciesReferenceGlyphToGraph(SpeciesReferenceGlyph* speciesReferenceGlyph, Agraph_t* graph, Agnode_t* reactionNode);

void applyAutoLayoutOnGraph(Layout* layout, GVC_t* gvc, Agraph_t* graph);

void extractGlyphsFeaturesFromGraph(Model* model, Layout* layout, Agraph_t* graph);

void extractCompartmentGlyphsFromGraph(Model* model, Layout* layout, Agraph_t* graph, double& minXLayout, double& minYLayout, double& maxXLayout, double& maxYLayout);

void extractSpeciesGlyphsFromGraph(Layout* layout, Agraph_t* graph, double& minXLayout, double& minYLayout, double& maxXLayout, double& maxYLayout, double& minXCompartment, double& minYCompartment, double& maxXCompartment, double& maxYCompartment);

void extractSpeciesGlyphFromGraph(SpeciesGlyph* speciesGlyph, Agraph_t* graph, double &minXLayout, double& minYLayout, double& maxXLayout, double& maxYLayout, double& minXCompartment, double& minYCompartment, double& maxXCompartment, double& maxYCompartment);

void extractReactionGlyphsFromGraph(Layout* layout, Agraph_t* graph, double& minXLayout, double& minYLayout, double& maxXLayout, double& maxYLayout);

void extractReactionGlyphFromGraph(ReactionGlyph* reactionGlyph, Agraph_t* graph, double& minXLayout, double& minYLayout, double& maxXLayout, double& maxYLayout);

void extractSpeciesReferenceGlyphsFromGraph(ReactionGlyph* reactionGlyph, Agraph_t* graph, Agnode_t* reactionNode, double& minXLayout, double& minYLayout, double& maxXLayout, double& maxYLayout);

void extractSpeciesReferenceGlyphFromGraph(SpeciesReferenceGlyph* speciesReferenceGlyph, Agraph_t* graph, Agnode_t* reactionNode, double& minXLayout, double& minYLayout, double& maxXLayout, double& maxYLayout);

void updateBoundingBox(BoundingBox* box, Agnode_t* node);

void updateBoundingBox(BoundingBox* box, const double minX, const double minY, const double maxX, const double maxY);

void updateLineSegment(LineSegment* lineSegment, Agedge_t* edge);

void updateExtetns(double& minX, double& minY, double& maxX, double& maxY, BoundingBox* box);

void updateExtetns(double& minX, double& minY, double& maxX, double& maxY, LineSegment* lineSegment);

void updateExtetns(double& minX, double& minY, double& maxX, double& maxY, const double x, const double y);

void updateDimensions(Layout* layout, const double minXLayout, const double minYLayout, const double maxXLayout, const double maxYLayout);

void deleteGraph(GVC_t* gvc, Agraph_t* graph);

}

#endif

