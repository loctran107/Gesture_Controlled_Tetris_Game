#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
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
	sleep(5);
	cout << "y is " << y << endl;
	return EXIT_SUCCESS;
}
