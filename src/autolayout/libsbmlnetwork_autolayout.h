#ifndef __LIBSBMLNETWORK_AUTOLAYOUT_H_
#define __LIBSBMLNETWORK_AUTOLAYOUT_H_

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE  {

void locateGlyphs(Model* model, Layout* layout, const bool& useNameAsTextLabel = true);

void locateReactions(Model *model, Layout *layout, const bool& useNameAsTextLabel = false);

const double getStiffness(Layout *layout);

void setStiffness(Layout *layout, const double& stiffness);

const double getGravity(Layout *layout);

void setGravity(Layout *layout, const double& gravity);

void randomizeGlyphsLocations(Model* model, Layout* layout);

void randomizeSpeciesGlyphsLocations(Model* model, Layout* layout, const double& canvasWidth, const double& canvasHeight);

void randomizeReactionGlyphsLocations(Model* model, Layout* layout, const double& canvasWidth, const double& canvasHeight);

void randomizeBoundingBoxesPosition(BoundingBox* boundingBox, const double& canvasWidth, const double& canvasHeight);

void randomizeCurveCenterPoint(Curve* curve, const double& canvasWidth, const double& canvasHeight);

void setGlyphsDimensions(Model *model, Layout *layout);

void setSpeciesGlyphDimensions(Model *model, SpeciesGlyph* speciesGlyph);

void initializeCompartmentGlyphExtents(BoundingBox* compartmentGlyphBoundingBox, BoundingBox* speciesGlyphBoundingBox);

void updateCompartmentExtents(Model *model, Layout *layout);

void updateCompartmentExtents(BoundingBox* compartmentGlyphBoundingBox, BoundingBox* speciesGlyphBoundingBox);

void updateCompartmentExtents(BoundingBox* compartmentGlyphBoundingBox, Curve* reactionCurve);

void updateLayoutDimensions(Layout* layout);

const bool adjustLayoutDimensions(Layout *layout);

const bool autolayoutMayStillConverge(const double &stiffness, const double &gravity);

void extractExtents(Layout* layout, double &maxX, double &maxY);

void extractExtents(BoundingBox* boundingBox, double &minX, double &minY, double &maxX, double &maxY);

void extractExtents(Curve* reactionCurve, double &minX, double &minY, double &maxX, double &maxY);

}

#endif

