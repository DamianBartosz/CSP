#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "ColorMapNode.h"

class GraphicalColorMapGenerator {
	int sizeX;
	int sizeY;
	std::vector<std::shared_ptr<ColorMapNode>> nodes;
	std::vector<std::shared_ptr<Node>> solution;
	sf::RenderWindow window;
	static const int distance = 40;
public:
	GraphicalColorMapGenerator(int sizeX, int sizeY, std::vector<std::shared_ptr<ColorMapNode>>& nodes);

	void display();

	void setSolution(const std::vector<std::shared_ptr<Node>>& solution);

private:
	void displayBackground();

	void displayPoints();

	void setPointColorAndPosition(sf::CircleShape& gPoint, int index);

	void refreshWindow();

	void displayEdges();


};
