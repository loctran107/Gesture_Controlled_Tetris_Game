//Author: Donavan Tran
/*Tetris program controlled using keyboard or using flex sensor
 *Verion 1.1
 */

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>

using namespace sf;
int main(int argc, char** argv) {

	//Set up framework for the game
	RenderWindow gameWindow(VideoMode(320, 480), "Tetris Game!");

	//Load a sprite to display
	Texture texture;
	if (!texture.loadFromFile("images/tiles.png")) {
		return EXIT_FAILURE;
	}
	
	Sprite sprite(texture); //calling the Sprite constructor
	
	
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


