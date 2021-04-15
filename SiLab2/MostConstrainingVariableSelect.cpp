#include "MostConstrainingVariableSelect.h"
#include <algorithm>

std::shared_ptr<Node> MostConstrainingVariableSelect::selectNode() {
	if(!sorted) {
		std::sort(nodes.begin(), nodes.end(), comparator);
	}
	for (auto node : nodes) {
		for (int i = 0; i < node->getDomains().size(); i++) {
			if ((*node)[i].empty()) return node;
		}
	}
	return nullptr;
}

bool MostConstrainingVariableSelect::comparator(std::shared_ptr<Node> a, std::shared_ptr<Node> b) {
	return a->getNeighbors().size() > b->getNeighbors().size();
}
