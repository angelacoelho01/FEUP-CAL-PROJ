#include "controller/Operations.h"
#include "util/Time.h"
#include "model/client/Client.h"
#include "graph/Graph.h"
#include "model/order/Order.h"
#include "model/van/Van.h"

#include <iostream>

void printUsage() {
    std::cout << "Usage:" << std::endl;
    std::cout << "./silvios view" << std::endl;
    std::cout << "./silvios preprocess" << std::endl;
    std::cout << "./silvios astar" << std::endl;
    std::cout << "./silvios orders <file_number>" << std::endl;
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printUsage();
        return 0;
    }
    /*Time time(7, 30);
    Time time2(7, 20);
    Time time3(12,30);
    std::string nome ="MARTA";
    std::string id = "3";
    Client c1(id, nome, 91599799);
    Client c2(id, nome, 91599799);
    Client c3(id, nome, 91599799);

    Graph graph;
    graph.addVertex(1,1,1);
    graph.addVertex(2,1,1);


    Order o1(1,c1, 2, time);
    Order o2(2,c2, 2, time2);
    Order o3(3,c3, 2, time3);
    Order o4(4,c3, 2, time3);


    std::string name = "manuel";
    Van van(name ,10,  Time(15,30));
    van.addOrder(o1);
    van.addOrder(o2);
    van.addOrder(o3);

    graph.checkInvalidOrders(van);

    van.sortOrders();

    for (auto & i : van.getOrders()){
        std::cout<< i <<std::endl;
    }*/


    std::string operation = argv[1];
    if (operation == "view") {
        // only draw the original graph of the area
        operation::view();
    } else if (operation == "preprocess") {
        // analyse connectivity and remove unvisited vertices
        // show preprocess graph
        operation::preprocess();
    } else if (operation == "astar") {
        // process graph using Astar algorithm
        operation::aStar();
    } else if (operation == "orders") {
        if (argc != 3) {
            std::cout << "Not enough arguments." << std::endl;
            exit(1);
        }
        // pass a van for all orders in this folder with time interval
        operation::orders(argv[2]);
    } else {
        printUsage();
    }

    return 0;
}
