#include "libsbml_ne_fruchterman_reingold_algorithm.h"

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE {

FruthtermanReingoldAlgorithm::FruthtermanReingoldAlgorithm() {

}

void FruthtermanReingoldAlgorithm::setElements(Model *model, Layout* layout) {
    /*
    _connections = (Connection[]) connlist1.ToArray(
    typeof(Connection));
    _nodes = (Node[]) nodelist1.ToArray(
    typeof(Node));
     */
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
    /*
    _maxits = (int) (100 * std::log(nodes.size() + 2, std::exp(1.0)));
    _tempinit = 1000 * std::log(nodes.size() + 2, std::exp(1.0));
    _tempcurr = tempinit;
    _time = 0.0;
    _alpha = std::log(tempinit) - std::log(0.25);
    _timeinc = 1.0 / (double) maxits;
    _adjustk = 0;
    _its;
    _d;
    _delta = Point(0, 0);

    //used with the constrain option
    _width = std::sqrt(nodes.size()) * k * 5;
    _length = width;

    //let's just do the barycenter at 0,0
    _barycenter = PointF(0, 0);
     */
}

void FruthtermanReingoldAlgorithm::iterate() {
    /*
    for (its = 0; its < maxits; its++) {
        tempcurr = tempinit * std::exp(-alpha * time);
        time += timeinc;
        clearDisplacements()
        computeRepulsiveForces()
        computeAttractiveForces()
        applyMagnetism();
        applyGravity();
        adjustCoordinates();
    }
     */
}

void FruthtermanReingoldAlgorithm::clearDisplacements() {
    /*
    for (int i = 0; i < nodelist.Length; i++) {
        Node v = nodelist[i];
        v.disp.X = 0;
        v.disp.Y = 0;
    }
     */
}

void FruthtermanReingoldAlgorithm::computeRepulsiveForces() {

}

void FruthtermanReingoldAlgorithm::computeAttractiveForces() {

}

void FruthtermanReingoldAlgorithm::applyMagnetism() {

}

void FruthtermanReingoldAlgorithm::applyGravity() {

}

void FruthtermanReingoldAlgorithm::adjustCoordinates() {

}

}
