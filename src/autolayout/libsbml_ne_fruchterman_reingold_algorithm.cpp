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
    setNodesDegrees();
}

void FruthtermanReingoldAlgorithm::setNodes(Layout* layout) {
    for (int i = 0; i < layout->getNumSpeciesGlyphs(); i++)
        _nodes.push_back(new AutoLayoutNode(layout, layout->getSpeciesGlyph(i)));
}

void FruthtermanReingoldAlgorithm::setConnections(Layout* layout) {
    for (int i = 0; i < layout->getNumReactionGlyphs(); i++)
        _connections.push_back(new AutoLayoutConnection(layout, layout->getReactionGlyph(i)));
}

void FruthtermanReingoldAlgorithm::setNodesDegrees() {
    AutoLayoutCurve* curve = NULL;
    AutoLayoutNodeBase* vNode = NULL;
    AutoLayoutNodeBase* uNode = NULL;
    for (int connectionIndex = 0; connectionIndex < _connections.size(); connectionIndex++) {
        for (int curveIndex = 0; curveIndex < ((AutoLayoutConnection*)_connections.at(connectionIndex))->getCurves().size(); curveIndex++) {
            curve = (AutoLayoutCurve*)(((AutoLayoutConnection*)_connections.at(connectionIndex))->getCurves().at(curveIndex));
            vNode = (AutoLayoutNodeBase*)findObject(_nodes, curve->getNodeId());
            uNode = (AutoLayoutNodeBase*)((AutoLayoutConnection*)_connections.at(connectionIndex))->getCentroidNode();
            if (vNode && uNode) {
                vNode->incrementDegree();
                uNode->incrementDegree();
            }
        }
    }
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
    updateConnectionsControlPoints();
}

