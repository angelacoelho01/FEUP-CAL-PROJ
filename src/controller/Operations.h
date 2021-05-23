#ifndef SRC_OPERATIONS_H
#define SRC_OPERATIONS_H

#include <iostream>

namespace operation {
    // Only draw the original graph of the area of the bakery
    void view();

    // Analyse connectivity and remove unvisited vertices
    // Show preprocess graph of bakery zone, staring at certain node
    void preprocess(int start_node);

    // Process graph using AStar algorithm of bakery zone
    // Shows shortest path between 2 given nodes
    void aStar(int start_node, int dest_node);

    // Pass a van for all orders in a certain file
    // without time interval - nearest neighbor approach
    void orders(const std::string& file_name);

    // Pass a van for all orders in a certain file
    // considering the desired time interval and time window of arrival
    void ordersInTime(const std::string& file_name);
}

#endif //SRC_OPERATIONS_H
