#include "MainInterface.h"
#include "AlgorithmInterface.h"
#include "Board.h"
#include "Writer.h"
#include <stack>
#include <Windows.h>


#define DEFAULT_BOARD_SIZE 100

class Application : public MainInterface, public AlgorithmInterface
{
public:
	Application();

	void Run();

	InterfaceState GetInterfaceState() override;
	void ChangeInterfaceState(InterfaceState state) override;
	void ChangeInterfaceState() override;
	void Exit() override;

	void LoadData() override;
	AlgoState PerformAlgorithm() override;
	AlgoType GetCurrentAlgorithm() override;
	std::string GetAlgorithmDescription() override;
	AlgoType ChangeAlgorithmType(AlgoType type) override;
	AlgoType ChangeAlgorithmType() override;
private: //operations for console interface
	int ChooseOption();
	void Footer();

private:
	AlgoType algorithmType=AlgoType::None;
	AlgoState algorithmState=AlgoState::NONE;
	InterfaceState interfaceState=InterfaceState::MAIN;
	std::string algorithmDescription="";
	std::vector<unsigned int> data;
	BoardImplementation myBoard;

	std::stack<std::string> messages;

};