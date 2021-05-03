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

class QPushButton;
class QMainInterface : public QWidget {
	Q_OBJECT

public:
	explicit QMainInterface(QWidget* parent=0);

signals:

public slots:
	void changeTitle() {
		auto text = this->WhichButton();
		switch (text) {
		case AppButton::None : {
			
		}break;
		case AppButton::SwitchToAlgorithms: {
			ui.label->setText("Algorithms");
			ui.stackedWidget->setCurrentIndex(1);
		}break;
		case AppButton::SwitchToData: {
			ui.label->setText("Data");
			ui.stackedWidget->setCurrentIndex(0);
		}break;
		}
	}

	void WriteButton(QString buttonName)
	{
		std::cout << "im here\n";
		std::cout << buttonName.toUtf8().constData() << std::endl;
	}
private:  //variables
	Ui::Form ui;

	std::vector<std::tuple<QString, bool>> buttons{ {"Algorithms",0},{"Data",0} };
	QDrawingBoard* board;
	QSignalMapper* mapper;
private: //methods
	AppButton WhichButton();
};

#endif
