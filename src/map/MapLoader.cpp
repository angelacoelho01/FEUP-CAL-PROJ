//
// Created by angela on 17/05/21.
//

#include "MapLoader.h"

#include <sstream>
#include <algorithm>
#include <iostream>

MapLoader::MapLoader(int width, int height) : _width(width), _height(height){
}


void MapLoader::loadNodes(const std::string& location) {
    std::ifstream ifs("../resources/" + location + "/nodes_x_y.txt");
    //TODO: In case the file wasn't successfully opened, throw exception

    int numNodes, id;
    double x, y;
    char c;

    if(ifs) {
        ifs >> numNodes;

        for(int i = 0; i < numNodes; i++) {
            ifs >> c >> id >> c >> x >> c >> y >> c;
            GraphViewer::Node &node = _gv.addNode(id, sf::Vector2f (x, y));
        }

        ifs.close();
    }
}

void MapLoader::loadEdges(const std::string& location) {
    std::ifstream ifs("../resources/" + location + "/edges.txt");

    //TODO: In case the file wasn't successfully opened, throw exception

    int numEdges, idOrig, idDest;
    char c;

    if(ifs) {
        ifs >> numEdges;

        for(int i = 0; i < numEdges; i++) {
            ifs >> c >> idOrig >> c >> idDest >> c;
            _gv.addEdge(i, _gv.getNode(idOrig), _gv.getNode(idDest));
        }

        ifs.close();
    }
}

void MapLoader::loadMap(const std::string& location) {
    //_gv.setCenter(sf::Vector2f(100, 300));

    _gv.setScale(6.0);
    loadNodes(location);
    loadEdges(location);

    std::cout << "Number of nodes: " << _gv.getNodes().size() << std::endl;

    _gv.createWindow(_width, _height);
    _gv.join();
}

