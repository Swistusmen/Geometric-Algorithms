#include "Board.h"
#include "Writer.h"
#include "Application.h"

/*TODO
1. Make a line straight line DONE
2. Make a implementation of some basic geometriacl functions in separete classes and inherit from them
3. Make a reader DONE
4. Make an input reader (choose cell and then input cell) DONE
5. Add informartion how to use, and what algorithm does
6. Add more tests DONE
7. Add GUI app
8. Add Deluanya Triangulation algorithm -DONE
*/


int main()
{
	/*
	std::vector<unsigned int> input{ 
		3, 3, 3, 3, 4, 4, 4, 4,
		3, 2, 3, 3, 4, 4, 2, 4,
		3, 3, 3, 3, 4, 4, 4, 4,
		3, 3, 3, 3, 4, 4, 4, 4,
		5, 5, 5, 5, 6, 6, 6, 6,
		5, 5, 5, 5, 6, 6, 6, 6,
		5, 2, 5, 5, 6, 6, 2, 6,
		5, 5, 5, 5, 6, 6, 6, 6
	};
	*/
	//auto input=ReadInputFromFile("hello.txt");
	/*std::vector<unsigned int> input{
		3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5,
		3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5,
		3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5,
		3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5,
		3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5,
		3, 3, 2, 3, 3, 3, 3, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5,
		3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5,
		3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5,
		3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5,
		3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
		3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
		3, 3, 3, 3, 6, 6, 6, 6, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 2, 5, 5, 5, 5,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 8, 8, 8, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 8, 8, 8, 8, 5, 5, 5, 5, 5, 5, 5, 5, 7, 7, 7,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 8, 8, 8, 8, 8, 5, 5, 5, 5, 5, 7, 7, 7, 7, 7,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 8, 8, 8, 8, 8, 8, 8, 5, 5, 7, 7, 7, 7, 7, 7, 7,
		6, 6, 6, 6, 2, 6, 6, 6, 6, 8, 8, 8, 8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 2, 7,
		6, 6, 6, 6, 6, 6, 6, 6, 8, 8, 8, 8, 8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7, 7,
		9, 6, 6, 6, 6, 6, 6, 6, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7,
		9, 9, 9, 6, 6, 6, 6, 8, 8, 8, 8, 2, 8, 8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7,
		9, 9, 9, 9, 9, 6, 6, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7,
		9, 9, 9, 9, 9, 9, 9, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7,
		9, 2, 9, 9, 9, 9, 9, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7,
		9, 9, 9, 9, 9, 9, 9, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7
	};
	*/
	/*
	std::vector<unsigned int> input{
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 2, 1, 1, 1, 1, 2, 0,
		0, 1, 0, 0, 0, 0, 1, 0,
		0, 1, 0, 0, 0, 0, 1, 0,
		0, 1, 0, 0, 0, 0, 1, 0,
		0, 1, 0, 0, 0, 0, 1, 0,
		0, 2, 1, 1, 1, 1, 2, 0,
		0, 0, 0, 0, 0, 0, 0, 0
	};
	*/
	/*
	std::cout << ParseToMatrix(input) << std::endl;
	auto algorithms = std::make_shared<AlgorithmsKeeper>();
	auto board = std::make_unique<BoardImplementation>(algorithms, input);
	
	board->SetAlgorithm(AlgoType::VoronoiDiagram);

	board->PerformAlgorithm();
	auto mat = board->GetCurrentState();
	
	std::cout << ParseToMatrix(mat) << std::endl;
	*/
	Application app;
	app.Run();
	//SaveOutputToFile("triangulation.txt", input);
	return 0;
}