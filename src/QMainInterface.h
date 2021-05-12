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
#include <qdatawidgetmapper.h>
#include <qstandarditemmodel.h>
#include <vector>
#include <tuple>
#include <map>
#include <qcolordialog.h>

#define TIME 3000

class QPushButton;
class QMainInterface : public QWidget {
	Q_OBJECT

public:
	explicit QMainInterface(QWidget* parent=0);

signals:

public slots:
	void ChangePage(int index);
	void ChangeAlgorithm(int index);
	void CommandAlgorithm(int commad);
	void ClearBoard();
private:  //variables
	Ui::Form ui;

	std::unique_ptr<BoardImplementation> algorithms=nullptr;
	QDrawingBoard* board;
	QDrawingBoard* inputBoard;
	QSignalMapper* pageMapper;
	QSignalMapper* algorithmMapper;
	QDataWidgetMapper* algoType;
	QStandardItemModel* model;
	std::vector<std::tuple< std::string, AlgoType>> algoSetup; //swithc to read from file
	std::map<AlgoState,QString> algoStates;
	
	int time = TIME;
private: //methods
	inline void UpdateAlgorithmState(AlgoState state);
	//void ChangeBoardSize();// to implement today
	//make 1 board which for both interfaces -DONE
	//repair reset button
};

#endif
