#ifndef __LIBSBML_NE_AUTOLAYOUT_CURVE__H
#define __LIBSBML_NE_AUTOLAYOUT_CURVE__H

#include "libsbml_ne_autolayout_object_base.h"
#include "libsbml_ne_autolayout_point.h"

class AutoLayoutCurve : public AutoLayoutObjectBase {
public:

    AutoLayoutCurve(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph);

    const std::string getId() override;

    const std::string getNodeId();

    const SpeciesReferenceRole_t getRole();

    const std::string getRoleString();

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
};

#endif