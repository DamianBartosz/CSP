#include "MilkInMiddleConstraint.h"
bool MilkInMiddleConstraint::check(Node& node, std::vector<std::shared_ptr<Node>>& allNodes) {
	for (int i = 0; i < 5; i++) {
		if ((*allNodes[i])[3] == "milk" && i != 2) return false;
		if (i == 2 && !(*allNodes[i])[3].empty() && (*allNodes[i])[3] != "milk") return false;
	}
	return true;
}
