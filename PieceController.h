#ifndef _PIECECONTROLLER_H_
#define _PIECECONTROLLER_H_
#include <cstdlib>

class PieceController {
	
	public:
		PieceController() : dx_(0), rotate_(false), color_(1) { }
		PieceController(int dx, bool rotate, int color) : dx_(dx), rotate_(rotate), color_(color) { }
		
		//Accessor
		int get_dx() { return dx_; }
		bool get_rotate() { return rotate_; }
		int get_color() { return color_; }
		
		//Mutator
		void set_dx(const int dx);
		void set_rotate(const bool rotate);
		void set_color(const int color);

	private:
		int dx_; //changes in x
		bool rotate_;
		int color_; //1-7


}; //class PieceController
#endif //_PIECECONTROLLER_H_
