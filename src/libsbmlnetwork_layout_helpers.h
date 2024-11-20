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

void lockGraphicalObjects(Layout* layout, std::set<std::pair<std::string, int> > lockedNodesSet, const bool resetLockedElements);

void lockCompartmentGlyphs(Layout* layout, const bool resetLockedElements);

void lockSpeciesGlyphs(Layout* layout, std::set<std::pair<std::string, int> > lockedNodesSet, const bool resetLockedElements);

void lockReactionGlyphs(Layout* layout, std::set<std::pair<std::string, int> > lockedNodesSet, const bool resetLockedElements);

void lockGraphicalObject(GraphicalObject* graphicalObject);

void unlockGraphicalObject(GraphicalObject* graphicalObject);

std::vector<GraphicalObject*> getLockedGraphicalObjects(std::vector<GraphicalObject*> graphicalObjects);

void fixGraphicalObjectWidth(GraphicalObject* graphicalObject);

void unfixGraphicalObjectWidth(GraphicalObject* graphicalObject);

void fixGraphicalObjectHeight(GraphicalObject* graphicalObject);

void unfixGraphicalObjectHeight(GraphicalObject* graphicalObject);

void clearGraphicalObjects(Layout* layout);

void clearCompartmentGlyphs(Layout* layout);

void clearSpeciesGlyphs(Layout* layout);

void clearReactionGlyphs(Layout* layout);

void clearReactionGlyphSpeciesReferenceGlyphs(ReactionGlyph* reactionGlyph);

void setCompartmentGlyphs(Model* model, Layout* layout, const std::vector<std::map<std::string, std::string>>& userData = {});

void setReactionGlyphs(Model* model, Layout* layout, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData = {});

void setReactantGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData);

void setProductGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData);

void setModifierGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData);

void setEmptySpeciesReferenceGlyphs(Model* model, Layout* layout, ReactionGlyph* reactionGlyph, const std::vector<std::map<std::string, std::string>>& userData = {});

SpeciesReferenceGlyph* createEmptySpeciesReferenceGlyph(Model* model, Layout* layout, ReactionGlyph* reactionGlyph);

SpeciesGlyph* createEmptySpeciesGlyph(Model* model, Layout* layout, ReactionGlyph* reactionGlyph);

SpeciesGlyph* createEmptySpeciesGlyph(ReactionGlyph* reactionGlyph);

SpeciesReferenceGlyph* createEmptySpeciesReferenceGlyph(Layout* layout, ReactionGlyph* reactionGlyph, SpeciesGlyph* EmptySpeciesGlyph);

bool isSetEmptySpeciesGlyph(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph);

const std::string getEmptySpeciesGlyphId(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph);

SpeciesGlyph* getSpeciesGlyph(Layout* layout, const std::string& speciesId, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData);

int setSpeciesGlyphIndexInReactionGlyph(Layout* layout, const std::string speciesId, ReactionGlyph* reactionGlyph, const unsigned int index);

std::vector<SpeciesReferenceGlyph*> getConnectedSpeciesGlyphReferences(Layout* layout, SpeciesGlyph* speciesGlyph);

void setTextGlyphs(Layout* layout);

void clearTextGlyphs(Layout* layout);

void clearReactionTextGlyphs(Layout* layout);

void setCompartmentTextGlyphs(Layout* layout);

void setSpeciesTextGlyphs(Layout* layout);

void setReactionTextGlyphs(Layout* layout);

CompartmentGlyph* createCompartmentGlyph(Layout* layout, const std::string& compartmentId, const std::vector<std::map<std::string, std::string>>& userData = {});

SpeciesGlyph* createSpeciesGlyph(Layout* layout, const std::string& speciesId, const std::vector<std::map<std::string, std::string>>& userData = {});

SpeciesGlyph* createEmptySpeciesGlyph(Layout* layout, const std::string& reactionGlyphId);

ReactionGlyph* createReactionGlyph(Layout* layout, const std::string& reactionId, const std::vector<std::map<std::string, std::string>>& userData = {});

SpeciesReferenceGlyph* createSpeciesReferenceGlyph(Layout* layout, ReactionGlyph* reactionGlyph, const std::string& speciesId, unsigned int stoichiometryIndex, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData = {});

SpeciesReferenceGlyph* createSpeciesReferenceGlyph(ReactionGlyph* reactionGlyph, const std::string& speciesId, unsigned int stoichiometryIndex);

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

