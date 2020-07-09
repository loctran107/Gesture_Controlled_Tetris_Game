CXX=g++
CXXFLAGS=-Wall -std=c++11 -g
PROGS=tetris testTile

all: $(PROGS)

tetris: tetris.o TetrisPiece.o PieceController.o PointTile.o
	$(CXX) $(CXXFLAGS) -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system

testTile: testTile.o PointTile.o
	$(CXX) $(CXXFLAGS) -o $@ $^

testTile.o: testTile.cc PointTile.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<


tetris.o: tetris.cc TetrisPiece.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

TetrisPiece.o: TetrisPiece.cc TetrisPiece.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

PieceController.o: PieceController.cc PieceController.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

PointTile.o: PointTile.cc PointTile.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<
clean:
	rm $(PROGS)
