#include "Operations.h"

#include "../model/SilviosBakery.h"
#include "../graph/Graph.h"
#include "../model/van/Van.h"
#include "FilesReader.h"
#include "../model/VanDeliveryPlanner.h"

void operation::view() {
    Graph graph;
    // MapDrawer mapDrawer(2000, 2000);
    // GraphLoader::loadGraph(BAKERY_ZONE, &graph);
    // mapDrawer.drawMapFromGraph(&graph);
    getchar();
}

void operation::preprocess(int start_node) {
    Graph graph;
    // MapDrawer mapDrawer(2000, 2000);
    // GraphLoader::loadGraph(BAKERY_ZONE, &graph);

    Vertex* source = graph.findVertex(start_node);
    if (source == nullptr) {
        std::cout << "Vertex not found." << std::endl;
        exit(1);
    }

    graph.DFSConnectivity(source);
    graph.removeUnvisitedVertices();

    // mapDrawer.drawMapFromGraph(&graph);
    getchar();
}

void operation::aStar(int start_node, int dest_node) {
    Graph graph;
    // MapDrawer mapDrawer(2000, 2000);
    // GraphLoader::loadGraph(BAKERY_ZONE, &graph);

    Vertex* source = graph.findVertex(start_node);
    if (source == nullptr) {
        std::cout << "Start vertex id does not exist." << std::endl;
        exit(1);
    }
    // test connectivity around start vertex
    graph.DFSConnectivity(source);
    graph.removeUnvisitedVertices();

    Vertex* dest = graph.findVertex(dest_node);
    if (dest == nullptr) {
        std::cout << "Start and Destination vertexes are not in the same strongly connected component." << std::endl;
        exit(1);
    }

    graph.AStar(start_node, dest_node);
    std::vector<Edge> path = graph.AGetPathEdges(start_node, dest_node);

    /*
    mapDrawer.drawMapFromGraph(&graph);
    for (const Edge& e: path) {
        mapDrawer.getViewer()->setEdgeThickness(e.getId(), 10);
        mapDrawer.getViewer()->setEdgeColor(e.getId(), RED);
    }
    */
    getchar();
}

void operation::orders(const std::string& file_name) {

    std::vector<Van> vans = fileReader::getVansFromFile(); // only 1 exists
    std::vector<Client> clients = fileReader::getClientsFromFile();
    std::vector<Order> orders = fileReader::getOrdersFromFile("orders_1.txt", clients);

    vans[0].setOrders(orders); // the van is responsible by all orders

    Graph graph;
    // MapDrawer mapDrawer(2000, 2000);
    // GraphLoader::loadGraph(BAKERY_ZONE, &graph);

    int bakeryId = SILVIOS_BAKERY;
    VanDeliveryPlanner planner(&graph, bakeryId, vans[0]);

    graph.dijkstraShortestPath(bakeryId);

    planner.planVanDeliveryWithoutTimeWindow();

    /*
    mapDrawer.drawMapFromGraph(&graph);
    mapDrawer.getViewer()->setVertexColor(bakeryId, PINK);
    mapDrawer.getViewer()->rearrange();

    for (const Order& order: planner.getOrders()) {
        mapDrawer.getViewer()->setVertexColor(order.getAddress(), GREEN);
    }

    for (const Edge& e: planner.getPath()) {
        mapDrawer.getViewer()->setEdgeThickness(e.getId(), 10);
        mapDrawer.getViewer()->setEdgeColor(e.getId(), YELLOW);
    }

    mapDrawer.getViewer()->rearrange();
    */
    getchar();
}

void operation::ordersInTime(const std::string& file_name) {

}
