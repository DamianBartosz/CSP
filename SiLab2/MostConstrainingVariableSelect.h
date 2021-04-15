#pragma once
#include "Select.h"

class MostConstrainingVariableSelect :
	public Select {
	bool sorted = false;
public:
	explicit MostConstrainingVariableSelect(const std::vector<std::shared_ptr<Node>>& shared_ptrs)
		: Select(shared_ptrs) {}

	std::shared_ptr<Node> selectNode() override;

	static bool comparator(std::shared_ptr<Node> a, std::shared_ptr<Node> b);
};
