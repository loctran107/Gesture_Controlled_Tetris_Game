//Author: Donavan Tran
/*Tetris program controlled using keyboard or using flex sensor
 */

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>

#include "TetrisPiece.h"
#include "PieceController.h"
#include "PointTile.h"

#define LENGTH 20
#define WIDTH 10
#define NUMPIECE 7
#define NUMTILES 4
#define SIZE 27
#define ANGLE 90
#define CENTER_OF_ROTATION 1
//global field. Declare static for internal linkage only
//static int field[LENGTH][WIDTH] = { 0 };

using namespace sf;
using namespace std;

//Define array of tetris pieces
static TetrisPiece pieceArray[NUMPIECE];
static PieceController control;

/*Argument: None
 *Return: void
 */
void updateRotation(int& x_tile, int& y_tile, const int piece, const int tileIndex);

/*Argument: array of tetris pieces from the main method
 *Return: void
 */
void pieceArrayConstruction(TetrisPiece* pieceArray);

void printArrayPiece(int piece);

/*Tetris Game Administrator
 *Argument: int argc and char** argv
 *Return: void
 */

static int countArray = 1;
int main(int argc, char** argv) {

	//Set up framework for the game
	RenderWindow gameWindow(VideoMode(480, 720), "Tetris Game!");

	//Load a sprite to display
	Texture texture;
	if (!texture.loadFromFile("tiles.png")) {
		return EXIT_FAILURE;
	}
	
	Sprite sprite(texture); //calling the Sprite constructor
	sprite.setTextureRect(IntRect(0, 0, 27, 27)); //extract only a rectangle of the sprite	
	
	
	
	//Construct pieceArray
	pieceArrayConstruction(pieceArray);
	
		
	//Control the entire game
	while (gameWindow.isOpen()) {
		
		//Process the event
		Event e;
		while (gameWindow.pollEvent(e)) {
			
			//Close window and exit
			if (e.type == Event::Closed) {
				gameWindow.close();
			}
			
			//Handle key pressed on keyboard mode
			if (e.type == Event::KeyPressed) {

				//Rotate if pressed UP
				if (e.key.code == Keyboard::Up) {
					control.set_rotate(true);
				}
				
				//<--BOUNDS CHECKING-->
				//Update dx if pressed left
				else if (e.key.code == Keyboard::Left) {
					if (control.get_dx() > 0) {
						control.set_dx(control.get_dx() - 1);
					}
				}

				//Update dx if pressed right
				else if (e.key.code == Keyboard::Right) {
					if (control.get_dx() < 480) {
						control.set_dx(control.get_dx() + 1);
					}
				}
					
			}
		}
	 			
		//Clear the screen
		gameWindow.clear(Color::White);
		
		//Displaying sprite of the pieces
		int piece = 3;
		
		for (int i = 0; i < NUMTILES; i++) {
			int x_tile = ((*(pieceArray + piece)).getTile(i)).get_x();
		        int y_tile = ((*(pieceArray + piece)).getTile(i)).get_y();
			 
			if (control.get_rotate()) {
				updateRotation(x_tile, y_tile, piece, i);
			}
					
			sprite.setPosition((x_tile + control.get_dx())  * SIZE, y_tile * SIZE);
			gameWindow.draw(sprite); //Draw the sprite
			
			
		}

			
		//Set rotate to default
		//Stop the rotate when done
		control.set_rotate(false);
		

		//Update the window
		gameWindow.display();

	}
	
	return EXIT_SUCCESS;
}	

//Learn how to customize assert function
//Write a method that prints out the current pieceArray
void printArrayPiece(int piece) {
	
	if (countArray) {
		for (int i = 0; i < NUMTILES; i++) {
			cout << endl;
			int x_tile = ((*(pieceArray + piece)).getTile(i)).get_x();
			int y_tile = ((*(pieceArray + piece)).getTile(i)).get_y();
			cout << "x tile of " << i << " is " << x_tile << endl;
			cout << "y tile of " << i << " is " << y_tile << endl;
			cout << endl;
		}
		countArray--;
	}

}


void updateRotation(int& x_tile, int& y_tile, const int piece, const int tileIndex) {
	
	//Extract tile that is at axis of rotation
	const int x_axisRotate = ((*(pieceArray + piece)).getTile(CENTER_OF_ROTATION)).get_x();
	const int y_axisRotate = ((*(pieceArray + piece)).getTile(CENTER_OF_ROTATION)).get_y();
	
	//Calculate relative coordinate of translation
	const int x_tile_trans = x_axisRotate - x_tile;
	const int y_tile_trans = y_axisRotate - y_tile;

	//update the rotation
	x_tile = x_axisRotate - y_tile_trans;
	y_tile = y_axisRotate + x_tile_trans;	

	//Update the tile	
	PointTile p1(x_tile, y_tile);
	(*(pieceArray + piece)).setTileBasedIndex(tileIndex, p1);
}


void pieceArrayConstruction(TetrisPiece* const pieceArray) {
	
	//List of points associated with each tile	
	PointTile tile_one(0, 0);
	PointTile tile_two(1, 0);
	PointTile tile_three(0, 1);
	PointTile tile_four(1, 1);
	PointTile tile_five(0, 2);
	PointTile tile_six(1, 2);
	PointTile tile_seven(0, 3);
	PointTile tile_eight(1, 3);

	//I piece (checked)
	(*pieceArray).setTile(tile_two, tile_four, tile_six, tile_eight);
	//Z piece (checked)
	(*(pieceArray + 1)).setTile(tile_three, tile_five, tile_six, tile_eight);
	//S piece 
	(*(pieceArray + 2)).setTile(tile_four, tile_six, tile_five, tile_seven);
	//T piece
	(*(pieceArray + 3)).setTile(tile_four, tile_six, tile_five, tile_eight);
	//L piece
	(*(pieceArray + 4)).setTile(tile_three, tile_four, tile_six, tile_eight);
	//J piece
	(*(pieceArray + 5)).setTile(tile_four, tile_six, tile_eight, tile_seven);
	//O piece
	(*(pieceArray + 6)).setTile(tile_three, tile_four, tile_five, tile_six);
}
