#include "MapLoader.h"

#include <sstream>
#include <algorithm>
#include <iostream>

#include "../model/exception/FileException.h"

MapLoader::MapLoader(int width, int height) : _width(width), _height(height){
}


void MapLoader::loadNodes(const std::string& location) {
    std::stringstream ss; ss << "../resources/" << location << "/nodes_x_y.txt";
    std::string path = ss.str();

    std::ifstream ifs(path);

    if(!ifs) throw FileNotFound(path);
    int numNodes, id;
    double x, y;
    char c;

    ifs >> numNodes;

    for(int i = 0; i < numNodes; i++) {
        ifs >> c >> id >> c >> x >> c >> y >> c;
        GraphViewer::Node &node = _gv.addNode(id, sf::Vector2f (x, y));
    }

    ifs.close();
}

void MapLoader::loadEdges(const std::string& location) {
    std::stringstream ss; ss << "../resources/" << location << "/edges.txt";
    std::string path = ss.str();

    std::ifstream ifs(path);

    if(!ifs) throw FileNotFound(path);

    int numEdges, idOrig, idDest;
    char c;

    ifs >> numEdges;

    for(int i = 0; i < numEdges; i++) {
        ifs >> c >> idOrig >> c >> idDest >> c;
        _gv.addEdge(i, _gv.getNode(idOrig), _gv.getNode(idDest));
    }

    ifs.close();
}

void MapLoader::loadMap(const std::string& location) {
    _gv.setCenter(sf::Vector2f(_width, -_height));
    _gv.setScale(6.0);

    loadNodes(location);
    loadEdges(location);

    std::cout << "Number of nodes: " << _gv.getNodes().size() << std::endl;

    //_gv.setEnabledNodes(false); // Disable node drawing
    //_gv.setEnabledEdgesText(false); // Disable edge text drawing

    _gv.setZipEdges(true);
    _gv.createWindow(_width, _height);
    _gv.join();
}

