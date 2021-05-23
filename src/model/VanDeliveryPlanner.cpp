#include "VanDeliveryPlanner.h"
#include "SilviosBakery.h"

VanDeliveryPlanner::VanDeliveryPlanner(Graph *graph, int bakery, const Van& van)
        : _graph(graph), _bakery(bakery), _van(van) {

    this->_orders = this->buildOrders();
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
    return this->_orders;
}

std::multiset<Order> VanDeliveryPlanner::buildOrders() const {
    std::vector<Order> vanOrders = _van.getOrders();
    std::multiset<Order> orderedOrders(vanOrders.begin(), vanOrders.end());

    return orderedOrders;
}

std::vector<Edge> VanDeliveryPlanner::getPath() const {
    return this->_path;
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

    for (it = toAdd.begin(); it != toAdd.end(); it++) {
        if (_graph->findVertex((*it).getAddress()) == nullptr) {
            it = toAdd.erase(it);
            it--;
        }
    }

    _orders = std::multiset<Order>(toAdd.begin(), toAdd.end());

    /* Orders were already divided to fit vans size and already sorted due to the use of multiset */

    // Apply dijkstra algorithm - starting in Silvio's Bakery
    _graph->dijkstraShortestPath(_bakery);
}

// *********************** WITHOUT TIME WINDOW - NEAREST NEIGHBOR ***********************

std::vector<Vertex*>::const_iterator VanDeliveryPlanner::getClosestVertex(Vertex* pivot, const std::vector<Vertex*>& list) {

    std::vector<Vertex*>::const_iterator closest = list.begin();
    double closestDist = pivot->getPosition().euclideanDistance((*closest)->getPosition());

    for (auto it = list.begin(); it != list.end(); it++) {
        Vertex* v = *it;
        if (v == pivot) continue;

        double tmpDist = pivot->getPosition().euclideanDistance(v->getPosition());

        if (tmpDist < closestDist) {
            closest = it;
            closestDist = tmpDist;
        }
    }

    return closest;
}

// Starts in the bakery, deliveries all orders and get back to the bakery
// based on the nearest neighbor approach when choosing the next order to delivery
std::vector<Edge> VanDeliveryPlanner::calculatePath(const std::set<Vertex*>& orders) {
    std::vector<Edge> path;

    Vertex* bakeryVertex = _graph->findVertex(_bakery);
    std::vector<Vertex*> tmpOrders(orders.begin(), orders.end());

    // Start by finding the closest from the silvio's bakery
    auto it = getClosestVertex(bakeryVertex, tmpOrders);
    Vertex* firstClosest = *it;
    tmpOrders.erase(it);

    // Make the path from silvio's bakery to the first order
    // - according to the shortest path between two vertexes (with A*)
    _graph->AStar(_bakery, firstClosest->getId());
    std::vector<Edge> fromBakery = _graph->AGetPathEdges(_bakery, firstClosest->getId());
    path.insert(path.end(), fromBakery.begin(), fromBakery.end());

    // Nearest neighbour approach between orders
    Vertex* current = firstClosest;
    while(!tmpOrders.empty()){
        auto it = getClosestVertex(current, tmpOrders);
        Vertex* closest = *it;
        tmpOrders.erase(it);

        _graph->AStar(current->getId(), closest->getId());
        std::vector<Edge> tmpPath = _graph->AGetPathEdges(current->getId(), closest->getId());
        path.insert(path.end(), tmpPath.begin(), tmpPath.end());

        current = closest;
    }

    // From final order back to Silvio's Bakery
    _graph->AStar(current->getId(), _bakery);
    std::vector<Edge> tmpPath = _graph->AGetPathEdges(current->getId(), _bakery);
    path.insert(path.end(), tmpPath.begin(), tmpPath.end());

    return path;
}

std::vector<Edge> VanDeliveryPlanner::calculatePathFromOrders() {
    std::set<Vertex*> vertexes;
    for (const auto& order: _orders) {
        vertexes.insert(_graph->findVertex(order.getAddress()));
    }

    return this->calculatePath(vertexes);
}

