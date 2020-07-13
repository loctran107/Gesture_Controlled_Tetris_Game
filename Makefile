CXX=g++
CXXFLAGS=-Wall -std=c++11 -g
PROGS=tetris

all: $(PROGS)

tetris: TetrisGameMain.o TetrisAdmin.o Tetris.o Field.o TetrisPiece.o PieceController.o PointTile.o
	$(CXX) $(CXXFLAGS) -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system

TetrisGameMain.o: TetrisGameMain.cc 
	$(CXX) $(CXXFLAGS) -o $@ -c $<

TetrisAdmin.o: TetrisAdmin.cc TetrisAdmin.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

Tetris.o: Tetris.cc Tetris.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

Field.o: Field.cc Field.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

TetrisPiece.o: TetrisPiece.cc TetrisPiece.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

PieceController.o: PieceController.cc PieceController.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

PointTile.o: PointTile.cc PointTile.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<
clean:
	rm $(PROGS)
