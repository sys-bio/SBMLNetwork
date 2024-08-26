#ifndef __LIBSBMLNETWORK_AUTOLAYOUT_POINT__H
#define __LIBSBMLNETWORK_AUTOLAYOUT_POINT__H

class AutoLayoutPoint {
public:

    AutoLayoutPoint(const double& x = 0.0, const double& y = 0.0);

    const double getX() const;

    void setX(const double& x);

    const double getY() const;

    void setY(const double& y);

    void setPosition(const AutoLayoutPoint position);

    const AutoLayoutPoint getPosition();

    const bool isEmpty();

protected:

    double _x;
    double _y;
};

#endif
