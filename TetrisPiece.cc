#include <cstdlib>
#include "TetrisPiece.h"

using namespace std;

PointTile TetrisPiece::getTile(const int tileNum) {
	
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
			return tile1_;
	}	
}

void TetrisPiece::setTile(const PointTile tile1, const PointTile tile2,
	                  const PointTile tile3, const PointTile tile4) {
	tile1_ = tile1;
	tile2_ = tile2;
	tile3_ = tile3;
	tile4_ = tile4;
}

void TetrisPiece::setTileBasedIndex(const int tileIndex, const PointTile tile) {
	
	switch (tileIndex) {
		case 0:
			tile1_ = tile;
			break;
		case 1: 
			tile2_ = tile;
			break;
		case 2:
			tile3_ = tile;
			break;
		case 3: 
			tile4_ = tile;
			break;
		default:
			break;
	}
}


