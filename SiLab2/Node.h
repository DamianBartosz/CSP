#pragma once
#include <vector>
#include <string>
#include <memory>
#include <ostream>

class Node {
	std::vector<std::string> variables;
	std::vector<std::vector<std::string>> domains;
	std::vector<std::shared_ptr<Node>> neighbors;
public:

	Node(std::vector<std::vector<std::string>> domains);

	Node(const Node& other);

	std::vector<std::shared_ptr<Node>>& getNeighbors();

	std::string& operator[](int index);


	friend std::ostream& operator<<(std::ostream& os, const Node& obj);


	std::vector<std::vector<std::string>>& getDomains();

	void setDomains(const std::vector<std::vector<std::string>>& domains);
};
