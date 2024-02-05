#ifndef __LIBSBML_NE_AUTOLAYOUT_H_
#define __LIBSBML_NE_AUTOLAYOUT_H_

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

void locateGlyphs(Model* model, Layout* layout, const double& stiffness = 10.0, const double& gravity = 15.0,
                  const bool& useMagnetism = false, const bool& useBoundary = false, const bool& useGrid = false,
                  const std::vector<std::string>& lockedNodeIds = std::vector<std::string>());

void randomizeGlyphsLocations(Model* model, Layout* layout, const double &padding, const std::vector<std::string>& lockedNodeIds);

void randomizeSpeciesGlyphsLocations(Model* model, Layout* layout, const double& canvasWidth, const double& canvasHeight, const double& padding, const std::vector<std::string>& lockedNodeIds);

void randomizeReactionGlyphsLocations(Model* model, Layout* layout, const double& canvasWidth, const double& canvasHeight, const double& padding, const std::vector<std::string>& lockedNodeIds);

void randomizeBoundingBoxesPosition(BoundingBox* boundingBox, const double& canvasWidth, const double& canvasHeight);

void randomizeCurveCenterPoint(Curve* curve, const double& canvasWidth, const double& canvasHeight);

void setGlyphsDimensions(Model *model, Layout *layout);

void setSpeciesGlyphDimensions(Model *model, SpeciesGlyph* speciesGlyph);

const double calculateSpeciesGlyphDefaultWidth(Model *model, SpeciesGlyph* speciesGlyph);

const double calculateSpeciesGlyphDefaultHeight(SpeciesGlyph* speciesGlyph, const double& speciesWidth);

void applyAutolayout(Model* model, Layout* layout, const double& stiffness = 10.0, const double& gravity = 15.0,
                     const bool& useMagnetism = false, const bool& useBoundary = false, const bool& useGrid = false,
                     const std::vector <std::string> &lockedNodeIds = std::vector<std::string>());

void initializeCompartmentGlyphExtents(BoundingBox* compartmentGlyphBoundingBox, BoundingBox* speciesGlyphBoundingBox, const double& padding);

void updateCompartmentExtents(Model *model, Layout *layout, const double &padding);

void updateCompartmentExtents(BoundingBox* compartmentGlyphBoundingBox, BoundingBox* speciesGlyphBoundingBox, const double& padding);

void updateCompartmentExtents(BoundingBox* compartmentGlyphBoundingBox, Curve* reactionCurve, const double& padding);

}

#endif

