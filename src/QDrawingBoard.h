#pragma once
#ifndef QDRAWINGBOARD_H
#define QDRAWINGBOARD_H

#include <qwidget.h>
#include <qframe.h>
#include <qpushbutton.h>
#include <memory>
#include <qpainter.h>
#include <vector>
#include <map>
#include "qcolor.h"
#include <array>

/*
1. Add posibility to draw a vector of values
	-different number= different color
	-make it flexible- size of cells will depend on what is the resoultion of this widget
2. Make it changeable- as a whole component- to created easy way to update this widget
3. Place this widget on proper layout
*/

class QDrawingBoard : public QFrame {
	Q_OBJECT

public:
	explicit QDrawingBoard(QWidget* parent = 0);

	void LoadNewData(std::vector<unsigned int> data);
	void SetUpCollorPallete(std::vector < std::array<int, 3>> colors);
signals:

public slots:
	void PresentAlgorithm();

private:  //variables
	QPainter* paint;
	QPen* pen;
	QPushButton* button;
	bool isSquareDisplayd = false;
	std::vector<unsigned int> currentPicture;
	std::map<int, QColor> colorPallete; //make it read from file
private: //methods
	virtual void QDrawingBoard::paintEvent(QPaintEvent* event);


};

#endif
