#include "Vertex.h"

Vertex::Vertex(int id, int x, int y) : _id(id), _pos(Position(x, y)) { }

int Vertex::getId() const {
    return this->_id;
}

Position Vertex::getPosition() const {
    return this->_pos;
}

std::vector<MapLabel> Vertex::getLabels() const {
    return this->_labels;
}

std::vector<Edge> Vertex::getAdj() const {
    return this->_adj;
}

bool Vertex::getVisited() const {
    return this->_visited;
}

double Vertex::getDistance() const {
    return this->_distance;
}

void Vertex::addEdge(int id, Vertex* orig, Vertex* dest, double weight) {
    _adj.push_back(Edge(id, orig, dest, weight));
}

void Vertex::addLabel(MapLabel label) {
    this->_labels.push_back(label);
}

bool Vertex::operator<(Vertex & vertex) const {
    return this->_distance < vertex.getDistance();
}
