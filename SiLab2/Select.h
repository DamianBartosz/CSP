#pragma once
#include "Node.h"

class Select
{
protected:
	std::vector<std::shared_ptr<Node>> nodes;
public:

	explicit Select(const std::vector<std::shared_ptr<Node>>& shared_ptrs)
		: nodes(shared_ptrs) {}

	virtual std::shared_ptr<Node> selectNode();
	virtual int selectVariable(std::shared_ptr<Node> node);
};

