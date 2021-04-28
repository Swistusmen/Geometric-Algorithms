#pragma once
#ifndef QDRAWINGBOARD_H
#define QDRAWINGBOARD_H

#include <qwidget.h>
#include <qframe.h>
#include <qpushbutton.h>

class QDrawingBoard : public QFrame {
	Q_OBJECT

public:
	explicit QDrawingBoard(QWidget* parent = 0);

signals:

public slots:
	
private:  //variables
	QPushButton* pushButton;
private: //methods
	
};

#endif
