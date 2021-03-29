#include "Board.h"

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
	std::vector<unsigned int> output = matrix;
	return output;
}

void BoardImplementation::LoadNewData(std::vector<unsigned int> data)
{
	std::cout << "Loaded\n";
	matrix = data;
}

FieldRepresentation BoardImplementation::Representation()
{
	return this->representation;
}

AlgoType BoardImplementation::GetAlgorithm()
{
	return algo->Type();
}

AlgoState BoardImplementation::PerformAlgorithm()
{
	matrix=algo->Perform(matrix);
	return algo->State();
}

void BoardImplementation::SetAlgorithm(AlgoType type)
{
	algo = algorithmGetter->GetAlgorithm(type);
	//to implement
}

void BoardImplementation::ClearAlgorithm()
{
	if(this->algo)
		this->algo->ClearMemory();
}