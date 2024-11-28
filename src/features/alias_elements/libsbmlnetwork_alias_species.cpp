#include "libsbmlnetwork_alias_species.h"
#include "../../libsbmlnetwork_layout.h"
#include "../../libsbmlnetwork_layout_helpers.h"
#include "../../features/set_layout_features/libsbmlnetwork_set_layout_features.h"
#include "../../features/alias_elements/libsbmlnetwork_alias_element.h"
#include "../../features/defaults/libsbmlnetwork_defaults_layout.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

int alias_element_createAliasSpeciesGlyph(Layout* layout, const std::string speciesId, ReactionGlyph* reactionGlyph) {
    if (reactionGlyph) {
        std::vector<SpeciesReferenceGlyph*> speciesGlyphReferences = getSpeciesReferencesAssociatedWithSpecies(layout, reactionGlyph, speciesId);
        if (alias_element_canHaveAlias(layout, speciesGlyphReferences)) {
            SpeciesGlyph* aliasSpeciesGlyph = alias_element_createAliasSpeciesGlyph(layout, speciesId, speciesGlyphReferences);
            if (aliasSpeciesGlyph) {
                alias_element_setAliasGraphicalObjectPosition(aliasSpeciesGlyph, reactionGlyph);
                alias_element_setAliasSpeciesGlyphDimensions(aliasSpeciesGlyph, reactionGlyph);
                alias_element_setAliasSpeciesGlyphTextGlyph(layout, aliasSpeciesGlyph);
                return 0;
            }
        }
    }

    return -1;
}

SpeciesGlyph* alias_element_createAliasSpeciesGlyph(Layout* layout, SpeciesGlyph* speciesGlyph, const double& padding) {
    SpeciesGlyph* aliasSpeciesGlyph = NULL;
    if (speciesGlyph) {
        aliasSpeciesGlyph = set_layout_features_createSpeciesGlyph(layout, speciesGlyph->getSpeciesId());
        alias_element_setAliasGraphicalObjectPosition(aliasSpeciesGlyph, speciesGlyph, padding);
        alias_element_setAliasSpeciesGlyphDimensions(aliasSpeciesGlyph, speciesGlyph);
        alias_element_setAliasSpeciesGlyphTextGlyph(layout, aliasSpeciesGlyph);
    }

    return aliasSpeciesGlyph;
}

SpeciesGlyph* alias_element_createAliasSpeciesGlyph(Layout* layout, const std::string& speciesId, std::vector<SpeciesReferenceGlyph*> speciesGlyphReferences) {
    SpeciesGlyph* aliasSpeciesGlyph = NULL;
    if (speciesGlyphReferences.size()) {
        aliasSpeciesGlyph = set_layout_features_createSpeciesGlyph(layout, speciesId);
        while (speciesGlyphReferences.size()) {
            SpeciesReferenceGlyph* speciesReferenceGlyph = speciesGlyphReferences.back();
            speciesReferenceGlyph->setId(getIdOfSpeciesReferenceGlyphConnectedToNewSpeciesGlyph(speciesReferenceGlyph->getId(), speciesReferenceGlyph->getSpeciesGlyphId(), aliasSpeciesGlyph->getId()));
            speciesReferenceGlyph->setSpeciesGlyphId(aliasSpeciesGlyph->getId());
            speciesGlyphReferences.pop_back();
        }
    }

    return aliasSpeciesGlyph;
}

const bool alias_element_canHaveAlias(Layout* layout, std::vector<SpeciesReferenceGlyph*> connectedSpeciesGlyphReferencesOfReactionGlyph) {
    if (connectedSpeciesGlyphReferencesOfReactionGlyph.size()) {
        SpeciesGlyph* speciesGlyph = layout->getSpeciesGlyph(connectedSpeciesGlyphReferencesOfReactionGlyph.at(0)->getSpeciesGlyphId());
        std::vector<SpeciesReferenceGlyph*> connectedSpeciesGlyphReferencesOfSpeciesGlyph = set_layout_features_getConnectedSpeciesGlyphReferences(layout, speciesGlyph);
        if (connectedSpeciesGlyphReferencesOfSpeciesGlyph.size() > connectedSpeciesGlyphReferencesOfReactionGlyph.size())
            return true;
    }

    return false;
}

void alias_element_setAliasSpeciesGlyphDimensions(SpeciesGlyph* aliasSpeciesGlyph, GraphicalObject* graphicalObject) {
    double width = defaults_getSpeciesDefaultWidth();;
    if (isSpeciesGlyph(graphicalObject))
        width = getDimensionWidth(graphicalObject);
    aliasSpeciesGlyph->getBoundingBox()->setWidth(width);
    double height = defaults_getSpeciesDefaultHeight();
    if (isSpeciesGlyph(graphicalObject))
        height = getDimensionHeight(graphicalObject);
    aliasSpeciesGlyph->getBoundingBox()->setHeight(height);
}

void alias_element_setAliasSpeciesGlyphTextGlyph(Layout* layout, SpeciesGlyph* aliasSpeciesGlyph) {
    TextGlyph* textGlyph = createAssociatedTextGlyph(layout, aliasSpeciesGlyph);
    setTextGlyphBoundingBox(textGlyph, aliasSpeciesGlyph);
}

}
