#ifndef __LIBSBML_NE_AUTOLAYOUT_NODE__H
#define __LIBSBML_NE_AUTOLAYOUT_NODE__H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

class AutoLayoutNode {
public:

    AutoLayoutNode(GraphicalObject* graphicalObject);

    const std::string getId();

    const double getX();

    void setX(const double& x);

    const double getY();

    void setY(const double& y);

    const double getWidth();

    void setWidth(const double& width);

    const double getHeight();

    void setHeight(const double& height);

    const double getDisplacementX();

    void setDisplacementX(const double& dx);

    const double getDisplacementY();

    void setDisplacementY(const double& dy);

    const int getDegree();

    void setDegree(const int& degree);

protected:

    GraphicalObject* _graphicalObject;
    double _displacementX;
    double _displacementY;
    int _degree;
};

#endif
