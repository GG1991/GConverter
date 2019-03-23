
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
