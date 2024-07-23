#ifndef __LIBSBMLNETWORK_AUTOLAYOUT_H_
#define __LIBSBMLNETWORK_AUTOLAYOUT_H_

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

#include "libsbmlnetwork_locked_node_info.h"

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE  {

void locateGlyphs(Model* model, Layout* layout, const double& stiffness = 10.0, const double& gravity = 15.0,
                  const bool& useMagnetism = false, const bool& useBoundary = false, const bool& useGrid = false,
                  const bool& useNameAsTextLabel = true, const std::vector<LockedNodeInfo>& lockedNodesInfo = std::vector<LockedNodeInfo>());

void locateReactions(Model *model, Layout *layout, const double &stiffness, const double &gravity,
                     const bool &useMagnetism, const bool &useBoundary, const bool &useGrid,
                     const bool& useNameAsTextLabel, const std::vector<LockedNodeInfo>& lockedNodesInfo);

void randomizeGlyphsLocations(Model* model, Layout* layout, const double &padding);

void randomizeSpeciesGlyphsLocations(Model* model, Layout* layout, const double& canvasWidth, const double& canvasHeight, const double& padding);

void randomizeReactionGlyphsLocations(Model* model, Layout* layout, const double& canvasWidth, const double& canvasHeight, const double& padding);

void randomizeBoundingBoxesPosition(BoundingBox* boundingBox, const double& canvasWidth, const double& canvasHeight);

void randomizeCurveCenterPoint(Curve* curve, const double& canvasWidth, const double& canvasHeight);

void setGlyphsDimensions(Model *model, Layout *layout);

void setSpeciesGlyphDimensions(Model *model, SpeciesGlyph* speciesGlyph);

void initializeCompartmentGlyphExtents(BoundingBox* compartmentGlyphBoundingBox, BoundingBox* speciesGlyphBoundingBox, const double& padding);

void updateCompartmentExtents(Model *model, Layout *layout, const double &padding);

void updateCompartmentExtents(BoundingBox* compartmentGlyphBoundingBox, BoundingBox* speciesGlyphBoundingBox, const double& padding);

void updateCompartmentExtents(BoundingBox* compartmentGlyphBoundingBox, Curve* reactionCurve, const double& padding);

void updateLayoutDimensions(Layout* layout, const double &padding);

void extractExtents(Layout* layout, double &minX, double &minY, double &maxX, double &maxY);

void extractExtents(BoundingBox* boundingBox, double &minX, double &minY, double &maxX, double &maxY);

void extractExtents(Curve* reactionCurve, double &minX, double &minY, double &maxX, double &maxY);

std::vector<LockedNodeInfo> getLockedNodesInfo(Layout* layout, const std::vector<std::string>& lockedNodeIds, const bool& resetLockedNodes = false);

void unlockNodes(Layout *layout);

LockedNodeInfo createLockedNodeInfo(SpeciesGlyph *speciesGlyph);

}

#endif

