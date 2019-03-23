
#include "obj.hpp"

void obj_geometry::read_geo(const string& filename)
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

	while (std::getline(fio, line))
	{
		std::istringstream iss(line);
		string etype;
		iss >> etype;
		if (etype == "v") {
			nvert++;
		}
	} 

	fio.clear();
	fio.seekg(0, ios::beg);

	cout << "Nvert : " << nvert << endl;
	coord = (double *)malloc(3 * nvert * sizeof(double));
		
	cout << "Vertices : " << endl;
	int n = 0;
	while (std::getline(fio, line))
	{
		std::istringstream iss(line);
		string etype;
		iss >> etype;

		if (etype == "v") {
			for (int i = 0; i < 3; ++i) {
				iss >> coord[3 * n + i];
				cout << " " << coord[3 * n + i];
			}
			cout << endl;
			n++;
		}
	}

	fio.clear();
	fio.seekg(0, ios::beg);


	cout << "Reading Faces" << endl;
	nfaces = 0;

	while (std::getline(fio, line))
	{
		std::istringstream iss(line);
		string ftype;
		iss >> ftype;
		if (ftype == "f") nfaces++;
	} 

	cout << "Nfaces : " << nfaces << endl;

	fio.clear();
	fio.seekg(0, ios::beg);

	while (std::getline(fio, line))
	{
		std::istringstream iss(line);
		string ftype, a, b;
		iss >> ftype;

		if (ftype == "f") {
			while (getline(iss, a, ' ')) {
				std::istringstream ss(a);
				while (getline(ss, b, '/')) {
					cout << b << " ";
				}
			}
			cout << endl;
		}
	}

	fio.close();
}

obj_geometry::~obj_geometry_(void)
{
	free(coord);
}
