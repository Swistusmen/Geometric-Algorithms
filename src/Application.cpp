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
	// choose operations: 1 interface, 2. Close, 3 Operations for interface
	//Operations for algorithm interface: perform, load, change algorithm, read description, read messages, save
	//Present
	int choice = -1;
	
	while (true)
	{
		Footer();
		choice = ChooseOption();
		switch (choice) {
		case 0: {Exit(); }break;
		case 1: {ChangeInterfaceState(); } break;
		case 2: {LoadData(); } break;
		case 3: {PerformAlgorithm(); } break;
		case 4: {GetAlgorithmDescription(); } break;
		case 5: {ChangeAlgorithmType(); } break;
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
	data = ReadInputFromFile(saves[saveToLoad]);
	myBoard.LoadNewData(data);
}

AlgoState Application::PerformAlgorithm()
{
	myBoard.PerformAlgorithm();
	return AlgoState::NONE;
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
	if (type == this->algorithmType)
	{
		messages.push("You've already chosen this algorithm, nothing will happen\n");
	}
	switch (type)  {
	case AlgoType::FindingWay: case AlgoType::BoundingBox: case AlgoType::FindingVerticies:
	{
		messages.push("Changing algorithm will cause loose of current data\n");
		this->algorithmType = type;
		myBoard.SetAlgorithm(type);
		return this->algorithmType;

	}break;
	case AlgoType::VoronoiDiagram:
	{
		if (this->algorithmType == AlgoType::FindingVerticies)
		{
			this->algorithmType = type;
			myBoard.SetAlgorithm(type);
			return type;
		}
		messages.push("Changing algorithm will cause loose of current data\n");
		this->algorithmType = type;
		myBoard.SetAlgorithm(type);
		return this->algorithmType;
	}break;
	case AlgoType::DelaunayTriangulation:
	{
		if (this->algorithmType == AlgoType::FindingVerticies||this->algorithmType==AlgoType::VoronoiDiagram)
		{
			this->algorithmType = type;
			myBoard.SetAlgorithm(type);
			return type;
		}
		messages.push("Changing algorithm will cause loose of current data\n");
		this->algorithmType = type;
		myBoard.SetAlgorithm(type);
		return this->algorithmType;
	}break;
	}
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
	std::cout << "Choose interface: \n 1. Bounding Box\n 2. Finding way\n 3. Finding verticies\n 4.Voronoi Daigram\n 5.Triangulation\n";
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
	data.size() != 0 ? std::cout << "Initialized\n" : std::cout << "Not initialized\n";
	SetConsoleTextAttribute(hConsole, 15);
	/*for (int i = 0; i < 255; i++)
	{
		SetConsoleTextAttribute(hConsole, i);
		std::cout << i << std::endl;
	}*/
}
