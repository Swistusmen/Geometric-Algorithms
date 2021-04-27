#include "QDrawingBoard.h"

QDrawingBoard::QDrawingBoard(QWidget* parent) :QFrame(parent) {
	pushButton = new QPushButton("Hello world", this);
}