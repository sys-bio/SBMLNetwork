#include "libsbml_ne_autolayout_node.h"

AutoLayoutNode::AutoLayoutNode(GraphicalObject* graphicalObject) {
    _graphicalObject = graphicalObject;
    _degree = 0;
}

const std::string AutoLayoutNode::getId() {
    return _graphicalObject->getId();
}

const double AutoLayoutNode::getX() {
    return _graphicalObject->getBoundingBox()->x();
};

void AutoLayoutNode::setX(const double& x) {
    _graphicalObject->getBoundingBox()->setX(x);
}

const double AutoLayoutNode::getY() {
    return _graphicalObject->getBoundingBox()->y();
};

void AutoLayoutNode::setY(const double& y) {
    _graphicalObject->getBoundingBox()->setY(y);
}

const double AutoLayoutNode::getWidth() {
    return _graphicalObject->getBoundingBox()->width();
};

void AutoLayoutNode::setWidth(const double& width) {
    _graphicalObject->getBoundingBox()->setWidth(width);
}

const double AutoLayoutNode::getHeight() {
    return _graphicalObject->getBoundingBox()->height();
};

void AutoLayoutNode::setHeight(const double& height) {
    _graphicalObject->getBoundingBox()->setHeight(height);
}

const double AutoLayoutNode::getDisplacementX() {
    return _displacementX;
}

void AutoLayoutNode::setDisplacementX(const double& dx) {
    _displacementX = dx;
}

const double AutoLayoutNode::getDisplacementY() {
    return _displacementY;
}

void AutoLayoutNode::setDisplacementY(const double& dy) {
    _displacementY= dy;
}

const int AutoLayoutNode::getDegree() {
    return _degree;
}

void AutoLayoutNode::setDegree(const int& degree) {
    _degree = degree;
}
