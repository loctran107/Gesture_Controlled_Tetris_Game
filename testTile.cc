#include <iostream>
#include <cstdlib>

#include "PointTile.h"

using namespace std;
int main(int argc, char** argv) {

	PointTile p1(1, 2);
	PointTile p2(2, 3);
	cout << "x_p1 is " << p1.get_x() << endl;
	cout << "y_p1 is " << p1.get_y() << endl;

	p1.set_x(34);
	p1.set_y(12);
	cout << "x_p1 after set is " << p1.get_x() << endl;
	cout << "y_p1 after set is " << p1.get_y() << endl;


}
