#ifndef _POINTTILE_H_
#define _POINTTILE_H_
#include <iostream>
#include <cstdlib>

class PointTile {
	
	public:
		PointTile() : x_(0), y_(0) { }
		PointTile(const int x_tile, const int y_tile) : x_(x_tile), y_(y_tile) { }
		int get_x() { return x_; } //accessor
		int get_y() { return y_; } //acessor
		void set_x(const int x_tile); //mutator
		void set_y(const int y_tile); //mutator

	private:
		int x_;
		int y_;

}; //class PointTile

#endif //_POINTTILE_H_
