
#include "stl.hpp"

void STL_triangle::write_ascii(fstream& _fio)
{
	_fio << scientific << uppercase;
	_fio << "facet normal";  
	for (int d = 0; d < 3; ++d)
		_fio << " " << n[d];
	_fio << endl;  

	_fio << "    outerloop" << endl;  
	for (int i = 0; i < 3; ++i) {
		_fio << "        vertex";
		for (int d = 0; d < 3; ++d)
			_fio << " " << v[3 * i + d];
		_fio << endl;
	}  
	_fio << "    endloop" << endl;  
	_fio << "endfacet" << endl;  
}

void STL_geometry::add_triangle(STL_triangle _stl_triangle)
{
	triangles.push_back(_stl_triangle);
}

void STL_geometry::write_ascii(const string& filename)
{
	fstream fio;
	fio.open(filename, ios::out); 
	fio << "solid " << filename.substr(0, filename.size() - 4) << endl;  
	for(vector<STL_triangle>::iterator it = this->triangles.begin(); it != this->triangles.end(); ++it) {
		it->write_ascii(fio);
	}
	fio << "endsolid " << filename.substr(0, filename.size() - 4) << endl;  
	fio.close(); 
}
