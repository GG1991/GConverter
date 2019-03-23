
#ifndef OBJ_HPP
#define OBJ_HPP

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <cstdlib>

#define MAX_NVERT 10

using namespace std;


struct obj_geometry_ {

	int nvert;
	double *coord = nullptr;
	int nfaces;

	void read_geo(const string& filename);
	~obj_geometry_(void);
};

typedef struct obj_geometry_ obj_geometry;


struct obj_face_ {

	int nverts;

	int v[MAX_NVERT];
	int vt[MAX_NVERT];
	int vn[MAX_NVERT];

	obj_face_()
	{
		nverts = 0;
		memset(v, 0.0, MAX_NVERT * sizeof(int));
		memset(vt, 0.0, MAX_NVERT * sizeof(int));
		memset(vn, 0.0, MAX_NVERT * sizeof(int));
	}

	obj_face_(int _nverts, const double _v[MAX_NVERT], const double _vt[MAX_NVERT], const double _vn[MAX_NVERT])
	{
		nverts = _nverts;
		memcpy(v, _v, MAX_NVERT * sizeof(double));
		memcpy(vt, _vt, MAX_NVERT * sizeof(double));
		memcpy(vn, _vn, MAX_NVERT * sizeof(double));
	}
};

typedef struct obj_face_ obj_face;

#endif
