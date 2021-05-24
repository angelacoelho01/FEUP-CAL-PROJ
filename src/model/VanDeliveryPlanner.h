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
    VanDeliveryPlanner(Graph *graph, int bakery, const Van& van);

    Graph * getGraph() const;
    int getBakery() const;
    Van getVan() const;
    std::multiset<Order> getOrders() const;
    std::multiset<Order> buildOrders() const;
    std::vector<Edge> getPath() const;

    void preProcessEntryData();
    void planVanDeliveryWithoutTimeWindow();
    void planVanDeliveryWithTimeWindow();

    std::vector<Edge> calculatePath(const std::set<Vertex*>& orders);
    std::vector<Edge> calculatePathFromOrders();

    int calculateMinWaitPathInInterval(Order currentOrder, Time arrival, std::multiset<Order> remainingOrders, std::vector<Edge> &path);

    // int objectiveFunction();
private:
    Graph * _graph; // the graph that represents the area for which the van is responsible
    int _bakery; // vertex id here is located the bakery
    Van _van; // already has the orders that must delivery

    std::multiset<Order> _orders; // the ordered orders that the van is responsible by, ordered by desired delivery time
    std::vector<Edge> _path; // represents the edges that the van must travel to delivery all orders

    std::vector<Vertex*>::const_iterator getClosestVertex(Vertex* pivot, const std::vector<Vertex*>& list);
};

#endif //SRC_VAN_DELIVERY_PLANNER_H
