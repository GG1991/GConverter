
#include "obj.hpp"

void OBJ_geometry::read_geo(const string& filename)
{
	nvert = 0;

	cout << "Reading Obj geometry :" << endl;

	fstream fio;
	string line;

	fio.open(filename, ios::in); 
	if (fio.fail()) {
		cout << "File : " << filename << " couldn't be opened" << endl;
	}

	cout << "Reading Vertices" << endl;

	cout << "Vertices : " << endl;
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
				cout << " " << coord[i];
			}
			Obj_Vertex vertex(coord);
			this->add_vertex(vertex);
			cout << endl;
			n++;
		}
	}

	cout << "NVertex : " << this->vertices.size() << endl;


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
						cout << b << " ";
					}
				}

				// parse vt (cannot be here)
				if(getline(ss, b, '/')) {
					if (b != "") {
						face.add_vt(stoi(b));
						cout << b << " ";
					}
				}

				// parse vn (cannot be here)
				if(getline(ss, b, '/')) {
					face.add_vn(stoi(b));
					cout << b << " ";
				}

			}

			face.check();
			this->add_face(face);
			cout << endl;
		}
	}
	cout << "Nfaces : " << this->faces.size() << endl;

	fio.close();
}

OBJ_geometry::~OBJ_geometry_(void)
{
}
