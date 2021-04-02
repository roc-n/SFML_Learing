SRC = $(wildcard *.cpp) $(wildcard ./Source/*.cpp)
@echo "mkdir ./obj"
OBJ := $(wildcard ./obj)

main : $(objects)
	g++ -o main $(objects) -lsfml-graphics -lsfml-system -lsfml-window

