#include "Edge.h"

Edge::Edge() : _id(-1), _orig(nullptr), _dest(nullptr), _weight(Time(0, 0)) { }

Edge::Edge(int id, Vertex *orig, Vertex *dest, Time weight)
        : _id(id), _orig(orig), _dest(dest), _weight(weight) { }

int Edge::getId() const {
    return this->_id;
}

Vertex* Edge::getOrig() const {
    return this->_orig;
}

Vertex* Edge::getDest() const {
    return this->_dest;
}

Time Edge::getWeight() const {
    return this->_weight;
}

void Edge::setId(const int id) {
    this->_id = id;
}

void Edge::setOrig(Vertex *orig) {
    this->_orig = orig;
}

void Edge::setDest(Vertex *dest) {
    this->_dest = dest;
}

void Edge::setWeight(const Time weight) {
    this->_weight = weight;
}

void Edge::invertEdge() {
    Vertex * tmp = _dest;
    _dest = _orig;
    _orig = tmp;
}
