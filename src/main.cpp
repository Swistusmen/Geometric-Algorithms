#include "Board.h"
#include "Writer.h"
#include "Application.h"

#include <QtWidgets/qapplication.h>
#include <qwidget.h>
#include <qpushbutton.h>
#include "QMainInterface.h"
#include "../build/src/ui_QMainInterface.h"


#ifdef QT_VERSION >= 0x040100
#define QT "Yes"
#else
#define QT "No"
#endif


/*TODO
1. Add:
-checking app state -DONE
-zero algorithm -DONE
-alogrithm flow- if data suites to selevted kind of algorithm -DONE
-update writing- save data flow -DONE
-set up flows DONE
-add descriptions to algorithms and handling them
2. Add Output DONE
3. Simplify code as much as possible
4. Start making GUI
5. Add Input and creating data
*/

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QMainInterface qmain;
	Ui::Form ui;
	ui.setupUi(&qmain);
	qmain.show();
	return app.exec();
}

