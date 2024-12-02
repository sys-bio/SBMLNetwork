#ifndef __LIBSBMLNETWORK_SET_LAYOUT_FEATURES_H
#define __LIBSBMLNETWORK_SET_LAYOUT_FEATURES_H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

#include <set>

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

int set_layout_features_setDefaultLayoutFeatures(SBMLDocument* document, Layout* layout, const int maxNumConnectedEdges);

int set_layout_features_setDefaultLayoutLocations(SBMLDocument* document, Layout* layout, const int maxNumConnectedEdges,
                              bool resetFixedPositionElements, const std::set<std::pair<std::string, int> > fixedPositionNodesSet);

void set_layout_features_clearGraphicalObjects(Layout* layout);

void set_layout_features_clearCompartmentGlyphs(Layout* layout);

void set_layout_features_clearSpeciesGlyphs(Layout* layout);

void set_layout_features_clearReactionGlyphs(Layout* layout);

void set_layout_features_clearReactionGlyphSpeciesReferenceGlyphs(ReactionGlyph* reactionGlyph);

void set_layout_clearAdditionalGraphicalObjects(Layout* layout);

void set_layout_features_setCompartmentGlyphs(Model* model, Layout* layout, const std::vector<std::map<std::string, std::string>>& userData = {});

void set_layout_features_setReactionGlyphs(Model* model, Layout* layout, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData = {});

void set_layout_features_setReactantGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData);

void set_layout_features_setProductGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData);

void set_layout_features_setModifierGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData);

void set_layout_features_setEmptySpeciesReferenceGlyphs(Model* model, Layout* layout, ReactionGlyph* reactionGlyph, const std::vector<std::map<std::string, std::string>>& userData = {});

SpeciesReferenceGlyph* set_layout_features_createEmptySpeciesReferenceGlyph(Model* model, Layout* layout, ReactionGlyph* reactionGlyph);

SpeciesGlyph* set_layout_features_createEmptySpeciesGlyph(Model* model, Layout* layout, ReactionGlyph* reactionGlyph);

SpeciesGlyph* set_layout_features_createEmptySpeciesGlyph(ReactionGlyph* reactionGlyph);

SpeciesReferenceGlyph* set_layout_features_createEmptySpeciesReferenceGlyph(Layout* layout, ReactionGlyph* reactionGlyph, SpeciesGlyph* EmptySpeciesGlyph);

SpeciesGlyph* set_layout_features_getSpeciesGlyph(Layout* layout, const std::string& speciesId, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData);

void set_layout_features_setTextGlyphs(Layout* layout);

void set_layout_features_clearTextGlyphs(Layout* layout);

void set_layout_features_clearReactionTextGlyphs(Layout* layout);

void set_layout_features_setCompartmentTextGlyphs(Layout* layout);

void set_layout_features_setSpeciesTextGlyphs(Layout* layout);

void set_layout_features_setReactionTextGlyphs(Layout* layout);

CompartmentGlyph* set_layout_features_createCompartmentGlyph(Layout* layout, const std::string& compartmentId, const std::vector<std::map<std::string, std::string>>& userData = {});

SpeciesGlyph* set_layout_features_createSpeciesGlyph(Layout* layout, const std::string& speciesId, const std::vector<std::map<std::string, std::string>>& userData = {});

SpeciesGlyph* set_layout_features_createEmptySpeciesGlyph(Layout* layout, const std::string& reactionGlyphId);

ReactionGlyph* set_layout_features_createReactionGlyph(Layout* layout, const std::string& reactionId, const std::vector<std::map<std::string, std::string>>& userData = {});

SpeciesReferenceGlyph* set_layout_features_createSpeciesReferenceGlyph(Layout* layout, ReactionGlyph* reactionGlyph, const std::string& speciesId, unsigned int stoichiometryIndex, const int maxNumConnectedEdges, const std::vector<std::map<std::string, std::string>>& userData = {});

SpeciesReferenceGlyph* set_layout_features_createSpeciesReferenceGlyph(ReactionGlyph* reactionGlyph, const std::string& speciesId, unsigned int stoichiometryIndex);

GraphicalObject* set_layout_features_createAdditionalGraphicalObject(Layout* layout, const std::string& id);

int set_layout_features_removeAdditionalGraphicalObject(Layout* layout, const std::string& id);

int set_layout_features_removeAdditionalGraphicalObject(Layout* layout, const unsigned int index);

std::vector<SpeciesReferenceGlyph*> set_layout_features_getConnectedSpeciesGlyphReferences(Layout* layout, SpeciesGlyph* speciesGlyph);

const std::string set_layout_features_getTextGlyphUniqueId(Layout* layout, GraphicalObject* graphicalObject);

const std::string set_layout_features_getCompartmentGlyphId(Layout* layout, const std::string compartmentId);

const std::string set_layout_features_getSpeciesGlyphId(Layout* layout, const std::string speciesId);

const std::string set_layout_features_getReactionGlyphId(Layout* layout, const std::string reactionId);

const std::string set_layout_features_getSpeciesReferenceGlyphId(ReactionGlyph* reactionGlyph, const std::string speciesGlyphId, unsigned int stoichiometryIndex = 0);

void set_layout_features_setGraphicalObjectBoundingBox(GraphicalObject* graphicalObject);

void set_layout_features_setSpeciesReferenceGlyphCurve(SpeciesReferenceGlyph* speciesReferenceGlyph, SpeciesReferenceGlyph* referenceSpeciesReferenceGlyph, const double& padding=0.0);

void set_layout_features_setSpeciesReferenceGlyphCurve(SpeciesReferenceGlyph* speciesReferenceGlyph);

void set_layout_features_addCurveSegment(Curve* curve, LineSegment* referenceLineSegment, const double& padding);

void set_layout_features_setCurveCubicBezier(Curve* curve, const double& x = 0.0, const double& y = 0.0);

}

#endif
