#ifndef SRC_VERTEX_H
#define SRC_VERTEX_H

#include <vector>
#include <string>
#include "Edge.h"
#include "../util/map/Position.h"
#include "../util/map/MapLabel.h"
#include "../util/MutablePriorityQueue.h"

class Vertex {
public:
    Vertex(int id, int x, int y);

    int getId() const;
    Position getPosition() const;
    std::vector<MapLabel> getLabels() const;
    std::vector<Edge> getAdj() const;

    bool getVisited() const; // DFS
    double getDistance() const; // Dijkstra and A*

    void addLabel(MapLabel label);
    bool operator<(Vertex & vertex) const;

    friend class Graph;
    friend class MutablePriorityQueue<Vertex>; // Needed to implement the desired algorithms
private:
    int _id; // Identifies the vertex by a unique number
    Position _pos; // x and y of this vertex

    std::vector<MapLabel> _labels;
    std::vector<Edge> _adj;

    bool _visited = false;
    double _distance = 0; // Represents total cost in dijkstra algorithm and fScore in A*
    Vertex* _path = nullptr;
    Edge _pathEdge;

    // --- A*, auxiliary variables
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
