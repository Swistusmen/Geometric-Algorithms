#pragma once
#include "Algorithm.h"

class FindingWay : public Algorithm {
public:
	FindingWay();

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
	std::pair<RobotAction, int> ScanForAWay(std::vector<unsigned int> board, int dimension, int robot);
	std::vector<unsigned int>  MakeAMove(int robot, int distance, int dimension, std::vector<unsigned int> board);

	AlgoType type = AlgoType::FindingWay;
	std::map<Direction, std::function<int( int, int)>> robotMoves;
	std::array<Direction, 8>directions;

	Direction currentDirection = Direction::NONE;
	AlgoState state = AlgoState::NONE;
};