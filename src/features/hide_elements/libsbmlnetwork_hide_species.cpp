#include "libsbmlnetwork_hide_species.h"
#include "../../libsbmlnetwork_layout.h"
#include "../../libsbmlnetwork_layout_helpers.h"
#include "../../features/user_data/libsbmlnetwork_user_data.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

int hide_elements_makeSpeciesGlyphsVisible(Model* model, Layout* layout, std::set<std::tuple<std::string, std::string, int> > species, bool visible) {
    for (std::set<std::tuple<std::string, std::string, int> >::const_iterator speciesIt = species.cbegin(); speciesIt != species.cend(); speciesIt++) {
        if (hide_elements_makeSpeciesGlyphVisible(getReactionGlyph(layout, std::get<1>(*speciesIt), std::get<2>(*speciesIt)), std::get<0>(*speciesIt), visible))
            return -1;
    }

    return 0;
}

int hide_elements_makeSpeciesGlyphVisible(ReactionGlyph* reactionGlyph, const std::string speciesId, bool visible) {
    if (!visible)
        return hide_elements_hideSpeciesGlyph(reactionGlyph, speciesId);
    else
        return hide_elements_unHideSpeciesGlyph(reactionGlyph, speciesId);
}

int hide_elements_hideSpeciesGlyph(SBase* sBase, const std::string speciesId) {
    if (sBase) {
        std::string hiddenSpeciesIds = user_data_getUserData(sBase, "hidden_species_ids");
        if (hiddenSpeciesIds.find(speciesId) == std::string::npos) {
            if (hiddenSpeciesIds.size())
                hiddenSpeciesIds += ",";
            hiddenSpeciesIds += speciesId;
            if (isGraphicalObject(sBase))
                user_data_setUserData((GraphicalObject*)sBase, "hidden_species_ids", hiddenSpeciesIds);
            else
                user_data_setUserData(sBase, "hidden_species_ids", hiddenSpeciesIds);
        }

        return 0;
    }

    return -1;
}

int hide_elements_unHideSpeciesGlyph(SBase* sBase, const std::string speciesId) {
    if (sBase) {
        std::string hiddenSpeciesIds = user_data_getUserData(sBase, "hidden_species_ids");
        size_t found = hiddenSpeciesIds.find(speciesId);
        if (found != std::string::npos) {
            hiddenSpeciesIds.erase(found, speciesId.size());
            if (hiddenSpeciesIds.back() == ',')
                hiddenSpeciesIds.pop_back();
            if (isGraphicalObject(sBase))
                user_data_setUserData((GraphicalObject*)sBase, "hidden_species_ids", hiddenSpeciesIds);
            else
                user_data_setUserData(sBase, "hidden_species_ids", hiddenSpeciesIds);
        }

        return 0;
    }

    return -1;
}

const bool hide_elements_isSpeciesGlyphHidden(Layout* layout, ReactionGlyph* reactionGlyph, const std::string speciesId) {
    return user_data_getUserData(layout, "hidden_species_ids").find(speciesId) != std::string::npos ||  user_data_getUserData(reactionGlyph, "hidden_species_ids").find(speciesId) != std::string::npos;
}

}
