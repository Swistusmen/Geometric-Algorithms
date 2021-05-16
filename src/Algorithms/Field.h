#pragma once

enum class FieldRepresentation {
	SDF, //Signed distance field- double values
	DAO, //DAO- 0-dead or 1-alive f.e game of life
	HOG, //HOG stands for Hero Obstacle Goal- f.e ant- 0-hero, 1-obstacle, 2-goal
	//- food/ lines without matter like in BB
	NONE
};

