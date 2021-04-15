#include "DaneDrinksTeaConstraint.h"

bool DaneDrinksTeaConstraint::check(Node& node, std::vector<std::shared_ptr<Node>>& allNodes) {
	if (node[0] == "Dane" && !node[3].empty() && node[3] != "tea") return false;
	if (node[3] == "tea" && !node[0].empty() && node[0] != "Dane") return false;
	return true;
}
