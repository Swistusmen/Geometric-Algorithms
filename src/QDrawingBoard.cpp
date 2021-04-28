#include "QDrawingBoard.h"

QDrawingBoard::QDrawingBoard(QWidget* parent) :QFrame(parent) {
	this->setFixedSize(400, 400);

	
	button = new QPushButton("Draw", this);

	connect(button, &QPushButton::pressed,
		this, &QDrawingBoard::PresentAlgorithm);
}

void QDrawingBoard::PresentAlgorithm()
{
	repaint();
}

void QDrawingBoard::paintEvent(QPaintEvent* event)
{

	if (!isSquareDisplayd) {
		pen = new QPen(Qt::red);
		pen->setWidth(30);
		auto painter = std::make_unique<QPainter>(this);
		painter->setPen(*pen);
		painter->drawPoint(100, 100);
	}
	else {
		pen = new QPen(Qt::black);
		pen->setWidth(30);
		auto painter = std::make_unique<QPainter>(this);
		painter->setPen(*pen);
		painter->drawPoint(100, 100);
	}
	isSquareDisplayd = isSquareDisplayd;
}