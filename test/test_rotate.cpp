
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

	OBJ_geometry obj_1;
	obj_1.read_geo(filename);
	obj_1.print();

	double centroid[3];
	obj_1.calc_centroid(centroid);
	cout << "Centroid :";
	for (int i = 0; i < 3; ++i)
		cout << " " << centroid[i];
	cout << endl;

	double PI = 3.14;
	obj_1.rotate(PI / 4, 0);
	obj_1.print();

	obj_1.calc_centroid(centroid);
	cout << "Centroid :";
	for (int i = 0; i < 3; ++i)
		cout << " " << centroid[i];
	cout << endl;

	obj_1.write_ascii("test_rotate_out.obj");

	return 0;
}
