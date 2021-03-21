#include "MainInterface.h"
#include "AlgorithmInterface.h"
#include "Board.h"
#include "Writer.h"


class Application : public MainInterface, public AlgorithmInterface
{
public:
	InterfaceState GetInterfaceState() override;
	void ChangeInterfaceState() override;
	void Exit() override;

	void LoadData() override;
	AlgoState PerformAlgorithm() override;
	AlgoType GetCurrentAlgorithm() override;
	std::string GetAlgorithmDescription() override;
	AlgoType ChangeAlgorithmType() override;
private:
	AlgoType algorithmType;
	AlgoState algorithmState;
	std::string algorithmDescription;
	std::vector<unsigned int> data;
};