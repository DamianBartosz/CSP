#include "ColorMapNode.h"

int ColorMapNode::getX() {
	return x;
}

int ColorMapNode::getY() {
	return y;
}

bool operator==(const ColorMapNode& lhs, const ColorMapNode& rhs) {
	return lhs.x == rhs.x
		&& lhs.y == rhs.y;
}

bool operator!=(const ColorMapNode& lhs, const ColorMapNode& rhs) {
	return !(lhs == rhs);
}
