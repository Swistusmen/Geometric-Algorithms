#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>

std::string ParseToMatrix(std::vector<unsigned int> input);

std::vector<unsigned int> ReadInputFromFile(std::string filename);

std::string SaveOutputToFile(std::string filename, std::vector<unsigned int> data);

std::vector<std::string> GetSaves();

std::string CodeMatrix(std::vector<unsigned int> data);

std::vector<unsigned int> DecodeFileToMatrix(std::string filename);