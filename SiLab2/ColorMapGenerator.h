#pragma once
#include "ColorMapNode.h"

struct Edge {
	int x1, y1, x2, y2;
};

class ColorMapGenerator {
	int x;
	int y;
	int n;
	std::vector<std::vector<std::string>> domains;
	std::vector<std::shared_ptr<ColorMapNode>> nodes;
	std::vector<Edge> edges;
public:
	ColorMapGenerator(int x, int y, int n, std::vector<std::vector<std::string>> domains) : x(x), y(y), n(n), domains(domains) {}

	std::vector<std::shared_ptr<ColorMapNode>> getNodes();
	
	bool doEdgesCross(Edge a, Edge b);
private:
	void generateNodes();

	void generateEdges();


	int vectorProduct(Edge a, int x, int y);

	bool isPointOnEdge(Edge a, int x, int y);

	double getNodesDistance(ColorMapNode& a, ColorMapNode& b);
};
