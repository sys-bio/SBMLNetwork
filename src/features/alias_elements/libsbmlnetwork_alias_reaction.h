#ifndef __LIBSBMLNETWORK_ALIAS_REACTION_H
#define __LIBSBMLNETWORK_ALIAS_REACTION_H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

int alias_element_createAliasReactionGlyph(SBMLDocument* document, Layout* layout, ReactionGlyph* reactionGlyph);

ReactionGlyph* alias_element_createAliasReactionGlyph(Layout* layout, ReactionGlyph* reactionGlyph, const double& padding = 0.0);

void alias_element_setAliasReactionGlyphTextGlyph(Layout* layout, ReactionGlyph* aliasReactionGlyph, ReactionGlyph* reactionGlyph);

int alias_element_createAliasSpeciesReferenceGlyphs(SBMLDocument* document, Layout* layout, ReactionGlyph* referenceReactionGlyph, ReactionGlyph* reactionGlyph, const double& padding = 0.0);

SpeciesReferenceGlyph* alias_element_createAliasSpeciesReferenceGlyph(ReactionGlyph* reactionGlyph, SpeciesReferenceGlyph* referenceSpeciesReferenceGlyph, const std::string& speciesGlyphId, unsigned int stoichiometryIndex = 0, const double& padding = 0.0);

}

#endif
