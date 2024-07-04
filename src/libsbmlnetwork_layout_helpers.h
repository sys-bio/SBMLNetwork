#ifndef __LIBSBMLNETWORK_LAYOUT_HELPERS_H_
#define __LIBSBMLNETWORK_LAYOUT_HELPERS_H_

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE  {

LayoutModelPlugin* getLayoutModelPlugin(SBMLDocument* document);

LayoutModelPlugin* enableAndGetLayoutModelPlugin(SBMLDocument* document);

SBasePlugin* getLayoutPlugin(SBMLDocument* document);

LayoutModelPlugin* getLayoutModelPlugin(SBasePlugin* layoutBase);

void enableLayoutPlugin(SBMLDocument* document);

LayoutPkgNamespaces* getLayoutPkgNamespaces(Layout* layout);

void setDefaultLayoutId(Layout* layout);

void setDefaultLayoutDimensions(Layout* layout);

void setCompartmentGlyphs(Model* model, Layout* layout);

void setSpeciesGlyphs(Model* model, Layout* layout);

void setReactionGlyphs(Model* model, Layout* layout);

void setReactantGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph);

void setProductGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph);

void setModifierGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph);

SpeciesReferenceGlyph* getDummySpeciesReferenceGlyph(Model* model, Layout* layout, ReactionGlyph* reactionGlyph);

SpeciesGlyph* getDummySpeciesGlyph(Model* model, Layout* layout, ReactionGlyph* reactionGlyph);

SpeciesGlyph* getDummySpeciesGlyph(ReactionGlyph* reactionGlyph);

SpeciesReferenceGlyph* getDummySpeciesReferenceGlyph(Layout* layout, ReactionGlyph* reactionGlyph, SpeciesGlyph* dummySpeciesGlyph);

void setCompartmentTextGlyphs(Layout* layout);

void setSpeciesTextGlyphs(Layout* layout);

void setReactionTextGlyphs(Layout* layout);

CompartmentGlyph* getCompartmentGlyph(Layout* layout, Compartment* compartment);

SpeciesGlyph* getSpeciesGlyph(Layout* layout, Species* species);

ReactionGlyph* getReactionGlyph(Layout* layout, Reaction* reaction);

CompartmentGlyph* getCompartmentGlyphOfReactionGlyph(Model* model, Layout* layout, ReactionGlyph* reactionGlyph);

CompartmentGlyph* getDefaultCompartmentGlyph(Layout* layout);

SpeciesReferenceGlyph* getAssociatedSpeciesReferenceGlyph(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, SimpleSpeciesReference* speciesReference);

const int getNumSpeciesReferencesAssociatedWithSpecies(Reaction* reaction, const std::string& speciesId);

const int getNumSpeciesReferencesGlyphsAssociatedWithSpecies(Layout* layout, ReactionGlyph* reactionGlyph, const std::string& speciesId);

TextGlyph* getAssociatedTextGlyph(Layout* layout, GraphicalObject* graphicalObject);

void setGraphicalObjectBoundingBox(GraphicalObject* graphicalObject);

void setTextGlyphBoundingBox(TextGlyph* textGlyph, GraphicalObject* graphicalObject, const double& padding = 0.0);

void setReactionGlyphCurve(ReactionGlyph* reactionGlyph);

void clearReactionGlyphSpeciesReferenceGlyphs(ReactionGlyph* reactionGlyph);

void removeReactionGlyphCurve(ReactionGlyph* reactionGlyph);

void setSpeciesReferenceGlyphCurve(SpeciesReferenceGlyph* speciesReferenceGlyph);

void setCurveCubicBezier(Curve* curve);

Compartment* findCompartmentGlyphCompartment(Model* model, CompartmentGlyph* compartmentGlyph);

Compartment* findSpeciesGlyphCompartment(Model* model, SpeciesGlyph* speciesGlyph);

Species* findSpeciesGlyphSpecies(Model* model, SpeciesGlyph* speciesGlyph);

Compartment* findReactionGlyphCompartment(Model* model, ReactionGlyph* reactionGlyph);

Reaction* findReactionGlyphReaction(Model* model, ReactionGlyph* reactionGlyph);

bool containsSpecies(Model* model, Layout* layout, CompartmentGlyph* compartmentGlyph);

bool compartmentGlyphBelongs(CompartmentGlyph* compartmentGlyph, Compartment* compartment);

bool speciesGlyphBelongs(SpeciesGlyph* speciesGlyph, Species* species);

bool reactionGlyphBelongs(ReactionGlyph* reactionGlyph, Reaction* reaction);

const std::string getSpeciesReferenceGlyphSpeciesId(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph);

bool textGlyphBelongs(TextGlyph* textGlyph, GraphicalObject* graphicalObject);

bool graphicalObjectBelongsToReactionGlyph(Layout* layout, ReactionGlyph* reactionGlyph, GraphicalObject* graphicalObject);

std::vector<TextGlyph*> getAssociatedTextGlyphsWithGraphicalObject(Layout* layout, GraphicalObject* graphicalObject);

GraphicalObject* getGraphicalObjectUsingItsOwnId(Layout* layout, const std::string& graphicalObjectId);

std::vector<std::string> getGraphicalObjectsIdsWhosePositionIsNotDependentOnGraphicalObject(Layout* layout, std::vector<GraphicalObject*> graphicalObjects);

