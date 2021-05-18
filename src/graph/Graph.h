#ifndef SRC_GRAPH_H
#define SRC_GRAPH_H

#include "Vertex.h"
#include "../util/MutablePriorityQueue.h"

#include <vector>
#include <algorithm>
#include <unordered_map>

#define INF std::numeric_limits<double>::max()

class Graph {
public:
    std::vector<Vertex *> getVertexSet() const;
    Vertex* findVertex(const int &id) const;
    bool addVertex(const int &id, int x, int y);
    bool addEdge(int id, int origId, int destId);
    int getNumVertex() const;

    // single source algorithms
    Vertex * initSource(const int &origin);
    bool relax(Vertex *v, Edge edge);
    void dijkstraShortestPath(const int &origin);
    void dijkstraShortestPath(const int &origin, const int &dest);
    std::vector<int> getPathVertices(const int origin, const int dest) const;
    std::vector<Edge> getPathEdges(const int origin, const int dest) const;
    std::vector<int> getPath(const int origin, const int dest);
    // --

    // A*
    void AStar(const int &origin, const int &dest);
    double heuristic(Vertex* current, Vertex* dest);
    Vertex* AInitSingleSource(const int &origin);
    std::vector<int> AGetPathVertices(const int origin, const int dest);
    std::vector<Edge> AGetPathEdges(const int origin, const int dest);
    // --

    void reset();
    ~Graph();

    void DFSConnectivity(Vertex* start);
    void removeUnvisitedVertices();

private:
    std::unordered_map<int, Vertex *> _vertexHashMap;
    std::vector<Vertex *> _vertexSet;

    void DFSVisit(Vertex* v);
};

#endif //SRC_GRAPH_H
