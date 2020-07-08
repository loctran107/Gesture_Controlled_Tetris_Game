//Author: Donavan Tran
/*Tetris program controlled using keyboard or using flex sensor
 */

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>

#include "TetrisPiece.h"
#include "PieceController.h"
#define LENGTH 20
#define WIDTH 10
#define NUMPIECE 7
#define NUMTILES 4
#define SIZE 27
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
void updateMovement();

/*Argument: array of tetris pieces from the main method
 *Return: void
 */
void pieceArrayConstruction(TetrisPiece* pieceArray);

/*Tetris Game Administrator
 *Argument: int argc and char** argv
 *Return: void
 */
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
				
				//Update dx if pressed left
				else if (e.key.code == Keyboard::Left) {
					control.set_dx(control.get_dx() - 1);
				}

				//Update dx if pressed right
				else if (e.key.code == Keyboard::Right) {
					control.set_dx(control.get_dx() + 1);
				}
				
				
			}
		}
	
		//updateMovement();
	 		
		//Clear the screen
		gameWindow.clear(Color::White);
		
		//Displaying sprite of the pieces
		int piece = 2;
		for (int i = 0; i < NUMTILES; i++) {
			int x_tile = (*(pieceArray + piece)).getTile(i) % 2;
		        int y_tile = (*(pieceArray + piece)).getTile(i) / 2;
			sprite.setPosition((x_tile + control.get_dx())  * SIZE, y_tile * SIZE);
			gameWindow.draw(sprite); //Draw the sprite
		}	

		//Update the window
		gameWindow.display();

	}
	
	return EXIT_SUCCESS;
}	

void updateMovement() {
	
}


void pieceArrayConstruction(TetrisPiece* const pieceArray) {
	
	//I piece
	(*pieceArray).setTile(1, 3, 5, 7);
	//Z piece
	(*(pieceArray + 1)).setTile(2, 4, 5, 7);
	//S piece
	(*(pieceArray + 2)).setTile(3, 5, 4, 6);
	//T piece
	(*(pieceArray + 3)).setTile(3, 5, 4, 7);
	//L piece
	(*(pieceArray + 4)).setTile(2, 3, 5, 7);
	//J piece
	(*(pieceArray + 5)).setTile(3, 5, 7, 6);
	//O piece
	(*(pieceArray + 6)).setTile(2, 3, 4, 5);
}
