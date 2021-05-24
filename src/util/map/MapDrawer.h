#ifndef SRC_MAPDRAWER_H
#define SRC_MAPDRAWER_H

#include "MapLabel.h"

#include <iostream>
#include <graphviewer.h>

class Graph;
class VanDeliveryPlanner;

class MapDrawer {
public:
    MapDrawer(int width, int height);
    ~MapDrawer();

    GraphViewer* getGraphViewer();
    void lockGraphViewer();
    void unlockGraphViewer();
    // Draws the graph viewer - called after load and change desired appearances
    void drawGraphViewer();

    // load and draw a map from the information in a file
    bool drawMapFromFile(const std::string& location);
    // Build the graphViewer according the information of a graph
    bool loadMapFromGraph(Graph* graph);
    const sf::Color getLabelColor(MapLabel label);

    // Functions to change nodes and edges appearances
    void setNodeSize(int nodeId, float size);
    void setNodeColor(int nodeId, const sf::Color &color);
    void setEdgeThickness(int edgeId, float thickness);
    void setEdgeColor(int edgeId, const sf::Color &color);
private:
    int _width, _height;
    GraphViewer _graphViewer;

    // load map nodes from the information in a file
    void loadNodesFromFile(const std::string& location);
    // load map edges from the information in a file
    void loadEdgesFromFile(const std::string& location);
};

#endif //SRC_MAPDRAWER_H
