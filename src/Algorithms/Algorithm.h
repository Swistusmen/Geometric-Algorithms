#pragma once
#include "Field.h"
#include <vector>
#include <algorithm>
#include <variant>
#include <functional>
#include <utility>
#include <memory>
#include <map>
#include <iostream>
#include <array>
#include "Utilities.h"

class Algorithm {
public:
	virtual std::vector<unsigned int> Perform(std::vector<unsigned int> data)=0;

	virtual void ClearMemory() = 0;
	virtual AlgoState State()=0;
	virtual AlgoType Type()=0;
};
