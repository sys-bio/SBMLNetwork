#include "libsbmlnetwork_update_curves.h"
#include "../../features/set_layout_features/libsbmlnetwork_set_layout_features.h"
#include "../../features/autolayout/libsbmlnetwork_autolayout.h"
#include "../../features/user_data/libsbmlnetwork_user_data.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

    int update_curves_updateLayoutCurves(SBMLDocument* document, Layout* layout) {
        if (document && layout) {
            user_data_passUserData(document, layout);
            Model* model = document->getModel();
            if (model) {
                set_layout_features_clearReactionTextGlyphs(layout);
                autolayout_locateReactions(model, layout);
                set_layout_features_setReactionTextGlyphs(layout);
                return 0;
            }
        }

        return -1;
    }

}
