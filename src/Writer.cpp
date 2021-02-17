#include "Writer.h"

std::string ParseToMatrix(std::vector<unsigned int> input)
{
	auto size = input.size();
	int dimensionSize = std::sqrt(size);
	std::string output = "";
	for (int index = 0; index < size; index++)
	{
		if (index % dimensionSize == 0)
			output += "\n";
		output += std::to_string(input[index]);
		output += " ";
	}
	return output;
}