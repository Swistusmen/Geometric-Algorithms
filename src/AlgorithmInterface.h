#include "Utilities.h"
#include "MainInterface.h"
#include <string>

class AlgorithmInterface :public MainInterface {
public:
	virtual InterfaceState GetInterfaceState();
	virtual void ChangeInterfaceState();
	virtual void Exit();

	virtual void LoadData();
	virtual AlgoState PerformAlgorithm();
	virtual AlgoType GetCurrentAlgorithm();
	virtual std::string GetAlgorithmDescription();
	virtual AlgoType ChangeAlgorithmType();
};