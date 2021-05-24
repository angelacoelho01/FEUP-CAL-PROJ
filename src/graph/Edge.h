#ifndef SRC_EDGE_H
#define SRC_EDGE_H

#include "../util/Time.h"

class Vertex;

class Edge {
public:
    Edge();
    Edge(int id, Vertex *orig, Vertex* dest, double weight);

    int getId() const;
    Vertex* getOrig() const;
    Vertex* getDest() const;
    double getWeight() const;

    void setId(int id);
    void setOrig(Vertex* orig);
    void setDest(Vertex* dest);
    void setWeight(double weight);

    void invertEdge();
    double getDistance() const;

    friend class Graph;
    friend class Vertex;

private:
    int _id; // identifies a edge by his unique number
    Vertex *_orig, *_dest; // a edge connects a start to a destination
    double _weight; // time in seconds that takes to travel that edge, according to the van speed
};

#endif //SRC_EDGE_H
