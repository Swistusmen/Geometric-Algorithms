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
Project is build, by there is need to made such a configuration:

-load project, change <keyword> to QtVS_v302, reload project

-Convert custom steps to MS/Qt build

-in Properties, select modules: Core, XML, Widget, GUI, select QtInstallation to 5.15.2 (if you haven't create it, create one)

-Properties/ Qt Settings/ Paths/ Additional header search path and Additional Qt library search path- you need to paste your paths into them

-save

-load project, change Keyword back to Win32Proj

-you should be able to use qt libraries from now

-<b>If it is not possible try to use backupCmakeLists.txt (2) - they have versio without qt, probably there will be need to change source code

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


<h4>Currently adding gui</h4>
https://stackoverflow.com/questions/4028604/add-qt-to-existing-visual-studio-c-project
https://forum.qt.io/topic/114299/convert-visual-studio-2017-solution-to-use-qt/2

Steps done to switch to Qt (the best solution, not working now):

-changing on CMakeList.txt: Adding set (CMAKE_PREFIX_PATH "C:\\Qt\\5.9.9\\msvc2017_64\\") to main, find_package(Qt5 COMPONENTS Widgets REQUIRED), find_package(Qt5 COMPONENTS Widgets REQUIRED)

-Switching to Qt project by changin .vcxproj <Keyword> to different options
  
  -using Qt5.9.9
  
  -always couldn't find Qt files

probably ther is a need to use install command for dll files
