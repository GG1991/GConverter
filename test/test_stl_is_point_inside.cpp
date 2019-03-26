
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

	GConversor conversor;
	STL_geometry stl_geometry = conversor.OBJ2STL(obj);

	stl_geometry.write_ascii("output.stl");

	bool is_point_inside;

	const float point_1[3] = { 1.0, 0.0, 0.0 };
	is_point_inside = stl_geometry.is_point_inside(point_1);

	cout << "The point : ";
	for (int i = 0; i < 3; ++i)
		cout << " " << point_1[i];

	cout << ((is_point_inside) ? " is inside." : " is outside.") << endl;

	const float point_2[3] = { 0.0, 0.0, 0.0 };
	is_point_inside = stl_geometry.is_point_inside(point_2);

	cout << "The point : ";
	for (int i = 0; i < 3; ++i)
		cout << " " << point_2[i];

	cout << ((is_point_inside) ? " is inside." : " is outside.") << endl;

	const float point_3[3] = { 0.5, 0.0, 0.0 };
	is_point_inside = stl_geometry.is_point_inside(point_3);

	cout << "The point : ";
	for (int i = 0; i < 3; ++i)
		cout << " " << point_3[i];

	cout << ((is_point_inside) ? " is inside." : " is outside.") << endl;

	const float point_4[3] = { 0.499, 0.0, 0.0 };
	is_point_inside = stl_geometry.is_point_inside(point_4);

	cout << "The point : ";
	for (int i = 0; i < 3; ++i)
		cout << " " << point_4[i];

	cout << ((is_point_inside) ? " is inside." : " is outside.") << endl;

	const float point_5[3] = { 0.499, -0.499, -0.499 };
	is_point_inside = stl_geometry.is_point_inside(point_5);

	cout << "The point : ";
	for (int i = 0; i < 3; ++i)
		cout << " " << point_5[i];

	cout << ((is_point_inside) ? " is inside." : " is outside.") << endl;

	const float point_6[3] = { 0.499, -0.499, -0.5001 };
	is_point_inside = stl_geometry.is_point_inside(point_6);

	cout << "The point : ";
	for (int i = 0; i < 3; ++i)
		cout << " " << point_6[i];

	cout << ((is_point_inside) ? " is inside." : " is outside.") << endl;

	return 0;
}
