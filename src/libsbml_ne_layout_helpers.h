#ifndef __LIBSBML_NE_LAYOUT_HELPERS_H_
#define __LIBSBML_NE_LAYOUT_HELPERS_H_

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

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

void setCompartmentTextGlyphs(Layout* layout);

void setSpeciesTextGlyphs(Layout* layout);

CompartmentGlyph* getCompartmentGlyph(Layout* layout, Compartment* compartment);

SpeciesGlyph* getSpeciesGlyph(Layout* layout, Species* species);

ReactionGlyph* getReactionGlyph(Layout* layout, Reaction* reaction);

SpeciesReferenceGlyph* getAssociatedSpeciesReferenceGlyph(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, SimpleSpeciesReference* speciesReference);

const int getNumSpeciesReferencesAssociatedWithSpecies(Reaction* reaction, const std::string& speciesId);

const int getNumSpeciesReferencesGlyphsAssociatedWithSpecies(Layout* layout, ReactionGlyph* reactionGlyph, const std::string& speciesId);

TextGlyph* getAssociatedTextGlyph(Layout* layout, GraphicalObject* graphicalObject);

void setGraphicalObjectBoundingBox(GraphicalObject* graphicalObject);

void setTextGlyphBoundingBox(TextGlyph* textGlyph, GraphicalObject* graphicalObject);

void setReactionGlyphCurve(ReactionGlyph* reactionGlyph);

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

bool canSpeciesReferenceGlyphBelongs(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph, SimpleSpeciesReference* speciesReference);

bool textGlyphBelongs(TextGlyph* textGlyph, GraphicalObject* graphicalObject);

std::vector<TextGlyph*> getAssociatedTextGlyphsWithGraphicalObject(Layout* layout, GraphicalObject* graphicalObject);

GraphicalObject* getGraphicalObjectUsingItsOwnId(Layout* layout, const std::string& graphicalObjectId);

const std::string getEntityId(Layout* layout, GraphicalObject* graphicalObject);

std::vector<CompartmentGlyph*> getAssociatedCompartmentGlyphsWithCompartmentId(Layout* layout, const std::string& compartmentId);

std::vector<SpeciesGlyph*> getAssociatedSpeciesGlyphsWithSpeciesId(Layout* layout, const std::string& speciesId);

std::vector<ReactionGlyph*> getAssociatedReactionGlyphsWithReactionId(Layout* layout, const std::string& reactionId);

std::vector<SpeciesReferenceGlyph*> getAssociatedSpeciesReferenceGlyphsWithReactionGlyph(ReactionGlyph* reactionGlyph);

}

#endif

