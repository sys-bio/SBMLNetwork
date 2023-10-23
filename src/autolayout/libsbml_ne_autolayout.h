#ifndef __LIBSBML_NE_AUTOLAYOUT_H_
#define __LIBSBML_NE_AUTOLAYOUT_H_

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

void locateGlyphs(Model* model, Layout* layout);

void randomizeGlyphLocations(Model* model, Layout* layout);

void randomizeSpeciesGlyphsLocations(Model* model, Layout* layout, const double& canvasWidth, const double& canvasHeight, const double& padding);

void randomizeReactionGlyphsLocations(Model* model, Layout* layout, const double& canvasWidth, const double& canvasHeight, const double& padding);

void initializeCompartmentGlyphExtents(BoundingBox* compartmentGlyphBoundingBox, BoundingBox* speciesGlyphBoundingBox, const double& padding);

void updateCompartmentExtents(BoundingBox* compartmentGlyphBoundingBox, BoundingBox* speciesGlyphBoundingBox, const double& padding);

void updateCompartmentExtents(BoundingBox* compartmentGlyphBoundingBox, Curve* reactionCurve, const double& padding);

void randomizeBoundingBoxValues(BoundingBox* boundingBox, const double& canvasWidth, const double& canvasHeight);

void randomizeCurveCenterPoint(Curve* curve, const double& canvasWidth, const double& canvasHeight);

void applyAutolayout(Model* model, Layout* layout);

}

#endif

