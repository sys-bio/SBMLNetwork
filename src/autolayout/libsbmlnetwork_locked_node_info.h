#ifndef __LIBSBMLNETWORK_LOCKED_NODE_INFO_H
#define __LIBSBMLNETWORK_LOCKED_NODE_INFO_H

#include <string>

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

    class LockedNodeInfo {

    public:

        LockedNodeInfo();

        LockedNodeInfo(const std::string& entityId, unsigned int graphicalObjectIndex, const double& x, const double& y);

        std::string getEntityId() const;

        unsigned int getGraphicalObjectIndex() const;

        double getX() const;

        double getY() const;

        void setEntityId(const std::string& entityId);

        void setGraphicalObjectIndex(unsigned int graphicalObjectIndex);

        void setX(const double& x);

        void setY(const double& y);

        bool operator<(const LockedNodeInfo& lockedNodeInfo) const;

        protected:

        std::string entityId;
        unsigned int graphicalObjectIndex;
        double x;
        double y;
    };
}


#endif
