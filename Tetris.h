#ifndef _TETRIS_H_
#define _TETRIS_H_

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>

#include "TetrisPiece.h"
#include "PieceController.h"
#include "PointTile.h"
#include "Field.h"

#define Stringizing( x ) #x
#define SIZE 27
#define NUMPIECE 7
#define NUMTILES 4
#define CENTER_OF_ROTATION 1
#define ROW 24
#define COLUMN 14

using namespace std;

class Tetris {
	public:
		Tetris() : WIDTH(378), HEIGHT(648) {} //Constructor
		void play(); //play the game in normal mode
	
	private:
		//Methods
		void pieceArrayConstruction(TetrisPiece* const pieceArray);

		//Fields
		TetrisPiece pieceArray[NUMPIECE];
		PieceController control;
		int WIDTH;
		int HEIGHT;

}; //class Tetris

#endif //_TETRIS_H_
