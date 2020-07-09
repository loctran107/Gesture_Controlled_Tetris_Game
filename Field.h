#ifndef _FIELD_H_
#define _FIELD_H_
#include <cstdlib>
#include "TetrisPiece.h"

class Field {

	public:
		Field(const int width, const int height) : width_(width), height_(height) { }
		bool hasPieceReachedBottom(TetrisPiece* const pieceArray, const int piece, 
				           const int numTiles, const int dy);
				
		bool hasPieceReachedBounds(TetrisPiece* const pieceArray, const int piece,
					   const int numTiles, const int dx, bool leftOrRight);
	private:

		//Properties
		int width_;
		int height_;

		
}; //class Field

#endif //_FIELD_H_
