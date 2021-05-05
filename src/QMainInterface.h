#pragma once
#ifndef QMAININTERFACE_H
#define QMAININTERFACE_H

#include <qwidget.h>
#include "../build/src/ui_QMainInterface.h"
#include <qstringbuilder.h>
#include "ButtonStates.h"
#include "QDrawingBoard.h"
#include "Writer.h"
#include <qsignalmapper.h>

class QPushButton;
class QMainInterface : public QWidget {
	Q_OBJECT

public:
	explicit QMainInterface(QWidget* parent=0);

signals:

public slots:
	void ChangePage(int index);

	void CommandAlgorithm(int commad);
private:  //variables
	Ui::Form ui;

	std::vector<std::tuple<QString, bool>> buttons{ {"Algorithms",0},{"Data",0} };
	QDrawingBoard* board;
	QSignalMapper* pageMapper;
	QSignalMapper* algorithmMapper;
private: //methods
	AppButton WhichButton();
};

#endif
