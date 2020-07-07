#ifndef _TETRISPIECE_H_
#define _TETRISPIEEC_H_

#include <cstdlib>

using namespace std;
class TetrisPiece {
	
	public:
		TetrisPiece() : tile1_(0), tile2_(0), tile3_(0), tile4_(0) { } //default constructor
		TetrisPiece(int tile1, int tile2, int tile3, int tile4) : tile1_(tile1), tile2_(tile2), tile3_(tile3), tile4_(tile4) { } //constructor
		
	//	~TetrisPiece(); //destructor
		
		//Accessors
		int getTile(const int tileNum);
		
		//Mutator
		void setTile(const int tile1, const int tile2, const int tile3, const int tile4);

	private:
		int tile1_;
		int tile2_;
		int tile3_;
		int tile4_;
	

}; //class TetrisPiece


#endif //_TETRISPIECE_H_
