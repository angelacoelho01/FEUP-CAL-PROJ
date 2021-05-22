#ifndef SRC_VAN_DELIVERY_PLANNER_H
#define SRC_VAN_DELIVERY_PLANNER_H

#include "../graph/Graph.h"
#include "van/Van.h"

#include <set>

// for later improvements the areas for which van is responsible by
// and the corresponding orders (according to their capacity) is defined before hand

// here the given graph already is the area of that van, and the van includes all
// orders that she is responsible by
// Consider that the van has the capacity for all orders in this area

class VanDeliveryPlanner {
public:
    VanDeliveryPlanner(Graph * graph, int bakery, const Van& van);

    Graph * getGraph() const;
    int getBakery() const;
    Van getVan() const;
    std::multiset<Order> getOrders() const;

    void preProcessEntryData();
    void planVanDeliveryWithoutTimeWindow();
    void planVanDeliveryWithTimeWindow();

    std::vector<Edge> calculatePath(const std::set<Vertex*>& orders);
    int objectiveFunction();
private:
    Graph * _graph; // the graph that represents the area for which the van is responsible
    int _bakery; // vertex here is located the bakery
    Van _van; // already has the orders that must delivery
};

#endif //SRC_VAN_DELIVERY_PLANNER_H
