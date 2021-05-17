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
    //std::ifstream ifs("../resources/" + location + "/nodes_x_y.txt");
    std::ifstream ifs("../resources/GridGraphs/16x16/nodes.txt");
    //TODO: In case the file wasn't successfully opened, throw exception

    int numNodes, id;
    double lat, lon;
    char c;

    if(ifs) {
        ifs >> numNodes;

        for(int i = 0; i < numNodes; i++) {
            ifs >> c >> id >> c >> lat >> c >> lon >> c;
            GraphViewer::Node &node = _gv.addNode(id, sf::Vector2f (lat, lon));
        }

        ifs.close();
    }
}

void MapLoader::loadEdges(const std::string& location) {
    //std::ifstream ifs("../resources/" + location + "/edges.txt");
    std::ifstream ifs("../resources/GridGraphs/16x16/edges.txt");

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
    //_gv.setScale(1/4000.0);
    //_gv.setCenter(sf::Vector2f(500,  500));
    loadNodes(location);
    loadEdges(location);

    _gv.createWindow(_width, _height);
    _gv.join();
}

