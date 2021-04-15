#pragma once
#include "Select.h"

class MostConstrainedVariableSelect :
	public Select {
public:
	explicit MostConstrainedVariableSelect(const std::vector<std::shared_ptr<Node>>& shared_ptrs)
		: Select(shared_ptrs) {}

	std::shared_ptr<Node> selectNode() override;
	
	static bool comparator(std::shared_ptr<Node> a, std::shared_ptr<Node> b);
};
