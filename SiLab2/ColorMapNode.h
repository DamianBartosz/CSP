#pragma once
#include "Node.h"

class ColorMapNode : public Node {
	int x;
	int y;
public:
	ColorMapNode(std::vector<std::vector<std::string>> domains, int x, int y) : Node(domains), x(x), y(y) {}

	int getX();

	int getY();

	friend bool operator==(const ColorMapNode& lhs, const ColorMapNode& rhs);

	friend bool operator!=(const ColorMapNode& lhs, const ColorMapNode& rhs);
};
