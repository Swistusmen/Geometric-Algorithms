#pragma once
#include "Algorithm.h"

class FindingVerticies : public Algorithm {
public:
	FindingVerticies();

	std::vector<unsigned int> Perform(std::vector<unsigned int> data) override;

	AlgoType Type() override;
	AlgoState State() override;

	void ClearMemory() override;
private:
	std::pair<std::vector<unsigned int>, int>  GoInDirectioUntilFinished(Direction direction, int robot, int dimension, std::vector<unsigned int> data);
	Direction FindDirection(int robot, int dimension, std::vector<unsigned int> data);

	std::map<Direction, std::function<int(int,int)>> moves;
	std::array<Direction, 8> directions;

	AlgoType type = AlgoType::FindingVerticies;
	AlgoState state = AlgoState::NONE;
};