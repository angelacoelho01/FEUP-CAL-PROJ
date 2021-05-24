#include "MapDrawer.h"
#include "Position.h"

#include "../../graph/Graph.h"
#include "../../model/exception/FileException.h"

#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

MapDrawer::MapDrawer(int width, int height) {
    this->_width = width;
    this->_height = height;
    // this->_graphViewer = new GraphViewer(width, height);
}

MapDrawer::~MapDrawer() {
    // delete this->_graphViewer;
}
/*
GraphViewer* MapDrawer::getGraphViewer() {
    return this->_graphViewer;
}

void MapDrawer::resetGraphViewer() {
    this->_graphViewer->closeWindow();
    delete this->_graphViewer;

    this->_graphViewer = new GraphViewer(width, height, false);
}
 */

void MapDrawer::loadNodesFromFile(const std::string& location) {
    std::stringstream ss;
    ss << "../resources/" << location << "/nodes_x_y.txt";
    std::string path = ss.str();

    std::ifstream ifs(path);
    if(!ifs) throw FileNotFound(path);

    int numNodes, id;
    double x, y;
    char c;

    ifs >> numNodes;

    for(int i = 0; i < numNodes; i++) {
        ifs >> c >> id >> c >> x >> c >> y >> c;
        GraphViewer::Node &node = _graphViewer.addNode(id, sf::Vector2f (x, y));
    }

    ifs.close();
}

void MapDrawer::loadEdgesFromFile(const std::string& location) {
    std::stringstream ss;
    ss << "../resources/" << location << "/edges.txt";
    std::string path = ss.str();

    std::ifstream ifs(path);
    if (!ifs) throw FileNotFound(path);

    int numEdges, idOrig, idDest;
    char c;

    ifs >> numEdges;

    for(int i = 0; i < numEdges; i++) {
        ifs >> c >> idOrig >> c >> idDest >> c;
        _graphViewer.addEdge(i, _graphViewer.getNode(idOrig), _graphViewer.getNode(idDest));
    }

    ifs.close();
}

bool MapDrawer::drawMapFromFile(const std::string& location) {
    _graphViewer.setCenter(sf::Vector2f(_width, -_height));
    _graphViewer.setScale(6.0);

    loadNodesFromFile(location);
    loadEdgesFromFile(location);

    std::cout << "Number of nodes: " << _graphViewer.getNodes().size() << std::endl;

    //_gv.setEnabledNodes(false); // Disable node drawing
    //_gv.setEnabledEdgesText(false); // Disable edge text drawing

    _graphViewer.setZipEdges(true);
    _graphViewer.createWindow(_width, _height);
    _graphViewer.join();
    return true;
}

bool MapDrawer::drawMapFromGraph(Graph* graph) {
    // this->resetGraphViewer();
    // _graphViewer->createWindow(_width, _height);
    // _graphViewer->defineVertexSize(1);

    double x_offset = 0, y_offset = 0;
    if (graph->getNumVertex() > 0) {
        Position firstVPos = graph->getVertexSet().at(0)->getPosition();
        x_offset = firstVPos.getX();
        y_offset = firstVPos.getY();
    }

    // Add the graph vertexes with the corresponding color, according to it's label
    for (Vertex* v : graph->getVertexSet()) {
        // _graphViewer->addNode(v->getId(), v->getPosition().getX() - x_offset, v->getPosition().getY() - y_offset);
        if (!v->getLabels().empty()) {
            // _graphViewer->setVertexColor(v->getId(), getLabelColor(v->getLabels().at(0)));
        }
    }

    // Add the graph edges with the corresponding color, according to it's label
    for (Vertex* v : graph->getVertexSet()) {
        for (const Edge &e : v->getAdj()) {
            // _graphViewer->addEdge(e.getId(), v->getId(), e.getDest()->getId(), EdgeType::DIRECTED);
        }
    }

    // _graphViewer->rearrange();
    return true;
}

std::string MapDrawer::getLabelColor(MapLabel label) {
    /*
    if (label == BAKERY) return PINK;
    else if (label == DELIVERY) return GREEN;
    else if (label == EDGE_PATH) return BLUE;
    else if (label == VERTEX_PATH) return RED;
    else if (label == DEFAULT) return BLACK;
     */

    return "";
}
