#include <iostream>
#include <cstdlib>

using namespace std;
void reference(int& a, int& b) {
	int temp = a;	
	a++;
	b++;
	cout << "Temp is " << temp << endl;
}

int main(int argc, char** argv) {
	int x = 1;
	int y = 2;
	reference(x, y);
	cout << "x is " << x << endl;
	cout << "y is " << y << endl;
	return EXIT_SUCCESS;
}
