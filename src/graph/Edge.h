#ifndef SRC_EDGE_H
#define SRC_EDGE_H

#include "../util/Time.h"

class Vertex;

class Edge {
public:
    Edge();
    Edge(int id, Vertex *orig, Vertex* dest, Time weight);

    int getId() const;
    Vertex* getOrig() const;
    Vertex* getDest() const;
    Time getWeight() const;

    void setId(const int id);
    void setOrig(Vertex* orig);
    void setDest(Vertex* dest);
    void setWeight(const Time weight);

    void invertEdge();

    friend class Graph;
    friend class Vertex;

private:
    int _id;
    Vertex *_orig, *_dest;
    Time _weight;
};

#endif //SRC_EDGE_H
