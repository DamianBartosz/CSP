#pragma once
#include "Constraint.h"
class MilkInMiddleConstraint :
    public Constraint
{

public:
	bool check(Node& node, std::vector<std::shared_ptr<Node>>& allNodes) override;
};
