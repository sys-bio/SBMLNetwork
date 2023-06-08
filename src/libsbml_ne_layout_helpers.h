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

void setCompartmentGlyphs(Model* model, Layout* layout, LayoutPkgNamespaces* layoutPkgNamespaces);

void setSpeciesGlyphs(Model* model, Layout* layout, LayoutPkgNamespaces* layoutPkgNamespaces);

void setReactionGlyphs(Model* model, Layout* layout, LayoutPkgNamespaces* layoutPkgNamespaces);

void setReactantGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, LayoutPkgNamespaces* layoutPkgNamespaces);

void setProductGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, LayoutPkgNamespaces* layoutPkgNamespaces);

void setModifierGlyphs(Layout* layout, Reaction* reaction, ReactionGlyph* reactionGlyph, LayoutPkgNamespaces* layoutPkgNamespaces);

void setCompartmentTextGlyphs(Layout* layout, LayoutPkgNamespaces* layoutPkgNamespaces);

void setSpeciesTextGlyphs(Layout* layout, LayoutPkgNamespaces* layoutPkgNamespaces);

CompartmentGlyph* getCompartmentGlyph(Layout* layout, Compartment* compartment);
SpeciesGlyph* getSpeciesGlyph(Layout* layout, Species* species);

ReactionGlyph* getReactionGlyph(Layout* layout, Reaction* reaction);

SpeciesReferenceGlyph* getSpeciesReferenceGlyph(Layout* layout, ReactionGlyph* reactionGlyph, SimpleSpeciesReference* speciesReference);

TextGlyph* getTextGlyph(Layout* layout, GraphicalObject* graphicalObject);

void setGraphicalObjectBoundingBox(GraphicalObject* graphicalObject, LayoutPkgNamespaces* layoutPkgNamespaces);

void setTextGlyphBoundingBox(TextGlyph* textGlyph, GraphicalObject* graphicalObject, LayoutPkgNamespaces* layoutPkgNamespaces);

void setSpeciesReferenceGlyphCurve(SpeciesReferenceGlyph* speciesReferenceGlyph, LayoutPkgNamespaces* layoutPkgNamespaces);

Compartment* findCompartmentGlyphCompartment(Model* model, CompartmentGlyph* compartmentGlyph);

Compartment* findSpeciesGlyphCompartment(Model* model, SpeciesGlyph* speciesGlyph);

Compartment* findReactionGlyphCompartment(Model* model, ReactionGlyph* reactionGlyph);

bool containsSpecies(Model* model, Layout* layout, CompartmentGlyph* compartmentGlyph);

bool compartmentGlyphBelongs(CompartmentGlyph* compartmentGlyph, Compartment* compartment);

bool speciesGlyphBelongs(SpeciesGlyph* speciesGlyph, Species* species);

bool reactionGlyphBelongs(ReactionGlyph* reactionGlyph, Reaction* reaction);

bool speciesReferenceGlyphBelongs(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph, SimpleSpeciesReference* speciesReference);

bool textGlyphBelongs(TextGlyph* textGlyph, GraphicalObject* graphicalObject);

const std::string getEntityId(Layout* layout, GraphicalObject* graphicalObject);

}

#endif

