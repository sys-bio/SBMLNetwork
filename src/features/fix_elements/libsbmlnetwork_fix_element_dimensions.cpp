#include "libsbmlnetwork_fix_element_dimensions.h"
#include "../../features/user_data/libsbmlnetwork_user_data.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

void fix_elements_fixGraphicalObjectWidth(GraphicalObject* graphicalObject) {
    user_data_setUserData(graphicalObject, "fixed_width", "true");
    user_data_setUserData(graphicalObject, "width", std::to_string(graphicalObject->getBoundingBox()->width()));
}

void fix_elements_unfixGraphicalObjectWidth(GraphicalObject* graphicalObject) {
    user_data_setUserData(graphicalObject, "fixed_width", "false");
    user_data_setUserData(graphicalObject, "width", "");
}

void fix_elements_fixGraphicalObjectHeight(GraphicalObject* graphicalObject) {
    user_data_setUserData(graphicalObject, "fixed_height", "true");
    user_data_setUserData(graphicalObject, "height", std::to_string(graphicalObject->getBoundingBox()->height()));
}

void fix_elements_unfixGraphicalObjectHeight(GraphicalObject* graphicalObject) {
    user_data_setUserData(graphicalObject, "fixed_height", "false");
    user_data_setUserData(graphicalObject, "height", "");
}

}
