#include "Application.h"

Application::Application()
{

}

InterfaceState Application::GetInterfaceState()
{
	return interfaceState;
}
void Application::Exit()
{
	exit(0);
}

void Application::ChangeInterfaceState(InterfaceState state)
{
	interfaceState = state;
}

void Application::LoadData()
{
	auto saves = GetSaves();
	const int noSaves = saves.size();
	for (int i = 0; i < noSaves; i++)
	{
		std::cout << i + 1 << ". " << saves[i] << std::endl;
	}
	int saveToLoad = -1;
	while (saveToLoad < 0 && saveToLoad >= noSaves)
	{
		std::cin >> saveToLoad;
	}
	data = ReadInputFromFile(saves[saveToLoad]);
}

AlgoState Application::PerformAlgorithm()
{

}
AlgoType Application::GetCurrentAlgorithm()
{

}
std::string Application::GetAlgorithmDescription()
{

}
AlgoType Application::ChangeAlgorithmType()
{

}

