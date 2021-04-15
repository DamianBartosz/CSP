#include "ColorMapGenerator.h"
#include "Random.h"
#include <iostream>

void ColorMapGenerator::generateNodes() {
	for (int i = 0; i < n; i++) {
		std::shared_ptr<ColorMapNode> newNode = std::make_shared<ColorMapNode>(
			domains, random::randInt(0, x-1), random::randInt(0, y-1));
		bool unique = true;
		for (auto node : nodes) {
			if (*node == *newNode) unique = false;
		}
		if (unique) {
			nodes.emplace_back(newNode);
		}
		else {
			i--;
		}
	}
}

void ColorMapGenerator::generateEdges() {
	std::vector<int> indexes;
	for (int i = 0; i < n; i++) {
		indexes.emplace_back(i);
	}

	while (!indexes.empty()) {
		int i = random::randInt(0, indexes.size() - 1);
		int index = indexes[i];

		std::vector<std::shared_ptr<ColorMapNode>> nodesToConnect;
		for (auto node : nodes) {
			auto neighbors = nodes[index]->getNeighbors();
			if (*(nodes[index]) != *node && std::count(neighbors.begin(), neighbors.end(), node) == 0) {
				Edge newEdge{nodes[index]->getX(), nodes[index]->getY(), node->getX(), node->getY()};
				bool crossing = false;
				for (auto edge : edges) {
					if (doEdgesCross(edge, newEdge)) crossing = true;
				}

				if (!crossing) {
					nodesToConnect.emplace_back(node);
				}
			}
		}

		if (nodesToConnect.empty()) {
			indexes.erase(indexes.begin() + i);
		}
		else {
			auto nearestNode = nodesToConnect[0];
			double shortestDistance = getNodesDistance(*(nodes[index]), *nearestNode);
			for (auto node : nodesToConnect) {
				double distance = getNodesDistance(*(nodes[index]), *node);
				if (distance < shortestDistance) {
					shortestDistance = distance;
					nearestNode = node;
				}
			}
			nodes[index]->getNeighbors().emplace_back(nearestNode);
			nearestNode->getNeighbors().emplace_back(nodes[index]);
			edges.emplace_back(Edge{
				nodes[index]->getX(), nodes[index]->getY(), nearestNode->getX(), nearestNode->getY()
				});
		}
	}

}

std::vector<std::shared_ptr<ColorMapNode>> ColorMapGenerator::getNodes() {
	nodes.clear();
	generateNodes();
	generateEdges();
	return nodes;
}


bool ColorMapGenerator::doEdgesCross(Edge a, Edge b) {
	int v1 = vectorProduct(b, a.x1, a.y1),
	    v2 = vectorProduct(b, a.x2, a.y2),
	    v3 = vectorProduct(a, b.x1, b.y1),
	    v4 = vectorProduct(a, b.x2, b.y2);

	if ((v1 > 0 && v2 < 0 || v1 < 0 && v2>0) && (v3 > 0 && v4 < 0 || v3 < 0 && v4>0)) return true;

	if (v1 == 0 && isPointOnEdge(b, a.x1, a.y1)) return true;
	if (v2 == 0 && isPointOnEdge(b, a.x2, a.y2)) return true;
	if (v3 == 0 && isPointOnEdge(a, b.x1, a.y1)) return true;
	if (v4 == 0 && isPointOnEdge(a, b.x2, b.y2)) return true;

	return false;
}

int ColorMapGenerator::vectorProduct(Edge a, int x, int y) {
	int x1 = x - a.x1,
	    y1 = y - a.y1,
	    x2 = a.x2 - a.x1,
	    y2 = a.y2 - a.y1;
	return x1 * y2 - x2 * y1;
}

bool ColorMapGenerator::isPointOnEdge(Edge a, int x, int y) {
	return std::min(a.x1, a.x2) < x && x < std::max(a.x1, a.x2)
		&& std::min(a.y1, a.y2) < y && y < std::max(a.y1, a.y2);
}


double ColorMapGenerator::getNodesDistance(ColorMapNode& a, ColorMapNode& b) {
	return sqrt((a.getX() - b.getX()) * (a.getX() - b.getX()) +
		(a.getY() - b.getY()) * (a.getY() - b.getY()));
}
