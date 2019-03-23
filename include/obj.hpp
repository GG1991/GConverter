
#ifndef OBJ_HPP
#define OBJ_HPP

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;

struct Obj_Vertex_ {

	double coord[3];

	Obj_Vertex_(const double _coord[3])
	{
		memcpy(coord, _coord, 3 * sizeof(double));
	};

};

typedef struct Obj_Vertex_ Obj_Vertex;

struct Obj_Face_ {

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
			cout << "Obj_Face with less than 3 vertices" << endl;
			return false;
		}
		if (vn.size() != 0 && vn.size() != v.size()) {
			cout << "Obj_Face with different vn than v" << endl;
			return false;
		}
		if (vt.size() != 0 && vt.size() != v.size()) {
			cout << "Obj_Face with different vt than v" << endl;
			return false;
		}
	};
};

typedef struct Obj_Face_ Obj_Face;

struct OBJ_geometry_ {

	int nvert;
	vector<Obj_Vertex> vertices;
	int nfaces;
	vector<Obj_Face> faces;

	void read_geo(const string& filename);

	void add_vertex(Obj_Vertex& _vertex)
	{
		vertices.push_back(_vertex);
	};

	void add_face(Obj_Face& _face)
	{
		faces.push_back(_face);
	};

	~OBJ_geometry_(void);
};

typedef struct OBJ_geometry_ OBJ_geometry;


#endif
