#include "MentholAndBeerConstraint.h"

bool MentholAndBeerConstraint::check(Node& node, std::vector<std::shared_ptr<Node>>& allNodes) {
	if (node[2] == "menthol") {
		if (!node[3].empty() && node[3] != "beer") return false;
	}else if(node[3] == "beer") {
		if (!node[2].empty() && node[2] != "menthol") return false;
	}
	return true;
}
