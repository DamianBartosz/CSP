#include "MostConstrainedVariableSelect.h"
#include <algorithm>

std::shared_ptr<Node> MostConstrainedVariableSelect::selectNode() {
	std::sort(nodes.begin(), nodes.end(), comparator);
	for (auto node : nodes) {
		for (int i = 0; i < node->getDomains().size(); i++) {
			if ((*node)[i].empty()) return node;
		}
	}
	return nullptr;
}


bool MostConstrainedVariableSelect::comparator(std::shared_ptr<Node> a, std::shared_ptr<Node> b) {
	return a->getDomains()[0].size() < b->getDomains()[0].size();
}
