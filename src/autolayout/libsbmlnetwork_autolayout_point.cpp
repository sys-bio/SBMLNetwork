#include "libsbmlnetwork_autolayout_point.h"
#include "libsbmlnetwork_common.h"

#include "iostream"

AutoLayoutPoint::AutoLayoutPoint(const double& x, const double& y) {
    _x = x;
    _y = y;
}

const double AutoLayoutPoint::getX() const {
    return roundToTwoDecimalPlaces(_x);
};

void AutoLayoutPoint::setX(const double& x) {
    _x = x;
}

const double AutoLayoutPoint::getY() const {
    return roundToTwoDecimalPlaces(_y);
};

void AutoLayoutPoint::setY(const double& y) {
    _y = y;
}

void AutoLayoutPoint::setPosition(const AutoLayoutPoint position) {
    _x = position.getX();
    _y = position.getY();
}

const AutoLayoutPoint AutoLayoutPoint::getPosition() {
    return AutoLayoutPoint(_x, _y);
}

const bool AutoLayoutPoint::isEmpty() {
    if (std::abs(_x) > 0.000001 || std::abs(_y) > 0.000001)
        return false;

    return true;
}
