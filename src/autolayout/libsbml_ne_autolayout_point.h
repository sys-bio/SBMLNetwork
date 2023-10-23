#ifndef __LIBSBML_NE_AUTOLAYOUT_POINT__H
#define __LIBSBML_NE_AUTOLAYOUT_POINT__H

class AutoLayoutPoint {
public:

    AutoLayoutPoint(const double& x = 0.0, const double& y = 0.0);

    const double getX();

    void setX(const double& x);

    const double getY();

    void setY(const double& y);

protected:

    double _x;
    double _y;
};

#endif
