#ifndef QMAININTERFACE_H
#define QMAININTERFACE_H

#include <qwidget.h>
#include "../build/src/ui_QMainInterface.h"
#include <qstringbuilder.h>


class QPushButton;
class QMainInterface : public QWidget {
	Q_OBJECT

public:
	explicit QMainInterface(QWidget* parent=0);

signals:
	void algoWasClicked() {
		emit(test_1);
	};
	void dataWasClicked() {
		emit(test_2);
	}
public slots:
	void changeTitle(QString display) {
		ui.label->setText(display);
	}
private:  //variables
	Ui::Form ui;

	QString test_1="Geometrical Algorithms";
	QString test_2="Data";
	QString to_display = "Geometrical Algorithms";

private: //methods

};

#endif
