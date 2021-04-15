#include "UnfilteredHasBirdsConstraint.h"

bool UnfilteredHasBirdsConstraint::check(Node& node, std::vector<std::shared_ptr<Node>>& allNodes) {
	if (node[2] == "unfiltered") {
		if (!node[4].empty() && node[4] != "birds") return false;
	}
	else if (node[4] == "birds") {
		if (!node[2].empty() && node[2] != "unfiltered") return false;
	}
	return true;
}