std::vector<std::string> getGraphicalObjectsIdsWhosePositionIsNotDependentOnGraphicalObject(Layout* layout, GraphicalObject* graphicalObject);

const std::string getEntityId(Layout* layout, GraphicalObject* graphicalObject);

std::vector<CompartmentGlyph*> getCompartmentGlyphs(Layout* layout);

std::vector<CompartmentGlyph*> getAssociatedCompartmentGlyphsWithCompartmentId(Layout* layout, const std::string& compartmentId);

std::vector<SpeciesGlyph*> getSpeciesGlyphs(Layout* layout);

std::vector<SpeciesGlyph*> getAssociatedSpeciesGlyphsWithSpeciesId(Layout* layout, const std::string& speciesId);

std::vector<ReactionGlyph*> getReactionGlyphs(Layout* layout);

std::vector<ReactionGlyph*> getAssociatedReactionGlyphsWithReactionId(Layout* layout, const std::string& reactionId);

std::vector<SpeciesReferenceGlyph*> getSpeciesReferenceGlyphs(ReactionGlyph* reactionGlyph);

std::vector<SpeciesReferenceGlyph*> getAssociatedSpeciesReferenceGlyphsWithReactionGlyph(ReactionGlyph* reactionGlyph);

const std::string getTextGlyphUniqueId(Layout* layout, GraphicalObject* graphicalObject);

const bool layoutContainsGlyphs(Layout* layout);

void alignGraphicalObjects(std::vector<GraphicalObject*> graphicalObjects, const std::string& alignment);

void alignGraphicalObjectsToTop(std::vector<GraphicalObject*> graphicalObjects);

void alignGraphicalObjectsToCenter(std::vector<GraphicalObject*> graphicalObjects);

void alignGraphicalObjectsToBottom(std::vector<GraphicalObject*> graphicalObjects);

void alignGraphicalObjectsToLeft(std::vector<GraphicalObject*> graphicalObjects);

void alignGraphicalObjectsToMiddle(std::vector<GraphicalObject*> graphicalObjects);

void alignGraphicalObjectsToRight(std::vector<GraphicalObject*> graphicalObjects);

void alignGraphicalObjectsCircularly(std::vector<GraphicalObject*> graphicalObjects);

void distributeGraphicalObjects(std::vector<GraphicalObject*> graphicalObjects, const std::string& direction, const double& spacing);

void distributeGraphicalObjectsHorizontally(std::vector<GraphicalObject*> graphicalObjects, const double& spacing);

void distributeEvenGraphicalObjectsHorizontally(std::vector<GraphicalObject*> graphicalObjects, const double& minX, const double& maxX, const double& distance);

void distributeOddGraphicalObjectsHorizontally(std::vector<GraphicalObject*> graphicalObjects, const double& minX, const double& maxX, const double& distance);

void distributeGraphicalObjectsVertically(std::vector<GraphicalObject*> graphicalObjects, const double& spacing);

void distributeEvenGraphicalObjectsVertically(std::vector<GraphicalObject*> graphicalObjects, const double& minY, const double& maxY, const double& distance);

void distributeOddGraphicalObjectsVertically(std::vector<GraphicalObject*> graphicalObjects, const double& minY, const double& maxY, const double& distance);

const double findDistributionDistance(const double& minPosition, const double& maxPosition, const unsigned int& numGraphicalObjects, const double& spacing);

const double getMinPositionX(std::vector<GraphicalObject*> graphicalObjects);

const double getMinPositionY(std::vector<GraphicalObject*> graphicalObjects);

const double getMaxPositionX(std::vector<GraphicalObject*> graphicalObjects);

const double getMaxPositionY(std::vector<GraphicalObject*> graphicalObjects);

const double getMinCenterX(std::vector<GraphicalObject*> graphicalObjects);

const double getMinCenterY(std::vector<GraphicalObject*> graphicalObjects);

const double getMaxCenterX(std::vector<GraphicalObject*> graphicalObjects);

const double getMaxCenterY(std::vector<GraphicalObject*> graphicalObjects);

const bool isValidLayoutDimensionWidthValue(const double& width);

const bool isValidLayoutDimensionHeightValue(const double& height);

const bool isValidRoleValue(const std::string& role);

const bool isValidBoundingBoxXValue(const double& x);

const bool isValidBoundingBoxYValue(const double& y);

const bool isValidBoundingBoxWidthValue(const double& width);

const bool isValidBoundingBoxHeightValue(const double& height);

const bool isValidCurveSegmentStartPointXValue(const double& x);

const bool isValidCurveSegmentStartPointYValue(const double& y);

const bool isValidCurveSegmentEndPointXValue(const double& x);

const bool isValidCurveSegmentEndPointYValue(const double& y);

const bool isValidCurveSegmentBasePoint1XValue(const double& x);

const bool isValidCurveSegmentBasePoint1YValue(const double& y);

const bool isValidCurveSegmentBasePoint2XValue(const double& x);

const bool isValidCurveSegmentBasePoint2YValue(const double& y);

const bool isValidDimensionValue(const double& dimensionValue);

const bool isValidAlignment(const std::string& alignment);

const bool isValidDistributionDirection(const std::string& direction);

std::vector<std::string> getValidRoleValues();

std::vector<std::string> getValidAlignmentValues();

std::vector<std::string> getValidDistributionDirectionValues();

}

#endif

