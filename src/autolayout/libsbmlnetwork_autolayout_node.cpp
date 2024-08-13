#include "libsbmlnetwork_autolayout_node.h"
#include "../libsbmlnetwork_layout_helpers.h"

// AutoLayoutNodeBase

AutoLayoutNodeBase::AutoLayoutNodeBase(Model* model, Layout* layout, const bool& useNameAsTextLabel, const bool& locked) : AutoLayoutObjectBase(model, layout) {
    _degree = 0;
    _useNameAsTextLabel = useNameAsTextLabel;
    setLocked(locked);
}

void AutoLayoutNodeBase::updateDimensions() {
    std::string fixedWidth = LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(getGraphicalObject(), "width");
    if (fixedWidth.empty())
        setWidth(std::max(calculateWidth(), std::max(getWidth(), getDefaultWidth())));
    else
        setWidth(std::stod(fixedWidth));
    std::string fixedHeight = LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(getGraphicalObject(), "height");
    if (fixedHeight.empty())
        setHeight(std::max(calculateHeight(), std::max(getHeight(), getDefaultHeight())));
    else
        setHeight(std::stod(fixedHeight));
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

const bool AutoLayoutNodeBase::isLocked() {
    return _locked;
}

void AutoLayoutNodeBase::setLocked(const bool& locked) {
    _locked = locked;
}

// AutoLayoutNode

AutoLayoutNode::AutoLayoutNode(Model* model, Layout* layout, SpeciesGlyph* speciesGlyph, const bool& useNameAsTextLabel, const bool& locked) : AutoLayoutNodeBase(model, layout, useNameAsTextLabel, locked) {
    _speciesGlyph = speciesGlyph;
}

const std::string AutoLayoutNode::getId() {
    return _speciesGlyph->getId();
}

GraphicalObject* AutoLayoutNode::getGraphicalObject() {
    return _speciesGlyph;
}

void AutoLayoutNode::updateLockedStatus() {;
    if (LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(_speciesGlyph, "locked") == "true") {
        setLocked(true);
        setX(std::stod(LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(_speciesGlyph, "x")));
        setY(std::stod(LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(_speciesGlyph, "y")));
    }
    else
        setLocked(false);
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

const double AutoLayoutNode::getDefaultWidth() {
    return 60.0;
}

void AutoLayoutNode::setWidth(const double& width) {
    _speciesGlyph->getBoundingBox()->setWidth(width);
}

const double AutoLayoutNode::getHeight() {
    return _speciesGlyph->getBoundingBox()->height();
}

const double AutoLayoutNode::getDefaultHeight() {
    return 36.0;
}

void AutoLayoutNode::setHeight(const double& height) {
    _speciesGlyph->getBoundingBox()->setHeight(height);
}

const double AutoLayoutNode::calculateWidth() {
    std::string displayedText = _speciesGlyph->getSpeciesId();
    Species *species = LIBSBMLNETWORK_CPP_NAMESPACE::findSpeciesGlyphSpecies(_model, _speciesGlyph);
    if (species && species->isSetName() && _useNameAsTextLabel)
        displayedText = species->getName();

    return std::max(60.0, displayedText.size() * 15.0);
}

const double AutoLayoutNode::calculateHeight() {
    return std::max(36.0, getHeight());
}

// AutoLayoutCentroidNode


AutoLayoutCentroidNode::AutoLayoutCentroidNode(Model* model, Layout* layout, ReactionGlyph* reactionGlyph, const bool& useNameAsTextLabel, const bool& locked) : AutoLayoutNodeBase(model, layout, useNameAsTextLabel, locked) {
    _reactionGlyph = reactionGlyph;
}

void AutoLayoutCentroidNode::updateLockedStatus() {
    if (LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(_reactionGlyph, "locked") == "true") {
        setLocked(true);
        setX(std::stod(LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(_reactionGlyph, "x")));
        setY(std::stod(LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(_reactionGlyph, "y")));
    }
    else
        setLocked(false);
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
    _reactionGlyph->getBoundingBox()->setX(x);
}

const double AutoLayoutCentroidNode::getY() {
    return 0.5 * (_reactionGlyph->getCurve()->getCurveSegment(0)->getStart()->y() + _reactionGlyph->getCurve()->getCurveSegment(0)->getEnd()->y());
}

void AutoLayoutCentroidNode::setY(const double& y) {
    _reactionGlyph->getCurve()->getCurveSegment(0)->getStart()->setY(y);
    ((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint1()->setY(y);
    _reactionGlyph->getCurve()->getCurveSegment(0)->getEnd()->setY(y);
    ((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint2()->setY(y);
    _reactionGlyph->getBoundingBox()->setY(y);
}

const double AutoLayoutCentroidNode::getWidth() {
    return _reactionGlyph->getCurve()->getCurveSegment(0)->getEnd()->x() - _reactionGlyph->getCurve()->getCurveSegment(0)->getStart()->x();
}

const double AutoLayoutCentroidNode::getDefaultWidth() {
    return getWidth();
}

void AutoLayoutCentroidNode::setWidth(const double& width) {
    if (std::abs(width - getWidth())) {
        _reactionGlyph->getCurve()->getCurveSegment(0)->getStart()->setX(_reactionGlyph->getCurve()->getCurveSegment(0)->getStart()->x() - 0.5 * std::abs(width - getWidth()));
        ((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint1()->setX(((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint1()->x() - 0.5 * std::abs(width - getWidth()));
        _reactionGlyph->getCurve()->getCurveSegment(0)->getEnd()->setX(_reactionGlyph->getCurve()->getCurveSegment(0)->getEnd()->x() + 0.5 * std::abs(width - getWidth()));
        ((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint2()->setX(((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint2()->x() - 0.5 * std::abs(width - getWidth()));
        _reactionGlyph->getBoundingBox()->setWidth(width);
    }
}

const double AutoLayoutCentroidNode::getHeight() {
    return _reactionGlyph->getCurve()->getCurveSegment(0)->getEnd()->y() - _reactionGlyph->getCurve()->getCurveSegment(0)->getStart()->y();
}

const double AutoLayoutCentroidNode::getDefaultHeight() {
    return getHeight();
}

void AutoLayoutCentroidNode::setHeight(const double& height) {
    if (std::abs(height - getHeight())) {
        _reactionGlyph->getCurve()->getCurveSegment(0)->getStart()->setY(_reactionGlyph->getCurve()->getCurveSegment(0)->getStart()->y() - 0.5 * std::abs(height - getHeight()));
        ((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint1()->setY(((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint1()->y() - 0.5 * std::abs(height - getHeight()));
        _reactionGlyph->getCurve()->getCurveSegment(0)->getEnd()->setY(_reactionGlyph->getCurve()->getCurveSegment(0)->getEnd()->y() + 0.5 * std::abs(height - getHeight()));
        ((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint2()->setY(((CubicBezier*)(_reactionGlyph->getCurve()->getCurveSegment(0)))->getBasePoint2()->y() - 0.5 * std::abs(height - getHeight()));
        _reactionGlyph->getBoundingBox()->setHeight(height);
    }
}

const double AutoLayoutCentroidNode::calculateWidth() {
    std::string displayedText = _reactionGlyph->getReactionId();
    Reaction *reaction = LIBSBMLNETWORK_CPP_NAMESPACE::findReactionGlyphReaction(_model, _reactionGlyph);
    if (reaction && reaction->isSetName() && _useNameAsTextLabel)
        displayedText = reaction->getName();

    return std::max(30.0, displayedText.size() * 9.0);
}

const double AutoLayoutCentroidNode::calculateHeight() {
    return std::max(20.0, getHeight());
}
