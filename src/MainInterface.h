#include "Utilities.h"

class MainInterface {
public:
	virtual InterfaceState GetInterfaceState();
	virtual void ChangeInterfaceState();

	virtual void Exit();
};