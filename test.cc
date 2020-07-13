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
	float x = 1.0;
	int y = 2;
	
	int matrix[3][4] = { 0 };
	cout <<  x /y << endl;
	return EXIT_SUCCESS;
}
