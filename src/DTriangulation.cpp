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
	std::cout << robots[0] << " " << std::floor(robots[0] / dim) << " " << static_cast<int>(robots[0]) % static_cast<int>(dim) << std::endl;
	std::cout << robots[1] << " " << std::floor(robots[1] / dim) << " " << static_cast<int>(robots[1]) % static_cast<int>(dim) << std::endl;
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
	std::cout << dx << " " << dy << std::endl;
	std::cout << kx << " " << ky << std::endl;
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
			std::cout << "punkt " << i << " " << point1.first * dim << " " << point1.second << std::endl;
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

std::vector<unsigned int> DTriangulation::ConnectTwoPoints(std::vector<unsigned int> data, int robot1, int robot2)
{
	auto dimension = std::sqrt(data.size());
	auto end = TransformIndexToCartesian(robot2, dimension);
	int currentPoint = robot1;
	int rowChanges = 0, columnChanges = 0;
	int tempPoint;
	while (currentPoint!=robot2)
	{
		tempPoint = ScanForTheNearestPoint(currentPoint ,end,dimension,data);
		if (tempPoint - 1 == currentPoint || tempPoint + 1 == currentPoint)
			columnChanges++;
		else
			rowChanges++;
		//data[tempPoint] = 1; //this to write line
		currentPoint = tempPoint;
		

	}
	//Make a line straight line

	data[currentPoint] = 2;
	return data;
}

int DTriangulation::ScanForTheNearestPoint(int begin, std::pair<int, int> end , int dimension, std::vector<unsigned int>)
{
	std::array<double, 8> realDistances;
	std::array<int, 8> indexes;
	for (int i = 0; i < 8; i++)
	{
		auto fun = this->moves.find(directions[i])->second;
		int pointToCheck= fun(begin,dimension);
		indexes[i] = pointToCheck;
		if (pointToCheck > -1 && pointToCheck < std::pow(dimension, 2) && !((begin % dimension == 0) && (pointToCheck + 1) % dimension == 0) && !((pointToCheck % dimension == 0) && (begin + 1) % dimension == 0))
			realDistances[i] = CalculateDistance(TransformIndexToCartesian(pointToCheck, dimension), end) ;
		else
			realDistances[i] =  std::numeric_limits<double>::max();
	}
	auto minDist = std::min_element(realDistances.begin(), realDistances.end()) - realDistances.begin();
	return indexes[minDist];
}

double DTriangulation::CalculateDistance(std::pair<int, int> p1, std::pair<int, int> p2)
{
	return std::sqrt(std::pow(p1.first - p2.first, 2) + std::pow(p1.second - p2.second, 2));
}

std::pair<int, int> DTriangulation::TransformIndexToCartesian(int robot, int dimension)
{
	int x = robot / dimension;
	int y = robot % dimension;
	return { x,y };
}

std::vector<unsigned int> DTriangulation::MarkWay(int robot, std::vector<unsigned int> data)
{
	int dimension = std::sqrt(data.size());
	bool isFinished = false;
	int sign = 10 * this->horizontalDistance + this->verticalDistance;
	while (true)
	{
		if (!isFinished)
		for (int i = 0; i < this->horizontalDistance; i++)
		{
			robot -= dimension;
			if (robot < 0)
			{
				isFinished = true;
				break;
			}
			data[robot] = sign;
		}
		if (!isFinished)
		{
			int prevRobot;
			for (int i = 0; i < this->verticalDistance; i++)
			{
				prevRobot = robot;
				robot++;
				if (robot % dimension == 0 && (prevRobot + 1) == 0)
				{
					isFinished = true;
					break;
				}
				data[robot] = sign;
			}
		}
		if (isFinished)
			break;
	}
	return data;
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