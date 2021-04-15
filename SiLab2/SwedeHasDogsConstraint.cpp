#include "SwedeHasDogsConstraint.h"
bool SwedeHasDogsConstraint::check(Node& node, std::vector<std::shared_ptr<Node>>& allNodes) {
	if(node[0]== "Swede") {
		if (!node[4].empty() && node[4] != "dogs") return false;
	}else if(node[4]=="dogs") {
		if (!node[0].empty() && node[0] != "Swede") return false;
	}
	return true;
}
