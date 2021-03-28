#include "Utilities.h"

class MainInterface {
public:
	virtual InterfaceState GetInterfaceState()=0;
	virtual void ChangeInterfaceState(InterfaceState state)=0;

	virtual void Exit()=0;
};