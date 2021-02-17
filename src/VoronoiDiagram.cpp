#include "VoronoiDiagram.h"

std::vector<unsigned int> VoronoiDiagram::Perform(std::vector<unsigned int> data)
{
	std::vector<unsigned int> primaryGeometry = data;
	std::vector<std::pair<int,int>> verticiesIndex;
	auto size = data.size();
	int dimension = std::sqrt(size);
	for (int i = 0; i < size; i++)
	{
		if (data[i] == 2)
			verticiesIndex.push_back(TransformIndexToCartesian(i, dimension));
	}
	data = DrawDiagram(data, verticiesIndex);
	for (int i = 0; i < size; i++)
	{
		data[i] = primaryGeometry[i] == 1 ? primaryGeometry[i] : data[i];
	}

	return data;
}

std::vector<unsigned int> VoronoiDiagram::DrawDiagram(std::vector<unsigned int> data, std::vector<std::pair<int, int>> indexes)
{
	auto matrixSize = data.size();
	int dimension = std::sqrt(matrixSize);
	auto noVerticies = indexes.size();
	std::vector<double> distances(noVerticies);
	for (int i = 0; i < matrixSize; i++)
	{
		if (data[i] == 0|| data[i] == 1)
		{
			auto point = TransformIndexToCartesian(i, dimension);
			for (int j = 0; j < noVerticies; j++)
			{
				distances[j] = CalculateDistance(point, indexes.at(j));
			}
			data[i] = std::min_element(distances.begin(), distances.end()) - distances.begin()+3;
		}
	}
	return data;
}

std::pair<int, int> VoronoiDiagram::TransformIndexToCartesian(int index, int dimension)
{
	int x = index / dimension;
	int y = index % dimension;
	return { x,y };
}

double VoronoiDiagram::CalculateDistance(std::pair<int, int> p1, std::pair<int, int> p2)
{
	return std::sqrt(std::pow(p1.first - p2.first, 2) + std::pow(p1.second - p2.second, 2));
}

std::vector<double> VoronoiDiagram::Perform(std::vector<double> data)
{
	return data;
}

AlgoType VoronoiDiagram::Type()
{
	return type;
}

AlgoState VoronoiDiagram::State()
{
	return state;
}

void VoronoiDiagram::ClearMemory()
{

}