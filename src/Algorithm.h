#pragma once
#include "Field.h"
#include <vector>
#include <algorithm>
#include <variant>
#include <functional>
#include <utility>
#include <memory>
#include <map>
#include <iostream>
#include <array>

enum class AlgoType {
	None,
	BoundingBox, //0 empty, 1 geometry
	FindingWay, //0 empty, 1 geoemtry, 2 goal, 3 hero, 4 path
	FindingVerticies, //0 empty, 1 geometry, 2 founded verticies, 3- visited
	VoronoiDiagram, //0 empty, 1- geoemtry(ignored), 2 ceneters, [3-x] values of centers 
	DelaunayTriangulation //0 empty, 1 line, 2 point to connect, 
};

enum class AlgoState {
	FINISHED_SUCCESS,
	FINISHED_FAILURE,
	PERFORMING,
	NONE
};

enum class Direction {
	TOP,
	TOP_RIGHT,
	RIGHT,
	BOTTOM_RIGHT,
	BOTTOM,
	BOTTOM_LEFT,
	LEFT,
	TOP_LEFT,
	NONE
};

class Algorithm {
public:
	virtual std::vector<unsigned int> Perform(std::vector<unsigned int> data)=0;
	virtual std::vector<double> Perform(std::vector<double> data)=0;

	virtual void ClearMemory() = 0;
	virtual AlgoState State()=0;
	virtual AlgoType Type()=0;
};
