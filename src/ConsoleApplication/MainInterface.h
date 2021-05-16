#include "../Algorithms/Utilities.h"
#include <vector>
#include <string>

class MainInterface {
public:
	virtual InterfaceState GetInterfaceState()=0;
	virtual void ChangeInterfaceState(InterfaceState state)=0;
	virtual void Exit()=0;

	virtual void ChangeInterfaceState() = 0; //for command line interface

	std::vector<std::string> mInterfaceCommands{ "Exit","Change interface" };
};