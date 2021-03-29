#include "FindingVerticies.h"

FindingVerticies::FindingVerticies()
{
	moves.insert({ Direction::TOP,[](int robot,int dimension) { return robot -= dimension; } });
	moves.insert({ Direction::TOP_RIGHT,[](int robot,int dimension) { return robot -= (dimension + 1); } });
	moves.insert({ Direction::RIGHT,[](int robot,int dimension) { return robot += 1; } });
	moves.insert({ Direction::BOTTOM_RIGHT,[](int robot,int dimension) { return robot += (dimension + 1); } });
	moves.insert({ Direction::BOTTOM,[](int robot,int dimension) { return robot += dimension; } });
	moves.insert({ Direction::BOTTOM_LEFT,[](int robot,int dimension) { return robot += (dimension - 1); } });
	moves.insert({ Direction::LEFT,[](int robot,int dimension) { return robot -= 1; } });
	moves.insert({ Direction::TOP_LEFT,[](int robot,int dimension) { return robot -= (dimension - 1); } });

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

std::vector<unsigned int> FindingVerticies::Perform(std::vector<unsigned int> data)
{
	if (this->state == AlgoState::FINISHED_SUCCESS)
		return data;
	auto size = data.size();
	int dimension = std::sqrt(size);
	int robot = std::find(data.begin(), data.end(), 1) - data.begin();
	Direction direction = Direction::NONE;
	while (true)
	{
		direction = FindDirection(robot, dimension, data);
		if (direction == Direction::NONE)
			break;
		auto result=GoInDirectioUntilFinished(direction, robot, dimension, data);
		data = result.first;
		robot = result.second;
	}
	std::transform(data.begin(), data.end(), data.begin(), [](auto a) { return a == 3 ? 1 : a; });
	this->state = AlgoState::FINISHED_SUCCESS;
	return data;
}

std::pair<std::vector<unsigned int>, int>  FindingVerticies::GoInDirectioUntilFinished(Direction direction, int robot, int dimension, std::vector<unsigned int> data)
{
	auto fun = moves.find(direction)->second;
	int prevRobot = robot;
	int tempRobot= fun(robot, dimension);

	while (data[tempRobot] == 1)
	{
		if (((tempRobot % dimension == 0 && (prevRobot + 1) % dimension == 0) || (prevRobot % dimension == 0 && (tempRobot + 1) % dimension == 0)))
			break;
		data[tempRobot] = 3;
		prevRobot = tempRobot;
		tempRobot = fun(tempRobot, dimension);
		if (tempRobot<0 || tempRobot>=std::pow(dimension, 2))
			break;
	}
	data[prevRobot] = 2;
	return { data,prevRobot };
}

Direction FindingVerticies::FindDirection(int robot, int dimension, std::vector<unsigned int> data)
{
	for (int i = 0; i < 8; i++)
	{
		auto fun = moves.find(directions[i])->second;
		int tempRobot = fun(robot, dimension);
		if (tempRobot < 0 ||tempRobot >= std::pow(dimension, 2))
			continue;
		if ((data[tempRobot] == 1)&&(!((tempRobot % dimension == 0 && (robot + 1) % dimension == 0) || (robot % dimension == 0 && (tempRobot + 1) % dimension == 0))))
			return directions[i];
	}
	return Direction::NONE;
}

AlgoType FindingVerticies::Type() { return type; }
AlgoState FindingVerticies::State() { return state;}

void FindingVerticies::ClearMemory()
{
	this->state = AlgoState::NONE;
}
