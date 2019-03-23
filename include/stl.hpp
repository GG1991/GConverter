
#ifndef STL_HPP
#define STL_HPP

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

struct stl_tri_ {

	double v[9];
	double n[3];

	stl_tri_()
	{
		memset(v, 0.0, 9 * sizeof(double));
		memset(n, 0.0, 3 * sizeof(double));
	}

	stl_tri_(const double _v[9], const double _n[3])
	{
		memcpy(v, _v, 9 * sizeof(double));
		memcpy(n, _n, 3 * sizeof(double));
	}

	void write_ascii(fstream& _fio);
};

typedef struct stl_tri_ stl_tri;

#endif
