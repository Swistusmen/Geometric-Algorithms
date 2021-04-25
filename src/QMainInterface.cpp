#include "QMainInterface.h"
#include <qpushbutton.h>

QMainInterface::QMainInterface(QWidget* parent) : QWidget(parent)
{
	setFixedSize(320, 240);

	algoInterface = new QPushButton("Perform algorithms",this);
	creativeInterface = new QPushButton("Data input",this);

	//ui.setupUi(this);
}
