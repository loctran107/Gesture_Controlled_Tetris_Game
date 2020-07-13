#ifndef _PIECECONTROLLER_H_
#define _PIECECONTROLLER_H_
#include <cstdlib>
#include "PointTile.h"
#include "TetrisPiece.h"


class PieceController {
	
	public:
		PieceController() : dx_(0), dy_(0), rotate_(false), color_(1), piece_(0), delay_(0.3), default_delay_(0.3) { }
		PieceController(int dx, int dy, bool rotate, int color) : dx_(dx), dy_(dy), rotate_(rotate), color_(color) { }
		
		//Accessor
		int get_dx() { return dx_; }
		int get_dy() { return dy_; }
		bool get_rotate() { return rotate_; }
		int get_color() { return color_; }
		int get_piece() { return piece_; }
		double get_delay() { return delay_; }
		double get_default_delay() { return default_delay_; }

		//Mutator
		void set_dx(const int dx);
		void set_dy(const int dy);
		void set_rotate(const bool rotate);
		void set_delay(const double delay);
		void set_color();
		void set_piece();
		void set_default_delay(const double default_delay);

		//Update Rotation
		void updateRotation(int& x_tile, int& y_tile, const int piece, const int tileIndex,
			       	    TetrisPiece* const tetrisPiece, const bool updateOrNot);	
		//Change the piece
		
	private:
		int dx_; //changes in x
		int dy_; //changes in y
		bool rotate_;
		int color_; //1-7
		int piece_;
	        double delay_;
		double default_delay_;
		


}; //class PieceController
#endif //_PIECECONTROLLER_H_
