#include "HorsesNextToYellowConstraint.h"
bool HorsesNextToYellowConstraint::check(Node& node, std::vector<std::shared_ptr<Node>>& allNodes) {
	int horsesIndex = -1, yellowIndex = -1;
	for (int i = 0; i < 5; i++) {
		if ((*allNodes[i])[4] == "horses") horsesIndex = i;
		if ((*allNodes[i])[1] == "yellow") yellowIndex = i;
	}

	return !(horsesIndex != -1 && yellowIndex != -1 && std::abs(horsesIndex - yellowIndex) != 1);
}
