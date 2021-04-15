#include "EnglishInRedConstraint.h"

bool EnglishInRedConstraint::check(Node& node, std::vector<std::shared_ptr<Node>>& allNodes) {
	if (node[0] == "English" && !node[1].empty() && node[1] != "red") return false;
	if (node[1] == "red" && !node[0].empty() && node[0] != "English") return false;
	return true;
}
