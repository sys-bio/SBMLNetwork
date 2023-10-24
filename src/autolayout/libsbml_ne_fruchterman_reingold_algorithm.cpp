#include "libsbml_ne_fruchterman_reingold_algorithm.h"
#include "libsbml_ne_autolayout_node.h"
#include "libsbml_ne_autolayout_connection.h"
#include "libsbml_ne_autolayout_curve.h"
#include <cstdlib>
#include <cmath>

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE {

FruthtermanReingoldAlgorithm::FruthtermanReingoldAlgorithm() {

}

void FruthtermanReingoldAlgorithm::setElements(Layout* layout) {
    setNodes(layout);
    setConnections(layout);
}

void FruthtermanReingoldAlgorithm::setNodes(Layout* layout) {
    for (int i = 0; i < layout->getNumSpeciesGlyphs(); i++)
        _nodes.push_back(new AutoLayoutNode(layout, layout->getSpeciesGlyph(i)));
}

void FruthtermanReingoldAlgorithm::setConnections(Layout* layout) {
    for (int i = 0; i < layout->getNumReactionGlyphs(); i++)
        _connections.push_back(new AutoLayoutConnection(layout, layout->getReactionGlyph(i)));
}

void FruthtermanReingoldAlgorithm::setStiffness(const double &stiffness) {
    _stiffness = stiffness;
}

void FruthtermanReingoldAlgorithm::setGravity(const double &gravity) {
    _gravity = gravity;
}

void FruthtermanReingoldAlgorithm::setUseMagnetism(const bool &useMagnetism) {
    _useMagnetism = useMagnetism;
}

void FruthtermanReingoldAlgorithm::setUseBoundary(const bool &useBoundary) {
    _useBoundary = useBoundary;
}

void FruthtermanReingoldAlgorithm::setUseGrid(const bool &useGrid) {
    _useGrid = useGrid;
}

void FruthtermanReingoldAlgorithm::apply() {
    initialize();
    iterate();
}

void FruthtermanReingoldAlgorithm::initialize() {
    _maximumIterations = 100 * std::log(_nodes.size() + 2);
    _initialTemperature = 1000 * std::log(_nodes.size() + 2);
    _currentTemperature = _initialTemperature;
    _time = 0.0;
    _alpha = std::log(_initialTemperature) - std::log(0.25);
    _timeIncrement = 1.0 / _maximumIterations;
    _width = std::sqrt(_nodes.size()) * _stiffness * 5;
    _height = _width;
}

void FruthtermanReingoldAlgorithm::iterate() {
    for (int i = 0; i < _maximumIterations; i++) {
        _currentTemperature = _initialTemperature * std::exp(-_alpha * _time);
        _time += _timeIncrement;
        clearDisplacements();
        computeRepulsiveForces();
        computeAttractiveForces();
        applyMagnetism();
        applyGravity();
        adjustCoordinates();
    }
}

void FruthtermanReingoldAlgorithm::clearDisplacements() {
    for (int i = 0; i < _nodes.size(); i++) {
        ((AutoLayoutNodeBase*)_nodes.at(i))->setDisplacementX(0.0);
        ((AutoLayoutNodeBase*)_nodes.at(i))->setDisplacementY(0.0);
    }
}

void FruthtermanReingoldAlgorithm::computeRepulsiveForces() {
    AutoLayoutNodeBase* vNode = NULL;
    AutoLayoutNodeBase* uNode = NULL;
    for (int vNodeIndex = 0; vNodeIndex < _nodes.size(); vNodeIndex++) {
        vNode = (AutoLayoutNodeBase*)(_nodes.at(vNodeIndex));
        for (int uNodeIndex = vNodeIndex + 1; uNodeIndex < _nodes.size(); uNodeIndex++) {
            uNode = ((AutoLayoutNodeBase*)_nodes.at(uNodeIndex));
            if (vNodeIndex != uNodeIndex) {
                double distanceX = vNode->getX() - uNode->getX();
                double distanceY = vNode->getY() - uNode->getY();
                double distance = calculateEuclideanDistance(AutoLayoutPoint(distanceX, distanceY));
                if (distance < 0.000001)  {
                    vNode->setX(vNode->getX() + std::rand() % int(_stiffness));
                    vNode->setY(vNode->getY() + std::rand() % int(_stiffness));
                }
                else {
                    double repulsionForce = calculateRepulsionForce(_stiffness * calculateStiffnessAdjustmentFactor(vNode, uNode), distance);
                    vNode->setDisplacementX(vNode->getDisplacementX() + (distanceX / distance * repulsionForce));
                    vNode->setDisplacementY(vNode->getDisplacementY() + (distanceY /distance * repulsionForce));
                    uNode->setDisplacementX(uNode->getDisplacementX() - (distanceX / distance * repulsionForce));
                    uNode->setDisplacementY(uNode->getDisplacementY() - (distanceY / distance * repulsionForce));
                }
            }
        }
    }
}

void FruthtermanReingoldAlgorithm::computeAttractiveForces() {
    AutoLayoutCurve* curve = NULL;
    AutoLayoutNodeBase* vNode = NULL;
    AutoLayoutNodeBase* uNode = NULL;

    for (int connectionIndex = 0; connectionIndex < _connections.size(); connectionIndex++) {
        for (int curveIndex = 0; curveIndex < ((AutoLayoutConnection*)_connections.at(connectionIndex))->getCurves().size(); curveIndex++) {
            curve = (AutoLayoutCurve*)(((AutoLayoutConnection*)_connections.at(connectionIndex))->getCurves().at(curveIndex));
            findObject(_nodes, curve->getId());
            vNode = (AutoLayoutNodeBase*)findObject(_nodes, curve->getNodeId());
            if (vNode) {
                uNode = (AutoLayoutNodeBase*)(((AutoLayoutConnection*)_connections.at(connectionIndex))->getCentroidNode());
                double distanceX = vNode->getX() - uNode->getX();
                double distanceY = vNode->getY() - uNode->getY();
                double distance = calculateEuclideanDistance(AutoLayoutPoint(distanceX, distanceY));
                if (distance > 0.000001) {
                    double attractionForce = calculateAttractionForce(_stiffness * calculateStiffnessAdjustmentFactor(vNode, uNode), distance);
                    vNode->setDisplacementX(vNode->getDisplacementX() - (distanceX / distance * attractionForce));
                    vNode->setDisplacementY(vNode->getDisplacementY() - (distanceY /distance * attractionForce));
                    uNode->setDisplacementX(uNode->getDisplacementX() + (distanceX / distance * attractionForce));
                    uNode->setDisplacementY(uNode->getDisplacementY() + (distanceY /distance * attractionForce));
                }
            }
        }
    }
}

void FruthtermanReingoldAlgorithm::applyMagnetism() {
    if (_useMagnetism) {
        AutoLayoutCurve* firstCurve = NULL;
        AutoLayoutCurve* secondCurve = NULL;
        AutoLayoutNodeBase* vNode = NULL;
        AutoLayoutNodeBase* uNode = NULL;
        for (int connectionIndex = 0; connectionIndex < _connections.size(); connectionIndex++) {
            for (int firstCurveIndex = 0; firstCurveIndex < ((AutoLayoutConnection*)_connections.at(connectionIndex))->getCurves().size(); firstCurveIndex++) {
                firstCurve = (AutoLayoutCurve*)(((AutoLayoutConnection*)_connections.at(connectionIndex))->getCurves().at(firstCurveIndex));
                vNode = (AutoLayoutNodeBase*)findObject(_nodes, firstCurve->getNodeId());
                if (vNode && !vNode->isLocked()) {
                    for (int secondCurveIndex = 0; secondCurveIndex < ((AutoLayoutConnection*)_connections.at(connectionIndex))->getCurves().size(); secondCurveIndex++) {
                        secondCurve = (AutoLayoutCurve*)(((AutoLayoutConnection*)_connections.at(connectionIndex))->getCurves().at(secondCurveIndex));
                        uNode = (AutoLayoutNodeBase*)findObject(_nodes, secondCurve->getNodeId());
                        if (uNode && firstCurveIndex != secondCurveIndex && firstCurve->getRole() == secondCurve->getRole() && vNode->getDegree() <= 1) {
                            double distanceX = vNode->getX() - uNode->getX();
                            double distanceY = vNode->getY() - uNode->getY();
                            double distance = calculateEuclideanDistance(AutoLayoutPoint(distanceX, distanceY));
                            if (distance > 0.000001) {
                                double attractionForce = calculateAttractionForce(_stiffness * calculateStiffnessAdjustmentFactor(vNode, uNode), distance);
                                vNode->setDisplacementX(vNode->getDisplacementX() - 0.25 * (distanceX / distance * attractionForce));
                                vNode->setDisplacementY(vNode->getDisplacementY() - 0.25 * (distanceY /distance * attractionForce));
                                uNode->setDisplacementX(uNode->getDisplacementX() + 0.25 * (distanceX / distance * attractionForce));
                                uNode->setDisplacementY(uNode->getDisplacementY() + 0.25 * (distanceY /distance * attractionForce));
                            }
                        }
                    }
                }
            }
        }
    }
}

void FruthtermanReingoldAlgorithm::applyGravity() {
    if (_gravity > 5.0) {
        AutoLayoutNodeBase* node = NULL;
        for(int nodeIndex = 0; nodeIndex < _nodes.size(); nodeIndex++) {
            node = (AutoLayoutNodeBase*)_nodes.at(nodeIndex);
            if (!node->isLocked()) {
                double distanceX = node->getX() - _barycenter.getX();
                double distanceY = node->getY() - _barycenter.getY();
                double distance = calculateEuclideanDistance(AutoLayoutPoint(distanceX, distanceY));
                if (distance > 0.000001) {
                    double force = distance * (_gravity / _stiffness);
                    node->setDisplacementX(node->getDisplacementX() - (distanceX / distance * force));
                    node->setDisplacementY(node->getDisplacementY() - (distanceY / distance * force));
                }
            }
        }
    }
}

void FruthtermanReingoldAlgorithm::adjustCoordinates() {
    for (int nodeIndex = 0; nodeIndex < _nodes.size(); nodeIndex++) {
        AutoLayoutNodeBase* node = (AutoLayoutNodeBase*)_nodes.at(nodeIndex);
        if (!node->isLocked()) {
            double distanceX = node->getDisplacementX();
            double distanceY = node->getDisplacementY();
            double distance = calculateEuclideanDistance(AutoLayoutPoint(distanceX, distanceY));
            if (distance > 0.000001) {
                node->setX(node->getX() + (distanceX / distance) * _currentTemperature);
                node->setY(node->getY() + (distanceY / distance) * _currentTemperature);
            }
            if(_useBoundary)
                adjustWithinTheBoundary(node);
            if (_useGrid && _currentTemperature < _stiffness)
                adjustOnTheGrids(node);
        }
    }
}

void FruthtermanReingoldAlgorithm::adjustWithinTheBoundary(AutoLayoutObjectBase* node) {
    if (((AutoLayoutNodeBase*)node)->getX() > 0.5 * _width)
        ((AutoLayoutNodeBase*)node)->setX(0.5 * _width - (_stiffness + std::rand() % int(0.25 * _width)));
    if (((AutoLayoutNodeBase*)node)->getY() > 0.5 * _height)
        ((AutoLayoutNodeBase*)node)->setY(0.5 * _height - (_stiffness + std::rand() % int(0.25 * _height)));
    if (((AutoLayoutNodeBase*)node)->getX() < -0.5 * _width)
        ((AutoLayoutNodeBase*)node)->setX(-0.5 * _width + (_stiffness + std::rand() % int(0.25 * _width)));
    if (((AutoLayoutNodeBase*)node)->getY() < -0.5 * _height)
        ((AutoLayoutNodeBase*)node)->setY(-0.5 * _height + (_stiffness + std::rand() % int(0.25 * _height)));
}

void FruthtermanReingoldAlgorithm::adjustOnTheGrids(AutoLayoutObjectBase* node) {
    ((AutoLayoutNodeBase*)node)->setX(std::floor(((AutoLayoutNodeBase*)node)->getX() / _stiffness) * _stiffness);
    ((AutoLayoutNodeBase*)node)->setY(std::floor(((AutoLayoutNodeBase*)node)->getY() / _stiffness) * _stiffness);
}

const double calculateEuclideanDistance(AutoLayoutPoint point) {
    return std::sqrt(point.getX() * point.getX() + point.getY() * point.getY());
}

const double calculateStiffnessAdjustmentFactor(AutoLayoutObjectBase* vNode, AutoLayoutObjectBase* uNode) {
    return std::log(((AutoLayoutNodeBase*)vNode)->getDegree() + ((AutoLayoutNodeBase*)uNode)->getDegree() + 2) + 0.25 * (std::max(((AutoLayoutNodeBase*)((AutoLayoutNodeBase*)uNode))->getWidth(), ((AutoLayoutNodeBase*)vNode)->getHeight()) + std::max(((AutoLayoutNodeBase*)uNode)->getWidth(), ((AutoLayoutNodeBase*)uNode)->getHeight()));
}

const double calculateRepulsionForce(const double& stiffness, const double& distance) {
    return stiffness * stiffness / distance;
}

const double calculateAttractionForce(const double& stiffness, const double& distance) {
    return distance * distance / stiffness;
}

AutoLayoutObjectBase* findObject(std::vector<AutoLayoutObjectBase*> objects, const std::string& objectId) {
    for (int i = 0; i < objects.size(); i++) {
        if (objects.at(i)->getId() == objectId)
            return objects.at(i);
    }

    return NULL;
}

}
