all: main.cpp cube.hh cube.cpp
	g++ main.cpp cube.hh cube.cpp -o main
run: main
	./main