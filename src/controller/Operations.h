#ifndef SRC_OPERATIONS_H
#define SRC_OPERATIONS_H

#include <iostream>

namespace operation {
    // only draw the original graph of the area of the bakery
    void view();

    // analyse connectivity and remove unvisited vertices
    // show preprocess graph of bakery zone, staring any point
    void preprocess(int start_node);

    // process graph using AStar algorithm of bakery zone
    // shows shortest path between 2 nodes
    void aStar(int start_node, int dest_node);

    // pass a van for all orders in this file
    // without time interval - nearest neighbor approach
    void orders(const std::string& file_name);

    // pass a van for all orders in this file
    // in the desired time interval
    void ordersInTime(const std::string& file_name);
}

#endif //SRC_OPERATIONS_H
