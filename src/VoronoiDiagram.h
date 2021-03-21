#pragma once
#include "Algorithm.h"

class VoronoiDiagram: public Algorithm {
public:
	VoronoiDiagram() = default;

	std::vector<unsigned int> Perform(std::vector<unsigned int> data) override;

	AlgoType Type() override;
	AlgoState State() override;

	void ClearMemory() override;
private:
	std::vector<unsigned int> DrawDiagram(std::vector<unsigned int> data, std::vector<std::pair<int, int>> indexes);

	double CalculateDistance(std::pair<int, int> p1, std::pair<int, int> p2);
	std::pair<int, int> TransformIndexToCartesian(int index, int dimension);

	AlgoType type = AlgoType::VoronoiDiagram;
	AlgoState state = AlgoState::NONE;
};