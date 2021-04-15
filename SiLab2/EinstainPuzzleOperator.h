#pragma once
#include "OperatorFC.h"

class EinstainPuzzleOperator :
	public OperatorFC {
public:
	void changeDomain(std::vector<std::shared_ptr<Node>> &nodes, int nodeIndex, int variableIndex) override;

};
