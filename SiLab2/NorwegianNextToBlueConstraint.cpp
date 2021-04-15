#include "NorwegianNextToBlueConstraint.h"

bool NorwegianNextToBlueConstraint::check(Node& node, std::vector<std::shared_ptr<Node>>& allNodes) {
	int norwegianIndex = -1, blueIndex = -1;
	for (int i = 0; i < 5; i++) {
		if ((*allNodes[i])[0] == "Norwegian") norwegianIndex = i;
		if ((*allNodes[i])[1] == "blue") blueIndex = i;
	}

	return !(norwegianIndex != -1 && blueIndex != -1 && std::abs(norwegianIndex - blueIndex) != 1);
}
