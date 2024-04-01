#include "libsbml_ne_autolayout_node.h"
#include "../libsbml_ne_layout_helpers.h"

// AutoLayoutNodeBase

AutoLayoutNodeBase::AutoLayoutNodeBase(Model* model, Layout* layout) : AutoLayoutObjectBase(model, layout) {
    _degree = 0;
    _locked = false;
}

void AutoLayoutNodeBase::updateDimensions() {
    setWidth(std::max(calculateWidth(), getWidth()));
    setHeight(std::max(calculateHeight(), getHeight()));
}

void AutoLayoutNodeBase::setPosition(const AutoLayoutPoint position) {
    setX(position.getX() - 0.5 * getWidth());
    setY(position.getY() - 0.5 * getHeight());
}

const AutoLayoutPoint AutoLayoutNodeBase::getPosition() {
    return AutoLayoutPoint(getX() + 0.5 * getWidth(), getY() + 0.5 * getHeight());
}

const double AutoLayoutNodeBase::getDisplacementX() {
    return _displacementX;
}

void AutoLayoutNodeBase::setDisplacementX(const double& dx) {
    _displacementX = dx;
}

const double AutoLayoutNodeBase::getDisplacementY() {
    return _displacementY;
}

void AutoLayoutNodeBase::setDisplacementY(const double& dy) {
    _displacementY= dy;
}

void AutoLayoutNodeBase::setDisplacement(const AutoLayoutPoint displacement) {
    setDisplacementX(displacement.getX());
    setDisplacementY(displacement.getY());
}

const AutoLayoutPoint AutoLayoutNodeBase::getDisplacement() {
    return AutoLayoutPoint(getDisplacementX(), getDisplacementY());
}

const int AutoLayoutNodeBase::getDegree() {
    return _degree;
}

void AutoLayoutNodeBase::incrementDegree() {
    _degree++;
}

void AutoLayoutNodeBase::setLocked(const bool& locked) {
    _locked = locked;
}

const bool AutoLayoutNodeBase::isLocked() {
    return _locked;
}

// AutoLayoutNode

AutoLayoutNode::AutoLayoutNode(Model* model, Layout* layout, SpeciesGlyph* speciesGlyph) : AutoLayoutNodeBase(model, layout) {
    _speciesGlyph = speciesGlyph;
}

const std::string AutoLayoutNode::getId() {
    return _speciesGlyph->getId();
}

GraphicalObject* AutoLayoutNode::getGraphicalObject() {
    return _speciesGlyph;
}

const double AutoLayoutNode::getX() {
    return _speciesGlyph->getBoundingBox()->x();
}

void AutoLayoutNode::setX(const double& x) {
    _speciesGlyph->getBoundingBox()->setX(x);
}

const double AutoLayoutNode::getY() {
    return _speciesGlyph->getBoundingBox()->y();
}

void AutoLayoutNode::setY(const double& y) {
    _speciesGlyph->getBoundingBox()->setY(y);
}

const double AutoLayoutNode::getWidth() {
    return _speciesGlyph->getBoundingBox()->width();
}

void AutoLayoutNode::setWidth(const double& width) {
    _speciesGlyph->getBoundingBox()->setWidth(width);
}

const double AutoLayoutNode::getHeight() {
    return _speciesGlyph->getBoundingBox()->height();
}

void AutoLayoutNode::setHeight(const double& height) {
    _speciesGlyph->getBoundingBox()->setHeight(height);
}

const double AutoLayoutNode::calculateWidth() {
    std::string displayedText = _speciesGlyph->getSpeciesId();
    Species *species = LIBSBML_NETWORKEDITOR_CPP_NAMESPACE::findSpeciesGlyphSpecies(_model, _speciesGlyph);
    if (species && species->isSetName())
        displayedText = species->getName();

    return std::max(60.0, displayedText.size() * 15.0);
}

const double AutoLayoutNode::calculateHeight() {
    return std::max(36.0, getHeight());
}

