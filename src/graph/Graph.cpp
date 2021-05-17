#include "Graph.h"

#include <iostream>
#include <unordered_set>

#define VAN_SPEED 50

std::vector<Vertex *> Graph::getVertexSet() const {
    return this->_vertexSet;
}

Vertex* Graph::findVertex(const int &id) const {
    std::unordered_map<int, Vertex*>::const_iterator it = _vertexHashMap.find(id);
    return it == _vertexHashMap.end() ? nullptr : it->second;
}

bool Graph::addVertex(const int &id, int x, int y) {
    if (findVertex(id) != nullptr) return false;

    Vertex* newVertex = new Vertex(id, x, y);
    _vertexSet.push_back(newVertex);
    _vertexHashMap.insert(std::pair<int,Vertex*>(id, newVertex));
    return true;
}

bool Graph::addEdge(int id, int origId, int destId) {
    Vertex *orig = findVertex(origId);
    Vertex *dest = findVertex(destId);
    if(orig == nullptr || dest == nullptr) return false;

    // Distance between to points in the Map
    double dist = orig->getPosition().euclideanDistance(dest->getPosition()); // in meters

    // TODO: pass speed to our time, according to distance
    double time1 = dist * 3600 / (VAN_SPEED * 1000);
    Time time = Time(0, 0);

    // Suppose that all roads have 2 ways
    orig->addEdge(id, orig, dest, time);
    dest->addEdge(id+1, dest, orig, time);
    return true;
}

int Graph::getNumVertex() const {
    return (int) (this->_vertexSet).size();
}

void Graph::reset() {
    for (auto & i : _vertexSet) delete i;
    _vertexSet.clear();
}

Graph::~Graph() {
    for (auto & i : _vertexSet) delete i;
}

void Graph::DFSVisit(Vertex* v) {
    v->_visited = true;
    for (const Edge &e : v->getAdj())
        if (!e.getDest()->getVisited())
            DFSVisit(e.getDest());
}

void Graph::DFSConnectivity(Vertex* start) {
    for (Vertex* v : _vertexSet)
        v->_visited = false;

    DFSVisit(start);
}

void Graph::removeUnvisitedVertices() {
    std::unordered_set<Vertex*, VertexHash, VertexHash> removed;

    // Remove vertices
    std::vector<Vertex *>::iterator v_it;
    for (v_it = _vertexSet.begin(); v_it != _vertexSet.end(); v_it++) {
        if (!((*v_it)->getVisited())) {
            removed.insert(*v_it);
            _vertexHashMap.erase((*v_it)->getId());
            v_it = _vertexSet.erase(v_it);
            v_it--;
        }
    }

    // Remove edges
    std::vector<Edge>::iterator e_it;
    for (Vertex* v : _vertexSet) {
        e_it = v->getAdj().begin();
        for (; e_it != v->getAdj().end(); e_it++) {
            if (removed.find((*e_it).getDest()) != removed.end()) {
                e_it = v->getAdj().erase(e_it);
                e_it--;
            }
        }
    }
}

// ------------------------------------------------------------
// ----------------- single source algorithms -----------------
Vertex* Graph::initSingleSource(const int &origin) {
    for (auto v : _vertexSet) {
        v->_visited = false;
        v->_distance = INF;
        v->_path = nullptr;
        v->_pathEdge = Edge();
    }

    auto s = findVertex(origin);
    s->_distance = 0;
    return s;
}

bool Graph::relax(Vertex* v, Edge edge) {
    Time weight = edge.getWeight();
    Vertex* w = edge.getDest();
    /*
    if (v->distance + weight < w->distance) {
        w->distance = v->distance + weight;
        w->path = v;
        w->pathEdge = edge;
        return true;
    }
    else
        return false;
    */
}

void Graph::dijkstraShortestPath(const int &origin) {

}

void Graph::dijkstraShortestPath(const int &origin, const int &dest) {

}

std::vector<int> Graph::getPathVertices(const int origin, const int dest) {

}

std::vector<Edge> Graph::getPathEdges(const int origin, const int dest) {

}

std::vector<int> Graph::getPath(const int origin, const int dest) {

}

// A*
void Graph::AStar(const int &origin, const int &dest) {

}

double Graph::heuristic(Vertex* current, Vertex * dest) {

}

Vertex* Graph::AInitSingleSource(const int &origin) {

}

std::vector<int> Graph::AGetPathVertices(const int origin, const int dest) {

}

std::vector<Edge> Graph::AGetPathEdges(const int origin, const int dest) {

}


