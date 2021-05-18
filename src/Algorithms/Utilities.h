#pragma once
#include <iostream>

enum class AlgoType {
	None,
	BoundingBox, //0 empty, 1 geometry
	FindingWay, //0 empty, 1 geoemtry, 2 goal, 3 hero, 4 path
	FindingVerticies, //0 empty, 1 geometry, 2 founded verticies, 3- visited in last move
	VoronoiDiagram, //0 empty, 1- geoemtry(ignored), 2 ceneters, [3-x] values of centers 
	DelaunayTriangulation, //0 empty, 1 line, 2 point to connect, 
	GraphFindingWay //0 empty, 1 geometry, 2 founded verticies, 3 visited in last move, 4-already visited, 5 scanned
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

enum class InterfaceState {
	NOT_INITIALIZED,
	MAIN,
	ALGORITH_INTERFACE,
	CREATIVE_INTERFACE
};
