#include "VanDeliveryPlanner.h"

VanDeliveryPlanner::VanDeliveryPlanner(Graph * graph, int bakery, const Van& van)
        : _graph(graph), _bakery(bakery), _van(van) { }

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
