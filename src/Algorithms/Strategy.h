#pragma once
#include "BoundingBox.h"
#include "FindingWay.h"
#include "FindingVerticies.h"
#include "VoronoiDiagram.h"
#include "DTriangulation.h"
#include "GraphFindingWay.h"

class GeometricalAlgorithms {
public:
	virtual std::shared_ptr<Algorithm> GetAlgorithm(AlgoType type) = 0;
};

class AlgorithmsKeeper :GeometricalAlgorithms{
public:
	AlgorithmsKeeper();
	std::shared_ptr<Algorithm> GetAlgorithm(AlgoType type) override;
private:
	std::map<AlgoType, std::shared_ptr<Algorithm>> algorithms;
};
