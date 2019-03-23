
#include "obj.hpp"
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{

	if (argc < 2) {
		cout << "Error : Specify Obj filename as " << argv[0] << " <filename.obj>." << endl;
		exit(1);
	}
	string filename = argv[1];
	obj_vertices vertices(filename);

	return 0;
}
