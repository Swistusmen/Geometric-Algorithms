#ifndef QMAININTERFACE_H
#define QMAININTERFACE_H

#include <qwidget.h>
#include "../build/src/ui_QMainInterface.h"


class QPushButton;
class QMainInterface : public QWidget {
	Q_OBJECT

public:
	explicit QMainInterface(QWidget* parent=0);

signals:

public slots:

private:  //variables
	Ui::Form ui;

private: //methods

};

#endif
