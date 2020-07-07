#ifndef _TETRISPIECE_H_
#define _TETRISPIEEC_H_

#include <cstdlib>

using namespace std;
class TetrisPiece {
	
	public:
		TetrisPiece(int tile1, int tile, int tile3, int tile4); //constructor
		~TetrisPiece(); //destructor
		
	private:
		int tile1_;
		int tile2_;
		int tile3_;
		int tile4_;
	

}; //class TetrisPiece


#endif //_TETRISPIECE_H_
