#ifndef __LIBSBMLNETWORK_HIDE_SPECIES_H
#define __LIBSBMLNETWORK_HIDE_SPECIES_H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#include "sbml/packages/render/common/RenderExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

int hide_elements_makeSpeciesGlyphsVisible(Model* model, Layout* layout, std::set<std::tuple<std::string, std::string, int> > species, bool visible = true);

int hide_elements_makeSpeciesGlyphVisible(ReactionGlyph* reactionGlyph, const std::string speciesId, bool visible = true);

int hide_elements_hideSpeciesGlyph(SBase* sBase, const std::string speciesId);

int hide_elements_unHideSpeciesGlyph(SBase* sBase, const std::string speciesId);

const bool hide_elements_isSpeciesGlyphHidden(Layout* layout, ReactionGlyph* reactionGlyph, const std::string speciesId);

}

#endif
