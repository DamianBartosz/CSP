#include "GermanWithPipeConstraint.h"

bool GermanWithPipeConstraint::check(Node& node, std::vector<std::shared_ptr<Node>>& allNodes) {
	if (node[0] == "German") {
		if (!node[2].empty() && node[2] != "pipe") return false;
	}
	else if (node[2] == "pipe") {
		if (!node[0].empty() && node[0] != "German") return false;
	}
	return true;
}
