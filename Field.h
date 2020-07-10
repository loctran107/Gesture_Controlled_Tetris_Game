#ifndef _FIELD_H_
#define _FIELD_H_
#include <cstdlib>
#include "TetrisPiece.h"
#include "PieceController.h"

class Field {

	public:
		Field(const int width, const int height) : width_(width), height_(height) { }
		bool hasPieceReachedBottom(TetrisPiece* const pieceArray, PieceController* const control,
				           const int piece, const int numTiles, const int dy);
				
		bool hasPieceReachedBounds(TetrisPiece* const pieceArray, PieceController* const control,
			            	   const int piece, const int numTiles, const int dx, const string opt);
		
		bool get_hasReachedBottom() { return hasReachedBottom_; }
		bool get_hasReachedBounds() { return hasReachedBounds_; }
	private:
		
		bool set_hasReachedBottom(const bool hasReachedBottom);
		bool set_hasReachedBounds(const bool hasReachedBounds);
		
		//Properties
		int width_;
		int height_;
		bool hasReachedBottom_;
		bool hasReachedBounds_;
		
}; //class Field

#endif //_FIELD_H_
