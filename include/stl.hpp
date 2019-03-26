
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
		float v[9];
		float n[3];

		STL_triangle()
		{
			memset(v, 0.0, 9 * sizeof(float));
			memset(n, 0.0, 3 * sizeof(float));
		}

		STL_triangle(const float _v[9], const float _n[3])
		{
			memcpy(v, _v, 9 * sizeof(float));
			memcpy(n, _n, 3 * sizeof(float));
		}

		void write_ascii(fstream& _fio);
		void write_binary(fstream& _fio);
};

class STL_geometry {

	public:
		vector<STL_triangle> triangles;

		void add_triangle(STL_triangle _stl_triangle);
		void write_ascii(const string& filename);
		void write_binary(const string& filename);

		void calc_centroid(float centroid[3]);
		float calc_surface(void);
		float calc_volume(void);
		bool is_point_inside(const float point[3]);
};


#endif
