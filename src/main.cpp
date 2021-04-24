#include "Board.h"
#include "Writer.h"
#include "Application.h"

#include <QtWidgets/qapplication.h>
#include <qwidget.h>
#include <qpushbutton.h>
#include "QMainInterface.h"


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
/*
int main(int argc, char* argv[])
{
	std::cout << QT << std::endl;
	QApplication app(argc,argv);
	//Application app;
	//app.Run();
	return 0;
}
*/


int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	/*
	QWidget window;
	QPushButton pushButton("Hello world",&window);
	window.resize(320, 240);
	window.show();
	window.setWindowTitle(
		QApplication::translate("toplevel", "Top-level widget"));
	*/
	QMainInterface qmain;
	qmain.show();
	return app.exec();
}

