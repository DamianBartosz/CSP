#include "EinstainPuzzleOperator.h"

void EinstainPuzzleOperator::changeDomain(std::vector<std::shared_ptr<Node>>& nodes, int nodeIndex, int variableIndex) {
	for (auto node : nodes) {
		node->getDomains()[variableIndex].erase(
			std::remove(node->getDomains()[variableIndex].begin(), node->getDomains()[variableIndex].end(),
			            (*nodes[nodeIndex])[variableIndex]), node->getDomains()[variableIndex].end());
	}

	if ((*nodes[nodeIndex])[variableIndex] == "English") {
		for (auto node : nodes) {
			node->getDomains()[1].erase(
				std::remove(node->getDomains()[1].begin(), node->getDomains()[1].end(),
				            "red"), node->getDomains()[1].end());
		}
		nodes[nodeIndex]->getDomains()[1] = {"red"};
	}
	else if ((*nodes[nodeIndex])[variableIndex] == "Dane") {
		for (auto node : nodes) {
			node->getDomains()[3].erase(
				std::remove(node->getDomains()[3].begin(), node->getDomains()[3].end(),
				            "tea"), node->getDomains()[3].end());
		}
		nodes[nodeIndex]->getDomains()[3] = {"tea"};
	}
	else if ((*nodes[nodeIndex])[variableIndex] == "German") {
		for (auto node : nodes) {
			node->getDomains()[2].erase(
				std::remove(node->getDomains()[2].begin(), node->getDomains()[2].end(),
				            "pipe"), node->getDomains()[2].end());
		}
		nodes[nodeIndex]->getDomains()[2] = {"pipe"};
	}
	else if ((*nodes[nodeIndex])[variableIndex] == "Swede") {
		for (auto node : nodes) {
			node->getDomains()[4].erase(
				std::remove(node->getDomains()[4].begin(), node->getDomains()[4].end(),
				            "dogs"), node->getDomains()[4].end());
		}
		nodes[nodeIndex]->getDomains()[4] = {"dogs"};
	}
	else if ((*nodes[nodeIndex])[variableIndex] == "green") {
		for (auto node : nodes) {
			node->getDomains()[1].erase(
				std::remove(node->getDomains()[1].begin(), node->getDomains()[1].end(),
				            "white"), node->getDomains()[1].end());
		}
		if (nodeIndex + 1 < nodes.size())
			nodes[nodeIndex + 1]->getDomains()[1] = {"white"};

		for (auto node : nodes) {
			node->getDomains()[3].erase(
				std::remove(node->getDomains()[3].begin(), node->getDomains()[3].end(),
				            "coffee"), node->getDomains()[3].end());
		}
		nodes[nodeIndex]->getDomains()[3] = {"coffee"};
	}
	else if ((*nodes[nodeIndex])[variableIndex] == "red") {
		for (auto node : nodes) {
			node->getDomains()[0].erase(
				std::remove(node->getDomains()[0].begin(), node->getDomains()[0].end(),
				            "English"), node->getDomains()[0].end());
		}
		nodes[nodeIndex]->getDomains()[0] = {"English"};
	}
	else if ((*nodes[nodeIndex])[variableIndex] == "white") {
		for (auto node : nodes) {
			node->getDomains()[1].erase(
				std::remove(node->getDomains()[1].begin(), node->getDomains()[1].end(),
				            "green"), node->getDomains()[1].end());
		}
		if (nodeIndex - 1 > 0)
			nodes[nodeIndex - 1]->getDomains()[1] = {"green"};
	}
	else if ((*nodes[nodeIndex])[variableIndex] == "yellow") {
		for (auto node : nodes) {
			node->getDomains()[2].erase(
				std::remove(node->getDomains()[2].begin(), node->getDomains()[2].end(),
				            "cigar"), node->getDomains()[2].end());
		}
		nodes[nodeIndex]->getDomains()[2] = {"cigar"};
	}

	else if ((*nodes[nodeIndex])[variableIndex] == "cigar") {
		for (auto node : nodes) {
			node->getDomains()[1].erase(
				std::remove(node->getDomains()[1].begin(), node->getDomains()[1].end(),
				            "yellow"), node->getDomains()[1].end());
		}
		nodes[nodeIndex]->getDomains()[1] = {"yellow"};
	}
	else if ((*nodes[nodeIndex])[variableIndex] == "menthol") {
		for (auto node : nodes) {
			node->getDomains()[3].erase(
				std::remove(node->getDomains()[3].begin(), node->getDomains()[3].end(),
				            "beer"), node->getDomains()[3].end());
		}
		nodes[nodeIndex]->getDomains()[3] = {"beer"};
	}
	else if ((*nodes[nodeIndex])[variableIndex] == "pipe") {
		for (auto node : nodes) {
			node->getDomains()[0].erase(
				std::remove(node->getDomains()[0].begin(), node->getDomains()[0].end(),
				            "German"), node->getDomains()[0].end());
		}
		nodes[nodeIndex]->getDomains()[0] = {"German"};
	}
	else if ((*nodes[nodeIndex])[variableIndex] == "unfiltered") {
		for (auto node : nodes) {
			node->getDomains()[4].erase(
				std::remove(node->getDomains()[4].begin(), node->getDomains()[4].end(),
				            "birds"), node->getDomains()[4].end());
		}
		nodes[nodeIndex]->getDomains()[4] = {"birds"};
	}

	else if ((*nodes[nodeIndex])[variableIndex] == "beer") {
		for (auto node : nodes) {
			node->getDomains()[2].erase(
				std::remove(node->getDomains()[2].begin(), node->getDomains()[2].end(),
				            "menthol"), node->getDomains()[2].end());
		}
		nodes[nodeIndex]->getDomains()[2] = {"menthol"};
	}
	else if ((*nodes[nodeIndex])[variableIndex] == "coffee") {
		for (auto node : nodes) {
			node->getDomains()[1].erase(
				std::remove(node->getDomains()[1].begin(), node->getDomains()[1].end(),
				            "green"), node->getDomains()[1].end());
		}
		nodes[nodeIndex]->getDomains()[1] = {"green"};
	}
	else if ((*nodes[nodeIndex])[variableIndex] == "tea") {
		for (auto node : nodes) {
			node->getDomains()[0].erase(
				std::remove(node->getDomains()[0].begin(), node->getDomains()[0].end(),
				            "Dane"), node->getDomains()[0].end());
		}
		nodes[nodeIndex]->getDomains()[0] = {"Dane"};
	}
	else if ((*nodes[nodeIndex])[variableIndex] == "water") {}

	else if ((*nodes[nodeIndex])[variableIndex] == "birds") {
		for (auto node : nodes) {
			node->getDomains()[2].erase(
				std::remove(node->getDomains()[2].begin(), node->getDomains()[2].end(),
				            "unfiltered"), node->getDomains()[2].end());
		}
		nodes[nodeIndex]->getDomains()[2] = {"unfiltered"};
	}
	else if ((*nodes[nodeIndex])[variableIndex] == "dogs") {
		for (auto node : nodes) {
			node->getDomains()[0].erase(
				std::remove(node->getDomains()[0].begin(), node->getDomains()[0].end(),
				            "Swede"), node->getDomains()[0].end());
		}
		nodes[nodeIndex]->getDomains()[0] = {"Swede"};
	}
}