void setSpeciesReferenceGlyphCurve(SpeciesReferenceGlyph* speciesReferenceGlyph, SpeciesReferenceGlyph* referenceSpeciesReferenceGlyph);

void setSpeciesReferenceGlyphCurve(SpeciesReferenceGlyph* speciesReferenceGlyph);

int removeReactionGlyphCurve(ReactionGlyph* reactionGlyph);

void setTextGlyphBoundingBox(TextGlyph* textGlyph, GraphicalObject* graphicalObject, const double& padding = 0.0);

void addCurveSegment(Curve* curve, LineSegment* referenceLineSegment, const double& padding);

void setCurveCubicBezier(Curve* curve, const double& x = 0.0, const double& y = 0.0);

Compartment* findCompartmentGlyphCompartment(Model* model, CompartmentGlyph* compartmentGlyph);

Compartment* findSpeciesGlyphCompartment(Model* model, SpeciesGlyph* speciesGlyph);

Species* findSpeciesGlyphSpecies(Model* model, SpeciesGlyph* speciesGlyph);

Compartment* findReactionGlyphCompartment(Model* model, ReactionGlyph* reactionGlyph);

Reaction* findReactionGlyphReaction(Model* model, ReactionGlyph* reactionGlyph);

SimpleSpeciesReference* findSpeciesReference(Model* model, Layout* layout, ReactionGlyph* reactionGlyph, SpeciesGlyph* speciesGlyph);

bool containsSpecies(Model* model, Layout* layout, CompartmentGlyph* compartmentGlyph);

bool compartmentGlyphBelongs(CompartmentGlyph* compartmentGlyph, Compartment* compartment);

bool speciesGlyphBelongs(SpeciesGlyph* speciesGlyph, Species* species);

bool reactionGlyphBelongs(ReactionGlyph* reactionGlyph, Reaction* reaction);

const std::string getSpeciesReferenceGlyphSpeciesId(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph);

bool textGlyphBelongs(TextGlyph* textGlyph, GraphicalObject* graphicalObject);

bool graphicalObjectBelongsToReactionGlyph(Layout* layout, ReactionGlyph* reactionGlyph, GraphicalObject* graphicalObject);

std::vector<TextGlyph*> getAssociatedTextGlyphsWithGraphicalObject(Layout* layout, GraphicalObject* graphicalObject);

GraphicalObject* getGraphicalObjectUsingItsOwnId(Layout* layout, const std::string& graphicalObjectId);

const std::string getEntityId(GraphicalObject* graphicalObject);

std::vector<CompartmentGlyph*> getCompartmentGlyphs(Layout* layout);

std::vector<CompartmentGlyph*> getAssociatedCompartmentGlyphsWithCompartmentId(Layout* layout, const std::string& compartmentId);

std::vector<SpeciesGlyph*> getSpeciesGlyphs(Layout* layout);

std::vector<SpeciesGlyph*> getAssociatedSpeciesGlyphsWithSpeciesId(Layout* layout, const std::string& speciesId);

std::vector<ReactionGlyph*> getReactionGlyphs(Layout* layout);

std::vector<ReactionGlyph*> getAssociatedReactionGlyphsWithReactionId(Layout* layout, const std::string& reactionId);

std::vector<SpeciesReferenceGlyph*> getSpeciesReferenceGlyphs(ReactionGlyph* reactionGlyph);

const std::string getTextGlyphUniqueId(Layout* layout, GraphicalObject* graphicalObject);

const std::string getCompartmentGlyphId(Layout* layout, const std::string compartmentId);

const std::string getSpeciesGlyphId(Layout* layout, const std::string speciesId);

const std::string getReactionGlyphId(Layout* layout, const std::string reactionId);

const std::string getSpeciesReferenceGlyphId(ReactionGlyph* reactionGlyph, const std::string speciesGlyphId, unsigned int stoichiometryIndex = 0);

const std::string getIdOfSpeciesReferenceGlyphConnectedToNewSpeciesGlyph(std::string speciesReferenceGlyphId, const std::string& originalSpeciesGlyphId, const std::string& aliasSpeciesGlyphId);

const bool layoutContainsGlyphs(Layout* layout);

const bool isGraphicalObject(SBase* sbase);

const int getStoichiometryAsInteger(SpeciesReferenceGlyph* speciesReferenceGlyph);

const int getStoichiometryAsInteger(SimpleSpeciesReference* speciesReference);

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

