#ifndef __LIBSBML_NE_FRUCHTERMAN_REINGOLD_ALGORITHM_H
#define __LIBSBML_NE_FRUCHTERMAN_REINGOLD_ALGORITHM_H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

#include "libsbml_ne_autolayout_object_base.h"
#include "libsbml_ne_autolayout_point.h"

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE {

class FruthtermanReingoldAlgorithm {

public:

    FruthtermanReingoldAlgorithm();

    void setElements(Layout* layout);

    void setStiffness(const double& stiffness);

    void setGravity(const double& gravity);

    void setUseMagnetism(const bool& useMagnetism);

    void setUseBoundary(const bool& useBoundary);

    void setUseGrid(const bool& useGrid);

    void apply();

    void initialize();

    void iterate();

    void clearDisplacements();

    void computeRepulsiveForces();

    void computeAttractiveForces();

    void applyMagnetism();

    void applyGravity();

    void adjustCoordinates();

    void adjustWithinTheBoundary(AutoLayoutObjectBase* node);

    void adjustOnTheGrids(AutoLayoutObjectBase* node);

protected:

    void setNodes(Layout* layout);

    void setConnections(Layout* layout);

    double _stiffness;
    double _gravity;
    bool _useMagnetism;
    bool _useBoundary;
    bool _useGrid;

    std::vector<AutoLayoutObjectBase*> _connections;
    std::vector<AutoLayoutObjectBase*> _nodes;

    int _maximumIterations;
    double _initialTemperature;
    double _currentTemperature;
    double _time;
    double _alpha;
    double _timeIncrement;
    double _adjustk;
    int _its;
    double _d;
    AutoLayoutPoint _delta;
    double _width;
    double _height;
    AutoLayoutPoint _barycenter;
};

const double calculateEuclideanDistance(AutoLayoutPoint point);

const double calculateStiffnessAdjustmentFactor(AutoLayoutObjectBase* vNode, AutoLayoutObjectBase* uNode);

const double calculateRepulsionForce(const double& stiffness, const double& distance);

const double calculateAttractionForce(const double& stiffness, const double& distance);

AutoLayoutObjectBase* findObject(std::vector<AutoLayoutObjectBase*> objects, const std::string& objectId);

}

#endif
