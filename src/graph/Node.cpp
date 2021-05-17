//
// Created by angela on 17/05/21.
//

#include "Node.h"

Node::Node(int id, double x, double y) : _id(id), _x(x), _y(y)/*, outgoing(), incoming()*/ {

}

int Node::getId() const {
    return _id;
}

bool Node::operator==(const Node &node) {
    return this->getId() == node.getId();
}

void Node::setLat(double lat) {
    _lat = lat;
}

void Node::setLon(double lon) {
    _lon = lon;
}

double Node::getX() const {
    return _x;
}

double Node::getY() const {
    return _y;
}
