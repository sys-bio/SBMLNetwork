#include "libsbml_ne_fruchterman_reingold_algorithm.h"
#include <cstdlib>
#include <cmath>

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE {

FruthtermanReingoldAlgorithm::FruthtermanReingoldAlgorithm() {

}

void FruthtermanReingoldAlgorithm::setElements(Model *model, Layout* layout) {
    setNodes(model, layout);
    setConnections(model, layout);
}

void FruthtermanReingoldAlgorithm::setNodes(Model *model, Layout* layout) {
    for (int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        _nodes.push_back(new AutoLayoutNode(layout->getSpeciesGlyph(i)));
    }
}

void FruthtermanReingoldAlgorithm::setConnections(Model *model, Layout* layout) {
    //_connections = (Connection[]) connlist1.ToArray(
    //typeof(Connection));
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
    _length = _width;
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
        _nodes.at(i)->setDisplacementX(0.0);
        _nodes.at(i)->setDisplacementY(0.0);
    }
}

void FruthtermanReingoldAlgorithm::computeRepulsiveForces() {
    AutoLayoutNode* vNode = NULL;
    AutoLayoutNode* uNode = NULL;
    for (int i = 0; i < _nodes.size(); i++) {
        vNode = _nodes.at(i);
        for (int j = i + 1; j < _nodes.size(); j++) {
            uNode = _nodes.at(j);
            if (i != j) {
                double distanceX = vNode->getX() - uNode->getX();
                double distanceY = vNode->getY() - uNode->getY();
                double distance = euclideanDistance(AutoLayoutPoint(distanceX, distanceY));
                if (distance < 0.000001)  {
                    vNode->setX(vNode->getX() + std::rand() % int(_stiffness));
                    vNode->setY(vNode->getY() + std::rand() % int(_stiffness));
                }
                else {
                    double adjustedStiffness = _stiffness * std::log(vNode->getDegree() + uNode->getDegree() + 2) +
                            0.25 * (std::max(vNode->getWidth(), vNode->getHeight()) + std::max(uNode->getWidth(), uNode->getHeight()));
                    vNode->setDisplacementX(vNode->getDisplacementX() + (distanceX / distance * repulsionForce(adjustedStiffness, distance)));
                    vNode->setDisplacementY(vNode->getDisplacementY() + (distanceY /distance * repulsionForce(adjustedStiffness, distance)));
                    uNode->setDisplacementX(uNode->getDisplacementX() - (distanceX / distance * repulsionForce(adjustedStiffness, distance)));
                    uNode->setDisplacementY(uNode->getDisplacementY() - (distanceY / distance * repulsionForce(adjustedStiffness, distance)));
                }
            }
        }
    }
}

void FruthtermanReingoldAlgorithm::computeAttractiveForces() {

}

void FruthtermanReingoldAlgorithm::applyMagnetism() {

}

void FruthtermanReingoldAlgorithm::applyGravity() {

}

void FruthtermanReingoldAlgorithm::adjustCoordinates() {

}

double euclideanDistance(AutoLayoutPoint point) {
    return std::sqrt(point.getX() * point.getX() + point.getY() * point.getY());
}

double repulsionForce(const double& stiffness, const double& distance) {
    return stiffness * stiffness / distance;
}

}
