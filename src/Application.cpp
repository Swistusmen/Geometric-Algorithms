#include "Application.h"

Application::Application()
{
	data.resize(DEFAULT_BOARD_SIZE * DEFAULT_BOARD_SIZE);
	std::fill(data.begin(), data.end(), 0);
	auto algorithms= std::make_shared<AlgorithmsKeeper>();
	this->myBoard = BoardImplementation(algorithms, data);
}

void Application::Run()
{
	int choice = -1;
	
	while (true)
	{
		system("cls");
		Footer();
		choice = ChooseOption();
		switch (choice) {
		case 0: {Exit(); }break;
		case 1: {ChangeInterfaceState(); } break;
		case 2: {LoadData(); } break;
		case 3: {PerformAlgorithm(); } break;
		case 4: {GetAlgorithmDescription(); } break;
		case 5: {ChangeAlgorithmType(); } break;
		case 6: {ClearAlgorithm(); }break;
		}
	}
}

int Application::ChooseOption()
{
	switch (this->interfaceState)
	{
	case InterfaceState::MAIN: {
		const int noFunctions = this->mInterfaceCommands.size();
		for (int i = 0; i < noFunctions; i++)
		{
			std::cout << i + 1 << ". " << this->mInterfaceCommands[i] << std::endl;
		}
		int choice = -1;
		while (choice<1 || choice>noFunctions)
		{
			std::cin >> choice;
			choice -= 1;
		}
		return choice;
	}break;
	case InterfaceState::ALGORITH_INTERFACE: {
		const int noFunctions = this->mInterfaceCommands.size();
		const int noFunctionsSpecific = this->aInterfaceCommands.size();
		const int totalNoFunctions = noFunctions + noFunctionsSpecific;
		int i = 0;
		for (; i < noFunctions; i++)
		{
			std::cout << i + 1 << ". " << this->mInterfaceCommands[i] << std::endl;
		}
		for (; i < totalNoFunctions; i++)
		{
			std::cout << i + 1 << ". " << this->aInterfaceCommands[i- noFunctions] << std::endl;
		}
		int choice = -1;
		while (choice<1 || choice>totalNoFunctions)
		{
			std::cin >> choice;
			choice--;
		}
		return choice;
	}break;
	}
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
	while (saveToLoad < 0 || saveToLoad >= noSaves)
	{
		std::cin >> saveToLoad;
		saveToLoad--;
	}
	auto readFile= ReadInputFromFile(saves[saveToLoad]);
	data = readFile.first;
	this->dataType = readFile.second;
	myBoard.LoadNewData(data);
	isDataSet = true;
}

void Application::PerformAlgorithm()
{
	if (this->dataType != this->algorithmType)
	{
		std::cout << "Incompatible data type\n";
		system("wait");
		return;
	}
	this->algorithmState=myBoard.PerformAlgorithm();
	data = myBoard.GetCurrentState();
	if (algorithmState == AlgoState::FINISHED_SUCCESS)
	{
		switch (dataType) {
		case AlgoType::FindingVerticies: {dataType = AlgoType::VoronoiDiagram; }break;
		case AlgoType::VoronoiDiagram: {dataType = AlgoType::DelaunayTriangulation; }break;
		}
	}
	DisplayColorful(data);
}

AlgoType Application::GetCurrentAlgorithm()
{
	return this->algorithmType;
}

std::string Application::GetAlgorithmDescription()
{
	return "To implement\n";
}

AlgoType Application::ChangeAlgorithmType(AlgoType type)
{
	this->algorithmType = type;
	myBoard.SetAlgorithm(type);
	return this->algorithmType;
}

void Application::ChangeInterfaceState()
{
	std::cout << "Choose interface: \n 1. Main interface\n 2. Algorithm interface\n";
	int choice = -1 ;
	while (choice < 1 || choice>2)
	{
		std::cin >> choice;
	}
	interfaceState = choice==1?InterfaceState::MAIN:InterfaceState::ALGORITH_INTERFACE;
}

AlgoType Application::ChangeAlgorithmType()
{
	std::cout << "Choose interface: \n 1. Bounding Box\n 2. Finding way\n 3. Finding verticies\n 4. Voronoi Daigram\n 5. Triangulation\n";
	int choice = -1;
	while (choice < 1 || choice>5)
	{
		std::cin >> choice;
	}
	AlgoType algo = AlgoType::None;
	switch (choice) {
	case 1:{ algo = AlgoType::BoundingBox; }break;
	case 2: { algo = AlgoType::FindingWay; }break;
	case 3: { algo = AlgoType::FindingVerticies; }break;
	case 4: { algo = AlgoType::VoronoiDiagram; }break;
	case 5: { algo = AlgoType::DelaunayTriangulation; }break;
	}
	return ChangeAlgorithmType(algo);
}

void Application::Footer()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Geometric algorithm: ";
	SetConsoleTextAttribute(hConsole, 11);
	auto currentAlgo = this->GetCurrentAlgorithm();
	switch (currentAlgo) {
	case AlgoType::BoundingBox: {std::cout << "Bounding box, "; }break;
	case AlgoType::FindingWay: {std::cout << "Finding way, "; }break;
	case AlgoType::FindingVerticies: {std::cout << "Finding veritcies, "; }break;
	case AlgoType::VoronoiDiagram: {std::cout << "Voronoi diagram, "; }break;
	case AlgoType::DelaunayTriangulation: {std::cout << "Triangulation, "; }break;
	case AlgoType::None: {std::cout << "None, "; }break;
	}
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Data: ";
	SetConsoleTextAttribute(hConsole, 11);
	isDataSet ? std::cout << "Initialized\n" : std::cout << "Not initialized\n";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Algorithm State: ";
	SetConsoleTextAttribute(hConsole, 11);
	switch (this->algorithmState)
	{
	case AlgoState::PERFORMING: {std::cout << "Performing "; }break;
	case AlgoState::FINISHED_FAILURE: {std::cout << "Finished failure "; }break;
	case AlgoState::FINISHED_SUCCESS: {std::cout << "Finished successfully "; }break;
	case AlgoState::NONE: {std::cout << "None "; }break;
	}
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Data type: ";
	SetConsoleTextAttribute(hConsole, 11);
	switch (this->dataType) {
	case AlgoType::None: { std::cout << "Not initlized\n"; }break;
	case AlgoType::BoundingBox: { std::cout << "Bounding box\n"; }break;
	case AlgoType::FindingWay: { std::cout << "Finding Way\n"; }break;
	case AlgoType::FindingVerticies: { std::cout << "Finding Verticies\n"; }break;
	case AlgoType::VoronoiDiagram: { std::cout << "Voronoi Diagram\n"; }break;
	case AlgoType::DelaunayTriangulation: { std::cout << "Triangulation\n"; }break;
	}
	SetConsoleTextAttribute(hConsole, 15);
	
}

void Application::ClearAlgorithm()
{
	myBoard.ClearAlgorithm();
	this->algorithmState = AlgoState::NONE;
}
