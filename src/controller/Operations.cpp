#include "Operations.h"

#include "../util/map/GraphLoader.h"
#include "../util/map/MapDrawer.h"
#include "../graph/Graph.h"
#include "../model/SilviosBakery.h"
#include "../model/van/Van.h"
#include "../model/VanDeliveryPlanner.h"
#include "FilesReader.h"

void operation::view() {
    Graph graph;
    MapDrawer mapDrawer(1644, 921);
    GraphLoader::loadGraph(BAKERY_ZONE, &graph);
    mapDrawer.drawMapFromGraph(&graph);
    getchar();
}

void operation::preprocess(int start_node) {
    Graph graph;
    MapDrawer mapDrawer(1644, 921);
    GraphLoader::loadGraph(BAKERY_ZONE, &graph);

    Vertex* source = graph.findVertex(start_node);
    if (source == nullptr) {
        std::cout << "Vertex not found." << std::endl;
        exit(1);
    }
    // Test connectivity around the start vertex
    graph.DFSConnectivity(source);
    graph.removeUnvisitedVertices();

    mapDrawer.drawMapFromGraph(&graph);
    getchar();
}

void operation::aStar(int start_node, int dest_node) {
    Graph graph;
    MapDrawer mapDrawer(1644, 921);
    GraphLoader::loadGraph(BAKERY_ZONE, &graph);

    Vertex* source = graph.findVertex(start_node);
    if (source == nullptr) {
        std::cout << "Start vertex id does not exist." << std::endl;
        exit(1);
    }
    // Test connectivity around the start vertex
    graph.DFSConnectivity(source);
    graph.removeUnvisitedVertices();

    Vertex* dest = graph.findVertex(dest_node);
    if (dest == nullptr) {
        std::cout << "Start and Destination vertexes are not in the same strongly connected component." << std::endl;
        exit(1);
    }

    graph.AStar(start_node, dest_node);
    std::vector<Edge> path = graph.AGetPathEdges(start_node, dest_node);

    // Draw map-backup from graph and highlight the shortest path between the two vertexes
    mapDrawer.drawMapFromGraph(&graph);
    for (const Edge& e: path) {
        GraphViewer::Edge &edge = mapDrawer.getGraphViewer()->getEdge(e.getId());
        edge.setThickness(10);
        edge.setColor(GraphViewer::BLUE);
    }
    getchar();
}

void operation::orders(const std::string& file_name) {
    // Read data from files
    std::vector<Van> vans = fileReader::getVansFromFile(); // only 1 exists
    std::vector<Client> clients = fileReader::getClientsFromFile();
    std::vector<Order> orders = fileReader::getOrdersFromFile("orders_1.txt", clients);
    vans[0].setOrders(orders); // the van is responsible by all orders

    Graph graph;
    MapDrawer mapDrawer(1644, 921);
    GraphLoader::loadGraph(BAKERY_ZONE, &graph);

    int bakeryId = SILVIOS_BAKERY;
    VanDeliveryPlanner planner(&graph, bakeryId, vans[0]);
    graph.dijkstraShortestPath(bakeryId);
    planner.planVanDeliveryWithoutTimeWindow();

    // Draw map-backup from graph and highlight the Van path
    mapDrawer.drawMapFromGraph(&graph);
    GraphViewer::Node &bakery = mapDrawer.getGraphViewer()->getNode(bakeryId);
    bakery.setColor(GraphViewer::PINK);

    for (const Order& order: planner.getOrders()) {
        GraphViewer::Node &node = mapDrawer.getGraphViewer()->getNode(order.getAddress());
        node.setColor(GraphViewer::GREEN);
    }
    for (const Edge& e: planner.getPath()) {
        GraphViewer::Edge &edge = mapDrawer.getGraphViewer()->getEdge(e.getId());
        edge.setThickness(10);
        edge.setColor(GraphViewer::YELLOW);
    }

    mapDrawer.rearrange();
    getchar();
}

void operation::ordersInTime(const std::string& file_name) {
    // Read data from files
    std::vector<Van> vans = fileReader::getVansFromFile(); // only 1 exists
    std::vector<Client> clients = fileReader::getClientsFromFile();
    std::vector<Order> orders = fileReader::getOrdersFromFile("orders_1.txt", clients);
    vans[0].setOrders(orders); // the van is responsible by all orders

    Graph graph;
    MapDrawer mapDrawer(1644, 921);
    GraphLoader::loadGraph(BAKERY_ZONE, &graph);

    int bakeryId = SILVIOS_BAKERY;
    VanDeliveryPlanner planner(&graph, bakeryId, vans[0]);
    graph.dijkstraShortestPath(bakeryId);
    planner.planVanDeliveryWithTimeWindow();

    // Draw map-backup from graph and highlight the Van path
    mapDrawer.drawMapFromGraph(&graph);
    GraphViewer::Node &bakery = mapDrawer.getGraphViewer()->getNode(bakeryId);
    bakery.setColor(GraphViewer::PINK);

    for (const Order& order: planner.getOrders()) {
        GraphViewer::Node &node = mapDrawer.getGraphViewer()->getNode(order.getAddress());
        node.setColor(GraphViewer::GREEN);
    }
    for (const Edge& e: planner.getPath()) {
        GraphViewer::Edge &edge = mapDrawer.getGraphViewer()->getEdge(e.getId());
        edge.setThickness(10);
        edge.setColor(GraphViewer::YELLOW);
    }

    mapDrawer.rearrange();
    getchar();
}
