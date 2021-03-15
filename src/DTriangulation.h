#pragma once
#include "Algorithm.h"
#include <numeric>


class DTriangulation : public Algorithm {
public:
	DTriangulation();

	std::vector<unsigned int> Perform(std::vector<unsigned int> data) override;
	std::vector<double> Perform(std::vector<double> data) override final;

	AlgoType Type() override;
	AlgoState State() override;

	void ClearMemory() override;
private:
	std::pair<int, int> TransformIndexToCartesian(int robot, int dimension);
	std::vector<unsigned int> ConnectTwoPointsWithBresenham(std::vector<unsigned int> data, int robot1, int robot2);


	std::map<Direction, std::function<int(int, int)>> moves;
	std::array<Direction, 8> directions;
	int verticalDistance = 1;
	int horizontalDistance = 1;
	AlgoType type = AlgoType::VoronoiDiagram;
	AlgoState state = AlgoState::NONE;
};