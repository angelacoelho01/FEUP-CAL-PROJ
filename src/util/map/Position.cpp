#include "Position.h"

#include <cmath>

Position::Position(double x, double y) : _x(x), _y(y) { }

Position::Position(const Position &pos) {
    this->_x = pos.getX();
    this->_y = pos.getY();
}

double Position::getX() const {
    return this->_x;
}

double Position::getY() const {
    return this->_y;
}

void Position::setX(const double x) {
    this->_x = x;
}

void Position::setY(const double y) {
    this->_y = y;
}

double Position::euclideanDistance(const Position &p2) const {
    return sqrt(pow(p2.getX() - _x, 2) + pow(p2.getY() - _y, 2));
}
