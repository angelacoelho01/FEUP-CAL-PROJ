#ifndef SRC_MAPDRAWER_H
#define SRC_MAPDRAWER_H

#include "MapLabel.h"

#include <iostream>

class Graph;
class VanDeliveryPlanner;

class MapDrawer {
public:
    MapDrawer(int width, int height);
    ~MapDrawer();

    // GraphViewer* getGraphViewer();

    bool drawMapFromGraph(Graph* graph);
    static std::string getLabelColor(MapLabel label);
private:
    int _width, _height;
    // GraphViewer* _graphViewer;

    void resetGraphViewer();
};

#endif //SRC_MAPDRAWER_H
