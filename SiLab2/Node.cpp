#include "Node.h"

Node::Node(std::vector<std::vector<std::string>> domains) : domains(domains) {
	for (int i = 0; i < domains.size(); i++) {
		variables.emplace_back("");
	}
}


Node::Node(const Node& other) {
	for (auto var : other.variables) {
		variables.emplace_back(var);
	}
	domains = other.domains;
}

std::vector<std::shared_ptr<Node>>& Node::getNeighbors() {
	return neighbors;
}

std::string& Node::operator[](int index) {
	return variables[index];
}

std::ostream& operator<<(std::ostream& os, const Node& obj) {
	std::string toString;
	for (auto var : obj.variables) {
		toString += var + " | ";
	}
	toString += '\n';

	return os << toString;
}


std::vector<std::vector<std::string>>& Node::getDomains() {
	return domains;
}

void Node::setDomains(const std::vector<std::vector<std::string>>& domains) {
	this->domains = domains;
}
