//Author: Donavan Tran
/*Tetris program controlled using keyboard or using flex sensor
 */

//NO CHAINING OBJECTS, UNLESS INHERITANCE REQUIRED
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>


#include "TetrisPiece.h"
#include "PieceController.h"
#include "PointTile.h"
#include "Field.h"
 
#define Stringizing( x ) #x //stringizing definition
#define SIZE 27
#define NUMPIECE 7
#define NUMTILES 4
#define CENTER_OF_ROTATION 1
#define ROW 27
#define COLUMN 18
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

static int countArray = 1;
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

		
	//Construct pieceArray
	pieceArrayConstruction(pieceArray);

	//Start the clock
	Clock clock; 
	float timer = 0.0;

	//Control the entire game
	while (gameWindow.isOpen()) {

		sprite.setTextureRect(IntRect(SIZE * control.get_color(), 0, SIZE, SIZE)); //extract only a rectangle of the sprite			
		
		//Find the time elapsed 
		float timeElapsed = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += timeElapsed;
		
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
					if (!(field.hasPieceReachedBounds(pieceArray, &control, control.get_piece(), NUMTILES, 
									  control.get_dx(), Stringizing(ROTATE)))) {
						control.set_rotate(true);
					}
				}
				
				//<--BOUNDS CHECKING-->
				//Update dx if pressed left
				else if (e.key.code == Keyboard::Left) {
					if (!(field.hasPieceReachedBounds(pieceArray, &control, control.get_piece(), NUMTILES,
								          control.get_dx(), Stringizing(LEFT)))) {
						control.set_dx(control.get_dx() - 1);
					}
				}

				//Update dx if pressed right
				else if (e.key.code == Keyboard::Right) {
					if (!(field.hasPieceReachedBounds(pieceArray, &control, control.get_piece(), NUMTILES, 
									  control.get_dx(), Stringizing(RIGHT)))) {
						control.set_dx(control.get_dx() + 1);
					}
				}

				else if (e.key.code == Keyboard::Down) {
					control.set_delay(0.01);								
				}	
			} 
		}
	 	
		//Tick the piece
		if (timer > control.get_delay()) {
			if (!(field.hasPieceReachedBottom(pieceArray, &control, control.get_piece(), NUMTILES, control.get_dy()))) {
				control.set_dy(control.get_dy() + 1);
			} else {
				
				//Make the piece stick to the field
				field.stick_piece(pieceArray, control.get_piece(), NUMTILES, control.get_dx(), control.get_dy());
					
				//Set up new piece	
				control.set_piece();
				control.set_color();
				control.set_dx(rand() % ((WIDTH / SIZE) - SIZE));
				control.set_dy(0);
				control.set_rotate(false);
			}
			timer = 0.0;
		} 
		
		//Reset to default delay
		control.set_delay(0.3);

		//Clear the screen
		gameWindow.clear(Color::White);
	
		for (int i = 0; i < HEIGHT / SIZE; i++) { //ROW
			for (int j = 0; j < WIDTH / SIZE; j++) { //COLUMN
				PointTile p = field.get_pointTile(j, i);
				if (p.get_x() == -1 && p.get_y() == -1) {
					continue;
				}
				sprite.setPosition(p.get_x(), p.get_y());
				gameWindow.draw(sprite);
			}
		}

		//Displaying the sprite of the pieces	
		for (int i = 0; i < NUMTILES; i++) {
			int x_tile = ((*(pieceArray + control.get_piece())).getTile(i)).get_x();
		        int y_tile = ((*(pieceArray + control.get_piece())).getTile(i)).get_y();
			if (control.get_rotate()) {
				control.updateRotation(x_tile, y_tile, control.get_piece(), i, pieceArray, true);
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