// AutoLayoutCentroidNode


AutoLayoutCentroidNode::AutoLayoutCentroidNode(Model* model, Layout* layout, ReactionGlyph* reactionGlyph) : AutoLayoutNodeBase(model, layout) {
    _reactionGlyph = reactionGlyph;
}

const std::string AutoLayoutCentroidNode::getId() {
    return _reactionGlyph->getId();
}

GraphicalObject* AutoLayoutCentroidNode::getGraphicalObject() {
    return _reactionGlyph;
}

const double AutoLayoutCentroidNode::getX() {
    return 0.5 * (_reactionGlyph->getCurve()->getCurveSegment(0)->getStart()->x() + _reactionGlyph->getCurve()->getCurveSegment(0)->getEnd()->x());
}

void AutoLayoutCentroidNode::setX(const double& x) {
    _reactionGlyph->getCurve()->getCurveSegment(0)->getStart()->setX(x);
    ((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint1()->setX(x);
    _reactionGlyph->getCurve()->getCurveSegment(0)->getEnd()->setX(x);
    ((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint2()->setX(x);
}

const double AutoLayoutCentroidNode::getY() {
    return 0.5 * (_reactionGlyph->getCurve()->getCurveSegment(0)->getStart()->y() + _reactionGlyph->getCurve()->getCurveSegment(0)->getEnd()->y());
}

void AutoLayoutCentroidNode::setY(const double& y) {
    _reactionGlyph->getCurve()->getCurveSegment(0)->getStart()->setY(y);
    ((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint1()->setY(y);
    _reactionGlyph->getCurve()->getCurveSegment(0)->getEnd()->setY(y);
    ((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint2()->setY(y);
}

const double AutoLayoutCentroidNode::getWidth() {
    return _reactionGlyph->getCurve()->getCurveSegment(0)->getEnd()->x() - _reactionGlyph->getCurve()->getCurveSegment(0)->getStart()->x();
}

void AutoLayoutCentroidNode::setWidth(const double& width) {
    if (std::abs(width - getWidth())) {
        _reactionGlyph->getCurve()->getCurveSegment(0)->getStart()->setX(_reactionGlyph->getCurve()->getCurveSegment(0)->getStart()->x() - 0.5 * std::abs(width - getWidth()));
        ((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint1()->setX(((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint1()->x() - 0.5 * std::abs(width - getWidth()));
        _reactionGlyph->getCurve()->getCurveSegment(0)->getEnd()->setX(_reactionGlyph->getCurve()->getCurveSegment(0)->getEnd()->x() + 0.5 * std::abs(width - getWidth()));
        ((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint2()->setX(((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint2()->x() - 0.5 * std::abs(width - getWidth()));
    }
}

const double AutoLayoutCentroidNode::getHeight() {
    return _reactionGlyph->getCurve()->getCurveSegment(0)->getEnd()->y() - _reactionGlyph->getCurve()->getCurveSegment(0)->getStart()->y();
}

void AutoLayoutCentroidNode::setHeight(const double& height) {
    if (std::abs(height - getHeight())) {
        _reactionGlyph->getCurve()->getCurveSegment(0)->getStart()->setY(_reactionGlyph->getCurve()->getCurveSegment(0)->getStart()->y() - 0.5 * std::abs(height - getHeight()));
        ((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint1()->setY(((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint1()->y() - 0.5 * std::abs(height - getHeight()));
        _reactionGlyph->getCurve()->getCurveSegment(0)->getEnd()->setY(_reactionGlyph->getCurve()->getCurveSegment(0)->getEnd()->y() + 0.5 * std::abs(height - getHeight()));
        ((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint2()->setY(((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint2()->y() - 0.5 * std::abs(height - getHeight()));
    }
}

const double AutoLayoutCentroidNode::calculateWidth() {
    return getWidth();
}

const double AutoLayoutCentroidNode::calculateHeight() {
    return getHeight();
}
