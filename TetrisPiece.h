#ifndef _TETRISPIECE_H_
#define _TETRISPIECE_H_

#include "PointTile.h"
#include <cstdlib>

using namespace std;
class TetrisPiece {
	
	public:
		TetrisPiece() : tile1_(0,0), tile2_(0,0),
	       			tile3_(0,0), tile4_(0,0) { } //default constructor
		TetrisPiece(PointTile tile1, PointTile tile2, PointTile tile3, PointTile tile4) : 
			   tile1_(tile1), tile2_(tile2), tile3_(tile3), tile4_(tile4) { } //constructor
		
	//	~TetrisPiece(); //destructor
		
		//Accessors
		PointTile getTile(const int tileNum);
		
		//Mutator
		void setTile(const PointTile tile1, const PointTile tile2,
			     const PointTile tile3, const PointTile tile4);
		void setTileBasedIndex(const int tileIndex, const PointTile tile);
	private:
		PointTile tile1_;
		PointTile tile2_;
		PointTile tile3_;
		PointTile tile4_;
	

}; //class TetrisPiece


#endif //_TETRISPIECE_H_
