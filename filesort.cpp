#include "InsertionSort.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 3) { //Confirm correct number of parameters.
		cerr << "Usage: " << argv[0] << " INPUTFILE OUTPUTFILE" << endl;
		return 1;
	}
	InsertionSort sort; //Create sort object.

	sort.filesort(argv[1], argv[2]); //Sort the file.

	return 0;
}