void VanDeliveryPlanner::planVanDeliveryWithoutTimeWindow() {
    this->preProcessEntryData();

    _path = this->calculatePathFromOrders();
}

// *********************** TIME WINDOW - BRUTE FORCE ***********************

Time calculatePathTime(std::vector<Edge> path) {
    double seconds = 0;
    for (auto e : path) {
        seconds += e.getWeight();
    }

    return Time(seconds);
}

int VanDeliveryPlanner::calculatePathWithTimeInterval(Order currentOrder, Time arrival, std::multiset<Order> remainingOrders, std::vector<Edge> &path) {
    if (currentOrder.getPreferredHour() + Time(0, MAX_ARRIVAL_TIME) < arrival)
        return INF;

    int waitTime = abs(arrival.toMinutes() - currentOrder.getPreferredHour().toMinutes()); // the interval of time that this client waits

    Vertex* currentOrderVertex = _graph->findVertex(currentOrder.getAddress());
    if (remainingOrders.empty()) {
        // From final order back to Silvio's Bakery
        _graph->AStar(currentOrderVertex->getId(), _bakery);
        std::vector<Edge> tmpPath = _graph->AGetPathEdges(currentOrderVertex->getId(), _bakery);
        path.insert(path.end(), tmpPath.begin(), tmpPath.end());

        return waitTime;
    }

    Time minLimitTime = currentOrder.getPreferredHour() - Time(0, MIN_ARRIVAL_TIME);
    if (arrival < minLimitTime)
        arrival = minLimitTime; // wait till lower bound of the time window

    arrival = arrival + _van.getDeliveryTime(); // stops and deliver the order to client
    int minNextWaitTime = 0;
    std::vector<Edge> minPath;

    for (auto remainOrder : remainingOrders) {
        std::vector<Edge> nextPath;
        std::multiset<Order> tmpOrders = remainingOrders;

        Vertex* remainOrderVertex = _graph->findVertex(remainOrder.getAddress());
        // Make the path from silvio's bakery to the order
        _graph->AStar(currentOrderVertex->getId(), remainOrderVertex->getId());
        std::vector<Edge> tmpPath = _graph->AGetPathEdges(currentOrderVertex->getId(), remainOrderVertex->getId());
        nextPath.insert(nextPath.end(), tmpPath.begin(), tmpPath.end());

        Time arrivalTime = arrival + calculatePathTime(nextPath);
        tmpOrders.erase(remainOrder);
        int nextWaitTime = calculatePathWithTimeInterval(remainOrder, arrivalTime, tmpOrders, nextPath);

        if (nextWaitTime < minNextWaitTime) {
            minNextWaitTime = nextWaitTime;
            minPath = path;
        }
    }

    path = minPath;
    return waitTime + minNextWaitTime;
}

void VanDeliveryPlanner::planVanDeliveryWithTimeWindow() {
    this->preProcessEntryData();

    Time startTime = Time(7, 0); // start time for the deliveries
    int minWaitTime = INF;

    for (auto order : _orders) {
        std::vector<Edge> path;
        std::multiset<Order> tmpOrders = _orders;

        Vertex* orderVertex = _graph->findVertex(order.getAddress());
        // Make the path from silvio's bakery to the order
        _graph->AStar(_bakery, orderVertex->getId());
        std::vector<Edge> fromBakery = _graph->AGetPathEdges(_bakery, orderVertex->getId());
        path.insert(path.end(), fromBakery.begin(), fromBakery.end());

        Time arrivalTime = startTime + calculatePathTime(path);
        tmpOrders.erase(order);
        int waitTime = calculatePathWithTimeInterval(order, arrivalTime, tmpOrders, path);

        if (waitTime < minWaitTime) {
            minWaitTime = waitTime;
            _path = path;
        }
    }
}
