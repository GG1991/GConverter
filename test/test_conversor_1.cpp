
#include <iostream>
#include <string.h>
#include <fstream>
#include "conversor.hpp"

using namespace std;

int main(int argc, char *argv[])
{

	if (argc < 2) {
		cout << "Error : Specify Obj filename as " << argv[0] << " <filename.obj>." << endl;
		exit(1);
	}
	string filename = argv[1];

	OBJ_geometry obj;
	obj.read_geo(filename);

	Conversor conversor;
	STL_geometry stl_geometry = conversor.OBJ2STL(obj);

	return 0;
}
