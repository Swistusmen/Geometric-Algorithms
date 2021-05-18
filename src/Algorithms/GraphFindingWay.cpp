#include "GraphFindingWay.h"

GraphFindingWay::GraphFindingWay() {
	robotMoves.insert({ Direction::TOP,[](int robot,int dimension) { return robot -= dimension; } });
	robotMoves.insert({ Direction::TOP_RIGHT,[](int robot,int dimension) { return robot -= (dimension + 1); } });
	robotMoves.insert({ Direction::RIGHT,[](int robot,int dimension) { return robot += 1; } });
	robotMoves.insert({ Direction::BOTTOM_RIGHT,[](int robot,int dimension) { return robot += (dimension + 1); } });
	robotMoves.insert({ Direction::BOTTOM,[](int robot,int dimension) { return robot += dimension; } });
	robotMoves.insert({ Direction::BOTTOM_LEFT,[](int robot,int dimension) { return robot += (dimension - 1); } });
	robotMoves.insert({ Direction::LEFT,[](int robot,int dimension) { return robot -= 1; } });
	robotMoves.insert({ Direction::TOP_LEFT,[](int robot,int dimension) { return robot -= (dimension - 1); } });

	directions = std::array<Direction, 8>{
			Direction::TOP,
			Direction::TOP_RIGHT,
			Direction::RIGHT,
			Direction::BOTTOM_RIGHT,
			Direction::BOTTOM,
			Direction::BOTTOM_LEFT,
			Direction::LEFT,
			Direction::TOP_LEFT };
}

std::vector<unsigned int> GraphFindingWay::Perform(std::vector<unsigned int> data)
{
	if ( (std::sqrt(data.size()) < 4) || (state == AlgoState::FINISHED_SUCCESS))
		return data;
	int robot = std::find(std::begin(data), std::end(data), 3) - std::begin(data);
	if (graph.size() == 0)
		graph = data;
	auto possibilites=Scanning(data, robot);
	return MakeMove(data, possibilites, robot);
}

std::array<int,8> GraphFindingWay::Scanning(std::vector<unsigned int>data, int robot)
{
	const int size = data.size();
	int dim = static_cast<int>(std::sqrt(size));
	std::array<int,8> distances{ 0 };
	for (int i = 0; i < 8; i++)
	{
		auto fun = robotMoves.find(directions.at(i))->second; //overeengieered
		int tempRobot = robot;
		int prevRobot;
		while (true)
		{
			int newRobot = fun(tempRobot, dim);
			if ( newRobot>size-1||newRobot<0)
				break;
			if ((data[newRobot] == 1) ||(tempRobot % dim == 0 && newRobot % dim == dim - 1) || (tempRobot % dim == dim - 1 && newRobot % dim == 0))
				break;
			if (data[newRobot] == 2)
			{
				founded = true;
				foundedDirection = directions[i];
			}
			if(graph[newRobot]!=6)
				graph[newRobot] = 4;
			tempRobot = newRobot;
			distances[i]++;
		}
	}
	return distances;
}

std::vector<unsigned int> GraphFindingWay::MakeMove(std::vector<unsigned int> data, std::array<int,8> distances, int robot)
{
	const int size = data.size();
	int dim = static_cast<int>(std::sqrt(size));
	if (founded == true)
	{
		auto fun= robotMoves.find(foundedDirection)->second;
		int tempRobot = fun(robot, dim);
		while (data[tempRobot] != 2)
		{
			data[tempRobot] = 3;
			tempRobot = fun(tempRobot, dim);
		}
		this->state = AlgoState::FINISHED_SUCCESS;
		return data;
	}
	
	std::srand(time(NULL));
	while (true)
	{
		int direction = rand() % 8;
		if (distances[direction] == 0)
			continue;
		int dist;
		if (distances[direction] == 1)
			dist = 1;
		else
			dist = rand() % (distances[direction] - 1) + 1;
		int newRobot = robot;
		auto fun = robotMoves.find(directions.at(direction))->second;
		for (int i = 0; i < dist; i++)
		{
			newRobot = fun(newRobot, dim);
		}
		if (graph[newRobot] != 6)
		{
			int newRobot = robot;
			for (int i = 0; i < dist; i++)
			{
				if(data[newRobot]!=6)
					data[newRobot] = 4; //road
				newRobot = fun(newRobot, dim);
			}
			graph[newRobot] = 6; //visited ending points
			data[newRobot] = 3; //ending point
			break;
		}

	}
	this->state = AlgoState::PERFORMING;
	return data;
}

AlgoType GraphFindingWay::Type()
{
	return this->type;
}

AlgoState GraphFindingWay::State()
{
	return this->state;
}

void GraphFindingWay::ClearMemory()
{
	graph.clear();
	this->state = AlgoState::NONE;
}