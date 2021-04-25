#ifndef QMAININTERFACE_H
#define QMAININTERFACE_H

#include <qwidget.h>
//#include "ui_QMainInterface.h"
//#include "../build/src/ui_MainWindow.h"
//#include "../build/src/ui_QMainWindow.h"
#include "../build/src/ui_QMainInterface.h"


class QPushButton;
class QMainInterface : public QWidget {
	Q_OBJECT

public:
	explicit QMainInterface(QWidget* parent=0);

signals:

public slots:

private:
	QPushButton *algoInterface;
	QPushButton *creativeInterface;

	//Ui::Form ui;
};

#endif
