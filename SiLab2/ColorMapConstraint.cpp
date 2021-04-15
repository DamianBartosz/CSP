#include "ColorMapConstraint.h"


bool ColorMapConstraint::check(Node& node, std::vector<std::shared_ptr<Node>>& allNodes) {
	for (auto neighbor : node.getNeighbors()) {
		if (!(*neighbor)[0].empty() && node[0] == (*neighbor)[0]) return false;
	}
	return true;
}
