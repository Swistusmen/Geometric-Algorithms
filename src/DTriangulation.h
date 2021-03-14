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
	std::vector<unsigned int> MarkWay(int robot, std::vector<unsigned int> data);
	double CalculateDistance(std::pair<int, int> p1, std::pair<int, int> p2);
	std::pair<int, int> TransformIndexToCartesian(int robot, int dimension);
	std::vector<unsigned int> ConnectTwoPoints(std::vector<unsigned int> data, int robot1, int robot2);
	std::vector<unsigned int> ConnectTwoPointsWithBresenham(std::vector<unsigned int> data, int robot1, int robot2);
	int ScanForTheNearestPoint(int , std::pair<int, int>, int, std::vector<unsigned int>);


	std::map<Direction, std::function<int(int, int)>> moves;
	std::array<Direction, 8> directions;
	int verticalDistance = 1;
	int horizontalDistance = 1;
	AlgoType type = AlgoType::VoronoiDiagram;
	AlgoState state = AlgoState::NONE;
};