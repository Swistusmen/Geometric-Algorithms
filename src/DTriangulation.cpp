#include "DTriangulation.h"

DTriangulation::DTriangulation()
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

std::vector<unsigned int> DTriangulation::Perform(std::vector<unsigned int> data)
{
	auto size = data.size();
	std::vector<int> robots;
	auto dim = std::sqrt(size);
	for (int i = 0; i < size; i++)
	{
		if (data[i] == 2)
			robots.push_back(i);
	}
	data = ConnectTwoPointsWithBresenham(data, robots[0], robots[1]);
	return data;
}

std::vector<unsigned int> DTriangulation::ConnectTwoPointsWithBresenham(std::vector<unsigned int> data, int robot1, int robot2)
{
	auto dim = static_cast<int>(std::sqrt(data.size()));
	auto point1 = std::make_pair(robot1 / dim, robot1 % dim);
	auto point2 = std::make_pair(robot2 / dim, robot2 % dim);
	int dx = point1.first - point2.first;
	int dy = point1.second - point2.second;
	int kx = point2.first >= point1.first ? 1 : -1;
	int ky = point2.second >= point1.second ? 1 : -1;
	dx = std::abs(dx);
	dy = std::abs(dy);
	int e = dx / 2;
	data[robot1] = 1;
	if (dy > dx)
	{
		e = dy / 2;
		for (int i = 0; i < dy; i++)
		{
			point1.second += ky;
			e -= dx;
			if (e < 0)
			{
				point1.first += kx;
				e += dy;
			}
			data[point1.first * dim + point1.second] = 1;
		}
		return data;
	}
	for (int i = 0; i < dx;i++)
	{
		point1.first += kx;
		e -= dy;
		if (e < 0)
		{
			point1.second += ky;
			e += dx;
		}
		std::cout << point1.first * dim + point1.second << std::endl;
		data[point1.first * dim + point1.second] = 1;
	}
	return data;
}

std::pair<int, int> DTriangulation::TransformIndexToCartesian(int robot, int dimension)
{
	int x = robot / dimension;
	int y = robot % dimension;
	return { x,y };
}

std::vector<double> DTriangulation::Perform(std::vector<double> data)
{
	return data;
}

AlgoType DTriangulation::Type()
{
	return type;
}

AlgoState DTriangulation::State()
{
	return state;
}

void DTriangulation::ClearMemory()
{

}