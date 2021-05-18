#pragma once
#include "Algorithm.h"

class GraphFindingWay : public Algorithm {
public:
	GraphFindingWay();

	std::vector<unsigned int> Perform(std::vector<unsigned int> data) override;

	AlgoType Type() override;
	AlgoState State() override;

	void ClearMemory() override;

private:
	enum class RobotAction {
		MOVE,
		SUCESS,
		FAILURE
	};

	std::array<int,8> Scanning(std::vector<unsigned int>, int);
	
	std::vector<unsigned int> MakeMove(std::vector<unsigned int>, std::array<int,8>, int);

	std::map<Direction, std::function<int(int, int)>> robotMoves;
	AlgoType type = AlgoType::FindingWay;
	std::array<Direction, 8>directions;
	bool founded = false;
	Direction foundedDirection=Direction::NONE;

	Direction currentDirection = Direction::NONE;
	AlgoState state = AlgoState::NONE;
	std::vector<unsigned int> graph;
};