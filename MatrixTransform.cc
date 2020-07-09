#include <cstdlib>
#include <cmath>
#include "MatrixTransform.h"
#define DEFAULT_SIZE 2
using namespace std;

void MatrixTransform::setAngle(const int angle) {
	angle_ = angle;
}

void MatrixTransform::matrixTransform(int& x_tile, int& y_tile) {

	int temp = x_tile; //temp variable of old x_tile
	x_tile = transform[0][0] * x_tile + transform[0][1] * y_tile;
	y_tile = transform[1][0] * temp + transform[1][1] * y_tile;
	
}
