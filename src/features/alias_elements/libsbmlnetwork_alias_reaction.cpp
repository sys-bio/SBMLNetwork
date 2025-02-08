#include "libsbmlnetwork_alias_reaction.h"
#include "../../libsbmlnetwork_layout.h"
#include "../../libsbmlnetwork_layout_helpers.h"
#include "../../features/set_layout_features/libsbmlnetwork_set_layout_features.h"
#include "../../features/alias_elements/libsbmlnetwork_alias_element.h"
#include "../../features/alias_elements/libsbmlnetwork_alias_species.h"
#include "../../features/defaults/libsbmlnetwork_defaults_layout.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

    int alias_element_createAliasReactionGlyph(SBMLDocument* document, Layout* layout, ReactionGlyph* reactionGlyph) {
        if (document && reactionGlyph) {
            double padding = getReactionGlyphs(layout, reactionGlyph->getReactionId()).size() * defaults_getAliasReactionGlyphPadding();
            ReactionGlyph* aliasReactionGlyph = alias_element_createAliasReactionGlyph(layout, reactionGlyph, padding);
            if (aliasReactionGlyph)
                return alias_element_createAliasSpeciesReferenceGlyphs(document, layout, reactionGlyph, aliasReactionGlyph, padding);
        }

        return -1;
    }

    ReactionGlyph* alias_element_createAliasReactionGlyph(Layout* layout, ReactionGlyph* reactionGlyph, const double& padding) {
        ReactionGlyph* aliasReactionGlyph = NULL;
        if (reactionGlyph) {
            aliasReactionGlyph = set_layout_features_createReactionGlyph(layout, reactionGlyph->getReactionId());
            alias_element_setAliasGraphicalObjectPosition(aliasReactionGlyph, reactionGlyph, padding);
            alias_element_setAliasReactionGlyphTextGlyph(layout, aliasReactionGlyph, reactionGlyph);
        }

        return aliasReactionGlyph;
    }

    void alias_element_setAliasReactionGlyphTextGlyph(Layout* layout, ReactionGlyph* aliasReactionGlyph, ReactionGlyph* reactionGlyph) {
        std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, reactionGlyph);
        if (textGlyphs.size()) {
            TextGlyph* textGlyph = createAssociatedTextGlyph(layout, aliasReactionGlyph);
            setTextGlyphBoundingBox(textGlyph, textGlyphs.at(0));
        }
    }

    int alias_element_createAliasSpeciesReferenceGlyphs(SBMLDocument* document, Layout* layout, ReactionGlyph* referenceReactionGlyph, ReactionGlyph* reactionGlyph, const double& padding) {
        std::map <std::string, std::string> speciesGlyphAliasSpeciesGlyphIds;
        for (unsigned int i = 0; i < referenceReactionGlyph->getNumSpeciesReferenceGlyphs(); i++) {
            SpeciesReferenceGlyph *speciesReferenceGlyph = referenceReactionGlyph->getSpeciesReferenceGlyph(i);
            SpeciesGlyph *speciesGlyph = layout->getSpeciesGlyph(speciesReferenceGlyph->getSpeciesGlyphId());
            if (!speciesGlyph)
                return -1;

            SpeciesGlyph *connectedSpeciesGlyph = NULL;
            if (speciesGlyphAliasSpeciesGlyphIds.find(speciesGlyph->getId()) == speciesGlyphAliasSpeciesGlyphIds.end())
                connectedSpeciesGlyph = alias_element_createAliasSpeciesGlyph(layout, speciesGlyph, padding);
            else
                connectedSpeciesGlyph = layout->getSpeciesGlyph(
                        speciesGlyphAliasSpeciesGlyphIds[speciesGlyph->getId()]);
            if (connectedSpeciesGlyph == NULL)
                return -1;

            speciesGlyphAliasSpeciesGlyphIds[speciesGlyph->getId()] = connectedSpeciesGlyph->getId();
            SimpleSpeciesReference* sr = findSpeciesReference(document->getModel(), layout, referenceReactionGlyph, speciesGlyph);
//            int stoichiometry = getStoichiometryAsInteger(layout, sr);
            int stoichiometry = 1;
            for (unsigned int stoichiometryIndex = 0; stoichiometryIndex < stoichiometry; stoichiometryIndex++)
                alias_element_createAliasSpeciesReferenceGlyph(reactionGlyph, speciesReferenceGlyph,
                                                               connectedSpeciesGlyph->getId(),
                                                               stoichiometryIndex, padding);
        }

        return 0;
    }

    SpeciesReferenceGlyph* alias_element_createAliasSpeciesReferenceGlyph(ReactionGlyph* reactionGlyph, SpeciesReferenceGlyph* referenceSpeciesReferenceGlyph, const std::string& speciesGlyphId, unsigned int stoichiometryIndex, const double& padding) {
        SpeciesReferenceGlyph* aliasSpeciesReferenceGlyph = set_layout_features_createSpeciesReferenceGlyph(reactionGlyph, speciesGlyphId, stoichiometryIndex);
        aliasSpeciesReferenceGlyph->setRole(referenceSpeciesReferenceGlyph->getRole());
        set_layout_features_setSpeciesReferenceGlyphCurve(aliasSpeciesReferenceGlyph, referenceSpeciesReferenceGlyph, padding);
        return aliasSpeciesReferenceGlyph;
    }

}
