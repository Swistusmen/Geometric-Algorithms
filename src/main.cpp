#include "Board.h"
#include "Writer.h"
#include "Application.h"

#include <QtWidgets/qapplication.h>
#include <qwidget.h>
#include <qpushbutton.h>
#include "QMainInterface.h"
#include "QDrawingBoard.h"


#ifdef QT_VERSION >= 0x040100
#define QT "Yes"
#else
#define QT "No"
#endif


/*TODO
1. Add 3rd layer- for data input (empty) //done
2. Fix switching between pages- make it nice //done
3. Integrate Application with GUI- to let it work separatelty 
-add combo box binding //done
4. Improve input data:
	-let read data //done
	-create input mode //done
5. Add nice features:
	-description of every algorithm
6. Improve building tool
	-make it easy to build on windows
	-make it possible to build on linux
7. Create CI/CD 
	-building
	-testing
	-deploying
8. Tests
9. Next algorithms in the future ...
*/

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QMainInterface qmain;
	qmain.show();
	
	return app.exec();
}

