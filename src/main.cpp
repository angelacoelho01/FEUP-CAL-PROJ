#include "controller/Operations.h"

#include <iostream>
#include <algorithm>

#include "model/SilviosBakery.h"
// #include "map-backup/MapLoader.h"
#include "util/map/MapDrawer.h"
#include "util/map/GraphLoader.h"

#include <float.h>
#include <sstream>

void printUsage() {
    std::cout << "Usage:" << std::endl;
    std::cout << "./silvios view" << std::endl;
    std::cout << "./silvios preprocess <node_id>" << std::endl;
    std::cout << "./silvios astar <node_id1> <node_id2>" << std::endl;
    std::cout << "./silvios orders <file_name>" << std::endl;
    std::cout << "./silvios orders intime <file_name>" << std::endl;
}

int main(int argc, char* argv[]) {
    /*
    MapDrawer mapDrawer(1644, 921);
    mapDrawer.drawMapFromFile("Porto");
    */
    /*
    MapDrawer mapDrawer(1644, 921);
    Graph graph;
    GraphLoader::loadGraph(BAKERY_ZONE, &graph);
    mapDrawer.drawMapFromGraph(&graph);
    */

    // to test purposes
    // operation::view();
    // operation::preprocess(SILVIOS_BAKERY);
    // operation::aStar(SILVIOS_BAKERY, 262);
    operation::orders("orders_1.txt");
    // operation::ordersInTime("orders_1.txt");
    return 0;

    if (argc < 2) {
        printUsage();
        return 0;
    }

    std::string operation = argv[1];
    if (operation == "view") {
        operation::view();

    } else if (operation == "preprocess") {
        if (argc != 3) {
            std::cout << "Not enough arguments." << std::endl;
            exit(1);
        }

        operation::preprocess(atoi(argv[2]));
    } else if (operation == "astar") {
        if (argc != 4) {
            std::cout << "Not enough arguments." << std::endl;
            exit(1);
        }

        operation::aStar(atoi(argv[2]), atoi(argv[3]));
    } else if (operation == "orders") {
        if (argc != 3 && argc != 4) {
            std::cout << "Not enough arguments." << std::endl;
            exit(1);
        }

        std:: string specification = argv[2];
        if (specification == "intime") {
            if (argc != 4) {
                std::cout << "Not enough arguments." << std::endl;
                exit(1);
            }

            operation::ordersInTime(specification);
        } else {
            operation::orders(specification);
        }
    } else {
        printUsage();
    }

    return 0;
}
