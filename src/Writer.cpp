#include "Writer.h"

namespace fs = std::filesystem;

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

std::vector<unsigned int> ReadInputFromFile(std::string filename)
{
	std::ifstream file;
	auto path = fs::current_path().parent_path().parent_path();
	path += "\\saves\\";
	path += filename;
	file.open(path);
	std::string codedMatrix;
	std::getline(file,codedMatrix);
	return DecodeFileToMatrix(codedMatrix);
}

std::string SaveOutputToFile(std::string filename, std::vector<unsigned int> data)
{
		std::ofstream file;
		auto path = fs::current_path().parent_path().parent_path();
		path += "\\saves\\";
		path += filename;
		file.open(path);
		file << CodeMatrix(data);
		file.close();
		std::cout << CodeMatrix(data) << std::endl;
		std::cout << path << std::endl;
	return "Hello";
}

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