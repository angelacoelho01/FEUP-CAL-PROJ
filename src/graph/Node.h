//
// Created by angela on 17/05/21.
//

#ifndef SRC_NODE_H
#define SRC_NODE_H

#include <vector>

#include "Edge.h"

class Edge;
class Node {
public:

    Node(int id, double x, double y);

    int getId() const;
    double getX() const;
    double getY() const;

    void setLat(double lat);
    void setLon(double lon);

    bool operator==(const Node& node);

private:
    int _id;
    double _x;
    double _y;
    double _lat;
    double _lon;

    std::vector<Edge*> outgoing;
    std::vector<Edge*> incoming;
};


#endif //SRC_NODE_H
