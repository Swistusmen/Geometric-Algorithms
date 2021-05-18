#include "BoundingBox.h"

std::vector<unsigned int> BoundingBox::Perform(std::vector<unsigned int> data)
{
	if (this->state == AlgoState::FINISHED_SUCCESS)
		return data;
	auto size = data.size();
	int dimension = static_cast<int>(sqrt(size));
	std::vector<int> geometries;
	for (int i = 0; i < size; i++)
	{
		if (data[i] == 1)
			geometries.push_back(i);
	}
	if (geometries.empty())
	{
		this->state == AlgoState::FINISHED_FAILURE;
		return data;
	}
	auto indexes = FindEdgeIndexes(geometries,dimension,size);
	indexes = CalculateEdgeRows(indexes, dimension);
	if (indexes[3] == -1 || indexes[1] == -1 || indexes[0] < 0 || indexes[2] < 0)
	{
		this->state == AlgoState::FINISHED_FAILURE;
		return data;
	}
	int tl =  indexes[0] * dimension + indexes[3];
	int tr = indexes[0] * dimension + indexes[1];
	int br =  (indexes[2]) * dimension + indexes[1];
	int bl =  (indexes[2])* dimension + indexes[3];

	for (int i = tl; i < tr; i ++)
		data[i] = 2;
	
	for (int i = bl; i < br; i ++)
		data[i] = 2;
	
	for (int i = tl; i <= bl; i += dimension)
		data[i] = 2;
	
	for (int i = tr-1; i < br; i += dimension)
		data[i] = 2;
	this->state = AlgoState::FINISHED_SUCCESS;
	return data;
}

std::array<int, 4> BoundingBox::FindEdgeIndexes(std::vector<int> data, int dim, int size)
{
	int topIndex = data.front();
	int botIndex = data.back();
	int rightIndex = -1, leftIndex = 10000000000;
	const int noCells = data.size();
	for (int i = 0; i < noCells; i++)
	{
		int value = data[i] % dim;
		leftIndex=value < leftIndex ? value : leftIndex;
		rightIndex = value > rightIndex ? value : rightIndex;
	}
	std::array<int, 4> a{ topIndex,rightIndex,botIndex,leftIndex };
	return a;
}

std::array<int, 4> BoundingBox::CalculateEdgeRows(std::array<int, 4> data, int dim)
{
	data[0] = floor(static_cast<double>(data[0] - dim) / dim);
	data[1] = (data[1] + 1) % dim == 0 ? -1 : (data[1] + 1) % dim + 1;
	data[2] = ceil(static_cast<double>((data[2] + dim) / dim));
	data[3] = data[3] % dim == 0 ? -1 : (data[3]) % dim - 1;
	return data;
}

AlgoType BoundingBox::Type() { return type; }

AlgoState BoundingBox::State() {return state;}

void BoundingBox::ClearMemory()
{
	state = AlgoState::NONE;
}