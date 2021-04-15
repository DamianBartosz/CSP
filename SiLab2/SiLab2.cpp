#include <iostream>
#include "Node.h"
#include <ctime>
#include "ColorMapGenerator.h"
#include "GraphicalColorMapGenerator.h"
#include "Constraint.h"
#include "ColorMapConstraint.h"
#include "CSP.h"
#include "AllDifferentConstraint.h"
#include "NorwegianInFirstConstraint.h"
#include "EnglishInRedConstraint.h"
#include "GreenOnWhitesLeftConstraint.h"
#include "DaneDrinksTeaConstraint.h"
#include "LightNextToCatsConstraint.h"
#include "CigarInYellowConstraint.h"
#include "GermanWithPipeConstraint.h"
#include "MilkInMiddleConstraint.h"
#include "LightNextToWaterConstraint.h"
#include "UnfilteredHasBirdsConstraint.h"
#include "SwedeHasDogsConstraint.h"
#include "NorwegianNextToBlueConstraint.h"
#include "HorsesNextToYellowConstraint.h"
#include "MentholAndBeerConstraint.h"
#include "CoffeeInGreenConstraint.h"
#include "ColorMapOperator.h"
#include "EinstainPuzzleOperator.h"
#include "MostConstrainedVariableSelect.h"
#include "MostConstrainingVariableSelect.h"
#include <chrono>


void colorMapProblem() {
	const int sizeX = 20;
	const int sizeY = 20;
	const int n = 14;
	std::vector<std::string> colors = {"blue", "green", "red", "white"};
	// std::vector<std::string> colors = {"blue", "green", "red"};
	std::vector<std::vector<std::string>> domains = {colors};

	ColorMapGenerator cmg(sizeX, sizeY, n, domains);
	auto colorMapNodes = cmg.getNodes();

	GraphicalColorMapGenerator gcmg(sizeX, sizeY, colorMapNodes);
	gcmg.display();

	std::vector<std::shared_ptr<Node>> nodes;
	for (auto colorMapNode : colorMapNodes) {
		nodes.emplace_back(colorMapNode);
	}
	std::vector<std::shared_ptr<Constraint>> constraints = {std::make_shared<ColorMapConstraint>()};

	std::unique_ptr<OperatorFC> operatorFC(new ColorMapOperator());

	// std::unique_ptr<Select> select(new Select(nodes));
	// std::unique_ptr<Select> select(new MostConstrainedVariableSelect(nodes));
	std::unique_ptr<Select> select(new MostConstrainingVariableSelect(nodes));

	CSP csp(nodes, constraints, operatorFC, select);
	auto begin = std::chrono::high_resolution_clock::now();

	// csp.backtracking();
	csp.forwardChecking();

	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	auto solutions = csp.getSolutions();

	std::cout << solutions.size() << '\n';
	std::cout << csp.getIterations() << '\n';
	std::cout << static_cast<double>(elapsed.count()) * 1e-9<< '\n';

	for (auto solution : solutions) {
		gcmg.setSolution(solution);
		gcmg.display();
	}
}

void einstainsPuzzle() {
	std::vector<std::vector<std::string>> domains = {
		{"Dane", "English", "German", "Norwegian", "Swede"},
		{"blue", "green", "red", "white", "yellow"},
		{"cigar", "light", "menthol", "pipe", "unfiltered"},
		{"beer", "coffee", "milk", "tea", "water"},
		{"birds", "cats", "dogs", "fish", "horses"}
	};
	std::vector<std::shared_ptr<Node>> nodes = {
		std::make_shared<Node>(domains),
		std::make_shared<Node>(domains),
		std::make_shared<Node>(domains),
		std::make_shared<Node>(domains),
		std::make_shared<Node>(domains)
	};
	for (int i = 0; i < nodes.size(); i++) {
		if (i == 0) {
			nodes[i]->getNeighbors().emplace_back(nullptr);
		}
		else {
			nodes[i]->getNeighbors().emplace_back(nodes[i - 1]);
		}

		if (i == nodes.size() - 1) {
			nodes[i]->getNeighbors().emplace_back(nullptr);
		}
		else {

			nodes[i]->getNeighbors().emplace_back(nodes[i + 1]);
		}
	}

	std::vector<std::shared_ptr<Constraint>> constraints = {
		std::make_shared<AllDifferentConstraint>(),
		std::make_shared<NorwegianInFirstConstraint>(),
		std::make_shared<EnglishInRedConstraint>(),
		std::make_shared<GreenOnWhitesLeftConstraint>(),
		std::make_shared<DaneDrinksTeaConstraint>(),
		std::make_shared<LightNextToCatsConstraint>(),
		std::make_shared<CigarInYellowConstraint>(),
		std::make_shared<GermanWithPipeConstraint>(),
		std::make_shared<MilkInMiddleConstraint>(),
		std::make_shared<LightNextToWaterConstraint>(),
		std::make_shared<UnfilteredHasBirdsConstraint>(),
		std::make_shared<SwedeHasDogsConstraint>(),
		std::make_shared<NorwegianNextToBlueConstraint>(),
		std::make_shared<HorsesNextToYellowConstraint>(),
		std::make_shared<MentholAndBeerConstraint>(),
		std::make_shared<CoffeeInGreenConstraint>()
	};

	std::unique_ptr<OperatorFC> operatorFC(new EinstainPuzzleOperator());

	std::unique_ptr<Select> select(new Select(nodes));

	CSP csp(nodes, constraints, operatorFC, select);
	auto begin = std::chrono::high_resolution_clock::now();

	// csp.backtracking();
	csp.forwardChecking();

	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	
	auto solutions = csp.getSolutions();

	std::cout << solutions.size() << '\n';
	std::cout << csp.getIterations() << '\n';
	std::cout << static_cast<double>(elapsed.count()) * 1e-9 << '\n';

	for (auto solution : solutions) {
		for (auto node : solution) {
			std::cout << *node;
		}
		std::cout << "\n\n\n";
	}
}

int main() {
	// srand(time(NULL));

	// einstainsPuzzle();
	colorMapProblem();
}
