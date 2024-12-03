#ifndef __LIBSBMLNETWORK_HIDE_ELEMENTS_H
#define __LIBSBMLNETWORK_HIDE_ELEMENTS_H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#include "sbml/packages/render/common/RenderExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

int hide_elements_makeVisible(SBMLDocument* document, unsigned int layoutIndex = 0);

int hide_elements_makeInvisible(SBMLDocument* document, unsigned int layoutIndex = 0);

int hide_elements_makeCompartmentVisible(SBMLDocument* document, unsigned int layoutIndex = 0);

int hide_elements_makeCompartmentInvisible(SBMLDocument* document, unsigned int layoutIndex = 0);

int hide_elements_makeSpeciesVisible(SBMLDocument* document, unsigned int layoutIndex = 0);

int hide_elements_makeSpeciesInvisible(SBMLDocument* document, unsigned int layoutIndex = 0);

int hide_elements_makeReactionVisible(SBMLDocument* document, unsigned int layoutIndex = 0);

int hide_elements_makeReactionInvisible(SBMLDocument* document, unsigned int layoutIndex = 0);

int hide_elements_makeSpeciesReferenceVisible(SBMLDocument* document, unsigned int layoutIndex = 0);

int hide_elements_makeSpeciesReferenceInvisible(SBMLDocument* document, unsigned int layoutIndex = 0);

int hide_elements_makeLineEndingVisible(SBMLDocument* document, unsigned int layoutIndex = 0);

int hide_elements_makeLineEndingInvisible(SBMLDocument* document, unsigned int layoutIndex = 0);

int hide_elements_makeGraphicalObjectLocalStyleVisible(SBMLDocument* document, LocalRenderInformation* localRenderInformation, GraphicalObject* graphicalObject);

int hide_elements_makeGraphicalObjectLocalStyleInvisible(SBMLDocument* document, LocalRenderInformation* localRenderInformation, GraphicalObject* graphicalObject);

int hide_elements_makeVisible(SBMLDocument* document, GraphicalObject* graphicalObject, const bool& applyToConnectedElements = true);

int hide_elements_makeInvisible(SBMLDocument* document, GraphicalObject* graphicalObject, const bool& applyToConnectedElements = true);

int hide_elements_makeCompartmentGlyphVisible(SBMLDocument* document, CompartmentGlyph* compartmentGlyph);

int hide_elements_makeCompartmentGlyphInvisible(SBMLDocument* document, CompartmentGlyph* compartmentGlyph);

int hide_elements_makeSpeciesGlyphVisible(SBMLDocument* document, SpeciesGlyph* speciesGlyph, const bool applyToConnectedElements = true);

int hide_elements_makeSpeciesGlyphInvisible(SBMLDocument* document, SpeciesGlyph* speciesGlyph, const bool applyToConnectedElements = true);

int hide_elements_makeReactionGlyphVisible(SBMLDocument* document, ReactionGlyph* reactionGlyph, const bool applyToConnectedElements = true);

int hide_elements_makeReactionGlyphInvisible(SBMLDocument* document, ReactionGlyph* reactionGlyph, const bool applyToConnectedElements = true);

int hide_elements_makeSpeciesReferenceGlyphVisible(SBMLDocument* document, SpeciesReferenceGlyph* speciesReferenceGlyph);

int hide_elements_makeSpeciesReferenceGlyphInvisible(SBMLDocument* document, SpeciesReferenceGlyph* speciesReferenceGlyph);

int hide_elements_makeTextGlyphVisible(SBMLDocument* document, TextGlyph* textGlyph, GraphicalObject* graphicalObject);

int hide_elements_makeTextGlyphInvisible(SBMLDocument* document, TextGlyph* textGlyph, GraphicalObject* graphicalObject);

int hide_elements_makeLineEndingVisible(SBMLDocument* document, LineEnding* lineEnding);

int hide_elements_makeLineEndingInvisible(SBMLDocument* document, LineEnding* lineEnding);

int hide_elements_make2DGraphicalObjectVisible(SBMLDocument* document, Style* style);

int hide_elements_make2DGraphicalObjectInvisible(SBMLDocument* document, Style* style);

int hide_elements_make2DGraphicalObjectVisible(SBMLDocument* document, LineEnding* lineEnding);

int hide_elements_make2DGraphicalObjectInvisible(SBMLDocument* document, LineEnding* lineEnding);

int hide_elements_make2DGraphicalObjectVisible(SBMLDocument* document, Style* style);

int hide_elements_make2DGraphicalObjectInvisible(SBMLDocument* document, Style* style);

int hide_elements_make1DGraphicalObjectVisible(SBMLDocument* document, LineEnding* lineEnding);

int hide_elements_make1DGraphicalObjectInvisible(SBMLDocument* document, LineEnding* lineEnding);

int hide_elements_make1DGraphicalObjectVisible(SBMLDocument* document, Style* style);

int hide_elements_make1DGraphicalObjectInvisible(SBMLDocument* document, Style* style);

int hide_elements_makeTextVisible(SBMLDocument* document, Style* style);

int hide_elements_makeTextInvisible(SBMLDocument* document, Style* style);

}

#endif
