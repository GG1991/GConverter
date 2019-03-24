
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

	stl_geometry.write_ascii("output.stl");

	const double point_1[3] = { 1.0, 0.0, 0.0 };
	bool is_point_inside = stl_geometry.is_point_inside(point_1);

	cout << "The point : ";
	for (int i = 0; i < 3; ++i)
		cout << " " << point_1[i];

	cout << ((is_point_inside) ? " is inside." : " is outside.") << endl;

	return 0;
}
