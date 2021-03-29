#include "Board.h"
#include "Writer.h"
#include "Application.h"

/*TODO
1. Add:
-checking app state -DONE
-checking algorithm state while changing it
-alogrithm flow- if data suites to selevted kind of algorithm
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