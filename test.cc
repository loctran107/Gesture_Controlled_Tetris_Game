#include <iostream>
#include <cstdlib>

using namespace std;
void reference(int& a, int& b) {
	
	a++;
	b++;
}

int main(int argc, char** argv) {
	int x = 1;
	int y = 2;
	int& a = x;
	int& b = y;
	reference(a, b);
	cout << "x is " << x << endl;
	cout << "y is " << y << endl;
	return EXIT_SUCCESS;
}
