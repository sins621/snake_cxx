g++ -c main.cpp -IC:\raylib\include -o main.o
g++ main.o -o main.exe -LC:\raylib\lib -lraylib -lopengl32 -lgdi32 -lwinmm -g
start /B main.exe