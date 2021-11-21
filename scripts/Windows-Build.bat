@echo off
mkdir bin
cd bin
g++ -o GuessTheNumber.exe ../src/main.cpp
cd ..
echo Finished compiling.
pause