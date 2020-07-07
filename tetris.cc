//Author: Donavan Tran
/*Tetris program controlled using keyboard or using flex sensor
 */

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>

#include "TetrisPiece.h"
#define LENGTH 20
#define WIDTH 10
#define NUMPIECE 7
#define NUMTILES 4
#define SIZE 27
//global field. Declare static for internal linkage only
//static int field[LENGTH][WIDTH] = { 0 };

using namespace sf;
using namespace std;

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
	
	//Define array of tetris pieces
	TetrisPiece pieceArray[NUMPIECE];
	
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
		}

		//Clear the screen
		gameWindow.clear(Color::White);
		
		//Displaying sprite of the pieces
		int piece = 2;
		for (int i = 0; i < NUMTILES; i++) {
			int x_tile = (*(pieceArray + piece)).getTile(i) % 2;
		        int y_tile = (*(pieceArray + piece)).getTile(i) / 2;
			sprite.setPosition(x_tile * SIZE, y_tile * SIZE);
			gameWindow.draw(sprite);
		}	

		//Draw the sprite
		gameWindow.draw(sprite);

		//Update the window
		gameWindow.display();

	}
	
	return EXIT_SUCCESS;
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
