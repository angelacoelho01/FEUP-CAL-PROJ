#ifndef SRC_MAPLOADER_H
#define SRC_MAPLOADER_H

#include "../../graph/Graph.h"
#include "MapLabel.h"

#include <string>

class GraphLoader {
public:
    // load the complete graph: nodes and edges
    static bool loadGraph(const std::string& location, Graph* graph);
    // load the nodes/vertex of a file to the graph
    static bool loadNodes(const std::string& location, Graph* graph);
    // load the edges of a file to the graph
    static bool loadEdges(const std::string& location, Graph* graph);
private:

};

#endif //SRC_MAPLOADER_H
