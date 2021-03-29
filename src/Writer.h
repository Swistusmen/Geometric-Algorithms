#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include "Utilities.h"

std::string ParseToMatrix(std::vector<unsigned int> input);

std::pair<std::vector<unsigned int>, AlgoType> ReadInputFromFile(std::string filename);

std::string SaveOutputToFile(std::string filename, std::vector<unsigned int> data);

std::vector<std::string> GetSaves();

std::string CodeMatrix(std::vector<unsigned int> data);

std::vector<unsigned int> DecodeFileToMatrix(std::string filename);

void DisplayColorful(std::vector<unsigned int> data);

AlgoType DecodeAlgorithm(std::string name);