#include "ColorMapOperator.h"

void ColorMapOperator::changeDomain(std::vector<std::shared_ptr<Node>> &nodes, int nodeIndex, int variableIndex) {
	for (auto neighbor : nodes[nodeIndex]->getNeighbors()) {
		neighbor->getDomains()[variableIndex].erase(
			std::remove(neighbor->getDomains()[variableIndex].begin(), neighbor->getDomains()[variableIndex].end(),
				(*nodes[nodeIndex])[variableIndex]), neighbor->getDomains()[variableIndex].end());
	}
}
