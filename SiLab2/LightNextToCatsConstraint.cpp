#include "LightNextToCatsConstraint.h"

bool LightNextToCatsConstraint::check(Node& node, std::vector<std::shared_ptr<Node>>& allNodes) {
	int lightIndex = -1, catsIndex = -1;
	for (int i = 0; i < 5; i++) {
		if ((*allNodes[i])[2] == "light") lightIndex = i;
		if ((*allNodes[i])[4] == "cats") catsIndex = i;
	}

	return !(lightIndex != -1 && catsIndex != -1 && std::abs(lightIndex - catsIndex) != 1);
}
