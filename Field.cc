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
			return set_hasReachedBottom(true);;
		}	

	}
	return set_hasReachedBottom(false);
}

bool Field::hasPieceReachedBounds(TetrisPiece* const pieceArray, const int piece, 
				  const int numTiles, const int dx, string opt) {
	int i;
	TetrisPiece tetrisPiece = *(pieceArray + piece);
	for (i = 0; i < numTiles; i++) {
		int x_tile = (tetrisPiece.getTile(i)).get_x();
		if (opt.compare("ROTATE") == 0) {
			if (((x_tile + dx) * 27 <= 0) || ((((x_tile + dx) * 27) + 27) >= width_)) {
				return set_hasReachedBounds(true);
			}
		} else if (opt.compare("LEFT") == 0) {
			if (((x_tile + dx) * 27) <= 0) {
				return set_hasReachedBounds(true);
			}
		} else if (opt.compare("RIGHT") == 0) {
			if ((((x_tile + dx) * 27) + 27) >= width_) {
				return set_hasReachedBounds(true);
			}
		} else {
			return set_hasReachedBounds(false);
		}
	}
	return set_hasReachedBounds(false);
}

bool Field::set_hasReachedBottom(const bool hasReachedBottom) {
	hasReachedBottom_ = hasReachedBottom;
	return hasReachedBottom_;
}

bool Field::set_hasReachedBounds(const bool hasReachedBounds) {
	hasReachedBounds_ = hasReachedBounds;
	return hasReachedBounds_;
}
