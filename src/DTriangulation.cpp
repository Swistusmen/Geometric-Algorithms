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
	//std::vector<std::pair<int,int>> robots;
	std::map<int, int> robots;
	auto dim = std::sqrt(size);
	for (int i = 0; i < size; i++)
	{
		if (data[i] == 2)
			robots.insert({ BelongsTo(i,data),i });
	}
	auto myConnections = DetectBorders(data);
	std::vector<unsigned int> output{ data };
	for (auto it = myConnections.begin(); it != myConnections.end(); it++)
	{
		auto drawing = ConnectTwoPointsWithBresenham(data, robots.at(it->first), robots.at(it->second));
		output = MergeDrawings(drawing, output);
	}
	//data = ConnectTwoPointsWithBresenham(data, robots[0].first, robots[1].first);
	//std::cout << robots[0].second << " " << robots[1].second << std::endl;

	return output;
}

std::vector<unsigned int> DTriangulation::MergeDrawings(std::vector<unsigned int> draw1, std::vector<unsigned int> draw2)
{
	std::vector<unsigned int> output;
	const int sizeOfDrawing = draw1.size();
	for (int i = 0; i < sizeOfDrawing; i++)
	{
		if (draw1[i] == 1 || draw2[i] == 1)
			output.push_back(1);
		else {
			output.push_back(draw1[i]);
		}
	}
	return output;
}

std::set<std::pair<int,int>> DTriangulation::DetectBorders(std::vector<unsigned int> data)
{
	const int noElements = data.size();
	std::set<std::pair<int, int>> ChangesOfFields;
	for (int i = 0; i < noElements; i++)
	{
		auto borders = KnowEnvironment(data, i);
		const int noBorders = borders.size();
		for (int j = 0; j < noBorders; j++)
		{
			if (borders[j] > 2 && borders[j] != data[i]&& data[i]!=2)
				ChangesOfFields.insert({ std::min(data[i],borders[j]),std::max(data[i],borders[j]) });
		}
	}
	return ChangesOfFields;
}

std::vector<unsigned int> DTriangulation::KnowEnvironment(std::vector<unsigned int> data, int robot)
{
	int dim = static_cast<int>(std::sqrt(data.size()));
	std::vector<unsigned int> borders;
	bool isLeftWall = robot % dim == 0 ? true : false;
	bool isRightWall = robot % dim == (dim - 1) ? true : false;
	if (robot - dim >= 0)
	{
		borders.push_back(data[robot - dim]);
		if (!isLeftWall && robot - 1 - dim >= 0) borders.push_back(data[robot - dim - 1]);
		if (!isRightWall) borders.push_back(data[robot - dim + 1]);
	}
	if (!isLeftWall) borders.push_back(data[robot - 1]);
	if (!isRightWall) borders.push_back(data[robot + 1]);
	if (robot + dim < data.size())
	{
		borders.push_back(data[robot + dim]);
		if (!isRightWall && robot + dim + 1 < data.size()) borders.push_back(data[robot + dim + 1]);
		if (!isLeftWall) borders.push_back(data[robot + dim - 1]);
	}
	return borders;
}

int DTriangulation::BelongsTo(int robot, std::vector<unsigned int> data)
{
	auto borders = KnowEnvironment(data, robot);
	//create vector of numbers-only 1 
	
	std::vector<unsigned int> results{ borders[0] };
	int noBorders = borders.size();
	for (int i = 1; i < noBorders; i++)
	{
		if (std::find(results.begin(), results.end(), borders[i]) == std::end(results))
			results.push_back(borders[i]);
	}
	//count
	
	int noFields = results.size();
	//std::cout << noFields << std::endl;
	std::vector<int> numbers( noFields );
	std::fill(numbers.begin(), numbers.end(), 0);
	for (int i = 0; i < noFields; i++)
	{
		numbers[i] = std::count(borders.begin(), borders.end(), results[i]);
	}
	//std::cout << numbers[0]<<" "<<numbers[1] << std::endl;
	//std::cout << std::max_element(numbers.begin(), numbers.end())-std::begin(numbers) << std::endl;
	return results[std::max_element(numbers.begin(), numbers.end()) - std::begin(numbers)];
	//return results[*std::max(numbers.begin(), numbers.end())];
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