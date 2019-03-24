
#ifndef OBJ_HPP
#define OBJ_HPP

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "utils.hpp"

using namespace std;

struct Obj_Vertex_ {

	double coord[3];

	Obj_Vertex_(const double _coord[3]);
};

typedef struct Obj_Vertex_ Obj_Vertex;

struct Obj_Face_ {

	vector<int> v;
	vector<int> vt;
	vector<int> vn;

	void add_v(int _v);
	void add_vt(int _vt);
	void add_vn(int _vn);
	bool check(void);
};

typedef struct Obj_Face_ Obj_Face;

struct OBJ_geometry_ {

	vector<Obj_Vertex> vertices;
	vector<Obj_Face> faces;

	void read_geo(const string& filename);
	void add_vertex(Obj_Vertex& _vertex);
	void add_face(Obj_Face& _face);

	void print(void);
	void write_ascii(const string& filename);

	void calc_centroid(double _centroid[3]);
	int translate(const double vector[3]);
	int scale(const double factor);
	int rotate(const double angle, const int axis);

	~OBJ_geometry_(void);
};

typedef struct OBJ_geometry_ OBJ_geometry;


#endif
