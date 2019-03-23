
#ifndef OBJ_HPP
#define OBJ_HPP

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>

#define MAX_NVERT 10

using namespace std;

struct Vertex_ {

	double coord[3];

	Vertex_(const double _coord[3])
	{
		memcpy(coord, _coord, 3 * sizeof(double));
	};

};

typedef struct Vertex_ Vertex;

struct Face_ {

	vector<int> v;
	vector<int> vt;
	vector<int> vn;

	void add_v(int _v)
	{
		v.push_back(_v);
	};

	void add_vt(int _vt)
	{
		vt.push_back(_vt);
	};

	void add_vn(int _vn)
	{
		vn.push_back(_vn);
	};

	bool check(void)
	{
		if (v.size() < 3) {
			cout << "Face with less than 3 vertices" << endl;
			return false;
		}
		if (vn.size() != 0 && vn.size() != v.size()) {
			cout << "Face with different vn than v" << endl;
			return false;
		}
		if (vt.size() != 0 && vt.size() != v.size()) {
			cout << "Face with different vt than v" << endl;
			return false;
		}
	};
};

typedef struct Face_ Face;

struct obj_geometry_ {

	int nvert;
	vector<Vertex> vertices;
	int nfaces;
	vector<Face> faces;

	void read_geo(const string& filename);

	void add_vertex(Vertex& _vertex)
	{
		vertices.push_back(_vertex);
	};

	void add_face(Face& _face)
	{
		faces.push_back(_face);
	};
	~obj_geometry_(void);
};

typedef struct obj_geometry_ obj_geometry;


#endif
