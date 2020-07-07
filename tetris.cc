//Author: Donavan Tran
/*Tetris program controlled using keyboard or using flex sensor
 *Verion 1.1
 */

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>

#include "TetrisPiece.h"
#define LENGTH 20
#define WIDTH 10

//global field. Declare static for internal linkage only
static int field[LENGTH][WIDTH] = { 0 };

//Declare array of different 
const int pieces[7][4] =
{
	3, 5, 7, 6, //J
	1, 3, 5, 7, //I
	2, 3, 5, 7, //L
	2, 3, 4, 5, //O
	3, 5, 4, 6, //S
	3, 5, 4, 7, //T
	2, 4, 5, 7, //Z
}; 

using namespace sf;
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
		
		//Draw the sprite
		gameWindow.draw(sprite);

		//Update the window
		gameWindow.display();

	}
	
	return EXIT_SUCCESS;
}	


