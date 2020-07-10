//Author: Donavan Tran
/*Tetris program controlled using keyboard or using flex sensor
 */

//NO CHAINING OBJECTS, UNLESS INHERITANCE REQUIRED
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>
#include <unistd.h>


#include "TetrisPiece.h"
#include "PieceController.h"
#include "PointTile.h"
#include "Field.h"
 
#define Stringizing( x ) #x //stringizing definition
#define SIZE 27
#define NUMPIECE 7
#define NUMTILES 4
#define CENTER_OF_ROTATION 1
#define TIME_DELAY 0.4
//global field. Declare static for internal linkage only
//static int field[LENGTH][WIDTH] = { 0 };

using namespace sf;
using namespace std;

//Define gloval variable to all C file (external linkage)
int WIDTH = 486; //For tile size of 27
int HEIGHT = 729; //7 times of 27

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
	RenderWindow gameWindow(VideoMode(WIDTH, HEIGHT), "Tetris Game!");
	
	//Creating tetris field
	Field field(WIDTH, HEIGHT);

	//Load a sprite to display
	Texture texture;
	if (!texture.loadFromFile("tiles.png")) {
		return EXIT_FAILURE;
	}
	
		
	
	Sprite sprite(texture); //calling the Sprite constructor
	sprite.setTextureRect(IntRect(0, 0, 27, 27)); //extract only a rectangle of the sprite	
		
	//Construct pieceArray
	pieceArrayConstruction(pieceArray);

	//Start the clock
	Clock clock; 
	float timer = 0.0;

	//Control the entire game
	while (gameWindow.isOpen()) {
		
		//Find the time elapsed 
		float timeElapsed = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += timeElapsed;
		
		int piece = 1;
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
					//cout << "dx " << control.get_dx() << endl;
					if (!(field.hasPieceReachedBounds(pieceArray, &control, piece, NUMTILES, 
									  control.get_dx(), Stringizing(ROTATE)))) {
					//	cout << "I'm here" << endl;
						control.set_rotate(true);
					}
				}
				
				//<--BOUNDS CHECKING-->
				//Update dx if pressed left
				else if (e.key.code == Keyboard::Left) {
					//cout << control.get_dx() << endl;
					if (!(field.hasPieceReachedBounds(pieceArray, &control, piece, NUMTILES,
								          control.get_dx(), Stringizing(LEFT)))) {
						//cout << "Current: " << control.get_dx() << endl;
						control.set_dx(control.get_dx() - 1);
						//cout << "New: " << control.get_dx() << endl;
					}
				}

				//Update dx if pressed right
				else if (e.key.code == Keyboard::Right) {
					//cout << control.get_dx() << endl;
					if (!(field.hasPieceReachedBounds(pieceArray, &control, piece, NUMTILES, 
									  control.get_dx(), Stringizing(RIGHT)))) {
						//cout << "Current: " << control.get_dx() << endl;
						control.set_dx(control.get_dx() + 1);
						//cout << "New: " << control.get_dx() << endl;
					}
				}	
			}
		}
	 	
		//Tick the piece
		/*if (timer > TIME_DELAY) {
			if (!(field.hasPieceReachedBottom(pieceArray, piece, NUMTILES, control.get_dy()))) {
				control.set_dy(control.get_dy() + 1);
			}

			
			timer = 0.0;
		}*/
		
		//Clear the screen
		gameWindow.clear(Color::White);
	
	
		//Displaying the sprite of the pieces	
		for (int i = 0; i < NUMTILES; i++) {
			int x_tile = ((*(pieceArray + piece)).getTile(i)).get_x();
		        int y_tile = ((*(pieceArray + piece)).getTile(i)).get_y();
			 
			if (control.get_rotate()) {
				control.updateRotation(x_tile, y_tile, piece, i, pieceArray, true);
			}	
			
				
			sprite.setPosition((x_tile + control.get_dx()) * SIZE, (y_tile + control.get_dy()) * SIZE);
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

void pieceArrayConstruction(TetrisPiece* const pieceArray) {
	
	//List of pointTile associated with each tile	
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
