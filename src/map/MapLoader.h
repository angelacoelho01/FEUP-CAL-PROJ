#ifndef SRC_MAPLOADER_H
#define SRC_MAPLOADER_H

#include <vector>
#include <fstream>
#include <string>
#include <graphviewer.h>

class MapLoader {
public:
    MapLoader(int width, int height);
    void loadMap(const std::string& location);

private:
    void loadNodes(const std::string& location);
    void loadEdges(const std::string& location);

    int _width;
    int _height;
    GraphViewer _gv;
};


#endif //SRC_MAPLOADER_H
