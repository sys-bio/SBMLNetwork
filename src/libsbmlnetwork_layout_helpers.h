#ifndef __LIBSBMLNETWORK_LAYOUT_HELPERS_H_
#define __LIBSBMLNETWORK_LAYOUT_HELPERS_H_

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

#include <set>

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE  {

LayoutModelPlugin* getLayoutModelPlugin(SBMLDocument* document);

LayoutModelPlugin* enableAndGetLayoutModelPlugin(SBMLDocument* document);

SBasePlugin* getLayoutPlugin(SBMLDocument* document);

LayoutModelPlugin* getLayoutModelPlugin(SBasePlugin* layoutBase);

void enableLayoutPlugin(SBMLDocument* document);

bool isSetEmptySpeciesGlyph(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph);

const std::string getEmptySpeciesGlyphId(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph);

int setSpeciesGlyphIndexInReactionGlyph(Layout* layout, const std::string speciesId, ReactionGlyph* reactionGlyph, const unsigned int index);

CompartmentGlyph* getCompartmentGlyphOfReactionGlyph(Model* model, Layout* layout, ReactionGlyph* reactionGlyph);

CompartmentGlyph* getDefaultCompartmentGlyph(Layout* layout);

std::vector<SpeciesReferenceGlyph*> getSpeciesReferencesAssociatedWithSpecies(Layout* layout, const std::string& speciesId);

std::vector<SpeciesReferenceGlyph*> getSpeciesReferencesAssociatedWithSpeciesGlyph(Layout* layout, const std::string& speciesGlyphId);

std::vector<SpeciesReferenceGlyph*> getSpeciesReferencesAssociatedWithSpecies(Layout* layout, ReactionGlyph* reactionGlyph, const std::string& speciesId);

std::vector<SpeciesReferenceGlyph*> getSpeciesReferencesAssociatedWithSpeciesGlyph(Layout* layout, ReactionGlyph* reactionGlyph, const std::string& speciesGlyphId);

const int getSpeciesReferenceIndex(Layout* layout, ReactionGlyph* reactionGlyph, SpeciesReferenceGlyph* speciesReferenceGlyph);

const int getIndexOfConnectedSpeciesGlyph(std::vector<SpeciesReferenceGlyph*> speciesReferenceGlyphs, std::vector<SpeciesGlyph*> speciesGlyphs);

TextGlyph* createAssociatedTextGlyph(Layout* layout, GraphicalObject* graphicalObject);

void setGraphicalObjectBoundingBox(GraphicalObject* graphicalObject);

void setReactionGlyphCurve(ReactionGlyph* reactionGlyph);

int removeReactionGlyphCurve(ReactionGlyph* reactionGlyph);

void setTextGlyphBoundingBox(TextGlyph* textGlyph, GraphicalObject* graphicalObject, const double& padding = 0.0);

Compartment* findCompartmentGlyphCompartment(Model* model, CompartmentGlyph* compartmentGlyph);

Compartment* findSpeciesGlyphCompartment(Model* model, SpeciesGlyph* speciesGlyph);

Species* findSpeciesGlyphSpecies(Model* model, SpeciesGlyph* speciesGlyph);

Compartment* findReactionGlyphCompartment(Model* model, ReactionGlyph* reactionGlyph);

Reaction* findReactionGlyphReaction(Model* model, ReactionGlyph* reactionGlyph);

SimpleSpeciesReference* findSpeciesReference(Model* model, Layout* layout, ReactionGlyph* reactionGlyph, SpeciesGlyph* speciesGlyph);

ReactionGlyph* findSpeciesReferenceReactionGlyph(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph);

bool containsSpecies(Model* model, Layout* layout, CompartmentGlyph* compartmentGlyph);

bool compartmentGlyphBelongs(CompartmentGlyph* compartmentGlyph, Compartment* compartment);

bool speciesGlyphBelongs(SpeciesGlyph* speciesGlyph, Species* species);

bool reactionGlyphBelongs(ReactionGlyph* reactionGlyph, Reaction* reaction);

const std::string getSpeciesReferenceGlyphSpeciesId(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph);

bool textGlyphBelongs(TextGlyph* textGlyph, GraphicalObject* graphicalObject);

std::vector<TextGlyph*> getAssociatedTextGlyphsWithGraphicalObject(Layout* layout, GraphicalObject* graphicalObject);

GraphicalObject* getGraphicalObjectUsingItsOwnId(Layout* layout, const std::string& graphicalObjectId);

int removeGraphicalObjectUsingItsOwnId(Layout* layout, const std::string& graphicalObjectId);

const std::string getEntityId(GraphicalObject* graphicalObject);

std::vector<CompartmentGlyph*> getCompartmentGlyphs(Layout* layout);

std::vector<CompartmentGlyph*> getAssociatedCompartmentGlyphsWithCompartmentId(Layout* layout, const std::string& compartmentId);

std::vector<SpeciesGlyph*> getSpeciesGlyphs(Layout* layout);

std::vector<SpeciesGlyph*> getAssociatedSpeciesGlyphsWithSpeciesId(Layout* layout, const std::string& speciesId);

std::vector<ReactionGlyph*> getReactionGlyphs(Layout* layout);

std::vector<ReactionGlyph*> getAssociatedReactionGlyphsWithReactionId(Layout* layout, const std::string& reactionId);

std::vector<SpeciesReferenceGlyph*> getSpeciesReferenceGlyphs(ReactionGlyph* reactionGlyph);

const std::string getTextGlyphUniqueId(Layout* layout, GraphicalObject* graphicalObject);

const std::string getIdOfSpeciesReferenceGlyphConnectedToNewSpeciesGlyph(std::string speciesReferenceGlyphId, const std::string& originalSpeciesGlyphId, const std::string& aliasSpeciesGlyphId);

const bool layoutContainsGlyphs(Layout* layout);

const bool isGraphicalObject(SBase* sbase);

const bool isUniUniReaction(Model* model, ReactionGlyph* reactionGlyph);

const bool isUniUniReaction(Reaction* reaction);

const int getStoichiometryAsInteger(Layout* layout, SimpleSpeciesReference* speciesReference);

void updateAssociatedTextGlyphsPositionX(Layout* layout, GraphicalObject* graphicalObject, const double& movedDistanceX);

void updateAssociatedTextGlyphsPositionY(Layout* layout, GraphicalObject* graphicalObject, const double& movedDistanceY);

void updateAssociatedTextGlyphsPosition(Layout* layout, GraphicalObject* graphicalObject, const double& movedDistanceX, const double& movedDistanceY);

void updateAssociatedTextGlyphsPosition(Layout* layout, GraphicalObject* graphicalObject, const double& movedDistanceX, const double& movedDistanceY);

void updateAssociatedTextGlyphsDimensionWidth(Layout* layout, GraphicalObject* graphicalObject, const double& changedWidth);

void updateAssociatedTextGlyphsDimensionHeight(Layout* layout, GraphicalObject* graphicalObject, const double& changedHeight);

const double getCurveMiddlePositionX(Curve* curve);

const double getCurveMiddlePositionY(Curve* curve);

int setCurveMiddlePositionX(Curve* curve, const double& x);

int setCurveMiddlePositionY(Curve* curve, const double& y);

int updateGraphicalObjectId(Layout* layout, GraphicalObject* graphicalObject, const std::string& newId);

int updateSpeciesReferenceGlyphSpeciesGlyphId(SpeciesReferenceGlyph* speciesReferenceGlyph, const std::string& originalSpeciesGlyphId, const std::string& newSpeciesGlyphId);

int updateSpeciesReferenceGlyphReactionGlyphId(SpeciesReferenceGlyph* speciesReferenceGlyph, const std::string& originalReactionGlyphId, const std::string& newReactionGlyphId);

int updateTextGlyphGraphicalObjectId(TextGlyph* textGlyph, const std::string& originalGraphicalObjectId, const std::string& newGraphicalObjectId);

const bool isValidLayoutDimensionWidthValue(const double& width, SBase* sBase = NULL);

const bool isValidLayoutDimensionHeightValue(const double& height, SBase* sBase = NULL);

const bool isValidRoleValue(const std::string& role, SBase* sBase = NULL);

const bool isValidBoundingBoxXValue(const double& x, SBase* sBase = NULL);

const bool isValidBoundingBoxYValue(const double& y, SBase* sBase = NULL);

const bool isValidBoundingBoxWidthValue(const double& width, SBase* sBase = NULL);

const bool isValidBoundingBoxHeightValue(const double& height, SBase* sBase = NULL);

const bool isValidCurveSegmentStartPointXValue(const double& x, SBase* sBase = NULL);

const bool isValidCurveSegmentStartPointYValue(const double& y, SBase* sBase = NULL);

const bool isValidCurveSegmentEndPointXValue(const double& x, SBase* sBase = NULL);

const bool isValidCurveSegmentEndPointYValue(const double& y, SBase* sBase = NULL);

const bool isValidCurveSegmentBasePoint1XValue(const double& x, SBase* sBase = NULL);

const bool isValidCurveSegmentBasePoint1YValue(const double& y, SBase* sBase = NULL);

const bool isValidCurveSegmentBasePoint2XValue(const double& x, SBase* sBase = NULL);

const bool isValidCurveSegmentBasePoint2YValue(const double& y, SBase* sBase = NULL);

const bool isValidDimensionValue(const double& dimension, SBase* sBase = NULL);

const bool isValidDoubleValue(const double& value, SBase* sBase = NULL);

std::vector<std::string> getValidRoleValues();

}

#endif

