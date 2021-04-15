#include "CigarInYellowConstraint.h"

bool CigarInYellowConstraint::check(Node& node, std::vector<std::shared_ptr<Node>>& allNodes) {
	if (node[1] == "yellow") {
		if (!node[2].empty() && node[2] != "cigar") return false;
	}
	else if (node[2] == "cigar") {
		if (!node[1].empty() && node[1] != "cigar") return false;
	}
	return true;
}
