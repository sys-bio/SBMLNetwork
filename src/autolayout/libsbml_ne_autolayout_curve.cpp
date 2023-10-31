#include "libsbml_ne_autolayout_curve.h"
#include "libsbml_ne_autolayout_node.h"
#include "../libsbml_ne_layout_helpers.h"

AutoLayoutCurve::AutoLayoutCurve(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph) : AutoLayoutObjectBase(layout) {
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

const AutoLayoutPoint& AutoLayoutCurve::getNodeSidePoint() {
    return _nodeSidePoint;
}

void AutoLayoutCurve::setNodeSidePoint(const AutoLayoutPoint& nodeSidePoint) {
    _nodeSidePoint.setX(nodeSidePoint.getX());
    _nodeSidePoint.setY(nodeSidePoint.getY());
}

const AutoLayoutPoint& AutoLayoutCurve::getNodeSideControlPoint() {
    return _nodeSideControlPoint;
}

void AutoLayoutCurve::setNodeSideControlPoint(const AutoLayoutPoint& nodeSideControlPoint) {
    _nodeSideControlPoint.setX(nodeSideControlPoint.getX());
    _nodeSideControlPoint.setY(nodeSideControlPoint.getY());
}

const AutoLayoutPoint& AutoLayoutCurve::getCentroidSidePoint() {
    return _centroidSidePoint;
}

void AutoLayoutCurve::setCentroidSidePoint(const AutoLayoutPoint& centroidSidePoint) {
    _centroidSidePoint.setX(centroidSidePoint.getX());
    _centroidSidePoint.setY(centroidSidePoint.getY());
}

const AutoLayoutPoint& AutoLayoutCurve::getCentroidSideControlPoint() {
    return _centroidSideControlPoint;
}

void AutoLayoutCurve::setCentroidSideControlPoint(const AutoLayoutPoint& centroidSideControlPoint) {
    _centroidSideControlPoint.setX(centroidSideControlPoint.getX());
    _centroidSideControlPoint.setY(centroidSideControlPoint.getY());
}
