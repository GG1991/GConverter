
#include <iostream>
#include <string.h>
#include <fstream>
#include "gconversor.hpp"

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

	const double translate[3] = { 1.0, 0.25, -0.9 };
	obj.translate(translate);

	GConversor conversor;
	STL_geometry stl_geometry = conversor.OBJ2STL(obj);

	stl_geometry.write_ascii("output.stl");

	double centroid[3];
	stl_geometry.calc_centroid(centroid);
	cout << "Centroid :";
	for (int i = 0; i < 3; ++i)
		cout << " " << centroid[i];
	cout << endl;

	return 0;
}
