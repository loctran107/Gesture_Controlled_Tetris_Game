#include <cstdlib>
#include "PieceController.h"
#define CENTER_OF_ROTATION 1

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

void PieceController::updateRotation(int& x_tile, int& y_tile, const int piece, const int tileIndex,
	       			     TetrisPiece* const pieceArray, bool const updateOrNot) {

	//Extract tile that is at axis of rotation
	const int x_axisRotate = ((*(pieceArray + piece)).getTile(CENTER_OF_ROTATION)).get_x();
	const int y_axisRotate = ((*(pieceArray + piece)).getTile(CENTER_OF_ROTATION)).get_y();

	//Calculate relative coordinate of translation
	const int x_tile_trans = x_axisRotate - x_tile;
	const int y_tile_trans = y_axisRotate - y_tile;

	//Update the rotation
	x_tile = x_axisRotate - y_tile_trans;
	y_tile = y_axisRotate + x_tile_trans;

	if (updateOrNot) {
		//Update the tile
		PointTile p1(x_tile, y_tile);
		(*(pieceArray + piece)).setTileBasedIndex(tileIndex, p1);
	}

}
