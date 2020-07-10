
#include <cstdlib>
#include <iostream>
#include <string.h>

#define stringer( x ) #x

using namespace std;

void process(string s) {
	
	if (strcmp(s, "ROTATE") == 0) {
		cout << "I'm here" << endl;
	} else {
		cout << "I'm not here" << endl;
	}
	/*cout << "I'm here" << endl;
	cout << s << endl;
	cout << endl;*/
}
int main()
{
	process(stringer(ROTATE));
	return EXIT_SUCCESS;
}
