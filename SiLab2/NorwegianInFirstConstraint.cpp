#include "NorwegianInFirstConstraint.h"


bool NorwegianInFirstConstraint::check(Node& node, std::vector<std::shared_ptr<Node>>& allNodes) {
	for (int i = 0; i < 5; i++) {
		if ((*allNodes[i])[0] == "Norwegian" && i != 0) return false;
		if (i == 0 && !(*allNodes[i])[0].empty() && (*allNodes[i])[0] != "Norwegian") return false;
	}
	return true;
}
