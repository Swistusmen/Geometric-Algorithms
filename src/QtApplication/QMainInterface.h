#pragma once
#ifndef QMAININTERFACE_H
#define QMAININTERFACE_H

#include <qwidget.h>
#include <qstringbuilder.h>
#include "QDrawingBoard.h"
#include "Writer.h"
#include <qsignalmapper.h>
#include "Algorithms/Board.h"
#include "Algorithms/Strategy.h"
#include <utility>
#include <qdatawidgetmapper.h>
#include <qstandarditemmodel.h>
#include <vector>
#include <tuple>
#include <map>
#include <qcolordialog.h>
#include <qfiledialog.h>
#include <stdio.h>
#include <qmessagebox.h>
#include <time.h>
#include <filesystem>
#include "../build/src/ui_QMainInterface.h"

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
	void ChangeBoardSize(int dim);
	void OpenFileDialogToLoadData();
	void OpenFileDialogToSaveData();
	void ChangeColor(int index);
private:  //variables
	Ui::Form ui;

	std::unique_ptr<BoardImplementation> algorithms=nullptr;
	QDrawingBoard* board;
	QDrawingBoard* inputBoard;
	QSignalMapper* pageMapper;
	QSignalMapper* algorithmMapper;
	QSignalMapper* algorithmMapper2;
	QSignalMapper* boardSizeMapper;
	QMessageBox msgBox;
	AlgoType currentType=AlgoType::None;
	
	QDataWidgetMapper* algoType;
	std::vector<std::tuple< QString, AlgoType>> algoSetup; //swithc to read from file
	std::map<AlgoState,QString> algoStates;
	int time = TIME;
private: //methods
	inline void UpdateAlgorithmState(AlgoState state);

	void ConnectWidgets();
	void InitializeWidgets();
	std::vector<std::array<int, 3>> GenerateColors();
	AlgoType IntToAlgoType(int index);
	int AlgoTypeToInt(AlgoType type);
	std::string path;
};

#endif

/*
2. Wczytywanie algorytmu
*/