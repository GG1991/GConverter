
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

double STL_geometry::calc_surface(void)
{
	double surface = 0.0;
	for(vector<STL_triangle>::iterator it = this->triangles.begin(); it != this->triangles.end(); ++it) {

		/* The surface of a triangle is the module of the cross product 
		 * of two of its sides represented by a vector divided by 2
		 */

		double *ptr_v = it->v;
		const double v1[3] = {
			ptr_v[1 * 3 + 0] - ptr_v[0 * 3 + 0],
			ptr_v[1 * 3 + 1] - ptr_v[0 * 3 + 1],
			ptr_v[1 * 3 + 2] - ptr_v[0 * 3 + 2]
		};

		const double v2[3] = {
			ptr_v[2 * 3 + 0] - ptr_v[0 * 3 + 0],
			ptr_v[2 * 3 + 1] - ptr_v[0 * 3 + 1],
			ptr_v[2 * 3 + 2] - ptr_v[0 * 3 + 2]
		};

		double v3[3];
		cross_product<double>(v1, v2, v3);
		surface += norm<double,3>(v3) / 2;

	}
	return surface;
}


double STL_geometry::calc_volume(void)
{
	double volume;
	return volume;
}


bool STL_geometry::is_point_inside(const double point[3])
{
	bool is_inside;
	return is_inside;
}
