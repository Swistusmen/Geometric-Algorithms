#include "Board.h"

//Constructors
BoardImplementation::BoardImplementation(std::shared_ptr<AlgorithmsKeeper> str, std::vector<unsigned int> input)
{
	this->algorithmGetter = str;
	auto size = input.size();
	double number = std::sqrt(static_cast<double>(size));
	int buffer = number;
	std::cout << number-buffer << std::endl;
	if (static_cast<double>(number - buffer) != 0.0||size<9)
	{
		std::cerr << "[E1] Wrong Board initialization- wrong size\n";
		exit(1);
	}
	this->matrix = input;
}
//
std::vector<unsigned int> BoardImplementation::GetCurrentState()
{
	if (this->representation == FieldRepresentation::NONE)
		return matrix;
	return this->OutputRepresentation();
}

std::vector<unsigned int> BoardImplementation::OutputRepresentation()
{
	std::vector<unsigned int> output;
	if (this->representation == FieldRepresentation::SDF)
	{
		output.resize(matrix.size());
		std::transform(sdf.begin(), sdf.end(), output.begin(), [](auto a) {
			return a == 0 ? 1 : a < 0 ? 0 : 2;
		});
	}
	else {
		output = matrix;
	}
	return output;
}

FieldRepresentation BoardImplementation::Representation()
{
	return this->representation;
}

AlgoType BoardImplementation::GetAlgorithm()
{
	return algo->Type();
}

void BoardImplementation::PerformAlgorithm()
{
	//to implement as it is only bounding box now
	matrix=algo->Perform(matrix);
}

void BoardImplementation::SetAlgorithm(AlgoType type)
{
	algo = algorithmGetter->GetAlgorithm(type);
	//to implement
}