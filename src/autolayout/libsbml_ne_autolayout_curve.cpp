#include "libsbml_ne_autolayout_curve.h"
#include "libsbml_ne_autolayout_node.h"
#include "../libsbml_ne_layout_helpers.h"

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
    if (getRole() == SPECIES_ROLE_PRODUCT || getRole() == SPECIES_ROLE_SIDEPRODUCT)
        return AutoLayoutPoint(_speciesReferenceGlyph->getCurve()->getCurveSegment(0)->getEnd()->x(), _speciesReferenceGlyph->getCurve()->getCurveSegment(0)->getEnd()->y());
    else
        return AutoLayoutPoint(_speciesReferenceGlyph->getCurve()->getCurveSegment(0)->getStart()->x(), _speciesReferenceGlyph->getCurve()->getCurveSegment(0)->getStart()->y());
}

void AutoLayoutCurve::setNodeSidePoint(const AutoLayoutPoint& nodeSidePoint) {
    if (getRole() == SPECIES_ROLE_PRODUCT || getRole() == SPECIES_ROLE_SIDEPRODUCT) {
        _speciesReferenceGlyph->getCurve()->getCurveSegment(0)->getEnd()->setX(nodeSidePoint.getX());
        _speciesReferenceGlyph->getCurve()->getCurveSegment(0)->getEnd()->setY(nodeSidePoint.getY());
    }
    else {
        _speciesReferenceGlyph->getCurve()->getCurveSegment(0)->getStart()->setX(nodeSidePoint.getX());
        _speciesReferenceGlyph->getCurve()->getCurveSegment(0)->getStart()->setY(nodeSidePoint.getY());
    }
}

const AutoLayoutPoint AutoLayoutCurve::getNodeSideControlPoint() {
    if (getRole() == SPECIES_ROLE_PRODUCT || getRole() == SPECIES_ROLE_SIDEPRODUCT)
        return AutoLayoutPoint(((CubicBezier*)(_speciesReferenceGlyph->getCurve()->getCurveSegment(0)))->getBasePoint2()->x(), ((CubicBezier*)(_speciesReferenceGlyph->getCurve()->getCurveSegment(0)))->getBasePoint2()->y());
    else
        return AutoLayoutPoint(((CubicBezier*)(_speciesReferenceGlyph->getCurve()->getCurveSegment(0)))->getBasePoint1()->x(), ((CubicBezier*)(_speciesReferenceGlyph->getCurve()->getCurveSegment(0)))->getBasePoint1()->y());
}

void AutoLayoutCurve::setNodeSideControlPoint(const AutoLayoutPoint& nodeSideControlPoint) {
    if (getRole() == SPECIES_ROLE_PRODUCT || getRole() == SPECIES_ROLE_SIDEPRODUCT) {
        ((CubicBezier*)(_speciesReferenceGlyph->getCurve()->getCurveSegment(0)))->getBasePoint2()->setX(nodeSideControlPoint.getX());
        ((CubicBezier*)(_speciesReferenceGlyph->getCurve()->getCurveSegment(0)))->getBasePoint2()->setY(nodeSideControlPoint.getY());
    }
    else {
        ((CubicBezier*)(_speciesReferenceGlyph->getCurve()->getCurveSegment(0)))->getBasePoint1()->setX(nodeSideControlPoint.getX());
        ((CubicBezier*)(_speciesReferenceGlyph->getCurve()->getCurveSegment(0)))->getBasePoint1()->setY(nodeSideControlPoint.getY());
    }
}

const AutoLayoutPoint AutoLayoutCurve::getCentroidSidePoint() {
    if (getRole() == SPECIES_ROLE_PRODUCT || getRole() == SPECIES_ROLE_SIDEPRODUCT)
        return AutoLayoutPoint(_speciesReferenceGlyph->getCurve()->getCurveSegment(0)->getStart()->x(), _speciesReferenceGlyph->getCurve()->getCurveSegment(0)->getStart()->y());
    else
        return AutoLayoutPoint(_speciesReferenceGlyph->getCurve()->getCurveSegment(0)->getEnd()->x(), _speciesReferenceGlyph->getCurve()->getCurveSegment(0)->getEnd()->y());
}

void AutoLayoutCurve::setCentroidSidePoint(const AutoLayoutPoint& centroidSidePoint) {
    if (getRole() == SPECIES_ROLE_PRODUCT || getRole() == SPECIES_ROLE_SIDEPRODUCT) {
        _speciesReferenceGlyph->getCurve()->getCurveSegment(0)->getStart()->setX(centroidSidePoint.getX());
        _speciesReferenceGlyph->getCurve()->getCurveSegment(0)->getStart()->setY(centroidSidePoint.getY());
    }
    else {
        _speciesReferenceGlyph->getCurve()->getCurveSegment(0)->getEnd()->setX(centroidSidePoint.getX());
        _speciesReferenceGlyph->getCurve()->getCurveSegment(0)->getEnd()->setY(centroidSidePoint.getY());
    }
}

const AutoLayoutPoint AutoLayoutCurve::getCentroidSideControlPoint() {
    if (getRole() == SPECIES_ROLE_PRODUCT || getRole() == SPECIES_ROLE_SIDEPRODUCT)
        return AutoLayoutPoint(((CubicBezier*)(_speciesReferenceGlyph->getCurve()->getCurveSegment(0)))->getBasePoint1()->x(),
                               ((CubicBezier*)(_speciesReferenceGlyph->getCurve()->getCurveSegment(0)))->getBasePoint1()->y());
    else
        return AutoLayoutPoint(((CubicBezier*)(_speciesReferenceGlyph->getCurve()->getCurveSegment(0)))->getBasePoint2()->x(),
                               ((CubicBezier*)(_speciesReferenceGlyph->getCurve()->getCurveSegment(0)))->getBasePoint2()->y());
}

void AutoLayoutCurve::setCentroidSideControlPoint(const AutoLayoutPoint& centroidSideControlPoint) {
    if (getRole() == SPECIES_ROLE_PRODUCT || getRole() == SPECIES_ROLE_SIDEPRODUCT) {
        ((CubicBezier*)(_speciesReferenceGlyph->getCurve()->getCurveSegment(0)))->getBasePoint1()->setX(centroidSideControlPoint.getX());
        ((CubicBezier*)(_speciesReferenceGlyph->getCurve()->getCurveSegment(0)))->getBasePoint1()->setY(centroidSideControlPoint.getY());
    }
    else {
        ((CubicBezier*)(_speciesReferenceGlyph->getCurve()->getCurveSegment(0)))->getBasePoint2()->setX(centroidSideControlPoint.getX());
        ((CubicBezier*)(_speciesReferenceGlyph->getCurve()->getCurveSegment(0)))->getBasePoint2()->setY(centroidSideControlPoint.getY());
    }
}