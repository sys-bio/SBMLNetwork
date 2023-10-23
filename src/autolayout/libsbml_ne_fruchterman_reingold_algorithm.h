#ifndef __LIBSBML_NE_FRUCHTERMAN_REINGOLD_ALGORITHM_H
#define __LIBSBML_NE_FRUCHTERMAN_REINGOLD_ALGORITHM_H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

#include "libsbml_ne_autolayout_node.h"
#include "libsbml_ne_autolayout_connection.h"

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE {

class FruthtermanReingoldAlgorithm {
    public:

    FruthtermanReingoldAlgorithm();

    void setElements(Model* model, Layout* layout);

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

    protected:

    double _stiffness;
    double _gravity;
    bool _useMagnetism;
    bool _useBoundary;
    bool _useGrid;

    std::vector<AutoLayoutConnection*> _connections;
    std::vector<AutoLayoutNode*> _nodes;

    int _maxits;
    double _tempinit;
    double _tempcurr;
    double _time;
    double _alpha;
    double _timeinc;
    double _adjustk;
    int _its;
    double _d;
    Point _delta;
    double _width;
    double _length;
    Point _barycenter;
};

}

#endif
