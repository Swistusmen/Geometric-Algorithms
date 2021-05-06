#include "QMainInterface.h"
#include <qpushbutton.h>
#include <iostream>

QMainInterface::QMainInterface(QWidget* parent) : QWidget(parent)
{
	ui.setupUi(this);
	ui.algoInterface->setCheckable(true);
	ui.creativInterface->setCheckable(true);

	auto collectionOfAlgorithms = std::make_shared<AlgorithmsKeeper>();
	std::vector<unsigned int> input{
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 1, 0, 0, 0, 2, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 1, 1, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0,
		0, 1, 1, 1, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 3, 0, 0, 0, 0, 0
	};
	algorithms = std::make_unique<BoardImplementation>( collectionOfAlgorithms,input );

	algorithms->SetAlgorithm(AlgoType::FindingWay);//later will be set up within GUI

	auto colors = ReadPalleteOfColors();
	board = new QDrawingBoard(ui.page_2);
	board->LoadNewData(input);
	board->SetUpCollorPallete(colors);
	ui.board_place->addWidget(board,Qt::AlignCenter);

	//just testing how things will work
	QString find_way = "Finding Way";
	QString triangulation = "Triangulation";
	QString notInitialized = "Not initialized";
	ui.algo_type->addItem(notInitialized);
	ui.algo_type->addItem(find_way);
	ui.algo_type->addItem(triangulation);
	
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
}

void QMainInterface::ChangePage(int index)
{
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
		std::cout << "Clear memory\n";
		algorithms->ClearAlgorithm();
	}break;
	case 1: {
		std::cout << "Perform the whole algortihm\n";
	}break;
	case 2: {
		std::cout << "Perform signle step\n";
		algorithms->PerformAlgorithm(); //need to be catch and displayed within GUI
		board->LoadNewData(algorithms->GetCurrentState());
		board->PresentAlgorithm();
	}break;
	}
}