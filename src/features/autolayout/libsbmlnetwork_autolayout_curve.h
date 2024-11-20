#ifndef __LIBSBMLNETWORK_AUTOLAYOUT_CURVE__H
#define __LIBSBMLNETWORK_AUTOLAYOUT_CURVE__H

#include "libsbmlnetwork_autolayout_object_base.h"
#include "libsbmlnetwork_autolayout_point.h"

class AutoLayoutCurve : public AutoLayoutObjectBase {
public:

    AutoLayoutCurve(Model* model, Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph);

    const std::string getId() override;

    const std::string getNodeId();

    const SpeciesReferenceRole_t getRole();

    const std::string getRoleString();

    const bool isPositionFixed();

    void setPositionFixed(const bool& positionFixed);

    void updateFixedPositionStatus();

    const AutoLayoutPoint getNodeSidePoint();

    void setNodeSidePoint(const AutoLayoutPoint& nodeSidePoint);

    const AutoLayoutPoint getNodeSideControlPoint();

    void setNodeSideControlPoint(const AutoLayoutPoint& nodeSideControlPoint);

    const AutoLayoutPoint getCentroidSidePoint();

    void setCentroidSidePoint(const AutoLayoutPoint& centroidSidePoint);

    const AutoLayoutPoint getCentroidSideControlPoint();

    void setCentroidSideControlPoint(const AutoLayoutPoint& centroidSideControlPoint);

protected:

    SpeciesReferenceGlyph* _speciesReferenceGlyph;
    bool _positionFixed;
};

#endif