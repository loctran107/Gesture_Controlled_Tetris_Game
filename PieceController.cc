#include <cstdlib>

#include "PieceController.h"
using namespace std;

void PieceController::set_dx(const int dx) {
	dx_ = dx;
}

void PieceController::set_rotate(const bool rotate) {
	rotate_ = rotate;
}

void PieceController::set_color(const int color) {
	color_ = color;
}
