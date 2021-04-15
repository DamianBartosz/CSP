#include "LightNextToWaterConstraint.h"
bool LightNextToWaterConstraint::check(Node& node, std::vector<std::shared_ptr<Node>>& allNodes) {
	int lightIndex = -1, waterIndex = -1;
	for (int i = 0; i < 5; i++) {
		if ((*allNodes[i])[2] == "light") lightIndex = i;
		if ((*allNodes[i])[3] == "water") waterIndex = i;
	}

	return !(lightIndex != -1 && waterIndex != -1 && std::abs(lightIndex - waterIndex) != 1);
}
