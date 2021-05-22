#include "VanDeliveryPlanner.h"

VanDeliveryPlanner::VanDeliveryPlanner(Graph * graph, int bakery, const Van& van)
        : _graph(graph), _bakery(bakery), _van(van) {

    this->_orders = this->getOrders();
}

Graph * VanDeliveryPlanner::getGraph() const {
    return this->_graph;
}

int VanDeliveryPlanner::getBakery() const {
    return this->_bakery;
}

Van VanDeliveryPlanner::getVan() const {
    return this->_van;
}

std::multiset<Order> VanDeliveryPlanner::getOrders() const {
    std::vector<Order> vanOrders = _van.getOrders();
    std::multiset<Order> orderedOrders(vanOrders.begin(), vanOrders.end());

    return orderedOrders;
}

void VanDeliveryPlanner::preProcessEntryData() {
    // Pre Process Graph
    Vertex *start = _graph->findVertex(_bakery);
    if (start == NULL) return;

    _graph->DFSConnectivity(start);
    _graph->removeUnvisitedVertices();

    // Pre Process Orders - Find if some order does not belong to the graph
    std::vector<Order> toAdd(_orders.begin(), _orders.end());
    std::vector<Order>::iterator it;
    
    // Find if some order does not belong to the graph
    for (it = toAdd.begin(); it != toAdd.end(); it++) {
        if (_graph->findVertex((*it).getAddress()) == nullptr) {
            it = toAdd.erase(it);
            it--;
        }
    }

    _orders = std::multiset<Order>(toAdd.begin(), toAdd.end());

    /* Orders were already divided to fit vans size and already sorted due to the use of multiset */

    // Apply dijkstra algorithm
    _graph->dijkstraShortestPath(_bakery);
}

void VanDeliveryPlanner::planVanDeliveryWithoutTimeWindow() {

}

void VanDeliveryPlanner::planVanDeliveryWithTimeWindow() {

}

// TODO
std::vector<Edge> VanDeliveryPlanner::calculatePath(const std::set<Vertex*>& orders) {
    std::vector<Edge> path;

    return path;
}

int VanDeliveryPlanner::objectiveFunction() {
    // TODO
    return 0;
}
