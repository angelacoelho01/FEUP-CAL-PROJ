#include "MapDrawer.h"
#include "Position.h"

#include "../../graph/Graph.h"

MapDrawer::MapDrawer(int width, int height) {
    this->_width = width;
    this->_height = height;
    // this->_graphViewer = new GraphViewer(width, height, false);
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
