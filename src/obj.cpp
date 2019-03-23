
#include "obj.hpp"

obj_vertices::obj_vertices_(const string& filename)
{
	nvert = 0;

	cout << "Obj Vertices constructor :" << endl;

	fstream fio;
	string line;

	fio.open(filename, ios::in); 
	if (fio.fail()) {
		cout << "File : " << filename << " couldn't be opened" << endl;
	}

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

	fio.close(); 
}

obj_vertices::~obj_vertices_(void)
{
	free(coord);
}
