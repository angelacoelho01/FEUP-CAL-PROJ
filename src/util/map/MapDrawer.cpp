#include "MapDrawer.h"
#include "Position.h"

#include "../../graph/Graph.h"
#include "../../model/exception/FileException.h"

#include <fstream>
#include <sstream>
#include <iostream>

MapDrawer::MapDrawer(int width, int height) {
    this->_width = width;
    this->_height = height;
}

MapDrawer::~MapDrawer() { }

GraphViewer* MapDrawer::getGraphViewer() {
    return &this->_graphViewer;
}

void MapDrawer::rearrange() {
    _graphViewer.closeWindow();
    _graphViewer.setCenter(sf::Vector2f(_width, -_height));
    _graphViewer.setScale(6.0);

    _graphViewer.setZipEdges(true);
    _graphViewer.createWindow(_width, _height);
    _graphViewer.join();
}

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
    _graphViewer.setCenter(sf::Vector2f(_width, -_height));
    _graphViewer.setScale(6.0);

    double x_offset = 0, y_offset = 0;
    if (graph->getNumVertex() > 0) {
        Position firstVPos = graph->getVertexSet().at(0)->getPosition();
        x_offset = firstVPos.getX();
        y_offset = firstVPos.getY();
    }

    // Add the graph vertexes with the corresponding color, according to it's label
    for (Vertex* v : graph->getVertexSet()) {
        double x = v->getPosition().getX() - x_offset;
        double y = v->getPosition().getY() - y_offset;
        GraphViewer::Node &node = _graphViewer.addNode(v->getId(), sf::Vector2f (x, y));
        if (!v->getLabels().empty()) {
            node.setColor(getLabelColor(v->getLabels().at(0)));
        }
    }

    // Add the graph edges
    for (Vertex* v : graph->getVertexSet()) {
        for (const Edge &e : v->getAdj()) {
            GraphViewer::Node &nodeOrig = _graphViewer.getNode(v->getId());
            GraphViewer::Node &nodeDest = _graphViewer.getNode(e.getDest()->getId());
            _graphViewer.addEdge(e.getId(), nodeOrig, nodeDest /*, GraphViewer::Edge::EdgeType::DIRECTED*/);
        }
    }

    _graphViewer.setZipEdges(true);
    _graphViewer.createWindow(_width, _height);
    _graphViewer.join();
    return true;
}

const sf::Color MapDrawer::getLabelColor(MapLabel label) {

    if (label == BAKERY) return GraphViewer::PINK;
    else if (label == DELIVERY) return GraphViewer::GREEN;
    else if (label == EDGE_PATH) return GraphViewer::BLUE;
    else if (label == VERTEX_PATH) return GraphViewer::ORANGE;
    else if (label == DEFAULT) return GraphViewer::BLACK;

    return GraphViewer::WHITE;
}
