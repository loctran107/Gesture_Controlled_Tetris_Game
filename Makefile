CXX=g++
CXXFLAGS=-Wall -std=c++11 -g
PROGS=tetris

all: $(PROGS)

tetris: tetris.o TetrisPiece.o PieceController.o MatrixTransform.o
	$(CXX) $(CXXFLAGS) -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system

tetris.o: tetris.cc TetrisPiece.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

TetrisPiece.o: TetrisPiece.cc TetrisPiece.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

PieceController.o: PieceController.cc PieceController.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

MatrixTransform.o: MatrixTransform.cc MatrixTransform.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<
clean:
	rm $(PROGS)
