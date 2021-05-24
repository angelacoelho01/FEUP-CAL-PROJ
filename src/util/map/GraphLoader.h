#ifndef SRC_MAPLOADER_H
#define SRC_MAPLOADER_H

#include "../../graph/Graph.h"
#include "MapLabel.h"

#include <string>

class GraphLoader {
public:
    static bool loadGraph(const std::string& location, Graph* graph);
    static bool loadNodes(const std::string& location, Graph* graph);
    static bool loadEdges(const std::string& location, Graph* graph);
    // static bool loadTags(const std::string& location, Graph* graph);
private:

};

#endif //SRC_MAPLOADER_H
