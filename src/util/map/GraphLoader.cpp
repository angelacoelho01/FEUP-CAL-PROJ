#include "GraphLoader.h"

#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

#include "../../model/exception/FileException.h"

bool GraphLoader::loadGraph(const std::string& location, Graph* graph) {
    return (loadNodes(location, graph) && loadEdges(location, graph));
}

bool GraphLoader::loadNodes(const std::string& location, Graph* graph) {
    std::stringstream ss;
    ss << "../resources/" << location << "/nodes_x_y.txt";
    std::string path = ss.str();

    std::ifstream ifs(path);
    if (!ifs.is_open()) throw FileNotFound(path);

    int numNodes, id;
    double x, y;
    char c;

    ifs >> numNodes;

    for(int i = 0; i < numNodes; i++) {
        ifs >> c >> id >> c >> x >> c >> y >> c;
        graph->addVertex(id, x, y);
    }

    ifs.close();
    return true;
}

bool GraphLoader::loadEdges(const std::string& location, Graph* graph) {
    std::stringstream ss;
    ss << "../resources/" << location << "/edges.txt";
    std::string path = ss.str();

    std::ifstream ifs(path);
    if (!ifs.is_open()) throw FileNotFound(path);

    int numEdges, idOrig, idDest;
    char c;

    ifs >> numEdges;

    for(int i = 0; i < numEdges; i++) {
        ifs >> c >> idOrig >> c >> idDest >> c;
        // std::cout << "id edge : " << i << std::endl;
        graph->addEdge(i * 2, idOrig, idDest);
    }

    ifs.close();
    return true;
}
