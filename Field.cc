#include <cstdlib>
#include <iostream>
#include "Field.h"

//Error when #include "TetrisPiece.h": explain this later

/*
 * Note: Next time, use pointer to refer to classes
 * Note: Handle constant (i.e 27 by defining it global in tetris.cc)
 * Note: Consider using "this" later to refer to object's fields
 */

using namespace std;

bool Field::hasPieceReachedBottom(TetrisPiece* const pieceArray, PieceController* const control,
	          	          const int piece, const int numTiles, const int dy) {
	int i;
	TetrisPiece tetrisPiece = *(pieceArray + piece);
	for (i = 0; i < numTiles; i++) {
	//	int x_tile = (tetrisPiece.getTile(i)).get_x();
		int y_tile = (tetrisPiece.getTile(i)).get_y();
	/*	if (rotateOrNot) {
			control->updateRotation(x_tile, y_tile, piece, i, pieceArray, false);
		}*/
		if (((y_tile + dy) * 27) + 27 >= height_) {
			return set_hasReachedBottom(true);;
		}	

	}
	return set_hasReachedBottom(false);
}

bool Field::hasPieceReachedBounds(TetrisPiece* const pieceArray, PieceController* const control,
		                  const int piece, const int numTiles, const int dx, const string opt) {
	int i;
	TetrisPiece tetrisPiece = *(pieceArray + piece);
	for (i = 0; i < numTiles; i++) {
		int x_tile = (tetrisPiece.getTile(i)).get_x();
		//cout << "x_tile initial " << x_tile << endl;
		int y_tile = (tetrisPiece.getTile(i)).get_y();
		//cout << "y_tile initial " << y_tile << endl; 
		if (opt.compare("ROTATE") == 0) {
			control->updateRotation(x_tile, y_tile, piece, i, pieceArray, false); 	
			if (((x_tile + dx) * 27 < 0) || ((((x_tile + dx) * 27) + 27) > width_)) {
		//		cout << "x_tile later" << x_tile << endl;
			//	cout << "dx " << dx << endl;
			//	cout << i << endl;
		//		cout << "True" << endl;
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
