#ifndef SRC_VERTEX_H
#define SRC_VERTEX_H

#include <vector>
#include <string>
#include "Edge.h"
#include "../util/Position.h"
#include "../util/MapLabel.h"
#include "../util/MutablePriorityQueue.h"

class Vertex {
public:
    Vertex(int id, int x, int y);

    int getId() const;
    Position getPosition() const;
    std::vector<MapLabel> getLabels() const;
    std::vector<Edge> getAdj() const;

    bool getVisited() const;
    double getDistance() const;

    void addLabel(MapLabel label);
    bool operator<(Vertex & vertex) const;

    friend class Graph;
    friend class MutablePriorityQueue<Vertex>;

private:
    int _id;
    Position _pos;

    std::vector<MapLabel> _labels;
    std::vector<Edge> _adj;

    bool _visited = false;
    double _distance = 0; // Represents total cost in dijkstra algorithm and fScore in A*
    Vertex* _path = nullptr;
    Edge _pathEdge;

    // A*
    double _gScore = 0;
    Vertex* _aPath = nullptr;
    Edge _aPathEdge;

    int queueIndex = 0; // MutablePriorityQueue

    void addEdge(int id, Vertex* orig, Vertex* dest, double weight);
};

struct VertexHash {
    bool operator()(const Vertex* v1, const Vertex* v2) const {
        return v1->getId() == v2->getId();
    }

    int operator()(const Vertex* v) const {
        return v->getId();
    }
};

#endif //SRC_VERTEX_H
