#include <cstdlib>
#include <iostream>

#include "Field.h"
//Error when #include "TetrisPiece.h": explain this later

/*
 * Note: Next time, use pointer to refer to classes
 * Note: Handle constant (i.e 27 by defining it global in tetris.cc)
 */

using namespace std;

bool Field::hasPieceReachedBottom(TetrisPiece* const pieceArray, const int piece,
	       			  const int numTiles, const int dy) {
	int i;
	TetrisPiece tetrisPiece = *(pieceArray + piece);
	for (i = 0; i < numTiles; i++) {

		int y_tile = (tetrisPiece.getTile(i)).get_y();
		if (((y_tile + dy) * 27) + 27 >= height_) {
			return true;
		}	

	}
	return false;
}

bool Field::hasPieceReachedBounds(TetrisPiece* const pieceArray, const int piece, 
				  const int numTiles, const int dx, bool leftOrRight) {
	int i;
	TetrisPiece tetrisPiece = *(pieceArray + piece);
	for (i = 0; i < numTiles; i++) {
		int x_tile = (tetrisPiece.getTile(i)).get_x();
		if (leftOrRight && ((x_tile + dx) * 27 + 27 >= width_)) {
			return true;
		} else if (!leftOrRight && ((x_tile + dx) * 27 <= 0)) {
			return true;
		}
	}
	return false;
}
