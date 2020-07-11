#ifndef _FIELD_H_
#define _FIELD_H_
#include <cstdlib>
#include "PointTile.h"
#include "TetrisPiece.h"
#include "PieceController.h"

#define ROW 27
#define COLUMN 18

class Field {

	public:
		Field(const int width, const int height) : width_(width), height_(height) { 
		
			int i, j;
			for (i = 0; i < ROW; i++) {
				for (j = 0; j < COLUMN; j++) {
					PointTile p(-1, -1);
					fieldMatrix[i][j] = p;
				}
			}
		
		}
		bool hasPieceReachedBottom(TetrisPiece* const pieceArray, PieceController* const control,
				           const int piece, const int numTiles, const int dy);
				
		bool hasPieceReachedBounds(TetrisPiece* const pieceArray, PieceController* const control,
			            	   const int piece, const int numTiles, const int dx, const string opt);
		void stick_piece(TetrisPiece* const pieceArray, const int piece, const int numTiles, const int dx, const int dy);	
		bool get_hasReachedBottom() { return hasReachedBottom_; }
		bool get_hasReachedBounds() { return hasReachedBounds_; }
		
		PointTile get_pointTile(const int dx, const int dy) { return fieldMatrix[dy][dx]; }
	private:
		
		bool set_hasReachedBottom(const bool hasReachedBottom);
		bool set_hasReachedBounds(const bool hasReachedBounds);
		
		//Properties
		int width_;
		int height_;
		bool hasReachedBottom_;
		bool hasReachedBounds_;
		PointTile fieldMatrix[ROW][COLUMN];
		
}; //class Field

#endif //_FIELD_H_
