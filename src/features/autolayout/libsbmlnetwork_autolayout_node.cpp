#include "libsbmlnetwork_autolayout_node.h"
#include "../../libsbmlnetwork_layout_helpers.h"
#include "../../libsbmlnetwork_common.h"
#include "../user_data/libsbmlnetwork_user_data.h"
#include "../defaults/libsbmlnetwork_defaults_layout.h"

// AutoLayoutNodeBase

AutoLayoutNodeBase::AutoLayoutNodeBase(Model* model, Layout* layout, GraphicalObject* graphicalObject, const bool& positionFixed) : AutoLayoutObjectBase(model, layout) {
    _degree = 0;
    if (LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(layout, "use_name_as_text_label") == "false")
        _useNameAsTextLabel = false;
    else
        _useNameAsTextLabel = true;
    _graphicalObject = graphicalObject;
    setPositionFixed(positionFixed);
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

const bool AutoLayoutNodeBase::isPositionFixed() {
    return _positionFixed;
}

void AutoLayoutNodeBase::setPositionFixed(const bool& positionFixed) {
    _positionFixed = positionFixed;
}

void AutoLayoutNodeBase::updateFixedPositionStatus() {;
    if (LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(_graphicalObject, "fixed_position") == "true") {
        setPositionFixed(true);
        setX(std::stod(LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(_graphicalObject, "x")));
        setY(std::stod(LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(_graphicalObject, "y")));
    }
}

// AutoLayoutNode

AutoLayoutNode::AutoLayoutNode(Model* model, Layout* layout, GraphicalObject* graphicalObject, const bool& positionFixed) : AutoLayoutNodeBase(model, layout, graphicalObject, positionFixed) {

}

const std::string AutoLayoutNode::getId() {
    return _graphicalObject->getId();
}

GraphicalObject* AutoLayoutNode::getGraphicalObject() {
    return _graphicalObject;
}

void AutoLayoutNode::updateDimensions() {
    std::string fixedWidth = LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(getGraphicalObject(), "width");
    if (fixedWidth.empty())
        setWidth(std::max(calculateWidth(), std::max(getWidth(), getDefaultWidth())));
    else
        setWidth(std::stod(fixedWidth));
    std::string fixedHeight = LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(getGraphicalObject(), "height");
    if (fixedHeight.empty())
        setHeight(std::max(calculateHeight(), std::max(getHeight(), getDefaultHeight())));
    else
        setHeight(std::stod(fixedHeight));
}

const double AutoLayoutNode::getX() {
    return _graphicalObject->getBoundingBox()->x();
}

void AutoLayoutNode::setX(const double& x) {
    _graphicalObject->getBoundingBox()->setX(x);
}

const double AutoLayoutNode::getY() {
    return _graphicalObject->getBoundingBox()->y();
}

void AutoLayoutNode::setY(const double& y) {
    _graphicalObject->getBoundingBox()->setY(y);
}

const double AutoLayoutNode::getWidth() {
    return _graphicalObject->getBoundingBox()->width();
}

const double AutoLayoutNode::getDefaultWidth() {
    return LIBSBMLNETWORK_CPP_NAMESPACE::defaults_getSpeciesDefaultWidth();
}

void AutoLayoutNode::setWidth(const double& width) {
    _graphicalObject->getBoundingBox()->setWidth(width);
}

const double AutoLayoutNode::getHeight() {
    return _graphicalObject->getBoundingBox()->height();
}

const double AutoLayoutNode::getDefaultHeight() {
    return LIBSBMLNETWORK_CPP_NAMESPACE::defaults_getSpeciesDefaultHeight();
}

void AutoLayoutNode::setHeight(const double& height) {
    _graphicalObject->getBoundingBox()->setHeight(height);
}

const double AutoLayoutNode::calculateWidth() {
    SpeciesGlyph* speciesGlyph = (SpeciesGlyph*)_graphicalObject;
    std::string displayedText = speciesGlyph->getSpeciesId();
    Species *species = LIBSBMLNETWORK_CPP_NAMESPACE::findSpeciesGlyphSpecies(_model, speciesGlyph);
    if (species && species->isSetName() && _useNameAsTextLabel)
        displayedText = species->getName();

    return std::max(60.0, displayedText.size() * 15.0);
}

const double AutoLayoutNode::calculateHeight() {
    return std::max(36.0, getHeight());
}

// AutoLayoutCentroidNode


AutoLayoutCentroidNode::AutoLayoutCentroidNode(Model* model, Layout* layout, GraphicalObject* graphicalObject, const bool& positionFixed) : AutoLayoutNodeBase(model, layout, graphicalObject, positionFixed) {

}

const std::string AutoLayoutCentroidNode::getId() {
    return _graphicalObject->getId();
}

GraphicalObject* AutoLayoutCentroidNode::getGraphicalObject() {
    return _graphicalObject;
}

void AutoLayoutCentroidNode::updateDimensions() {
    std::string fixedWidth = LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(getGraphicalObject(), "width");
    if (fixedWidth.empty())
        setWidth(calculateWidth());
    else
        setWidth(std::stod(fixedWidth));
    std::string fixedHeight = LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(getGraphicalObject(), "height");
    if (fixedHeight.empty())
        setHeight(calculateHeight());
    else
        setHeight(std::stod(fixedHeight));
}

const double AutoLayoutCentroidNode::getX() {
    if (isSetCurve()) {
        const LineSegment* ls = getCurve()->getCurveSegment(0);
        return 0.5 * (ls->getStart()->x() + ls->getEnd()->x());
    }

    return _graphicalObject->getBoundingBox()->x();
}

void AutoLayoutCentroidNode::setX(const double& x) {
    if (isSetCurve()) {
        Curve* curve = getCurve();
        curve->getCurveSegment(0)->getStart()->setX(x);
        ((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint1()->setX(x);
        curve->getCurveSegment(0)->getEnd()->setX(x);
        ((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint2()->setX(x);
        _graphicalObject->getBoundingBox()->setX(x - 0.5 * getWidth());
    }
    else
        _graphicalObject->getBoundingBox()->setX(x);
}

const double AutoLayoutCentroidNode::getY() {
    if (isSetCurve()) {
        const LineSegment* ls = getCurve()->getCurveSegment(0);
        return 0.5 * (ls->getStart()->y() + ls->getEnd()->y());
    }

    return _graphicalObject->getBoundingBox()->y();
}

void AutoLayoutCentroidNode::setY(const double& y) {
    if (isSetCurve()) {
        Curve* curve = getCurve();
        curve->getCurveSegment(0)->getStart()->setY(y);
        ((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint1()->setY(y);
        curve->getCurveSegment(0)->getEnd()->setY(y);
        ((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint2()->setY(y);
        _graphicalObject->getBoundingBox()->setY(y - 0.5 * getHeight());
    }
    else
        _graphicalObject->getBoundingBox()->setY(y);
}

const double AutoLayoutCentroidNode::getWidth() {
    if (isSetCurve()) {
        const LineSegment* ls = getCurve()->getCurveSegment(0);
        return ls->getEnd()->x() - ls->getStart()->x();
    }

    return _graphicalObject->getBoundingBox()->width();
}

const double AutoLayoutCentroidNode::getDefaultWidth() {
    return getWidth();
}

void AutoLayoutCentroidNode::setWidth(const double& width) {
    if (std::abs(width - getWidth())) {
        if (isSetCurve()) {
            Curve* curve = getCurve();
            if (LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(_graphicalObject, "fixed_position") == "true") {
                std::string fixedX = LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(_graphicalObject, "x");
                if (!fixedX.empty()) {
                    curve->getCurveSegment(0)->getStart()->setX(std::stod(fixedX) - 0.5 * width);
                    ((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint1()->setX(std::stod(fixedX) - 0.5 * width);
                    curve->getCurveSegment(0)->getEnd()->setX(std::stod(fixedX) + 0.5 * width);
                    ((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint2()->setX(std::stod(fixedX) - 0.5 * width);
                }
            }
            else {
                curve->getCurveSegment(0)->getStart()->setX(
                        curve->getCurveSegment(0)->getStart()->x() - 0.5 * std::abs(width - getWidth()));
                ((CubicBezier * )(curve->getCurveSegment(0)))->getBasePoint1()->setX(
                        ((CubicBezier * )(curve->getCurveSegment(0)))->getBasePoint1()->x() -
                        0.5 * std::abs(width - getWidth()));
                curve->getCurveSegment(0)->getEnd()->setX(
                        curve->getCurveSegment(0)->getEnd()->x() + 0.5 * std::abs(width - getWidth()));
                ((CubicBezier * )(curve->getCurveSegment(0)))->getBasePoint2()->setX(
                        ((CubicBezier * )(curve->getCurveSegment(0)))->getBasePoint2()->x() -
                        0.5 * std::abs(width - getWidth()));
            }
        }
        _graphicalObject->getBoundingBox()->setWidth(width);
    }
}

const double AutoLayoutCentroidNode::getHeight() {
    if (isSetCurve()) {
        const LineSegment* ls = getCurve()->getCurveSegment(0);
        return ls->getEnd()->y() - ls->getStart()->y();
    }

    return _graphicalObject->getBoundingBox()->height();
}

const double AutoLayoutCentroidNode::getDefaultHeight() {
    return getHeight();
}

void AutoLayoutCentroidNode::setHeight(const double& height) {
    if (std::abs(height - getHeight())) {
        if (isSetCurve()) {
            Curve* curve = getCurve();
            if (LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(_graphicalObject, "fixed_position") == "true") {
                std::string fixedY = LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(_graphicalObject, "y");
                if (!fixedY.empty()) {
                    curve->getCurveSegment(0)->getStart()->setY(std::stod(fixedY) - 0.5 * height);
                    ((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint1()->setY(std::stod(fixedY) - 0.5 * height);
                    curve->getCurveSegment(0)->getEnd()->setY(std::stod(fixedY) + 0.5 * height);
                    ((CubicBezier*)(curve->getCurveSegment(0)))->getBasePoint2()->setY(std::stod(fixedY) - 0.5 * height);
                }
            }
            else {
                curve->getCurveSegment(0)->getStart()->setY(
                        curve->getCurveSegment(0)->getStart()->y() - 0.5 * std::abs(height - getHeight()));
                ((CubicBezier * )(curve->getCurveSegment(0)))->getBasePoint1()->setY(
                        ((CubicBezier * )(curve->getCurveSegment(0)))->getBasePoint1()->y() -
                        0.5 * std::abs(height - getHeight()));
                curve->getCurveSegment(0)->getEnd()->setY(
                        curve->getCurveSegment(0)->getEnd()->y() + 0.5 * std::abs(height - getHeight()));
                ((CubicBezier * )(curve->getCurveSegment(0)))->getBasePoint2()->setY(
                        ((CubicBezier * )(curve->getCurveSegment(0)))->getBasePoint2()->y() -
                        0.5 * std::abs(height - getHeight()));
            }
        }
        _graphicalObject->getBoundingBox()->setHeight(height);
    }
}

const double AutoLayoutCentroidNode::calculateWidth() {
    if (isSetCurve())
        return getWidth();

    ReactionGlyph* reactionGlyph = (ReactionGlyph*)_graphicalObject;
    std::string displayedText = reactionGlyph->getReactionId();
    Reaction *reaction = LIBSBMLNETWORK_CPP_NAMESPACE::findReactionGlyphReaction(_model, reactionGlyph);
    if (reaction && reaction->isSetName() && _useNameAsTextLabel)
        displayedText = reaction->getName();

    return std::max(std::max(LIBSBMLNETWORK_CPP_NAMESPACE::defaults_getReactionDefaultWidth(), displayedText.size() * 9.0), getWidth());
}

const double AutoLayoutCentroidNode::calculateHeight() {
    if (isSetCurve())
        return getHeight();

    return std::max(LIBSBMLNETWORK_CPP_NAMESPACE::defaults_getReactionDefaultHeight(), getHeight());
}

const bool AutoLayoutCentroidNode::isSetCurve() {
    return ((ReactionGlyph*)_graphicalObject)->isSetCurve();
}

Curve* AutoLayoutCentroidNode::getCurve() {
    if (isSetCurve())
        return ((ReactionGlyph*)_graphicalObject)->getCurve();

    return NULL;
}
