#pragma once
#include "Constraint.h"
class DaneDrinksTeaConstraint :
    public Constraint
{

public:
	bool check(Node& node, std::vector<std::shared_ptr<Node>>& allNodes) override;
};

