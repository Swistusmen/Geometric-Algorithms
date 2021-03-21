#include "BoundingBox.h"

std::vector<unsigned int> BoundingBox::Perform(std::vector<unsigned int> data)
{
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
		std::cerr << "No geoemtires inside\n";
		return data;
	}
	auto indexes = FindEdgeIndexes(geometries,dimension,size);
	indexes = CalculateEdgeRows(indexes, dimension);
	if (indexes[3] == -1 || indexes[1] == -1 || indexes[0] < 0 || indexes[2] < 0)
	{
		std::cerr << "Size of board is to small\n";
		return data;
	}
	int tl =  indexes[0] * dimension + indexes[3];
	int tr = indexes[0] * dimension + indexes[1];
	int br =  (indexes[2] -1) * dimension + indexes[1];
	int bl =  (indexes[1] -1)* dimension + indexes[3];

	for (int i = tl; i < tr; i ++)
		data[i] = 2;
	
	for (int i = bl; i < br; i ++)
		data[i] = 2;
	
	for (int i = tl; i <= bl; i += dimension)
		data[i] = 2;
	
	for (int i = tr-1; i < br; i += dimension)
		data[i] = 2;

	return data;
}

std::array<int, 4> BoundingBox::FindEdgeIndexes(std::vector<int> data, int dim, int size)
{
	int topIndex = data.front();
	int botIndex = data.back();
	int rightIndex = -1, leftIndex = -1;
	for (int i = 0; i < dim; i++)
	{
		for (int j = i; j < size; j += dim)
		{
			if (data[j] == 1)
			{
				leftIndex = j;
				break;
			}
		}
		if (leftIndex != -1)
			break;
	}

	for (int i = dim - 1; i >= 0; i--)
	{
		for (int j = i; j < size; j += dim)
		{
			if (data[j] == 1)
			{
				rightIndex = j;
				break;
			}
		}
		if (rightIndex != -1)
			break;
	}
	std::array<int, 4> a{ topIndex,rightIndex,botIndex,leftIndex };
	return a;
}

std::array<int, 4> BoundingBox::CalculateEdgeRows(std::array<int, 4> data, int dim)
{
	data[0] = floor(static_cast<double>(data[0] - dim) / dim);
	data[1] = (data[1] + 1) % dim == 0 ? -1 : (data[1] + 1) % dim + 1;
	data[2] = ceil(static_cast<double>(data[2] + dim) / dim);
	data[3] = data[3] % dim == 0 ? -1 : (data[3]) % dim - 1;
	return data;
}

AlgoType BoundingBox::Type() { return type; }

AlgoState BoundingBox::State() {return state;}

void BoundingBox::ClearMemory()
{
	state = AlgoState::NONE;
}