#include "Utilities.h"
#include "MainInterface.h"

class CrateiveInterface: public MainInterface {
public:
	virtual InterfaceState GetInterfaceState();
	virtual void ChangeInterfaceState();
	virtual void Exit();

	virtual void ChangeColour(unsigned int);
	virtual unsigned int GetCurrentColour();
	virtual void NewBoard();
	virtual void SaveBoard();
	virtual void ChangeSize(unsigned int);
};