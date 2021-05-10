#include "QMainInterface.h"
#include <qpushbutton.h>
#include <iostream>

QMainInterface::QMainInterface(QWidget* parent) : QWidget(parent)
{
	ui.setupUi(this);
	ui.algoInterface->setCheckable(true);
	ui.creativInterface->setCheckable(true);

	algoSetup.push_back({ "Not initialized", AlgoType::None });
	algoSetup.push_back({ "Finding Way", AlgoType::FindingWay });
	algoSetup.push_back({ "Triangulation", AlgoType::DelaunayTriangulation });
	algoSetup.push_back({ "Bounding Box" ,AlgoType::BoundingBox});
	algoSetup.push_back({ "Voronoi Diagram" ,AlgoType::VoronoiDiagram});
	algoSetup.push_back({ "Finding Verticies" ,AlgoType::FindingWay});

	algoStates.insert({ AlgoState::NONE, "None" });
	algoStates.insert({ AlgoState::FINISHED_SUCCESS,"Success" });
	algoStates.insert({ AlgoState::FINISHED_FAILURE, "Failure" });
	algoStates.insert({ AlgoState::PERFORMING, "Performing" });
	auto collectionOfAlgorithms = std::make_shared<AlgorithmsKeeper>();
	/*std::vector<unsigned int> input{
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 1, 0, 0, 0, 2, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 1, 1, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0,
		0, 1, 1, 1, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 3, 0, 0, 0, 0, 0
	};*/

	std::vector<unsigned int> input{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};
	algorithms = std::make_unique<BoardImplementation>( collectionOfAlgorithms,input );
	//algorithms->SetAlgorithm(AlgoType::FindingWay);//later will be set up within GUI

	auto colors = ReadPalleteOfColors();
	board = new QDrawingBoard(ui.page_2);
	board->LoadNewData(input);
	board->SetUpCollorPallete(colors);
	ui.board_place->addWidget(board,Qt::AlignCenter);

	//just testing how things will work
	for (int i = 0; i < algoSetup.size(); i++)
	{
		ui.algo_type->addItem(QString::fromStdString(std::get<0>(algoSetup[i])));
	}
	
	//mapping signals
	algorithmMapper = new QSignalMapper(this);

	connect(algorithmMapper, SIGNAL(mapped(int)), this, SLOT(CommandAlgorithm(int)));
	
	algorithmMapper->setMapping(ui.clear_memory, 0);
	algorithmMapper->setMapping(ui.perform_whole_algorithm, 1);
	algorithmMapper->setMapping(ui.next_step, 2);

	connect(ui.clear_memory, SIGNAL(pressed()), algorithmMapper, SLOT(map()));
	connect(ui.next_step, SIGNAL(clicked()), algorithmMapper, SLOT(map()));
	connect(ui.perform_whole_algorithm, SIGNAL(clicked()), algorithmMapper, SLOT(map()));

	pageMapper = new QSignalMapper(this);

	connect(pageMapper, SIGNAL(mapped(int)), this, SLOT(ChangePage(int)));

	pageMapper->setMapping(ui.creativInterface, 2);
	pageMapper->setMapping(ui.algoInterface, 1);

	connect(ui.algoInterface, SIGNAL(clicked()), pageMapper, SLOT(map()));
	connect(ui.creativInterface, SIGNAL(clicked()), pageMapper, SLOT(map()));

	connect(ui.algo_type, SIGNAL(currentIndexChanged(int)), this, SLOT(ChangeAlgorithm(int)));


	inputBoard = new QDrawingBoard(ui.input_page);
	std::vector<unsigned int> input_2{ 
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0 };
	inputBoard->LoadNewData(input_2);
	inputBoard->SetUpCollorPallete(colors);
	ui.input_board_place->addWidget(inputBoard, Qt::AlignCenter);
}

void QMainInterface::ChangePage(int index)
{
	std::cout << ui.algo_type->currentIndex() << std::endl;
	switch (index) {
	case 2: {
		ui.label->setText("Data");
		ui.stackedWidget->setCurrentIndex(2);
	}break;
	case 1: {
		ui.label->setText("Algorithms");
		ui.stackedWidget->setCurrentIndex(1);
	}break;
	}
}

void QMainInterface::CommandAlgorithm(int command)
{
	switch (command) {
	case 0: {
		algorithms->ClearAlgorithm();
		UpdateAlgorithmState(AlgoState::NONE);
		board->LoadNewData(std::vector<unsigned int> {0, 0, 0, 0});
		board->PresentAlgorithm();
	}break;
	case 1: {
		time = TIME;
		try {
			time = ui.input_time->text().toInt();
			time *= 1000;
		}
		catch (std::exception e) {
			time = TIME;
		}
		auto state = algorithms->PerformAlgorithm();
		do{
			UpdateAlgorithmState(state);
			board->LoadNewData(algorithms->GetCurrentState());
			board->PresentAlgorithm();
			state = algorithms->PerformAlgorithm();
			Sleep(time);// works only on windows
		} while (state == AlgoState::PERFORMING); UpdateAlgorithmState(state);
		board->LoadNewData(algorithms->GetCurrentState());
		board->PresentAlgorithm();
		
	}break;
	case 2: {
		
		UpdateAlgorithmState(algorithms->PerformAlgorithm()); 
		board->LoadNewData(algorithms->GetCurrentState());
		board->PresentAlgorithm();
	}break;
	}
}

void QMainInterface::ChangeAlgorithm(int index)
{
	ui.current_algo_state->setText(QString::fromStdString(std::get<0>(algoSetup[index])));
	algorithms->SetAlgorithm(std::get<1>(algoSetup[index]));
}

void QMainInterface::UpdateAlgorithmState(AlgoState state)
{
	ui.current_algo_state->setText(algoStates.at(state));
}

//DZISIAJ
//ChangeAlgorithm- zmienic:
//	-dodac ustawianie labela //jest
//	-dodac zmiane algorytmu //jest
//Clear:
//	-dodac ustawianie zerowanie //jest
//Perform Whole:
//	-zaimplementowac //jest
//	-dodac feature z ustawianiem time framu //jest
//Perform:
//	-dodac ustawianie stanu //jest
//Collor pallete- dodac wiecej kolorkow //jest
//Testy 

/*TODO
-poprawic flow clear (ma przywracac algorytm do poczatkowego stanu- zmienic z clear na restart algorithm
-dane maja miec typ ktory to jest wczytywany i czytany (czy agorytm moze operowac na takich danych)
-poprawic konsturktor(dodac wyjatki)
*/


// Input:
//	-okno pokazujace zapisane algorytmy
//  -stworzyc interaktywna tablice do pisania czarny kolorem
//	-dodac mozliwosc zapisu
//	-mozliwosc wyboru koloru
//	-mozliwosc ustawiania typu danych
//