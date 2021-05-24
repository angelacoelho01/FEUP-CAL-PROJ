#ifndef SRC_GRAPH_H
#define SRC_GRAPH_H

#include "Vertex.h"
#include "../util/MutablePriorityQueue.h"

#include <vector>
#include <algorithm>
#include <unordered_map>

#define INF std::numeric_limits<double>::max()
#define INF_INT std::numeric_limits<int>::max()

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
    std::vector<int> getPathVertices(int origin, int dest) const;
    std::vector<Edge> getPathEdges(int origin, int dest) const;
    std::vector<int> getPath(int origin, int dest);
    // --

    // A*
    Vertex* AInitSource(const int &origin);
    void AStar(const int &origin, const int &dest);
    double heuristic(Vertex* current, Vertex* dest);
    std::vector<int> AGetPathVertices(int origin, int dest) const;
    std::vector<Edge> AGetPathEdges(int origin, int dest) const;
    // --

    void reset();
    ~Graph();

    // Test connectivity from a specific source
    void DFSConnectivity(Vertex* start);
    // Remove the unvisited vertices and edges that end in those
    void removeUnvisitedVertices();
    // Combined they generates a strong connected graph based on the start vertex
private:
    std::unordered_map<int, Vertex *> _vertexHashMap; // to optimize vertex find
    std::vector<Vertex *> _vertexSet; // the set of vertexes that composes the graph

    void DFSVisit(Vertex* v);
};

#endif //SRC_GRAPH_H
