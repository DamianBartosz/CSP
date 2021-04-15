#pragma once
#include "Node.h"

class Constraint {
public:
	virtual bool check(Node& node, std::vector<std::shared_ptr<Node>>& allNodes) = 0;
};
