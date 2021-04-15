#pragma once
#include "Node.h"

class OperatorFC {
public:
	virtual void changeDomain(std::vector<std::shared_ptr<Node>> &nodes, int nodeIndex, int variableIndex) =0;
};
