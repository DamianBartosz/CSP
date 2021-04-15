#include "AllDifferentConstraint.h"


bool AllDifferentConstraint::check(Node& node, std::vector<std::shared_ptr<Node>>& allNodes) {
	for (int i = 0; i < 5; i++) {
		if (!node[i].empty()) {
			int counter = 0;
			for (auto n : allNodes) {
				if ((*n)[i] == node[i]) {
					counter++;
				}
			}
			if (counter > 1) return false;
		}
	}
	return true;
}
