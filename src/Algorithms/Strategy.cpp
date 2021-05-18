#include "Strategy.h"

AlgorithmsKeeper::AlgorithmsKeeper()
{
	algorithms.insert({ AlgoType::BoundingBox, std::make_shared<BoundingBox>() });
	algorithms.insert({ AlgoType::FindingWay, std::make_shared<FindingWay>() });
	algorithms.insert({ AlgoType::FindingVerticies, std::make_shared<FindingVerticies>() });
	algorithms.insert({ AlgoType::VoronoiDiagram, std::make_shared<VoronoiDiagram>() });
	algorithms.insert({ AlgoType::DelaunayTriangulation, std::make_shared<DTriangulation>() });
	algorithms.insert({ AlgoType::GraphFindingWay, std::make_shared<GraphFindingWay>() });
}

std::shared_ptr<Algorithm> AlgorithmsKeeper::GetAlgorithm(AlgoType type)
{
	auto founded = algorithms.find(type);
	return founded->second;
}