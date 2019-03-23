
#ifndef STL_HPP
#define STL_HPP

#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>

using namespace std;

struct STL_triangle_ {

	double v[9];
	double n[3];

	STL_triangle_()
	{
		memset(v, 0.0, 9 * sizeof(double));
		memset(n, 0.0, 3 * sizeof(double));
	}

	STL_triangle_(const double _v[9], const double _n[3])
	{
		memcpy(v, _v, 9 * sizeof(double));
		memcpy(n, _n, 3 * sizeof(double));
	}

	void write_ascii(fstream& _fio);
};

typedef struct STL_triangle_ STL_triangle;


struct STL_geometry_ {

	vector<STL_triangle> triangles;

	void add_triangle(STL_triangle _stl_triangle);

};

typedef struct STL_geometry_ STL_geometry;

#endif
