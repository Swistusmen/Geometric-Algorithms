<h1>Geometric Algorithms</h1>

<h2>Tech stack</h2>

-C++ 17

-Googletest

-Qt 5.15.2

<h2>Demands</h2>

Project was designed to be built using msvcc19 compiler. It hasn't been testing for any unix-like system. To built, there is need to provide googletest manually to destination: lib/googletest/. Also project doesn't include any tool for installation of Qt packages, interested person should perfomr it manually. If both googletest and qt will be provided, build should be done successfuly. I'm planning to implement building console app in case if no Qt packages were detected. Unit tests covers only algorithms

<h2>Build</h2>

```
mkdir build
cd build
cmake -S .. -B $(pwd)
```

<h2> Implemented algorithms </h2>

- Bounding box (rectangle)

-Finding way (stupid algorithm- choosing always the longest path)

-Finding verticies

-Voronoi Diagram

-Delano Traingulation

<h2>Implemented algorithms </h2>

-finding path in labirynth- select longest possible road or road to glory, don't check if repeat

-minimum square bounding box

-searching for verticies

-voronoi diagram

-Delano triangulation

-finding path in labirynth- check if repeat, randomly select way 

<h2>Gui app information </h2>

<b> Meaningufull (constant) colors: </b> 

⬜- empty/ not initialized

⬛- wall / shape boundary /line

🟥- goal / founded

🟩- position / movement

<b> Interfaces: </b>

Data interface:

![alt text](https://github.com/Swistusmen/Geometric-Algorithms/blob/master/screenshots/input.png)

Algorithm iterface:
![alt text](https://github.com/Swistusmen/Geometric-Algorithms/blob/master/screenshots/algorithm.png)





