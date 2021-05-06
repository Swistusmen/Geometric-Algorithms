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
#include "Board.h"
#include "Strategy.h"
#include <utility>

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

	std::unique_ptr<BoardImplementation> algorithms=nullptr;
	QDrawingBoard* board;
	QSignalMapper* pageMapper;
	QSignalMapper* algorithmMapper;
private: //methods
	
};

#endif
