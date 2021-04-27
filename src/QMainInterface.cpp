#include "QMainInterface.h"
#include <qpushbutton.h>
#include <iostream>

QMainInterface::QMainInterface(QWidget* parent) : QWidget(parent)
{
	//setFixedSize(366, 300);

	ui.setupUi(this);
	ui.algoInterface->setCheckable(true);
	ui.creativInterface->setCheckable(true);
	//connect(this, SIGNAL(QMainInterface::algoWasClicked()),
	//	this, SLOT(QMainInterface::changeTitle(QString)));
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
