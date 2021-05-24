#include "MapLoader.h"


bool GraphLoader::loadGraph(const std::string& location, Graph* graph) {
    return (loadVertices(location, graph) && loadEdges(location, graph));
}

bool GraphLoader::loadVertices(const std::string& location, Graph* graph) {

    return true;
}

bool GraphLoader::loadEdges(const std::string& location, Graph* graph) {

    return true;
}
