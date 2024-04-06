#include "libsbmlnetwork_fruchterman_reingold_algorithm.h"
#include "libsbmlnetwork_autolayout_node.h"
#include "libsbmlnetwork_autolayout_connection.h"
#include "libsbmlnetwork_autolayout_curve.h"
#include "../libsbmlnetwork_layout_helpers.h"
#include <cstdlib>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

FruthtermanReingoldAlgorithm::FruthtermanReingoldAlgorithm() {

}

void FruthtermanReingoldAlgorithm::setElements(Model* model, Layout* layout, const bool& useNameAsTextLabel) {
    setConnections(model, layout, useNameAsTextLabel);
    setNodes(model, layout, useNameAsTextLabel);
    setNodesDegrees();
}

void FruthtermanReingoldAlgorithm::setConnections(Model* model, Layout* layout, const bool& useNameAsTextLabel) {
    for (int i = 0; i < layout->getNumReactionGlyphs(); i++)
        _connections.push_back(new AutoLayoutConnection(model, layout, layout->getReactionGlyph(i), useNameAsTextLabel));
}

void FruthtermanReingoldAlgorithm::setNodes(Model* model, Layout* layout, const bool& useNameAsTextLabel) {
    for (int i = 0; i < layout->getNumSpeciesGlyphs(); i++)
        _nodes.push_back(new AutoLayoutNode(model, layout, layout->getSpeciesGlyph(i), useNameAsTextLabel));
    for (int i = 0; i < _connections.size(); i++)
        _nodes.push_back(((AutoLayoutConnection*)_connections.at(i))->getCentroidNode());
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

void FruthtermanReingoldAlgorithm::setNodesLockedStatus(Layout *layout, const std::vector<std::string> &lockedNodeIds) {
    for (int i = 0; i < _nodes.size(); i++) {
        if (whetherGraphicalObjectIsLocked(layout, ((AutoLayoutNodeBase*)_nodes.at(i))->getGraphicalObject(), lockedNodeIds))
            ((AutoLayoutNodeBase*)_nodes.at(i))->setLocked(true);
    }
}

void FruthtermanReingoldAlgorithm::setPadding(const double &padding) {
    _padding = padding;
}

void FruthtermanReingoldAlgorithm::apply() {
    initialize();
    iterate();
    updateNodesDimensions();
    adjustCoordinateOrigin();
    updateConnectionsControlPoints();
}

void FruthtermanReingoldAlgorithm::initialize() {
    _maximumIterations = int(100 * std::log(_nodes.size() - _connections.size() + 2));
    _initialTemperature = 1000 * std::log(_nodes.size() - _connections.size() + 2);
    _currentTemperature = _initialTemperature;
    _time = 0.0;
    _alpha = std::log(_initialTemperature) - std::log(0.25);
    _timeIncrement = 1.0 / double(_maximumIterations);
    _width = std::sqrt(_nodes.size() - _connections.size()) * _stiffness * 5;
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
                    if (!vNode->isLocked()) {
                        vNode->setX(vNode->getX() + std::rand() % int(_stiffness));
                        vNode->setY(vNode->getY() + std::rand() % int(_stiffness));
                    }
                }
                else {
                    double repulsionForce = calculateRepulsionForce(_stiffness * calculateStiffnessAdjustmentFactor(vNode, uNode), distance);
                    if (!vNode->isLocked()) {
                        vNode->setDisplacementX(vNode->getDisplacementX() + (distanceX / distance * repulsionForce));
                        vNode->setDisplacementY(vNode->getDisplacementY() + (distanceY /distance * repulsionForce));
                    }
                    if (!uNode->isLocked()) {
                        uNode->setDisplacementX(uNode->getDisplacementX() - (distanceX / distance * repulsionForce));
                        uNode->setDisplacementY(uNode->getDisplacementY() - (distanceY / distance * repulsionForce));
                    }
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
                    if (!vNode->isLocked()) {
                        vNode->setDisplacementX(vNode->getDisplacementX() - (distanceX / distance * attractionForce));
                        vNode->setDisplacementY(vNode->getDisplacementY() - (distanceY /distance * attractionForce));
                    }
                    if (!uNode->isLocked()) {
                        uNode->setDisplacementX(uNode->getDisplacementX() + (distanceX / distance * attractionForce));
                        uNode->setDisplacementY(uNode->getDisplacementY() + (distanceY /distance * attractionForce));
                    }
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
                                if (!vNode->isLocked()) {
                                    vNode->setDisplacementX(vNode->getDisplacementX() - 0.25 * (distanceX / distance * attractionForce));
                                    vNode->setDisplacementY(vNode->getDisplacementY() - 0.25 * (distanceY /distance * attractionForce));
                                }
                                if (!uNode->isLocked()) {
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

void FruthtermanReingoldAlgorithm::updateNodesDimensions() {
    for (int nodeIndex = 0; nodeIndex < _nodes.size(); nodeIndex++) {
        AutoLayoutNodeBase* node = (AutoLayoutNodeBase*)_nodes.at(nodeIndex);
        ((AutoLayoutNodeBase*)node)->updateDimensions();
    }
}

void FruthtermanReingoldAlgorithm::adjustCoordinateOrigin() {
    AutoLayoutPoint _origin = AutoLayoutPoint(0.0, 0.0);
    for (int nodeIndex = 0; nodeIndex < _nodes.size(); nodeIndex++) {
        if (((AutoLayoutNodeBase*)_nodes.at(nodeIndex))->getX() < _origin.getX())
            _origin.setX(((AutoLayoutNodeBase *) _nodes.at(nodeIndex))->getX());
        if (((AutoLayoutNodeBase*)_nodes.at(nodeIndex))->getY() < _origin.getY())
            _origin.setY(((AutoLayoutNodeBase*)_nodes.at(nodeIndex))->getY());
    }
    _origin.setX(_origin.getX() - _padding);
    _origin.setY(_origin.getY() - _padding);
    for (int nodeIndex = 0; nodeIndex < _nodes.size(); nodeIndex++) {
        if (!((AutoLayoutNodeBase*)_nodes.at(nodeIndex))->isLocked()) {
            ((AutoLayoutNodeBase*)_nodes.at(nodeIndex))->setX(((AutoLayoutNodeBase*)_nodes.at(nodeIndex))->getX() - _origin.getX());
            ((AutoLayoutNodeBase*)_nodes.at(nodeIndex))->setY(((AutoLayoutNodeBase*)_nodes.at(nodeIndex))->getY() - _origin.getY());
        }
    }
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
    adjustUniUniConnections(connection);
}

void FruthtermanReingoldAlgorithm::calculateCenterControlPoint(AutoLayoutObjectBase* connection) {
    _centerControlPoint = AutoLayoutPoint(0.0, 0.0);
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
        _centerControlPoint.setX(centroidNode->getX() + (x2 - x1));
        _centerControlPoint.setY(centroidNode->getY() + (y2 - y1));
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
        if (curveNode) {
            curve->setNodeSidePoint(curveNode->getPosition());
            curve->setNodeSideControlPoint(curveNode->getPosition());
            curve->setCentroidSidePoint(centroidNode->getPosition());
            curve->setCentroidSideControlPoint(centroidNode->getPosition());
            switch(curve->getRole()) {
                case SPECIES_ROLE_PRODUCT:
                case SPECIES_ROLE_SIDEPRODUCT:
                    curve->setCentroidSideControlPoint(adjustPointPosition(_centerControlPoint, centroidNode->getPosition(), 0, 1, true));
                    curve->setNodeSidePoint(calculateCurveNodeSidePoint(curve->getCentroidSideControlPoint(), curveNode, 10));
                    curve->setNodeSideControlPoint(adjustPointPosition(curve->getNodeSidePoint(), curveNode->getPosition(), 0, -2.5 * calculateEuclideanDistance(curve->getNodeSidePoint(), curveNode->getPosition()), false));
                    break;

                case SPECIES_ROLE_SUBSTRATE:
                case SPECIES_ROLE_SIDESUBSTRATE:
                    curve->setCentroidSideControlPoint(_centerControlPoint);
                    curve->setNodeSidePoint(calculateCurveNodeSidePoint(curve->getCentroidSideControlPoint(), curveNode, 10));
                    curve->setNodeSideControlPoint(adjustPointPosition(curve->getNodeSidePoint(), curveNode->getPosition(), 0, -2.5 * calculateEuclideanDistance(curve->getNodeSidePoint(), curveNode->getPosition()), false));
                    break;

                case SPECIES_ROLE_ACTIVATOR:
                case SPECIES_ROLE_INHIBITOR:
                case SPECIES_ROLE_MODIFIER:
                    curve->setCentroidSidePoint(adjustPointPosition(curveNode->getPosition(), centroidNode->getPosition(), 0, -15, false));
                    curve->setCentroidSideControlPoint(adjustPointPosition(curveNode->getPosition(), centroidNode->getPosition(), 0, -20, false));
                    curve->setNodeSidePoint(calculateCurveNodeSidePoint(curve->getCentroidSideControlPoint(), curveNode, 10));
                    curve->setNodeSideControlPoint(adjustPointPosition(curve->getNodeSidePoint(), curveNode->getPosition(), 0, -2.5 * calculateEuclideanDistance(curve->getNodeSidePoint(), curveNode->getPosition()), false));
                    break;

                default:
                    curve->setNodeSidePoint(calculateCurveNodeSidePoint(curve->getCentroidSideControlPoint(), curveNode, 10));
                    curve->setNodeSideControlPoint(curve->getNodeSidePoint());
                    break;
            }
        }
    }
}

void FruthtermanReingoldAlgorithm::adjustCurvePoints(AutoLayoutObjectBase* connection) {
    for (int firstCurveIndex = 0; firstCurveIndex < ((AutoLayoutConnection*)connection)->getCurves().size(); firstCurveIndex++) {
        AutoLayoutCurve* firstCurve = (AutoLayoutCurve*)(((AutoLayoutConnection*)connection)->getCurves().at(firstCurveIndex));
        AutoLayoutNodeBase* firstCurveNode = (AutoLayoutNodeBase*)findObject(_nodes, firstCurve->getNodeId());
        if (firstCurveNode) {
            for (int secondCurveIndex = firstCurveIndex + 1; secondCurveIndex < ((AutoLayoutConnection*)connection)->getCurves().size(); secondCurveIndex++) {
                AutoLayoutCurve* secondCurve = (AutoLayoutCurve*)(((AutoLayoutConnection*)connection)->getCurves().at(secondCurveIndex));
                AutoLayoutNodeBase* secondCurveNode = (AutoLayoutNodeBase*)findObject(_nodes, secondCurve->getNodeId());
                if (firstCurve->getNodeId() == secondCurve->getNodeId() ) {
                    if (firstCurve->getRole() == secondCurve->getRole()) {
                        firstCurve->setNodeSideControlPoint(adjustPointPosition(firstCurveNode->getPosition(), firstCurve->getNodeSideControlPoint(), 12.5, 7.5, false));
                        secondCurve->setNodeSideControlPoint(adjustPointPosition(secondCurveNode->getPosition(), secondCurve->getNodeSideControlPoint(), -12.5, 7.5, false));
                    }
                    else {
                        firstCurve->setNodeSideControlPoint(adjustPointPosition(firstCurveNode->getPosition(), firstCurve->getNodeSideControlPoint(), 10, 5, false));
                        secondCurve->setNodeSideControlPoint(adjustPointPosition(secondCurveNode->getPosition(), secondCurve->getNodeSideControlPoint(), -10, 5, false));
                    }
                    firstCurve->setNodeSidePoint(adjustPointPosition(firstCurve->getNodeSideControlPoint(), firstCurve->getNodeSidePoint(), -12.5, 0, false));
                    secondCurve->setNodeSidePoint(adjustPointPosition(secondCurve->getNodeSideControlPoint(), secondCurve->getNodeSidePoint(), 12.5, 0, false));
                }
            }
        }
    }
}

void FruthtermanReingoldAlgorithm::adjustUniUniConnections(AutoLayoutObjectBase* connection) {
    if (((AutoLayoutConnection*)connection)->getCurves().size() == 2) {
        double slope = getNodePairSlope(_nodes, ((AutoLayoutConnection*)connection)->getNodeIds().at(0), ((AutoLayoutConnection*)connection)->getNodeIds().at(1));
        if (slope < 0.0)
                slope += M_PI;
        double centerPadding = getConnectionCenterPadding(_connections, connection);
        AutoLayoutPoint nodesCenter = getNodesCenter(_nodes, ((AutoLayoutConnection *) connection)->getNodeIds());
        AutoLayoutPoint centerPosition = AutoLayoutPoint(nodesCenter.getX() + centerPadding * std::sin(slope), nodesCenter.getY() - centerPadding * std::cos(slope));
        ((AutoLayoutNodeBase *)(((AutoLayoutConnection *) connection)->getCentroidNode()))->setPosition(centerPosition);
        setUniUniConnectionCurvePoints(connection, nodesCenter, slope);
    }
}

void FruthtermanReingoldAlgorithm::setUniUniConnectionCurvePoints(AutoLayoutObjectBase* connection, const AutoLayoutPoint& nodesCenter, const double& slope) {
    for (int curveIndex = 0; curveIndex < ((AutoLayoutConnection*)connection)->getCurves().size(); curveIndex++) {
        AutoLayoutCurve *curve = (AutoLayoutCurve *) (((AutoLayoutConnection *) connection)->getCurves().at(
                curveIndex));
        AutoLayoutNodeBase *curveNode = (AutoLayoutNodeBase*)findObject(_nodes, curve->getNodeId());
         if (curveNode) {
             AutoLayoutPoint centroidSideControlPoint;
             double centroidSideControlPointDistance = 40.0;
             if (getPointPairSlope(nodesCenter, curveNode->getPosition()) >= 0.0)
                 centroidSideControlPoint = AutoLayoutPoint(((AutoLayoutNodeBase *)(((AutoLayoutConnection *) connection)->getCentroidNode()))->getPosition().getX() + centroidSideControlPointDistance * std::cos(slope),
                                                            ((AutoLayoutNodeBase *)(((AutoLayoutConnection *) connection)->getCentroidNode()))->getPosition().getY() + centroidSideControlPointDistance * std::sin(slope));
             else
                 centroidSideControlPoint = AutoLayoutPoint(((AutoLayoutNodeBase *)(((AutoLayoutConnection *) connection)->getCentroidNode()))->getPosition().getX() - centroidSideControlPointDistance * std::cos(slope),
                                                            ((AutoLayoutNodeBase *)(((AutoLayoutConnection *) connection)->getCentroidNode()))->getPosition().getY() - centroidSideControlPointDistance * std::sin(slope));
            curve->setCentroidSidePoint(((AutoLayoutNodeBase *)(((AutoLayoutConnection *) connection)->getCentroidNode()))->getPosition());
            curve->setCentroidSideControlPoint(centroidSideControlPoint);
            curve->setNodeSideControlPoint(centroidSideControlPoint);
            curve->setNodeSidePoint(calculateCenterWardIntersectionPoint(curve->getNodeSideControlPoint(), curveNode, -10));
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
    double minimumDimension = 15.0;
    double uNodeDimension = std::max(std::max(((AutoLayoutNodeBase*)vNode)->getWidth(), ((AutoLayoutNodeBase*)vNode)->getHeight()), minimumDimension);
    double vNodeDimension = std::max(std::max(((AutoLayoutNodeBase*)uNode)->getWidth(), ((AutoLayoutNodeBase*)uNode)->getHeight()), minimumDimension);
    return std::log(((AutoLayoutNodeBase*)vNode)->getDegree() + ((AutoLayoutNodeBase*)uNode)->getDegree() + 2) + 0.25 * (uNodeDimension + vNodeDimension);
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

AutoLayoutPoint calculateCenterWardIntersectionPoint(AutoLayoutPoint source, AutoLayoutObjectBase* target, double distance) {
    AutoLayoutPoint center = ((AutoLayoutNodeBase*)target)->getPosition();
    double width = ((AutoLayoutNodeBase*)target)->getWidth();
    double height = ((AutoLayoutNodeBase*)target)->getHeight();
    double ratio = height / width;
    double slope = atan2(source.getY() - center.getY(), source.getX() - center.getX());
    if (slope < 0.0)
        slope += 2 * M_PI;
    if (slope >= 2 * M_PI - ratio || slope < ratio)
        return adjustPointPosition(source, AutoLayoutPoint(center.getX() + 0.5 * width, center.getY() + 0.5 * width * tan(slope)), 0, distance, false);
    else if (slope >= ratio && slope < (M_PI - ratio))
        return adjustPointPosition(source, AutoLayoutPoint(center.getX() + 0.5 * height / tan(slope), center.getY() + 0.5 * height), 0, distance, false);
    else if (slope >= (M_PI - ratio) && slope < M_PI + ratio)
        return adjustPointPosition(source, AutoLayoutPoint(center.getX() - 0.5 * width, center.getY() - 0.5 * width * tan(slope)), 0, distance, false);
    else if (slope >= M_PI + ratio && slope < 2 * M_PI - ratio)
        return adjustPointPosition(source, AutoLayoutPoint(center.getX() - 0.5 * height / tan(slope), center.getY() - 0.5 * height), 0, distance, false);

    return adjustPointPosition(source, center, 0, distance, false);
}

AutoLayoutObjectBase* findObject(std::vector<AutoLayoutObjectBase*> objects, const std::string& objectId) {
    for (int objectIndex = 0; objectIndex < objects.size(); objectIndex++) {
        if (objects.at(objectIndex)->getId() == objectId)
            return objects.at(objectIndex);
    }

    return NULL;
}

const int numOfConnectionsBetweenTheSameNodes(std::vector<AutoLayoutObjectBase*> connections, std::vector<std::string> connectionNodeIds) {
    int numConnections = 0;
    for (int connectionIndex = 0; connectionIndex < connections.size(); connectionIndex++) {
        if (compare(((AutoLayoutConnection*)connections.at(connectionIndex))->getNodeIds(), connectionNodeIds))
            numConnections++;
    }

    return numConnections;
}

const int indexOfConnectionBetweenTheSameNodes(std::vector<AutoLayoutObjectBase*> connections, std::vector<std::string> connectionNodeIds, AutoLayoutObjectBase* connection) {
    int index = -1;
    for (int connectionIndex = 0; connectionIndex < connections.size(); connectionIndex++) {
        if (compare(((AutoLayoutConnection*)connections.at(connectionIndex))->getNodeIds(), connectionNodeIds)) {
            index++;
            if (connections.at(connectionIndex) == connection)
                break;
        }
    }

    return index;
}

const double getNodePairSlope(std::vector<AutoLayoutObjectBase*> nodes, const std::string &node1Id, const std::string &node2Id) {
    return getNodePairSlope(nodes, findObject(nodes, node1Id), findObject(nodes, node2Id));
}

const double getNodePairSlope(std::vector<AutoLayoutObjectBase*> nodes, AutoLayoutObjectBase* node1, AutoLayoutObjectBase* node2) {
    if (node1 && node2)
        return getPointPairSlope(((AutoLayoutNodeBase *) node2)->getPosition(), ((AutoLayoutNodeBase *) node1)->getPosition());

    return  0.0;
}

const double getPointPairSlope(AutoLayoutPoint point1, AutoLayoutPoint point2) {
    return std::atan2(point2.getY() - point1.getY(), point2.getX() - point1.getX());
}

const double getConnectionCenterPadding(std::vector<AutoLayoutObjectBase*> connections, AutoLayoutObjectBase* connection) {
    int numOfSameConnections = numOfConnectionsBetweenTheSameNodes(connections, ((AutoLayoutConnection*)connection)->getNodeIds());
    int indexOfSameConnection = indexOfConnectionBetweenTheSameNodes(connections, ((AutoLayoutConnection*)connection)->getNodeIds(), connection);
    int centerPaddingStep = 65.0;
    int indexFactor = indexOfSameConnection;
    if (numOfSameConnections % 2) {
        if (indexOfSameConnection == 0)
            indexFactor = -2;
        else
            indexFactor--;
    }

    return  (int(0.5 * indexFactor)  + 1)  * std::pow(-1, indexFactor) * centerPaddingStep;
}

AutoLayoutPoint getNodesCenter(std::vector<AutoLayoutObjectBase*> nodes, std::vector<std::string> nodeIds) {
    AutoLayoutPoint center = AutoLayoutPoint(0.0, 0.0);
    for (int nodeIndex = 0; nodeIndex < nodeIds.size(); nodeIndex++) {
        AutoLayoutObjectBase* node = findObject(nodes, nodeIds[nodeIndex]);
        if (node)
            center.setPosition(AutoLayoutPoint(center.getX() + ((AutoLayoutNodeBase *) node)->getPosition().getX(),
                                               center.getY() + ((AutoLayoutNodeBase *) node)->getPosition().getY()));
    }

    return AutoLayoutPoint(center.getX() / nodeIds.size(), center.getY() / nodeIds.size());
}

const bool compare(std::vector<std::string> strings1, std::vector<std::string> strings2) {
    if (strings1.size() != strings2.size())
        return false;
    for (int i = 0; i < strings1.size(); i++) {
        if (std::find(strings2.begin(), strings2.end(), strings1[i]) == strings2.end())
            return false;
    }

    return true;
}

const bool whetherGraphicalObjectIsLocked(Layout* layout, GraphicalObject *graphicalObject, const std::vector <std::string> &lockedNodeIds) {
    for (int i = 0; i < lockedNodeIds.size(); i++) {
        if (graphicalObject->getId() == lockedNodeIds[i] || getEntityId(layout, graphicalObject) == lockedNodeIds[i])
            return true;
    }
    return false;

}

}