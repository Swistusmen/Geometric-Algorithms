#include "Writer.h"

namespace fs = std::filesystem;

///////////////////////// READ WRITE FUNTIONS
std::vector<std::string> GetSaves()
{
	std::vector<std::string > saves;
	fs::path path = fs::current_path().parent_path().parent_path();
	path += "\\saves";
	for (const auto& entry : std::filesystem::directory_iterator(path))
	{
		saves.push_back(entry.path().filename().string());
	}
	return saves;
}

std::pair<std::vector<unsigned int>, AlgoType> ReadInputFromFile(std::string filename,bool isPath)
{
	std::ifstream file;
	if (!isPath) {
		auto path = fs::current_path().parent_path().parent_path();
		path += "\\saves\\";
		path += filename;
		file.open(path);
	}
	else {
		file.open(filename);
	}
	std::string codedMatrix;
	std::string algoType;
	std::getline(file, algoType);
	std::getline(file, codedMatrix);
	return { DecodeFileToMatrix(codedMatrix),DecodeAlgorithm(algoType) };
}

std::string SaveOutputToFile(std::string filename, std::vector<unsigned int> data, AlgoType type)
{
	std::ofstream file;
	auto path = fs::current_path().parent_path().parent_path();
	path += "\\saves\\";
	path += filename;
	file.open(path);
	file << EncodeAlgorithm(type);
	file << CodeMatrix(data);
	file.close();
	return "Hello";
}

////////////////////////////// DISPLAY FUNCTIONS
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

void DisplayColorful(std::vector<unsigned int> data)
{
	auto size = data.size();
	int dimensionSize = std::sqrt(size);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int index = 0; index < size; index++)
	{
		if (index % dimensionSize == 0)
		{
			std::cout << "\n";
		}
		if (data[index] == 1)
		{
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << data[index] << " ";
			SetConsoleTextAttribute(hConsole, 15);
		}
		else {
			SetConsoleTextAttribute(hConsole, 15);
			std::cout << data[index] << " ";
			SetConsoleTextAttribute(hConsole, 11);
		}
	}std::cout << std::endl;
	system("pause");
}

///////////////////////////////// INTERNAL FUNCTIONS
std::string CodeMatrix(std::vector<unsigned int> data)
{
	std::string output = "";
	const int noFields = data.size();
	int currentNumberCounter = 1;
	int currentNumber = data[0];
	for (int i = 1; i < noFields;i++)
	{
		if (data[i] != currentNumber)
		{
			output += "{" + std::to_string(currentNumberCounter) + "}" + std::to_string(currentNumber);
			currentNumber = data[i];
			currentNumberCounter = 1;
		}
		else {
			currentNumberCounter++;
		}
	}
	output += "{" + std::to_string(currentNumberCounter) + "}" + std::to_string(currentNumber);
	return output;
}

std::vector<unsigned int> DecodeFileToMatrix(std::string file)
{
	std::vector<unsigned int> data;
	std::string::iterator it;
	std::string field = "";
	std::string number = "";
	bool addToNumber = false;
	for (it = file.begin(); it != file.end(); it++)
	{
		if ('{' == *it)
		{
			if (field != "")
			{
				int n = std::stoi(number);
				unsigned int num = static_cast<unsigned int>(std::stoi(field));
				for (int i = 0; i < n;i++)
				{
					data.push_back(num);
				}
				field = "";
				number = "";
			}
			addToNumber = true;
		}
		else if ('}' == *it)
		{
			addToNumber = false;
		}
		else {
			addToNumber == true ? number += *it : field += *it;
		}
	}
	int n = std::stoi(number);
	unsigned int num = static_cast<unsigned int>(std::stoi(field));
	for (int i = 0; i < n; i++)
	{
		data.push_back(num);
	}
	std::cout << data.size() << std::endl;
	return data;
}

AlgoType DecodeAlgorithm(std::string name)
{
	int algo = std::stoi(name);
	switch (algo) {
	case 1: return AlgoType::BoundingBox;
	case 2: return AlgoType::FindingWay;
	case 3: return AlgoType::FindingVerticies;
	case 4: return AlgoType::VoronoiDiagram;
	case 5: return AlgoType::DelaunayTriangulation;
	}
}

std::string EncodeAlgorithm(AlgoType type)
{
	switch(type)
	{
	case AlgoType::None:{ return "0\n"; }break;
	case AlgoType::BoundingBox:{ return "1\n"; }break;
	case AlgoType::FindingWay:{ return "2\n"; }break;
	case AlgoType::FindingVerticies:{ return "3\n"; }break;
	case AlgoType::VoronoiDiagram:{ return "4\n"; }break;
	case AlgoType::DelaunayTriangulation: { return "5\n"; }break;
	}
}

std::vector<std::array<int, 3>> ReadPalleteOfColors()
{
	std::vector<std::array<int, 3>> colors;
	std::ifstream file;
	file.open("../../src/colors.txt");
	std::string a, b, c;
	while (!file.eof())
	{
		file >> a;
		file >> b;
		file >> c;
		colors.push_back({ std::stoi(a),std::stoi(b),std::stoi(c) });
	}
	file.close();
	return colors;
}