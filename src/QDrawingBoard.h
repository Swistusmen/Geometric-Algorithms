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
#include <qevent.h>

class QDrawingBoard : public QFrame {
	Q_OBJECT

public:
	explicit QDrawingBoard(QWidget* parent = 0, bool drawing=false);

	void LoadNewData(std::vector<unsigned int> data);
	void SetUpCollorPallete(std::vector < std::array<int, 3>> colors);
	std::vector<unsigned int> GetCurrentPicture() { return currentPicture; }
	void SetScribbling(bool toScrible) {scribbling = toScrible;}
	void SetColor(int c) { color = c; }

protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	
signals:

public slots:
	void PresentAlgorithm();

private:  //variables
	QPoint lastPoint;
	QPainter* paint;
	QPen* pen;
	QPushButton* button;
	bool isSquareDisplayd = false;
	std::vector<unsigned int> currentPicture;
	std::map<int, QColor> colorPallete; 
	bool isInputBoard = false;
	bool scribbling = false;
	bool isDrawingPossible = false;
	int color = 1;
private: //methods
	virtual void QDrawingBoard::paintEvent(QPaintEvent* event);
	void Draw(const QPoint& point);

};

#endif