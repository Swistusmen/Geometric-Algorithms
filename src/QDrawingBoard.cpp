#include "QDrawingBoard.h"
#include <iostream>

QDrawingBoard::QDrawingBoard(QWidget* parent) :QFrame(parent) {
	this->setFixedSize(400, 400);

	
	button = new QPushButton("Draw", this);

	colorPallete.insert({ 0, Qt::white });
	colorPallete.insert({ 1,Qt::black });
	colorPallete.insert({ 2, Qt::red });

	connect(button, &QPushButton::pressed,
		this, &QDrawingBoard::PresentAlgorithm);
}

void QDrawingBoard::PresentAlgorithm()
{
	repaint();
}
/*
void QDrawingBoard::paintEvent(QPaintEvent* event)
{

	if (!isSquareDisplayd) {
		pen = new QPen(Qt::red);
		pen->setWidth(100);
		auto painter = std::make_unique<QPainter>(this);
		painter->setPen(*pen);
		painter->drawPoint(300+50, 300+50);
	}
	else {
		std::cout << "Helo world\n";
		pen = new QPen(Qt::black);
		pen->setWidth(30);
		auto painter = std::make_unique<QPainter>(this);
		painter->setPen(*pen);
		painter->drawPoint(100, 100);
	}
	isSquareDisplayd = !isSquareDisplayd;
}
*/

void QDrawingBoard::paintEvent(QPaintEvent* event)
{
	const int noCells = currentPicture.size();
	const int dim = static_cast<int>(sqrt(noCells));
	//can be separate function- detect colors
	std::vector<unsigned int> colorsOnThePicture;
	for (int i = 0; i < noCells; i++)
	{
		std::cout << currentPicture[i] << std::endl;
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
	//pen = new QPen();
	const int cellWidth = this->width() / dim;
	//pen->setWidth(cellWidth);
	//auto painter = std::make_unique<QPainter>(this);
	//painter->setPen(*pen);
	const int noCollors = colorsOnThePicture.size();
	std::cout << noCollors << " kolorow\n";
	std::cout << this->width() << " " << this->height() << "\n";
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
				//painter->drawRect(QRect((j % dim) * cellWidth, (static_cast<int>(j / dim)) * cellWidth, cellWidth, cellWidth));
				std::cout << "width " << (j % dim) * cellWidth << "height " << (static_cast<int>(j / dim)) * cellWidth << std::endl;
			}
		}
	}
	
}

void QDrawingBoard::LoadNewData(std::vector<unsigned int> data)
{
	currentPicture = data;
}