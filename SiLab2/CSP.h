#pragma once
#include <vector>
#include <memory>
#include "Node.h"
#include "Constraint.h"
#include "OperatorFC.h"
#include "Select.h"

class CSP {
	std::vector<std::shared_ptr<Node>> nodes;
	std::vector<std::shared_ptr<Constraint>> constraints;
	std::vector<std::vector<std::shared_ptr<Node>>> solutions;
	std::unique_ptr<OperatorFC> operatorFC;
	std::unique_ptr<Select> select;
	int iterations = 0;
public:
	CSP(const std::vector<std::shared_ptr<Node>>& nodes,
	    const std::vector<std::shared_ptr<Constraint>>& constraints,
	    std::unique_ptr<OperatorFC>& operatorFC,
		std::unique_ptr<Select> &select)
		: nodes(nodes),
		  constraints(constraints),
		  operatorFC(std::move(operatorFC)),
		  select(std::move(select)) {}

	void backtracking();

	void forwardChecking();

	std::vector<std::vector<std::shared_ptr<Node>>>& getSolutions();


	int getIterations() const;
};
