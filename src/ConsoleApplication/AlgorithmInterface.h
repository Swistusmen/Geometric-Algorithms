#include <string>
#include <vector>

class AlgorithmInterface  {
public:

	virtual void LoadData()=0;
	virtual void PerformAlgorithm()=0;
	virtual AlgoType GetCurrentAlgorithm()=0;
	virtual std::string GetAlgorithmDescription()=0;
	virtual AlgoType ChangeAlgorithmType(AlgoType type)=0;
	virtual AlgoType ChangeAlgorithmType() = 0; //just for console interface
	virtual void ClearAlgorithm() = 0;

	std::vector<std::string> aInterfaceCommands{ "Load","Perform","Get Algorithm Description", "Change algorithm",  "Clear Algorithm" };
};