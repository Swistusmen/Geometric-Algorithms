#!/bin/bash

cd src
rm -r ALL_BUILD* CMakeFiles/ CMakeFiles/ INSTALL* GeometricAlgorithms* release/ src/ tst/ debug/ lib/ ZERO* src.v*
cd ../build 
cmake -S .. -B $(pwd)