#include <cstdlib>
#include "PieceController.h"

extern int LENGTH;
extern int WIDTH;

using namespace std;
void PieceController::set_dx(const int dx) {
	dx_ = dx;
}

void PieceController::set_dy(const int dy) {
	dy_ = dy;
}

void PieceController::set_rotate(const bool rotate) {
	rotate_ = rotate;
}

void PieceController::set_color(const int color) {
	color_ = color;
}

bool PieceController::hasReachedBottom(const int dy) {
	return (dy * 32 > LENGTH);
}
