#include "CoffeeInGreenConstraint.h"
bool CoffeeInGreenConstraint::check(Node& node, std::vector<std::shared_ptr<Node>>& allNodes) {
	if(node[1]== "green") {
		if (!node[3].empty() && node[3] != "coffee") return false;
	}else if(node[3]== "coffee") {
		if (!node[1].empty() && node[1] != "green") return false;
	}
	return true;
}
