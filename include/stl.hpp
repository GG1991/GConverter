
#ifndef STL_HPP
#define STL_HPP

#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include "utils.hpp"

using namespace std;

class STL_triangle {

	public:
		double v[9];
		double n[3];

		STL_triangle()
		{
			memset(v, 0.0, 9 * sizeof(double));
			memset(n, 0.0, 3 * sizeof(double));
		}

		STL_triangle(const double _v[9], const double _n[3])
		{
			memcpy(v, _v, 9 * sizeof(double));
			memcpy(n, _n, 3 * sizeof(double));
		}

		void write_ascii(fstream& _fio);
};

class STL_geometry {

	public:
		vector<STL_triangle> triangles;

		void add_triangle(STL_triangle _stl_triangle);
		void write_ascii(const string& filename);

		void calc_centroid(double centroid[3]);
		double calc_surface(void);
		double calc_volume(void);
		bool is_point_inside(const double point[3]);
};


#endif
