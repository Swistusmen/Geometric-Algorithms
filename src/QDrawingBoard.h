#pragma once
#ifndef QDRAWINGBOARD_H
#define QDRAWINGBOARD_H

#include <qwidget.h>
#include <qframe.h>
#include <qpushbutton.h>
#include <memory>
#include <qpainter.h>

class QDrawingBoard : public QFrame {
	Q_OBJECT

public:
	explicit QDrawingBoard(QWidget* parent = 0);

signals:

public slots:
	void PresentAlgorithm();
private:  //variables
	QPainter* paint;
	QPen* pen;
	QPushButton* button;
	bool isSquareDisplayd = false;
private: //methods
	virtual void QDrawingBoard::paintEvent(QPaintEvent* event);
};

#endif