void FruthtermanReingoldAlgorithm::initialize() {
    _maximumIterations = 100 * std::log(_nodes.size() + 2);
    _initialTemperature = 1000 * std::log(_nodes.size() + 2);
    _currentTemperature = _initialTemperature;
    _time = 0.0;
    _alpha = std::log(_initialTemperature) - std::log(0.25);
    _timeIncrement = 1.0 / _maximumIterations;
    _width = std::sqrt(_nodes.size()) * _stiffness * 10;
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
    for (int connectionIndex = 0; connectionIndex < _connections.size(); connectionIndex++) {
        ((AutoLayoutNodeBase*)((AutoLayoutConnection*)(_connections.at(connectionIndex)))->getCentroidNode())->setDisplacementX(0.0);
        ((AutoLayoutNodeBase*)((AutoLayoutConnection*)(_connections.at(connectionIndex)))->getCentroidNode())->setDisplacementY(0.0);
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
    for (int nodeIndex = 0; nodeIndex < _nodes.size(); nodeIndex++)
        adjustNodeCoordinates(_nodes.at(nodeIndex));
    for (int connectionIndex = 0; connectionIndex < _connections.size(); connectionIndex++)
        adjustNodeCoordinates(((AutoLayoutConnection*)_connections.at(connectionIndex))->getCentroidNode());
}

void FruthtermanReingoldAlgorithm::adjustNodeCoordinates(AutoLayoutObjectBase* node) {
    if (!((AutoLayoutNodeBase*)node)->isLocked()) {
        double distanceX = ((AutoLayoutNodeBase*)node)->getDisplacementX();
        double distanceY = ((AutoLayoutNodeBase*)node)->getDisplacementY();
        double distance = calculateEuclideanDistance(AutoLayoutPoint(distanceX, distanceY));
        if (distance > 0.000001) {
            ((AutoLayoutNodeBase*)node)->setX(((AutoLayoutNodeBase*)node)->getX() + (distanceX / distance) * _currentTemperature);
            ((AutoLayoutNodeBase*)node)->setY(((AutoLayoutNodeBase*)node)->getY() + (distanceY / distance) * _currentTemperature);
        }
        if(_useBoundary)
            adjustWithinTheBoundary(node);
        if (_useGrid && _currentTemperature < _stiffness)
            adjustOnTheGrids(node);
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

void FruthtermanReingoldAlgorithm::updateConnectionsControlPoints() {
    for (int connectionIndex = 0; connectionIndex < _connections.size(); connectionIndex++)
        updateConnectionControlPoints(_connections.at(connectionIndex));
}

void FruthtermanReingoldAlgorithm::updateConnectionControlPoints(AutoLayoutObjectBase* connection) {
    calculateCenterControlPoint(connection);
    adjustCenterControlPoint(connection);
    setCurvePoints(connection);
    adjustCurvePoints(connection);
}

void FruthtermanReingoldAlgorithm::calculateCenterControlPoint(AutoLayoutObjectBase* connection) {
    int numberOfSubstrates = 0;
    bool isLooped = false;
    AutoLayoutPoint loopedPoint;
    AutoLayoutNodeBase* centroidNode = (AutoLayoutNodeBase*)(((AutoLayoutConnection*)connection)->getCentroidNode());
    AutoLayoutCurve* firstCurve = NULL;
    AutoLayoutNodeBase* firstCurveNode = NULL;
    AutoLayoutCurve* secondCurve = NULL;
    AutoLayoutNodeBase* secondCurveNode = NULL;
    for (int firstCurveIndex = 0; firstCurveIndex < ((AutoLayoutConnection*)connection)->getCurves().size(); firstCurveIndex++) {
        firstCurve = (AutoLayoutCurve*)(((AutoLayoutConnection*)connection)->getCurves().at(firstCurveIndex));
        firstCurveNode = (AutoLayoutNodeBase*)findObject(_nodes, firstCurve->getNodeId());
        if (firstCurve->getRole() == SPECIES_ROLE_SUBSTRATE) {
            _centerControlPoint.setX(_centerControlPoint.getX() + firstCurveNode->getX());
            _centerControlPoint.setY(_centerControlPoint.getY() + firstCurveNode->getY());
            numberOfSubstrates++;
        }
        for (int secondCurveIndex = 0; secondCurveIndex < ((AutoLayoutConnection*)connection)->getCurves().size(); secondCurveIndex++) {
            secondCurve = (AutoLayoutCurve*)(((AutoLayoutConnection*)connection)->getCurves().at(secondCurveIndex));
            secondCurveNode = (AutoLayoutNodeBase*)findObject(_nodes, secondCurve->getNodeId());
            if (firstCurveNode == secondCurveNode && firstCurve->getRole() != secondCurve->getRole()) {
                isLooped = true;
                loopedPoint.setPosition(firstCurveNode->getPosition());
            }
        }
    }
    _centerControlPoint.setX((_centerControlPoint.getX() + centroidNode->getX()) / (numberOfSubstrates + 1));
    _centerControlPoint.setY((_centerControlPoint.getY() + centroidNode->getY())  / (numberOfSubstrates + 1));
    if (isLooped) {
        _centerControlPoint.setY(centroidNode->getY() + (centroidNode->getY() - loopedPoint.getX()));
        _centerControlPoint.setX(centroidNode->getX() + (centroidNode->getX() - loopedPoint.getY()));
        _centerControlPoint = adjustPointPosition(loopedPoint, centroidNode->getPosition(), 0, -25, false);
        _centerControlPoint = adjustPointPosition(centroidNode->getPosition(), _centerControlPoint, -90, 0, false);
    }
}

void FruthtermanReingoldAlgorithm::adjustCenterControlPoint(AutoLayoutObjectBase* connection) {
    if (((AutoLayoutConnection*)connection)->getNumNonModifierCurves() == 2) {
        AutoLayoutNodeBase* centroidNode = (AutoLayoutNodeBase*)(((AutoLayoutConnection*)connection)->getCentroidNode());
        double dist = -calculateEuclideanDistance(centroidNode->getPosition(), _centerControlPoint);
        double x1 = 0.0;
        double x2 = 0.0;
        double y1 = 0.0;
        double y2 = 0.0;
        for (int curveIndex = 0; curveIndex < ((AutoLayoutConnection*)connection)->getCurves().size(); curveIndex++) {
            AutoLayoutCurve* curve = (AutoLayoutCurve*)(((AutoLayoutConnection*)connection)->getCurves().at(curveIndex));
            AutoLayoutNodeBase* curveNode = (AutoLayoutNodeBase*)findObject(_nodes, curve->getNodeId());
            if (curveNode) {
                if (curve->getRole() == SPECIES_ROLE_PRODUCT || curve->getRole() == SPECIES_ROLE_SIDEPRODUCT) {
                    x1 = curveNode->getX();
                    y1 = curveNode->getY();
                }
                else if (curve->getRole() == SPECIES_ROLE_SUBSTRATE || curve->getRole() == SPECIES_ROLE_SIDESUBSTRATE) {
                    x2 = curveNode->getX();
                    y2 = curveNode->getY();
                }
            }
        }
        _centerControlPoint.setY(centroidNode->getY() + (y2 - y1));
        _centerControlPoint.setX(centroidNode->getX() + (x2 - x1));
        _centerControlPoint = adjustPointPosition(_centerControlPoint, centroidNode->getPosition(), 0, dist, false);
    }
}

void FruthtermanReingoldAlgorithm::setCurvePoints(AutoLayoutObjectBase* connection) {
    AutoLayoutNodeBase* centroidNode = (AutoLayoutNodeBase*)((AutoLayoutConnection*)connection)->getCentroidNode();
    AutoLayoutCurve* curve = NULL;
    AutoLayoutNodeBase* curveNode = NULL;
    _centerControlPoint = adjustPointPosition(_centerControlPoint, centroidNode->getPosition(), 0, -25, false);
    for (int curveIndex = 0; curveIndex < ((AutoLayoutConnection*)connection)->getCurves().size(); curveIndex++) {
        curve = (AutoLayoutCurve*)(((AutoLayoutConnection*)connection)->getCurves().at(curveIndex));
        curveNode = (AutoLayoutNodeBase*)findObject(_nodes, curve->getNodeId());
        curve->setNodeSidePoint(curveNode->getPosition());
        curve->setNodeSideControlPoint(curveNode->getPosition());
        curve->setCentroidSidePoint(centroidNode->getPosition());
        curve->setCentroidSideControlPoint(centroidNode->getPosition());
        switch(curve->getRole()) {
            case SPECIES_ROLE_PRODUCT:
            case SPECIES_ROLE_SIDEPRODUCT:
                curve->setCentroidSideControlPoint(adjustPointPosition(_centerControlPoint, centroidNode->getPosition(), 0, 1, true));
                curve->setNodeSidePoint(calculateCurveNodeSidePoint(curve->getCentroidSideControlPoint(), curveNode, 10));
                curve->setNodeSideControlPoint(adjustPointPosition(centroidNode->getPosition(), curve->getNodeSidePoint(), 0, -20, false));
                break;

            case SPECIES_ROLE_SUBSTRATE:
            case SPECIES_ROLE_SIDESUBSTRATE:
                curve->setCentroidSideControlPoint(_centerControlPoint);
                curve->setNodeSidePoint(calculateCurveNodeSidePoint(curve->getCentroidSideControlPoint(), curveNode, 10));
                curve->setNodeSideControlPoint(adjustPointPosition(centroidNode->getPosition(), curve->getNodeSidePoint(), 0, -20, false));
                break;

            case SPECIES_ROLE_ACTIVATOR:
            case SPECIES_ROLE_INHIBITOR:
            case SPECIES_ROLE_MODIFIER:
                curve->setCentroidSidePoint(adjustPointPosition(curveNode->getPosition(), centroidNode->getPosition(), 0, -15, false));
                curve->setCentroidSideControlPoint(adjustPointPosition(curveNode->getPosition(), centroidNode->getPosition(), 0, -20, false));
                curve->setNodeSidePoint(calculateCurveNodeSidePoint(curve->getCentroidSideControlPoint(), curveNode, 10));
                curve->setNodeSideControlPoint(curve->getNodeSidePoint());
                break;

            default:
                curve->setNodeSidePoint(calculateCurveNodeSidePoint(curve->getCentroidSideControlPoint(), curveNode, 10));
                curve->setNodeSideControlPoint(curve->getNodeSidePoint());
                break;
        }
    }
}

void FruthtermanReingoldAlgorithm::adjustCurvePoints(AutoLayoutObjectBase* connection) {
    for (int firstCurveIndex = 0; firstCurveIndex < ((AutoLayoutConnection*)connection)->getCurves().size(); firstCurveIndex++) {
        AutoLayoutCurve* firstCurve = (AutoLayoutCurve*)(((AutoLayoutConnection*)connection)->getCurves().at(firstCurveIndex));
        AutoLayoutNodeBase* firstCurveNode = (AutoLayoutNodeBase*)findObject(_nodes, firstCurve->getNodeId());
        for (int secondCurveIndex = firstCurveIndex + 1; secondCurveIndex < ((AutoLayoutConnection*)connection)->getCurves().size(); secondCurveIndex++) {
            AutoLayoutCurve* secondCurve = (AutoLayoutCurve*)(((AutoLayoutConnection*)connection)->getCurves().at(secondCurveIndex));
            AutoLayoutNodeBase* secondCurveNode = (AutoLayoutNodeBase*)findObject(_nodes, secondCurve->getNodeId());
            if (firstCurve->getNodeId() == secondCurve->getNodeId() && firstCurve->getRole() == secondCurve->getRole()) {
                firstCurve->setNodeSideControlPoint(adjustPointPosition(firstCurveNode->getPosition(), firstCurve->getNodeSideControlPoint(), 20, 10, false));
                secondCurve->setNodeSideControlPoint(adjustPointPosition(secondCurveNode->getPosition(), secondCurve->getNodeSideControlPoint(), -20, 10, false));
                firstCurve->setNodeSidePoint(adjustPointPosition(firstCurve->getNodeSideControlPoint(), firstCurve->getNodeSidePoint(), -10, 0, false));
                secondCurve->setNodeSidePoint(adjustPointPosition(secondCurve->getNodeSideControlPoint(), secondCurve->getNodeSidePoint(), 10, 0, false));
            }
        }
    }
}

const double calculateEuclideanDistance(AutoLayoutPoint point1, AutoLayoutPoint point2) {
    return calculateEuclideanDistance(AutoLayoutPoint(point2.getX() - point1.getX(), point2.getY() - point1.getY()));
}

const double calculateEuclideanDistance(AutoLayoutPoint point) {
    return calculateEuclideanDistance(point.getX(), point.getY());
}

const double calculateEuclideanDistance(const double& distanceX, const double& distanceY) {
    return std::sqrt(distanceX * distanceX + distanceY * distanceY);
}

const double calculateStiffnessAdjustmentFactor(AutoLayoutObjectBase* vNode, AutoLayoutObjectBase* uNode) {
    return std::log(((AutoLayoutNodeBase*)vNode)->getDegree() + ((AutoLayoutNodeBase*)uNode)->getDegree() + 2) + 0.25 * (std::max(((AutoLayoutNodeBase*)((AutoLayoutNodeBase*)vNode))->getWidth(), ((AutoLayoutNodeBase*)vNode)->getHeight()) + std::max(((AutoLayoutNodeBase*)uNode)->getWidth(), ((AutoLayoutNodeBase*)uNode)->getHeight()));
}

const double calculateRepulsionForce(const double& stiffness, const double& distance) {
    return stiffness * stiffness / distance;
}

const double calculateAttractionForce(const double& stiffness, const double& distance) {
    return distance * distance / stiffness;
}

AutoLayoutPoint adjustPointPosition(AutoLayoutPoint firstPoint, AutoLayoutPoint secondPoint, double degreesFactor, double distanceFactor, bool isRelativeDistance) {
    AutoLayoutPoint adjustedPosition;
    double distanceX = secondPoint.getX() - firstPoint.getX();
    double distanceY = secondPoint.getY() - firstPoint.getY();
    double distance = calculateEuclideanDistance(distanceX, distanceY);
    if (std::abs(distanceX) < 0.00000001)
        distanceX = 0.00000001;
    double degrees = std::atan(distanceY / distanceX);
    if (isRelativeDistance)
        distance += distance * distanceFactor;
    else
        distance += distanceFactor;
    distanceX = distance * std::cos(degrees + (M_PI / 180.0) * degreesFactor);
    distanceY = distance * std::sin(degrees + (M_PI / 180.0) * degreesFactor);
    if (secondPoint.getX() >= firstPoint.getX()) {
        adjustedPosition.setX(firstPoint.getX() + distanceX);
        adjustedPosition.setY(firstPoint.getY() + distanceY);
    }
    else {
        adjustedPosition.setX(firstPoint.getX() - distanceX);
        adjustedPosition.setY(firstPoint.getY() - distanceY);
    }

    return adjustedPosition;
}

AutoLayoutPoint calculateCurveNodeSidePoint(AutoLayoutPoint source, AutoLayoutObjectBase* target, double distance) {
    AutoLayoutPoint intersectionPoint = calculateLeftSideIntersectionPoint(source, target);
    AutoLayoutPoint possibleIntersectionPoint = calculateRightSideIntersectionPoint(source, target);
    if (!possibleIntersectionPoint.isEmpty() && calculateEuclideanDistance(intersectionPoint, source) > calculateEuclideanDistance(possibleIntersectionPoint, source))
        intersectionPoint = possibleIntersectionPoint;
    possibleIntersectionPoint = calculateTopSideIntersectionPoint(source, target);
    if (!possibleIntersectionPoint.isEmpty() && calculateEuclideanDistance(intersectionPoint, source) > calculateEuclideanDistance(possibleIntersectionPoint, source))
        intersectionPoint = possibleIntersectionPoint;
    possibleIntersectionPoint = calculateBottomSideIntersectionPoint(source, target);
    if (!possibleIntersectionPoint.isEmpty() && calculateEuclideanDistance(intersectionPoint, source) > calculateEuclideanDistance(possibleIntersectionPoint, source))
        intersectionPoint = possibleIntersectionPoint;

    return adjustPointPosition(source, intersectionPoint, 0, -distance, false);
}

AutoLayoutPoint calculateLeftSideIntersectionPoint(AutoLayoutPoint source, AutoLayoutObjectBase* target) {
    return calculateIntersectionPoint(AutoLayoutPoint(((AutoLayoutNodeBase*)target)->getX(), ((AutoLayoutNodeBase*)target)->getY()),
                                      AutoLayoutPoint(((AutoLayoutNodeBase*)target)->getX(), ((AutoLayoutNodeBase*)target)->getY() + ((AutoLayoutNodeBase*)target)->getHeight()),
                                      source, AutoLayoutPoint(((AutoLayoutNodeBase*)target)->getX(), ((AutoLayoutNodeBase*)target)->getY() + 0.5 * ((AutoLayoutNodeBase*)target)->getHeight()));
}

AutoLayoutPoint calculateRightSideIntersectionPoint(AutoLayoutPoint source, AutoLayoutObjectBase* target) {
    return calculateIntersectionPoint(AutoLayoutPoint(((AutoLayoutNodeBase*)target)->getX() + ((AutoLayoutNodeBase*)target)->getWidth(), ((AutoLayoutNodeBase*)target)->getY()),
                                      AutoLayoutPoint(((AutoLayoutNodeBase*)target)->getX() + ((AutoLayoutNodeBase*)target)->getWidth(), ((AutoLayoutNodeBase*)target)->getY() + ((AutoLayoutNodeBase*)target)->getHeight()),
                                      source, AutoLayoutPoint(((AutoLayoutNodeBase*)target)->getX() + ((AutoLayoutNodeBase*)target)->getWidth(), ((AutoLayoutNodeBase*)target)->getY() + 0.5 * ((AutoLayoutNodeBase*)target)->getHeight()));
}

AutoLayoutPoint calculateTopSideIntersectionPoint(AutoLayoutPoint source, AutoLayoutObjectBase* target) {
    return calculateIntersectionPoint(AutoLayoutPoint(((AutoLayoutNodeBase*)target)->getX(), ((AutoLayoutNodeBase*)target)->getY()),
                                      AutoLayoutPoint(((AutoLayoutNodeBase*)target)->getX() + ((AutoLayoutNodeBase*)target)->getWidth(), ((AutoLayoutNodeBase*)target)->getY()),
                                      source, AutoLayoutPoint(((AutoLayoutNodeBase*)target)->getX() + 0.5 * ((AutoLayoutNodeBase*)target)->getWidth(), ((AutoLayoutNodeBase*)target)->getY()));
}

AutoLayoutPoint calculateBottomSideIntersectionPoint(AutoLayoutPoint source, AutoLayoutObjectBase* target) {
    return calculateIntersectionPoint(AutoLayoutPoint(((AutoLayoutNodeBase*)target)->getX(), ((AutoLayoutNodeBase*)target)->getY() + ((AutoLayoutNodeBase*)target)->getHeight()),
                                      AutoLayoutPoint(((AutoLayoutNodeBase*)target)->getX() + ((AutoLayoutNodeBase*)target)->getWidth(), ((AutoLayoutNodeBase*)target)->getY() + ((AutoLayoutNodeBase*)target)->getHeight()),
                                      source, AutoLayoutPoint(((AutoLayoutNodeBase*)target)->getX() + 0.5 * ((AutoLayoutNodeBase*)target)->getWidth(), ((AutoLayoutNodeBase*)target)->getY() + ((AutoLayoutNodeBase*)target)->getHeight()));
}

AutoLayoutPoint calculateIntersectionPoint(AutoLayoutPoint p1, AutoLayoutPoint p2, AutoLayoutPoint q1, AutoLayoutPoint q2) {
    double denominator = ((q2.getY() - q1.getY()) * (p2.getX() - p1.getX())) - ((q2.getX() - q1.getX()) * (p2.getY() - p1.getY()));
    if (std::abs(denominator) > 0.000001) {
        double ua = (((q2.getX() - q1.getX()) * (p1.getY() - q1.getY())) - ((q2.getY() - q1.getY()) * (p1.getX() - q1.getX()))) / denominator;
        double ub = (((p2.getX() - p1.getX()) * (p1.getY() - q1.getY())) - ((p2.getY() - p1.getY()) * (p1.getX() - q1.getX()))) / denominator;
        if (ua >= 0.000001 && ua <= 1.000000 && ub >= 0.000001 && ub <= 1.00000)
            return AutoLayoutPoint((int)(p1.getX() + ua * (p2.getX() - p1.getX())), (int)(p1.getY() + ua * (p2.getY() - p1.getY())));
    }

    return AutoLayoutPoint(0.0000001, 0.0000001);
}

AutoLayoutObjectBase* findObject(std::vector<AutoLayoutObjectBase*> objects, const std::string& objectId) {
    for (int objectIndex = 0; objectIndex < objects.size(); objectIndex++) {
        if (objects.at(objectIndex)->getId() == objectId)
            return objects.at(objectIndex);
    }

    return NULL;
}

}
