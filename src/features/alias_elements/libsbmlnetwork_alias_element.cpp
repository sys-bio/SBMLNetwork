#include "libsbmlnetwork_alias_element.h"
#include "../../libsbmlnetwork_layout.h"
#include "../../libsbmlnetwork_layout_helpers.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

    void alias_element_setAliasGraphicalObjectPosition(GraphicalObject* aliasGraphicalObject, GraphicalObject* graphicalObject, const double& padding) {
        double x = getPositionX(graphicalObject);
        double y = getPositionY(graphicalObject);
        if (isSetCurve(aliasGraphicalObject)) {
            setPositionX(getCurve(aliasGraphicalObject), x + padding);
            setPositionY(getCurve(aliasGraphicalObject), y + padding);
        }
        else {
            setPositionX(getBoundingBox(aliasGraphicalObject), x + padding);
            setPositionY(getBoundingBox(aliasGraphicalObject), y + padding);
        }
    }

}
