#include "QMainInterface.h"
#include <qpushbutton.h>

QMainInterface::QMainInterface(QWidget* parent) : QWidget(parent)
{
	//setFixedSize(366, 300);

	ui.setupUi(this);
	ui.label->setParent(this);
	ui.algoInterface->setParent(this);
	connect(this, SIGNAL(algoWasClicked()),
		this, SLOT(changeTitle(QString)));
	connect(this, SIGNAL(this->dataWasClicked()),
		this, SLOT(changeTitle(QString)));
	//initializing main image

}
