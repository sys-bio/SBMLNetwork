#ifndef __LIBSBMLNETWORK_ALIAS_SPECIES_H
#define __LIBSBMLNETWORK_ALIAS_SPECIES_H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

int alias_element_createAliasSpeciesGlyph(Layout* layout, const std::string speciesId, ReactionGlyph* reactionGlyph);

SpeciesGlyph* alias_element_createAliasSpeciesGlyph(Layout* layout, SpeciesGlyph* speciesGlyph, const double& padding = 0.0);

SpeciesGlyph* alias_element_createAliasSpeciesGlyph(Layout* layout, const std::string& speciesId, std::vector<SpeciesReferenceGlyph*> speciesGlyphReferences);

const bool alias_element_canHaveAlias(Layout* layout, std::vector<SpeciesReferenceGlyph*> connectedSpeciesGlyphReferencesOfReactionGlyph);

void alias_element_setAliasSpeciesGlyphDimensions(SpeciesGlyph* aliasSpeciesGlyph, GraphicalObject* graphicalObject);

void alias_element_setAliasSpeciesGlyphTextGlyph(Layout* layout, SpeciesGlyph* aliasSpeciesGlyph);

}

#endif
