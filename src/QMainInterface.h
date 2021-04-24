#ifndef QMAININTERFACE_H
#define QMAININTERFACE_H

#include <qwidget.h>

class QPushButton;
class QMainInterface : public QWidget {
	Q_OBJECT

public:
	explicit QMainInterface(QWidget* parent=0);
/*
signals:

public slots:
*/
private:
	QPushButton* algoInterface;
	QPushButton* creativeInterface;
};

#endif
