#include "GreenOnWhitesLeftConstraint.h"

bool GreenOnWhitesLeftConstraint::check(Node& node, std::vector<std::shared_ptr<Node>>& allNodes) {
	if (node[1] == "green") {
		if (node.getNeighbors()[1] == nullptr || (!(*node.getNeighbors()[1])[1].empty() && (*node.getNeighbors()[1])[1]
			!= "white")) return false;
	}
	else if (node[1] == "white") {
		if (node.getNeighbors()[0] == nullptr || (!(*node.getNeighbors()[0])[1].empty() && (*node.getNeighbors()[0])[1]
			!= "green")) return false;
	}
	return true;
}
