#include "Utilities.h"
#include <string>

class AlgorithmInterface  {
public:

	virtual void LoadData()=0;
	virtual AlgoState PerformAlgorithm()=0;
	virtual AlgoType GetCurrentAlgorithm()=0;
	virtual std::string GetAlgorithmDescription()=0;
	virtual AlgoType ChangeAlgorithmType()=0;
};