#include <SFML/Window/Event.hpp>
#include "GraphicalColorMapGenerator.h"

GraphicalColorMapGenerator::GraphicalColorMapGenerator(int sizeX, int sizeY,
                                                       std::vector<std::shared_ptr<ColorMapNode>>& nodes) :
	sizeX(sizeX), sizeY(sizeY), nodes(nodes) {}

void GraphicalColorMapGenerator::display() {
	window.create(
		sf::VideoMode((sizeX + 1) * distance, (sizeY + 1) * distance, 32),
		"Color map");
	refreshWindow();
	while (window.isOpen()) {
		sf::Event event{};
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::Resized) {
				refreshWindow();
			}
		}
	}
}

void GraphicalColorMapGenerator::displayBackground() {
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; ++j) {
			sf::CircleShape point(1.f);
			point.setFillColor(sf::Color(255, 255, 255));
			point.setPosition((i + 1) * distance, (j + 1) * distance);
			window.draw(point);
		}
	}
}

void GraphicalColorMapGenerator::displayPoints() {
	for (int i = 0; i < nodes.size(); i++) {
		sf::CircleShape point(10.f);
		setPointColorAndPosition(point, i);
		window.draw(point);
	}
}

void GraphicalColorMapGenerator::setPointColorAndPosition(sf::CircleShape& gPoint, int index) {
	if (!solution.empty() && (*solution[index])[0] == "blue") gPoint.setFillColor(sf::Color(0, 0, 255));
	else if (!solution.empty() && (*solution[index])[0] == "green") gPoint.setFillColor(sf::Color(0, 255, 0));
	else if (!solution.empty() && (*solution[index])[0] == "red") gPoint.setFillColor(sf::Color(255, 0, 0));
	else gPoint.setFillColor(sf::Color(255, 255, 255));
	gPoint.setPosition(((*nodes[index]).getX() + 1) * distance - 10, ((*nodes[index]).getY() + 1) * distance - 10);
}

void GraphicalColorMapGenerator::refreshWindow() {
	window.clear();
	displayBackground();
	displayEdges();
	displayPoints();
	window.display();
}

void GraphicalColorMapGenerator::displayEdges() {
	for (auto node : nodes) {
		for (auto neighbor : node->getNeighbors()) {
			auto castedNeighbor = static_cast<ColorMapNode*>(neighbor.get());
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f((node->getX() + 1) * distance, (node->getY() + 1) * distance)),
				sf::Vertex(sf::Vector2f((castedNeighbor->getX() + 1) * distance,
				                        (castedNeighbor->getY() + 1) * distance))
			};
			window.draw(line, 2, sf::Lines);
		}
	}
}

void GraphicalColorMapGenerator::setSolution(const std::vector<std::shared_ptr<Node>>& solution) {
	this->solution = solution;
}
