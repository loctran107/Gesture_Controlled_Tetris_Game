#ifndef _FIELD_H_
#define _FIELD_H_
#include <cstdlib>
#include "PointTile.h"
#include "TetrisPiece.h"
#include "PieceController.h"

#define ROW 24
#define COLUMN 14

class Field {

	public:
		Field(const int width, const int height) : width_(width), height_(height), score_(0) { 
			int i, j;
			for (i = 0; i < ROW; i++) {
				for (j = 0; j < COLUMN; j++) {
					fieldMatrix[i][j] = -1;
				}
			}
		}		

		bool hasPieceReachedBottomOrOtherPiece(TetrisPiece* const pieceArray, PieceController* const control,
				                       const int piece, const int numTiles, const int dx, const int dy);
				
		bool hasPieceReachedBoundsOrOtherPiece(TetrisPiece* const pieceArray, PieceController* const control,
			            	   const int piece, const int numTiles, const int dx, const int dy, const string opt);

		void stick_piece(TetrisPiece* const pieceArray, const int piece, const int color,
				const int numTiles, const int dx, const int dy);	

		bool get_hasReachedBottom() { return hasReachedBottom_; }
		bool get_hasReachedBounds() { return hasReachedBounds_; }
		int getFieldMatrix(const int dy, const int dx) { return fieldMatrix[dy][dx]; }
		void checkLines(PieceController* const control);
		bool checkLoss();
		int get_score() { return score_; }
	private:
		
		bool set_hasReachedBottomOrOtherPiece(const bool hasReachedBottom);
		bool set_hasReachedBounds(const bool hasReachedBounds);
		void set_score(const int score);
		
		//Properties
		int width_;
		int height_;
		int score_;
		bool hasReachedBottom_;
		bool hasReachedBounds_;
		int fieldMatrix[ROW][COLUMN];
		
}; //class Field

#endif //_FIELD_H_
