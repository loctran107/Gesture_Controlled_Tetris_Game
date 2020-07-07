#include <cstdlib>
#include "TetrisPiece.h"

using namespace std;

int TetrisPiece::getTile(const int tileNum) {
	
	switch (tileNum) {
		case 0:
			return tile1_;
		case 1:
			return tile2_;
		case 2: 
			return tile3_;
		case 3: 
			return tile4_;
		default:
			return 0;

	}	
}

void TetrisPiece::setTile(const int tile1, const int tile2, const int tile3, const int tile4) {
	tile1_ = tile1;
	tile2_ = tile2;
	tile3_ = tile3;
	tile4_ = tile4;
}


