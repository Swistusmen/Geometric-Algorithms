#include "Board.h"
#include "Writer.h"
#include "Application.h"

/*TODO
1. Add:
-checking app state -DONE
-zero algorithm -DONE
-alogrithm flow- if data suites to selevted kind of algorithm -DONE
-update writing- save data flow
-set up flows 
-add descriptions to algorithms and handling them
2. Add Output DONE
3. Simplify code as much as possible
4. Start making GUI
5. Add Input and creating data
*/


int main()
{
	//auto input=ReadInputFromFile("hello.txt");
	
	Application app;
	app.Run();
	//SaveOutputToFile("triangulation.txt", input);
	return 0;
}