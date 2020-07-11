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
					fieldMatrix[i][j] = -1;
				}
			}
		}		

		bool hasPieceReachedBottom(TetrisPiece* const pieceArray, PieceController* const control,
				           const int piece, const int numTiles, const int dy);
				
		bool hasPieceReachedBounds(TetrisPiece* const pieceArray, PieceController* const control,
			            	   const int piece, const int numTiles, const int dx, const string opt);

		void stick_piece(TetrisPiece* const pieceArray, const int piece, const int color,
				const int numTiles, const int dx, const int dy);	

		bool get_hasReachedBottom() { return hasReachedBottom_; }
		bool get_hasReachedBounds() { return hasReachedBounds_; }
		int getFieldMatrix(const int dy, const int dx) { return fieldMatrix[dy][dx]; }
	private:
		
		bool set_hasReachedBottom(const bool hasReachedBottom);
		bool set_hasReachedBounds(const bool hasReachedBounds);
		
		//Properties
		int width_;
		int height_;
		bool hasReachedBottom_;
		bool hasReachedBounds_;
		int fieldMatrix[ROW][COLUMN];
		
}; //class Field

#endif //_FIELD_H_
