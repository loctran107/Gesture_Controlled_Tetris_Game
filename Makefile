CXX=g++
CXXFLAGS=-Wall -std=c++11 -g -o
PROGS=tetris

all: $(PROGS)

tetris: tetris.cc
	$(CXX) $(CXXFLAGS) $@ tetris.cc -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm $(PROGS)
