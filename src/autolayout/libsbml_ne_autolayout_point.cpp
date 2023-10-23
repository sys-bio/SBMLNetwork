#include "libsbml_ne_autolayout_point.h"

AutoLayoutPoint::AutoLayoutPoint(const double& x, const double& y) {
    _x = x;
    _y = y;
}

const double AutoLayoutPoint::getX() {
    return _x;
};

void AutoLayoutPoint::setX(const double& x) {
    _x = x;
}

const double AutoLayoutPoint::getY() {
    return _y;
};

void AutoLayoutPoint::setY(const double& y) {
    _y = y;
}
