#include "libsbmlnetwork_locked_node_info.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

    LockedNodeInfo::LockedNodeInfo() {
        entityId = "";
        graphicalObjectIndex = 0;
        x = 0.0;
        y = 0.0;
    }

    LockedNodeInfo::LockedNodeInfo(const std::string& entityId, unsigned int graphicalObjectIndex, const double& x, const double& y) {
        this->entityId = entityId;
        this->graphicalObjectIndex = graphicalObjectIndex;
        this->x = x;
        this->y = y;
    }

    std::string LockedNodeInfo::getEntityId() const {
        return entityId;
    }

    unsigned int LockedNodeInfo::getGraphicalObjectIndex() const {
        return graphicalObjectIndex;
    }

    double LockedNodeInfo::getX() const {
        return x;
    }

    double LockedNodeInfo::getY() const {
        return y;
    }

    void LockedNodeInfo::setEntityId(const std::string& entityId) {
        this->entityId = entityId;
    }

    void LockedNodeInfo::setGraphicalObjectIndex(unsigned int graphicalObjectIndex) {
        this->graphicalObjectIndex = graphicalObjectIndex;
    }

    void LockedNodeInfo::setX(const double& x) {
        this->x = x;
    }

    void LockedNodeInfo::setY(const double& y) {
        this->y = y;
    }

    bool LockedNodeInfo::operator<(const LockedNodeInfo& lockedNodeInfo) const {
        if (entityId < lockedNodeInfo.entityId)
            return true;
        else if (entityId == lockedNodeInfo.entityId)
            return graphicalObjectIndex < lockedNodeInfo.graphicalObjectIndex;

        return false;
    }
}