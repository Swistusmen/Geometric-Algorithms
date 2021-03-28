#include "MainInterface.h"
#include "AlgorithmInterface.h"
#include "Board.h"
#include "Writer.h"


class Application : public MainInterface, public AlgorithmInterface
{
public:
	Application();

	InterfaceState GetInterfaceState() override;
	void ChangeInterfaceState(InterfaceState state) override;
	void Exit() override;

	void LoadData() override;
	AlgoState PerformAlgorithm() override;
	AlgoType GetCurrentAlgorithm() override;
	std::string GetAlgorithmDescription() override;
	AlgoType ChangeAlgorithmType() override;
private:
	AlgoType algorithmType=AlgoType::None;
	AlgoState algorithmState=AlgoState::NONE;
	InterfaceState interfaceState=InterfaceState::MAIN;
	std::string algorithmDescription="";
	std::vector<unsigned int> data;
};