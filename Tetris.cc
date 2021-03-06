#include "Tetris.h"
using namespace sf;
using namespace std;

/*Tetris Game Administrator
 *Argument: int argc and char** argv
 *Return: void
 */
void Tetris::play(){

	//Set up framework for the game
	RenderWindow gameWindow(VideoMode(WIDTH, HEIGHT), "Tetris Game!");
	
	//Creating tetris field
	Field field(WIDTH, HEIGHT);

	//Load a sprite to display
	Texture texture;
	if (!texture.loadFromFile("images/tiles.png")) {
		cerr << "Images is not loadable" << endl;
	}
	
	Sprite sprite(texture); //calling the Sprite constructor

		
	//Construct pieceArray
	pieceArrayConstruction(pieceArray);

	//Start the clock
	Clock clock; 
	double timer = 0.0;

	//Control the entire game
	while (gameWindow.isOpen()) {

			
	
		//Find the time elapsed 
		double timeElapsed = clock.getElapsedTime().asSeconds();
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
					if (!(field.hasPieceReachedBoundsOrOtherPiece(pieceArray, &control, control.get_piece(), NUMTILES, 
									  control.get_dx(), control.get_dy(), Stringizing(ROTATE)))) {
						control.set_rotate(true);
					}
				}
				
				//<--BOUNDS CHECKING-->
				//Update dx if pressed left
				else if (e.key.code == Keyboard::Left) {
					if (!(field.hasPieceReachedBoundsOrOtherPiece(pieceArray, &control, control.get_piece(), NUMTILES,
									  control.get_dx(), control.get_dy(), Stringizing(LEFT)))) {
						control.set_dx(control.get_dx() - 1);
					}
				}

				//Update dx if pressed right
				else if (e.key.code == Keyboard::Right) {
					if (!(field.hasPieceReachedBoundsOrOtherPiece(pieceArray, &control, control.get_piece(), NUMTILES, 
									  control.get_dx(), control.get_dy(), Stringizing(RIGHT)))) {
						control.set_dx(control.get_dx() + 1);
					}
				}

					
			} 
		}
		
		//Speed up if pressing down
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			control.set_delay(0.05);
		}
		
		//Tick the piece
		if (timer > control.get_delay()) {
			if (!field.hasPieceReachedBottomOrOtherPiece(pieceArray, &control, control.get_piece(), 
								      NUMTILES, control.get_dx(), control.get_dy())) { 
				control.set_dy(control.get_dy() + 1);
			} else {
				if (!field.checkLoss()) {
					//Make the piece stick to the field
					field.stick_piece(pieceArray, control.get_piece(), control.get_color(), 
							  NUMTILES, control.get_dx(), control.get_dy());
						
					//Set up new piece	
					control.set_piece();
					control.set_color();
					control.set_dx(rand() % ((WIDTH / SIZE) - SIZE));
					control.set_dy(0);
					control.set_rotate(false);
				}
			}
			timer = 0.0;
		} 
	
		//Reset to default delay
		control.set_delay(control.get_default_delay());

		//Clear the screen
		gameWindow.clear(Color::White);
		
		//Check and eliminate lines if necessary
		field.checkLines(&control);

		//Draw the field
		for (int i = 0; i < HEIGHT / SIZE; i++) { //ROW
			for (int j = 0; j < WIDTH / SIZE; j++) { //COLUMN
				int pieceColor = field.getFieldMatrix(i, j);
				if (pieceColor == -1){
					continue;
				}
				sprite.setTextureRect(IntRect(SIZE * pieceColor, 0, SIZE, SIZE));
				sprite.setPosition(j * SIZE, i * SIZE);
				gameWindow.draw(sprite);
			}
		}

		//Check for losing
		if (!(field.checkLoss())) {

			//Displaying the sprite of the pieces	
			for (int i = 0; i < NUMTILES; i++) {
				int x_tile = ((*(pieceArray + control.get_piece())).getTile(i)).get_x();
				int y_tile = ((*(pieceArray + control.get_piece())).getTile(i)).get_y();
				if (control.get_rotate()) {
					control.updateRotation(x_tile, y_tile, control.get_piece(), i, pieceArray, true);
				}	
				
				sprite.setTextureRect(IntRect(SIZE * control.get_color(), 0, SIZE, SIZE)); //extract only a rectangle of the sprite			
				sprite.setPosition((x_tile + control.get_dx()) * SIZE, (y_tile + control.get_dy()) * SIZE);
				gameWindow.draw(sprite); //Draw the sprite
			}

			//Set rotate to default
			//Stop the rotate when done
			control.set_rotate(false);
		}		
		
		//Update the window
		gameWindow.display();

	}
	
}	

//Learn how to customize assert function
//Write a method that prints out the current pieceArray

void Tetris::pieceArrayConstruction(TetrisPiece* const pieceArray) {
	
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
