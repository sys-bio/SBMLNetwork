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

void updateStiffness(Layout *layout);

double getStiffnessAdjustmentFactor(Layout *layout);

const double getGravity(Layout *layout);

void setGravity(Layout *layout, const double& gravity);

void updateGravity(Layout *layout);

double getGravityAdjustmentFactor(Layout *layout);

double getCurrentDimensionToDesiredDimensionRatio(Layout *layout);

double getDesiredDimensionToCurrentDimensionRatio(Layout *layout);

void randomizeGlyphsLocations(Model* model, Layout* layout);

void randomizeSpeciesGlyphsLocations(Model* model, Layout* layout, const double& canvasWidth, const double& canvasHeight);

void randomizeReactionGlyphsLocations(Model* model, Layout* layout, const double& canvasWidth, const double& canvasHeight);

void randomizeBoundingBoxesPosition(BoundingBox* boundingBox, const double& canvasWidth, const double& canvasHeight);

void randomizeCurveCenterPoint(Curve* curve, const double& canvasWidth, const double& canvasHeight);

void setGlyphsDimensions(Model *model, Layout *layout);

void setSpeciesGlyphDimensions(Model *model, SpeciesGlyph* speciesGlyph);

void initializeCompartmentGlyphExtents(BoundingBox* compartmentGlyphBoundingBox, BoundingBox* speciesGlyphBoundingBox);

void updateCompartmentExtents(Model *model, Layout *layout);

void updateCompartmentExtentsUsingItsElementsExtents(Model *model, Layout *layout);

void updateCompartmentExtentsUsingItsElementsExtents(BoundingBox* compartmentGlyphBoundingBox, BoundingBox* speciesGlyphBoundingBox);

void updateCompartmentExtentsUsingItsElementsExtents(BoundingBox* compartmentGlyphBoundingBox, Curve* reactionCurve);

void updateCompartmentExtentsUsingItsPresetAttributes(Layout *layout);

void updateLayoutDimensions(Layout* layout);

const bool adjustLayoutDimensions(Layout *layout);

const double getLayoutDimensionsDesiredWidth(Layout *layout);

void setLayoutDimensionsDesiredWidth(Layout *layout, const double& width);

const double getLayoutDimensionsDesiredHeight(Layout *layout);

void setLayoutDimensionsDesiredHeight(Layout *layout, const double& height);

const bool autolayoutMayStillConverge(Layout *layout);

void extractExtents(Layout* layout, double &maxX, double &maxY);

void extractExtents(BoundingBox* boundingBox, double &minX, double &minY, double &maxX, double &maxY);

void extractExtents(Curve* reactionCurve, double &minX, double &minY, double &maxX, double &maxY);

}

#endif

