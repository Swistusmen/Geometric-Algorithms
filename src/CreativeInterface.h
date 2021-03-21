#include "Utilities.h"

class CrateiveInterface {
public:
	virtual void ChangeColour(unsigned int)=0;
	virtual unsigned int GetCurrentColour()=0;
	virtual void NewBoard()=0;
	virtual void SaveBoard()=0;
	virtual void ChangeSize(unsigned int)=0;
};