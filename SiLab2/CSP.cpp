#include "CSP.h"


void CSP::backtracking() {
	auto node = select->selectNode();
	if (!node) {
		std::vector<std::shared_ptr<Node>> solution;
		for (auto node : nodes) {
			solution.emplace_back(std::make_shared<Node>(*node));
		}
		solutions.emplace_back(solution);
		return;
	}
	int varIndex = select->selectVariable(node);

	for (auto value : node->getDomains()[varIndex]) {
		(*node)[varIndex] = value;
		iterations++;
		bool constraintsPassed = true;
		for (int i = 0; i < constraints.size(); i++) {
			if (!constraints[i]->check(*node, nodes)) {
				constraintsPassed = false;
				i = constraints.size();
			}
		}
		if (constraintsPassed) backtracking();
	}
	(*node)[varIndex] = "";
}

void CSP::forwardChecking() {
	auto node = select->selectNode();
	if (!node) {
		std::vector<std::shared_ptr<Node>> solution;
		for (auto node : nodes) {
			solution.emplace_back(std::make_shared<Node>(*node));
		}
		solutions.emplace_back(solution);
		return;
	}
	int nodeIndex = std::distance(nodes.begin(), std::find(nodes.begin(), nodes.end(), node));
	int varIndex = select->selectVariable(node);


	std::vector<std::vector<std::vector<std::string>>> domainsCopy;
	for (auto node : nodes) {
		domainsCopy.emplace_back(node->getDomains());
	}

	for (auto value : node->getDomains()[varIndex]) {
		(*node)[varIndex] = value;
		iterations++;
		operatorFC->changeDomain(nodes, nodeIndex, varIndex);
		bool constraintsPassed = true;
		for (int i = 0; i < constraints.size(); i++) {
			if (!constraints[i]->check(*node, nodes)) {
				constraintsPassed = false;
				i = constraints.size();
			}
		}
		if (constraintsPassed) forwardChecking();
		for (int i = 0; i < domainsCopy.size(); i++) {
			nodes[i]->setDomains(domainsCopy[i]);
		}
	}

	(*node)[varIndex] = "";
}

std::vector<std::vector<std::shared_ptr<Node>>>& CSP::getSolutions() {
	return solutions;
}

int CSP::getIterations() const {
	return iterations;
}
