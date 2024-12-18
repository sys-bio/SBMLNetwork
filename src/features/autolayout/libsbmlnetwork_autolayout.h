#ifndef __LIBSBMLNETWORK_AUTOLAYOUT_H_
#define __LIBSBMLNETWORK_AUTOLAYOUT_H_

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE  {

void autolayout_locateGlyphs(Model* model, Layout* layout);

void autolayout_locateReactions(Model *model, Layout *layout);

const double autolayout_getStiffness(Layout *layout);

void autolayout_setStiffness(Layout *layout, const double& stiffness);

const double autolayout_getGravity(Layout *layout);

void autolayout_setGravity(Layout *layout, const double& gravity);

const int autolayout_getNumberOfAutoLayoutParametersResets(Layout *layout);

void autolayout_randomizeGlyphsLocations(Model* model, Layout* layout);

void autolayout_randomizeSpeciesGlyphsLocations(Model* model, Layout* layout, const double& canvasWidth, const double& canvasHeight);

void autolayout_randomizeReactionGlyphsLocations(Model* model, Layout* layout, const double& canvasWidth, const double& canvasHeight);

void autolayout_randomizeBoundingBoxesPosition(BoundingBox* boundingBox, const double& canvasWidth, const double& canvasHeight);

void autolayout_randomizeCurveCenterPoint(Curve* curve, const double& canvasWidth, const double& canvasHeight);

void autolayout_setGlyphsDimensions(Model *model, Layout *layout);

void autolayout_setSpeciesGlyphDimensions(Model *model, SpeciesGlyph* speciesGlyph);

void autolayout_initializeCompartmentGlyphExtents(BoundingBox* compartmentGlyphBoundingBox, BoundingBox* speciesGlyphBoundingBox);

void autolayout_updateCompartmentsExtents(Model *model, Layout *layout);

void autolayout_updateCompartmentsExtentsUsingTheirElementsExtents(Model *model, Layout *layout);

void autolayout_updateCompartmentExtentsUsingItsElementsExtents(BoundingBox* compartmentGlyphBoundingBox, BoundingBox* speciesGlyphBoundingBox);

void autolayout_updateCompartmentExtentsUsingItsElementsExtents(BoundingBox* compartmentGlyphBoundingBox, Curve* reactionCurve);

void autolayout_updateCompartmentsExtentsUsingTheirPresetAttributes(Layout *layout);

void autolayout_updateLayoutDimensions(Layout* layout);

void autolayout_extractExtents(Layout* layout, double &maxX, double &maxY);

void autolayout_extractExtents(BoundingBox* boundingBox, double &minX, double &minY, double &maxX, double &maxY);

void autolayout_extractExtents(Curve* reactionCurve, double &minX, double &minY, double &maxX, double &maxY);

}

#endif

