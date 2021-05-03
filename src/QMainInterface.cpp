#include "QMainInterface.h"
#include <qpushbutton.h>
#include <iostream>

QMainInterface::QMainInterface(QWidget* parent) : QWidget(parent)
{
	ui.setupUi(this);
	ui.algoInterface->setCheckable(true);
	ui.creativInterface->setCheckable(true);

	auto colors = ReadPalleteOfColors();
	std::vector<unsigned int> input4{
		3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 3, 0, 0, 0, 4, 0, 1, 4,	0,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
		0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1
	};
	board = new QDrawingBoard(ui.page_2);
	board->LoadNewData(input4);
	board->SetUpCollorPallete(colors);
	ui.board_place->addWidget(board,Qt::AlignCenter);

	//just testing how things will work
	QString find_way = "Finding Way";
	QString triangulation = "Triangulation";
	QString notInitialized = "Not initialized";
	ui.algo_type->addItem(notInitialized);
	ui.algo_type->addItem(find_way);
	ui.algo_type->addItem(triangulation);

	mapper = new QSignalMapper(this);

	connect(mapper, SIGNAL(mapped(QString)), this, SLOT(WriteButton(QString)));

	mapper->setMapping(ui.clear_memory, QString("Clear Memory"));
	mapper->setMapping(ui.perform_whole_algorithm, "Perform whole Algorithm");
	mapper->setMapping(ui.next_step, "Next step");

	connect(ui.clear_memory, SIGNAL(pressed()), mapper, SLOT(map()));
	connect(ui.next_step, SIGNAL(clicked()), mapper, SLOT(map()));
	connect(ui.perform_whole_algorithm, SIGNAL(clicked()), mapper, SLOT(map()));

	connect(ui.algoInterface, &QPushButton::pressed,
			this, &QMainInterface::changeTitle);
	connect(ui.creativInterface, &QPushButton::pressed,
		this, &QMainInterface::changeTitle);
	
	//initializing main image

}

//very temporarly- when ui will be finished there will be no need to use such a circus solution, it's for test
//and until all the ui will be created
AppButton QMainInterface::WhichButton() {
	auto buttons = ui.interfaceButtons->buttons();
	const int noButtons = buttons.size();
	int destination = -1;
	for (int i = 0; i < noButtons; i++)
	{
		if (buttons.at(i)->isChecked() == true)
		{
			destination = i;
			break;
		}
		buttons.at(i)->setChecked(false);
	}
	for (int i = 0; i < noButtons; i++)
	{
		buttons.at(i)->setChecked(false);
	}
	if (destination == -1)
		return AppButton::None;
	if (buttons.at(destination)->text() == "Data")
		return AppButton::SwitchToData;
	else if (buttons.at(destination)->text() == "algorithms")
		return AppButton::SwitchToAlgorithms;
	else
		return AppButton::None;
}
