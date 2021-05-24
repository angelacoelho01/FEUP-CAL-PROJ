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

    mapDrawer.loadMapFromGraph(&graph);
    mapDrawer.drawGraphViewer();
    // getchar();
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

    mapDrawer.loadMapFromGraph(&graph);
    mapDrawer.setNodeSize(start_node, 50);
    mapDrawer.setNodeColor(start_node, GraphViewer::CYAN);
    mapDrawer.drawGraphViewer();
    // getchar();
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
    mapDrawer.loadMapFromGraph(&graph);
    // highlight source vertex
    mapDrawer.setNodeSize(start_node, 50);
    mapDrawer.setNodeColor(start_node, GraphViewer::CYAN);
    // highlight destination vertex
    mapDrawer.setNodeSize(dest_node, 50);
    mapDrawer.setNodeColor(dest_node, GraphViewer::CYAN);
    // highlight path edges
    for (const Edge& e: path) {
        mapDrawer.setEdgeThickness(e.getId(), 10);
        mapDrawer.setEdgeColor(e.getId(), GraphViewer::YELLOW);
    }
    mapDrawer.drawGraphViewer();
    // getchar();
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
    mapDrawer.loadMapFromGraph(&graph);
    // highlight bakery location
    mapDrawer.setNodeSize(bakeryId, 50);
    mapDrawer.setNodeColor(bakeryId, GraphViewer::CYAN);
    // highlight points of delivery
    std::set<int> ordersAddress;
    for (const Order& order: planner.getOrders()) {
        ordersAddress.insert(order.getAddress());
        mapDrawer.setNodeSize(order.getAddress(), 50);
        mapDrawer.setNodeColor(order.getAddress(), GraphViewer::GREEN);
    }
    // highlight path
    int i = 1;
    for (const Edge& e: planner.getPath()) {
        mapDrawer.setEdgeThickness(e.getId(), 10);
        mapDrawer.setEdgeColor(e.getId(), GraphViewer::YELLOW);
        if (ordersAddress.find(e.getDest()->getId()) != ordersAddress.end()) {
            mapDrawer.getGraphViewer()->getNode(e.getDest()->getId()).setLabel(std::to_string(i++));
        }
    }
    mapDrawer.drawGraphViewer();
    // getchar();
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
    mapDrawer.loadMapFromGraph(&graph);
    // highlight bakery location
    mapDrawer.setNodeSize(bakeryId, 50);
    mapDrawer.setNodeColor(bakeryId, GraphViewer::CYAN);
    // highlight points of delivery
    std::set<int> ordersAddress;
    for (const Order& order: planner.getOrders()) {
        ordersAddress.insert(order.getAddress());
        mapDrawer.setNodeSize(order.getAddress(), 50);
        mapDrawer.setNodeColor(order.getAddress(), GraphViewer::GREEN);
    }
    // highlight path
    int i = 1;
    for (const Edge& e: planner.getPath()) {
        mapDrawer.setEdgeThickness(e.getId(), 10);
        mapDrawer.setEdgeColor(e.getId(), GraphViewer::ORANGE);
        if (ordersAddress.find(e.getDest()->getId()) != ordersAddress.end()) {
            mapDrawer.getGraphViewer()->getNode(e.getDest()->getId()).setLabel(std::to_string(i++));
        }
    }
    mapDrawer.drawGraphViewer();
    // getchar();
}
