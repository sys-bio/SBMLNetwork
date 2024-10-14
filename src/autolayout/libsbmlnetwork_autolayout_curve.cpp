#include "libsbmlnetwork_autolayout_curve.h"
#include "libsbmlnetwork_autolayout_node.h"
#include "../libsbmlnetwork_layout_helpers.h"

AutoLayoutCurve::AutoLayoutCurve(Model* model, Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph) : AutoLayoutObjectBase(model, layout) {
    _speciesReferenceGlyph = speciesReferenceGlyph;
}

const std::string AutoLayoutCurve::getId() {
    return _speciesReferenceGlyph->getId();
}

const std::string AutoLayoutCurve::getNodeId() {
    return _speciesReferenceGlyph->getSpeciesGlyphId();
}

const SpeciesReferenceRole_t AutoLayoutCurve::getRole() {
    return _speciesReferenceGlyph->getRole();
}

const std::string AutoLayoutCurve::getRoleString() {
    return _speciesReferenceGlyph->getRoleString();
}

const AutoLayoutPoint AutoLayoutCurve::getNodeSidePoint() {
    Curve* curve = _speciesReferenceGlyph->getCurve();
    if (getRole() == SPECIES_ROLE_MODIFIER || getRole() == SPECIES_ROLE_ACTIVATOR || getRole() == SPECIES_ROLE_INHIBITOR)
        return AutoLayoutPoint(curve->getCurveSegment(0)->getStart()->x(), curve->getCurveSegment(0)->getStart()->y());
    else
        return AutoLayoutPoint(curve->getCurveSegment(0)->getEnd()->x(), curve->getCurveSegment(0)->getEnd()->y());
}

void AutoLayoutCurve::setNodeSidePoint(const AutoLayoutPoint& nodeSidePoint) {
    Curve* curve = _speciesReferenceGlyph->getCurve();
    if (getRole() == SPECIES_ROLE_MODIFIER || getRole() == SPECIES_ROLE_ACTIVATOR || getRole() == SPECIES_ROLE_INHIBITOR) {
        curve->getCurveSegment(0)->getStart()->setX(nodeSidePoint.getX());
        curve->getCurveSegment(0)->getStart()->setY(nodeSidePoint.getY());
    }
    else {
        curve->getCurveSegment(0)->getEnd()->setX(nodeSidePoint.getX());
        curve->getCurveSegment(0)->getEnd()->setY(nodeSidePoint.getY());
    }
}

const AutoLayoutPoint AutoLayoutCurve::getNodeSideControlPoint() {
    Curve* curve = _speciesReferenceGlyph->getCurve();
    if (getRole() == SPECIES_ROLE_MODIFIER || getRole() == SPECIES_ROLE_ACTIVATOR || getRole() == SPECIES_ROLE_INHIBITOR)
        return AutoLayoutPoint(((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint1()->x(), ((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint1()->y());
    else
        return AutoLayoutPoint(((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint2()->x(), ((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint2()->y());
}

void AutoLayoutCurve::setNodeSideControlPoint(const AutoLayoutPoint& nodeSideControlPoint) {
    Curve* curve = _speciesReferenceGlyph->getCurve();
    if (getRole() == SPECIES_ROLE_MODIFIER || getRole() == SPECIES_ROLE_ACTIVATOR || getRole() == SPECIES_ROLE_INHIBITOR) {
        ((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint1()->setX(nodeSideControlPoint.getX());
        ((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint1()->setY(nodeSideControlPoint.getY());
    }
    else {
        ((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint2()->setX(nodeSideControlPoint.getX());
        ((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint2()->setY(nodeSideControlPoint.getY());
    }
}

const AutoLayoutPoint AutoLayoutCurve::getCentroidSidePoint() {
    Curve* curve = _speciesReferenceGlyph->getCurve();
    if (getRole() == SPECIES_ROLE_MODIFIER || getRole() == SPECIES_ROLE_ACTIVATOR || getRole() == SPECIES_ROLE_INHIBITOR)
        return AutoLayoutPoint(curve->getCurveSegment(0)->getEnd()->x(), curve->getCurveSegment(0)->getEnd()->y());
    else
        return AutoLayoutPoint(curve->getCurveSegment(0)->getStart()->x(), curve->getCurveSegment(0)->getStart()->y());
}

void AutoLayoutCurve::setCentroidSidePoint(const AutoLayoutPoint& centroidSidePoint) {
    Curve* curve = _speciesReferenceGlyph->getCurve();
    if (getRole() == SPECIES_ROLE_MODIFIER || getRole() == SPECIES_ROLE_ACTIVATOR || getRole() == SPECIES_ROLE_INHIBITOR) {
        curve->getCurveSegment(0)->getEnd()->setX(centroidSidePoint.getX());
        curve->getCurveSegment(0)->getEnd()->setY(centroidSidePoint.getY());
    }
    else {
        curve->getCurveSegment(0)->getStart()->setX(centroidSidePoint.getX());
        curve->getCurveSegment(0)->getStart()->setY(centroidSidePoint.getY());
    }
}

const AutoLayoutPoint AutoLayoutCurve::getCentroidSideControlPoint() {
    Curve* curve = _speciesReferenceGlyph->getCurve();
    if (getRole() == SPECIES_ROLE_MODIFIER || getRole() == SPECIES_ROLE_ACTIVATOR || getRole() == SPECIES_ROLE_INHIBITOR)
        return AutoLayoutPoint(((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint2()->x(), ((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint2()->y());
    else
        return AutoLayoutPoint(((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint1()->x(), ((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint1()->y());
}

void AutoLayoutCurve::setCentroidSideControlPoint(const AutoLayoutPoint& centroidSideControlPoint) {
    Curve* curve = _speciesReferenceGlyph->getCurve();
    if (getRole() == SPECIES_ROLE_MODIFIER || getRole() == SPECIES_ROLE_ACTIVATOR || getRole() == SPECIES_ROLE_INHIBITOR) {
        ((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint2()->setX(centroidSideControlPoint.getX());
        ((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint2()->setY(centroidSideControlPoint.getY());
    }
    else {
        ((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint1()->setX(centroidSideControlPoint.getX());
        ((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint1()->setY(centroidSideControlPoint.getY());
    }
}