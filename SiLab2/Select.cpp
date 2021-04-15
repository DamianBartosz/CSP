#include "Select.h"

std::shared_ptr<Node> Select::selectNode() {
	for(auto node : nodes) {
		for(int i=0; i<node->getDomains().size(); i++) {
			if ((*node)[i].empty()) return node;
		}
	}
	return nullptr;
}
int Select::selectVariable(std::shared_ptr<Node> node) {
	for (int i = 0; i < node->getDomains().size(); i++) {
		if ((*node)[i].empty()) return i;
	}
	return node->getDomains().size();
}
