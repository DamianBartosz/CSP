#pragma once
#include "Constraint.h"

class LightNextToWaterConstraint :
	public Constraint {
public:
	bool check(Node& node, std::vector<std::shared_ptr<Node>>& allNodes) override;
};
