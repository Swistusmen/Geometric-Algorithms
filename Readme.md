<h1>Geometric Algorithms</h1>

<h2>Purpose of this project</h2>

-Learn geometric algorithms

-Improve C++ and project patterns skills

<h2>Demands</h2>

-visual studio 2019 (project include windows libraries)

-google test (every algorithm has test cases)

-compiler which supports C++2017 features (I'm compiling using msvc_2019)

<h2>Build</h2>

For now there is need to add google test manually to the lib as directory is empty (will be made as subdirectory)</br>
Project demand qt 5.15.2, in the future cmake will be modified to allow creting version without GUI
```
mkdir build
cd build
cmake -S .. -B $(pwd)
```
Go to C:\Windows\System32\cmd.exe, run

```
windeployqt.exe {Project path}\build\src\Debug
```

<b> Warning </b>
I'm not completly sure if this steps will be repeatable on other windows machines, first you need to install qt in vs, what is hardest part


<h2>Implemented algorithms </h2>

-finding path in labirynth

-minimum square bounding box

-searching for verticies

-voronoi diagram

-Delano triangulation

<h2>To implement </h2>

-GUI

-better input

-algorithm parallelism

-working on png files as inputs

-algorithms: other ways of finding paths, checking if figure is contiunues, blending figures, ncellular automata


<h4>Important about integrating cpp project with qt</h4>
https://stackoverflow.com/questions/4028604/add-qt-to-existing-visual-studio-c-project

https://forum.qt.io/topic/114299/convert-visual-studio-2017-solution-to-use-qt/2

Steps done to switch to Qt (the best solution, not working now):

-proper installation (for me 5.15.2 worked, but I had problems with 6.* and 5.9.9, maybe now I could work with it)- installer 2.4, run out of the VS

-changes in CMakeLists.txt- CMAKE_PREFIX_PATH need to be set, libraries should be dll files added by windeployqt.exe, there is also possiblitiy to add them by install in cmake probably

-no changes was needed in VS, but important things an be changed:
