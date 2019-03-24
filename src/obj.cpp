
#include "obj.hpp"

void OBJ_geometry::read_geo(const string& filename)
{
	fstream fio;
	string line;

	fio.open(filename, ios::in); 
	if (fio.fail()) {
		cout << "File : " << filename << " couldn't be opened" << endl;
	}

	int n = 0;
	while (std::getline(fio, line))
	{
		std::istringstream iss(line);
		string etype;
		iss >> etype;
		double coord[3];

		if (etype == "v") {
			for (int i = 0; i < 3; ++i) {
				iss >> coord[i];
			}
			Obj_Vertex vertex(coord);
			this->add_vertex(vertex);
			n++;
		}
	}



	fio.clear();
	fio.seekg(0, ios::beg);

	while (getline(fio, line))
	{
		std::istringstream iss(line);
		string ftype, a, b;
		iss >> ftype;
		Obj_Face face;

		if (ftype == "f") {
			while (getline(iss, a, ' ')) {

				std::istringstream ss(a);

				// parse v
				if(getline(ss, b, '/')) {
					if (b != "") {
						face.add_v(stoi(b));
					}
				}

				// parse vt (cannot be here)
				if(getline(ss, b, '/')) {
					if (b != "") {
						face.add_vt(stoi(b));
					}
				}

				// parse vn (cannot be here)
				if(getline(ss, b, '/')) {
					face.add_vn(stoi(b));
				}

			}

			face.check();
			this->add_face(face);
		}
	}

	fio.close();
}

void OBJ_geometry::print(void)
{
	cout << "Nfaces : " << this->faces.size() << endl;
	cout << "NVertex : " << this->vertices.size() << endl;
	cout << "Vertices : " << endl;
	for(auto it = vertices.begin(); it != vertices.end(); ++it) {
		for (int d = 0; d < 3; ++d)
			cout << " " << it->coord[d];
		cout << endl;
	}
	cout << "Faces : " << endl;
	for(vector<Obj_Face>::iterator it = faces.begin(); it != faces.end(); ++it) {

		for (int i = 0; i < it->v.size(); ++i) {

			cout << " " << it->v[i];
		}
		cout << endl;
	}
}


int OBJ_geometry::translate(const double vector[3])
{
	for(auto it = vertices.begin(); it != vertices.end(); ++it) {
		for (int d = 0; d < 3; ++d)
			it->coord[d] += vector[d];
	}
	return 0;
}

int OBJ_geometry::rotate(const double angle, const int axis)
{
	double R[3][3];
	switch (axis) {
		case 0:
			R[0][0] =  1         ; R[0][1] =  0         ; R[0][2] =  0          ;
			R[1][0] =  0         ; R[1][1] =  cos(angle); R[1][2] =  -sin(angle);
			R[2][0] =  0         ; R[2][1] =  sin(angle); R[2][2] =   cos(angle);
			break;
		case 1:
			R[0][0] =  cos(angle); R[0][1] =  0         ; R[0][2] = -sin(angle);
			R[1][0] =  0         ; R[1][1] =  1         ; R[1][2] =  0         ;
			R[2][0] =  sin(angle); R[2][1] =  0         ; R[2][2] =  cos(angle);
			break;
		case 2:
			R[0][0] =  cos(angle); R[0][1] = -sin(angle); R[0][2] =  0         ;
			R[1][0] =  sin(angle); R[1][1] =  cos(angle); R[1][2] =  0         ;
			R[2][0] =  0         ; R[2][1] =  0         ; R[2][2] =  1         ;
			break;
		default:
			return 1;
	}

	for(auto it = vertices.begin(); it != vertices.end(); ++it) {

		double vector[3], vector_rotated[3];
		memcpy(vector, it->coord, 3 * sizeof(double));

		mvp<double, 3>(R, vector, vector_rotated);

		memcpy(it->coord, vector_rotated, 3 * sizeof(double));
	}
	return 0;
}


void OBJ_geometry::calc_centroid(double _centroid[3])
{
	/* This is an easy way to get an internal point of the figure,
	 * for simple geometries works
	 */
	double centroid[3] = { 0.0 };
	for(auto it = vertices.begin(); it != vertices.end(); ++it) {
		for (int d = 0; d < 3; ++d)
			centroid[d] += it->coord[d];
	}
	for (int d = 0; d < 3; ++d)
		_centroid[d] = centroid[d] / vertices.size();
}


bool Obj_Face::check(void)
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

void OBJ_geometry::add_vertex(Obj_Vertex& _vertex)
{
	vertices.push_back(_vertex);
};

void OBJ_geometry::add_face(Obj_Face& _face)
{
	faces.push_back(_face);
};

Obj_Vertex::Obj_Vertex_(const double _coord[3])
{
	memcpy(coord, _coord, 3 * sizeof(double));
};

void Obj_Face::add_v(int _v)
{
	v.push_back(_v);
};

void Obj_Face::add_vt(int _vt)
{
	vt.push_back(_vt);
};

void Obj_Face::add_vn(int _vn)
{
	vn.push_back(_vn);
};

OBJ_geometry::~OBJ_geometry_(void)
{
}
