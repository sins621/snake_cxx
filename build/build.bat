del main.o
del main.exe
g++ -c ../src/main.cpp -I../include -o main.o
g++ main.o -o main.exe -L../lib -lraylib -lopengl32 -lgdi32 -lwinmm
start main.exe
