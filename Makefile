CXX=g++
CXXFLAGS=-Wall -std=c++11 -g
HEADERS=TetrisPiece.h
PROGS=tetris

all: $(PROGS)

tetris: tetris.o TetrisPiece.o
	$(CXX) $(CXXFLAGS) -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system

tetris.o: tetris.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

TetrisPiece.o: TetrisPiece.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
clean:
	rm $(PROGS)
