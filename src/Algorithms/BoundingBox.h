#pragma once
#include "Algorithm.h"

class BoundingBox: public Algorithm{
public:
	BoundingBox()=default;

	std::vector<unsigned int> Perform(std::vector<unsigned int> data) override;

	AlgoType Type() override;
	AlgoState State() override;

	void ClearMemory() override;
private:
	std::array<int, 4> FindEdgeIndexes(std::vector<int> data, int dim, int size);
	std::array<int, 4> CalculateEdgeRows(std::array<int, 4> data, int dim);

	AlgoType type = AlgoType::BoundingBox;
	AlgoState state = AlgoState::NONE;
};
