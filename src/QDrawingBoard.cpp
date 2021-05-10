#include "QDrawingBoard.h"
#include <iostream>

QDrawingBoard::QDrawingBoard(QWidget* parent) :QFrame(parent) {
	this->setFixedSize(400, 400);
}

void QDrawingBoard::PresentAlgorithm()
{
	repaint();
}

void QDrawingBoard::paintEvent(QPaintEvent* event)
{
	const int noCells = currentPicture.size();
	const int dim = static_cast<int>(sqrt(noCells));
	//can be separate function- detect colors
	std::vector<unsigned int> colorsOnThePicture;
	for (int i = 0; i < noCells; i++)
	{
		bool isInStack = false;
		if (std::find(colorsOnThePicture.begin(), colorsOnThePicture.end(),
			currentPicture[i])==colorsOnThePicture.end())
		{
			colorsOnThePicture.push_back(i);
		}
		if ((currentPicture[i] == 2)&& (std::find(colorsOnThePicture.begin(), colorsOnThePicture.end(),
			currentPicture[i]) != colorsOnThePicture.end())) //even thought it may be strange, my compiler doesn't find 2 number, it finds every else but not his one
		{
			colorsOnThePicture.push_back(i);
		}
	}
	//setting up size of a cell
	const int cellWidth = this->width() / dim;
	const int noCollors = colorsOnThePicture.size();
	for (int i = 0; i < noCollors; i++)
	{
		pen = new QPen();
		pen->setWidth(cellWidth);
		pen->setColor(colorPallete[i]);
		auto painter = std::make_unique<QPainter>(this);
		painter->setPen(*pen);
		for (int j = 0; j < noCells; j++)
		{
			if (currentPicture[j] == i)
			{
				painter->drawPoint(((j % dim) * cellWidth)+cellWidth/2, ((static_cast<int>(j / dim)) * cellWidth)+cellWidth/2);
			}
		}
	}
	
}

void QDrawingBoard::LoadNewData(std::vector<unsigned int> data)
{
	currentPicture = data;
}

void QDrawingBoard::SetUpCollorPallete(std::vector < std::array<int, 3>> colors)
{
	const int noCollors = colors.size();
	for (int i = 0; i < noCollors; i++)
	{
		auto color = colors[i];
		colorPallete.insert({ i,QColor(color[0],color[1],color[2]) });
	}
}

void QDrawingBoard::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) {
		lastPoint = event->pos();
		scribbling = true;
	}
}
/*
void QDrawingBoard::mouseMoveEvent(QMouseEvent* event)
{
	if ((event->buttons() & Qt::LeftButton) && scribbling)
		drawLineTo(event->pos());
}
*/

void QDrawingBoard::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton && scribbling) {
		Draw(event->pos());
		scribbling = false;
	}
}

//Make it possible to change colors to 0,1,2,3
//make it possible to hold and 

void QDrawingBoard::Draw(const QPoint& point)
{
	const int noCells = currentPicture.size();
	const int dim = static_cast<int>(sqrt(noCells));
	const int cellWidth = this->width() / dim;
	int x_pos = std::floor(point.x() / cellWidth);
	int y_pos = std::floor(point.y() / cellWidth);

	int index = y_pos * dim + x_pos;
	currentPicture[index] = 1;
	update();
}
