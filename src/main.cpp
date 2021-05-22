#include "util/Time.h"
#include "operations/Operations.h"

#include <iostream>

void printUsage() {
    std::cout << "Usage:" << std::endl;
    std::cout << "./silvios view" << std::endl;
    std::cout << "./silvios preprocess" << std::endl;
    std::cout << "./silvios astar" << std::endl;
    std::cout << "./silvios orders <orders_file>" << std::endl;
}

int main(int argc, char* argv[]) {
    /*Time time(23, 30);
    Time time2(0, 30);
    std::cout << time + time2 << std::endl;
     */

    if (argc < 2) {
        printUsage();
        return 0;
    }

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
