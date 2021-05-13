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
	}; //4,5,10,20,25, inne 50, 100, 200, 400, 
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

	inputBoard = new QDrawingBoard(ui.input_page,true);
	inputBoard->LoadNewData(input);
	inputBoard->SetUpCollorPallete(colors);
	ui.input_board_place->addWidget(inputBoard, Qt::AlignCenter);

	board->SetScribbling(false);

	boardSizeMapper = new QSignalMapper(this);

	ui.change_board_size->addItem("4");
	ui.change_board_size->addItem("10");
	ui.change_board_size->addItem("20");
	ui.change_board_size->addItem("25");
	ui.change_board_size->addItem("50");
	ui.change_board_size->addItem("100");

	connect(ui.change_board_size, SIGNAL(currentIndexChanged(int)), this, SLOT(ChangeBoardSize(int)));


	connect(ui.clear_board, SIGNAL(clicked()), this, SLOT(ClearBoard()));

	connect(ui.load_file, SIGNAL(clicked()), this, SLOT(OpenFileDialogToLoadData()));
	connect(ui.save_file, SIGNAL(clicked()), this, SLOT(OpenFileDialogToSaveData()));
	connect(ui.choose_color, SIGNAL(currentIndexChanged(int)), this, SLOT(ChangeColor(int)));
}

void QMainInterface::ChangePage(int index)
{
	std::cout << ui.algo_type->currentIndex() << std::endl;
	switch (index) {
	case 2: {
		ui.label->setText("Data");
		auto data = board->GetCurrentPicture();
		inputBoard->LoadNewData(data);
		algorithms->LoadNewData(data);
		ui.stackedWidget->setCurrentIndex(2);
	}break;
	case 1: {
		ui.label->setText("Algorithms");
		auto data = inputBoard->GetCurrentPicture();
		board->LoadNewData(data);
		algorithms->LoadNewData(data);
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


void QMainInterface::ClearBoard() {
	auto data = inputBoard->GetCurrentPicture();
	std::fill(std::begin(data), std::end(data), 0);
	inputBoard->LoadNewData(data);
	inputBoard->PresentAlgorithm();
	algorithms->ClearAlgorithm();
	UpdateAlgorithmState(AlgoState::NONE);
}

void QMainInterface::ChangeBoardSize(int index)
{
	int dim;
	switch (index) {
	case 0:{dim = 4;}break;
	case 1: {dim = 10; }break;
	case 2: {dim = 20; }break;
	case 3: {dim = 25; }break;
	case 4: {dim = 50; }break;
	case 5: {dim = 100; }break;
	}
	std::vector<unsigned int> data (dim*dim);
	std::fill(std::begin(data), std::end(data), 0);
	inputBoard->LoadNewData(data);
	algorithms->ClearAlgorithm();
}

void QMainInterface::OpenFileDialogToLoadData()
{
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open Image"), "/", tr("Image Files (*.txt */.cpp)"));
	if (fileName.toStdString() == "")
		return;
	auto readAlgo = ReadInputFromFile(fileName.toStdString(), true);
	ClearBoard();
	inputBoard->LoadNewData(readAlgo.first);
	inputBoard->PresentAlgorithm();
	algorithms->LoadNewData(readAlgo.first);
}

void QMainInterface::OpenFileDialogToSaveData()
{
	QString fileName = QFileDialog::getSaveFileName(this,
		tr("Open Image"), "/", tr("Image Files (*.txt */.cpp)"));
	if (fileName.toStdString() == "")
		return;
	std::cout << "File to save: " <<fileName.toStdString()<< std::endl;
	//WARNING -CHANGE LAST PARAMETER FO FUNCTION BELOW AFTER IMPLEENTATION
	SaveOutputToFile(fileName.toStdString(), inputBoard->GetCurrentPicture(), AlgoType::FindingVerticies, true);
}

void QMainInterface::ChangeColor(int index) 
{
	switch (index) {
	case 0: {inputBoard->SetColor(1); }break;
	case 1: {inputBoard->SetColor(0); }break;
	case 2: {inputBoard->SetColor(2); }break;
	case 3: {inputBoard->SetColor(3); }break;
	}
}

/*TODO
- dodanie opcji zmiany koloru -uproszczenie tylko pierwsze podstawowe //JEST
- dodanie opcji odczytu danych z pliku JEST
- dodanie opcji zapisu danych do pliku JEST
- poprawa layoutow //JEST
- poprawa algorytmow
- dodanie algorithm description
- poprawa czytelnosci kodu
- poprawa konstruktora
- poprawa cmake (budowa na widnowsie)
*/

