#include <iostream>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#include "TetrisAdmin.h"

#define MAX_ARGUMENT 2
using namespace std;

static TetrisAdmin admin;

int main(int argc, char** argv) {

	//Check if only 2 arguments
	if (argc < MAX_ARGUMENT) {
		cerr << "Error: Not enough arguments. Please rerun the program." << endl;
		return EXIT_FAILURE;
	} else if (argc > MAX_ARGUMENT) {
		cerr << "Error: Too many arguments. Please rerun the proram." << endl;
		return EXIT_FAILURE;
	}
	
	//Initialization
	int option;
	int nflag = 0;
	int fflag = 0;

	//Get the option
	while ((option = getopt(argc, argv, "nf")) != -1) {
		switch (option)  {
			case 'n':
				nflag = 1;
				break;
			case 'f':
				fflag = 1;
				break;
			case '?':
				cerr << "Sorry. The option -" << optopt << " is not available" << endl;
			        return EXIT_FAILURE;
			default:
				return EXIT_FAILURE;	
		}
	
	}

	//Play modes
	if (nflag) {
		admin.normalMode();
	} else if (fflag) {
		admin.flexMode();
	} 

	return EXIT_SUCCESS;
}
