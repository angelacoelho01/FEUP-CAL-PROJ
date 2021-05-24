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
    void drawGraphViewer();

    bool drawMapFromFile(const std::string& location);
    bool loadMapFromGraph(Graph* graph);
    const sf::Color getLabelColor(MapLabel label);

    void setNodeSize(int nodeId, float size);
    void setNodeColor(int nodeId, const sf::Color &color);
    void setEdgeThickness(int edgeId, float thickness);
    void setEdgeColor(int edgeId, const sf::Color &color);
private:
    int _width, _height;
    GraphViewer _graphViewer;

    void loadNodesFromFile(const std::string& location);
    void loadEdgesFromFile(const std::string& location);
};

#endif //SRC_MAPDRAWER_H
