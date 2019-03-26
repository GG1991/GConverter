
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


void STL_triangle::write_binary(fstream& _fio)
{
	_fio.write((char*)(this), sizeof(STL_triangle));
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


void STL_geometry::write_binary(const string& filename)
{
	fstream fio;
	fio.open(filename, ios::out | ios::binary);

	char head[80];
	string header_info = "GConvert-output";
	strncpy(head, header_info.c_str(), sizeof(head) - 1);
	fio.write(head, sizeof(head));

	uint32_t Ntriangles = triangles.size();
	fio.write((char*)(&Ntriangles), sizeof(uint32_t));

	for(auto &it : triangles)
		it.write_binary(fio);

	fio.close();
}

float STL_geometry::calc_surface(void)
{
	float surface = 0.0;
	for(auto &it : triangles) {

		/* The surface of a triangle is the module of the cross product 
		 * of two of its sides represented by a vector divided by 2
		 */

		float *ptr_v = it.v;
		const float v1[3] = {
			ptr_v[1 * 3 + 0] - ptr_v[0 * 3 + 0],
			ptr_v[1 * 3 + 1] - ptr_v[0 * 3 + 1],
			ptr_v[1 * 3 + 2] - ptr_v[0 * 3 + 2]
		};

		const float v2[3] = {
			ptr_v[2 * 3 + 0] - ptr_v[0 * 3 + 0],
			ptr_v[2 * 3 + 1] - ptr_v[0 * 3 + 1],
			ptr_v[2 * 3 + 2] - ptr_v[0 * 3 + 2]
		};

		float v3[3];
		cross_product<float>(v1, v2, v3);
		surface += norm<float,3>(v3) / 2;

	}
	return surface;
}

void STL_geometry::calc_centroid(float _centroid[3])
{
	/* This is an easy way to get an internal point of the figure,
	 * for simple geometries works
	 */
	float centroid[3] = { 0.0 };
	for(auto &it : triangles) {
		for (int n = 0; n < 3; ++n)
			for (int d = 0; d < 3; ++d)
				centroid[d] += it.v[n * 3 + d];
	}
	for (int d = 0; d < 3; ++d)
		_centroid[d] = centroid[d] / (3 * triangles.size());
}


float STL_geometry::calc_volume(void)
{
	float volume = 0.0;

	float centroid[3];
	calc_centroid(centroid);

	for(auto &it : triangles) {

		float v1[3] = { it.v[0 * 3 + 0], it.v[0 * 3 + 1], it.v[0 * 3 + 2] };
		float v2[3] = { it.v[1 * 3 + 0], it.v[1 * 3 + 1], it.v[1 * 3 + 2] };
		float v3[3] = { it.v[2 * 3 + 0], it.v[2 * 3 + 1], it.v[2 * 3 + 2] };

		for (int d = 0; d < 3; ++d) {
			v1[d] -= centroid[d];
			v2[d] -= centroid[d];
			v3[d] -= centroid[d];
		}

		volume += (1. / 6.) * ( \
			 v1[0] * (v2[1] * v3[2] - v2[2] * v3[1]) + \
			 v1[1] * (v2[2] * v3[0] - v2[0] * v3[2]) + \
			 v1[2] * (v2[0] * v3[1] - v2[1] * v3[0])   \
			 );
	}

	return volume;
}


bool STL_geometry::is_point_inside(const float point[3])
{
	bool is_inside = true;

	float sign_0 = 0;

	for(vector<STL_triangle>::iterator it = triangles.begin(); it != triangles.end(); ++it) {

		float centroid_triangle[3] = { 0.0 };

		for (int i = 0; i < 3; ++i) {
			for (int d = 0; d < 3; ++d) {
				centroid_triangle[d] += it->v[i * 3 + d];
			}
		}
		for (int d = 0; d < 3; ++d)
			centroid_triangle[d] /= 3;

		float AB[3];
		for (int d = 0; d < 3; ++d)
			AB[d] = (point[d] - centroid_triangle[d]);

		float *normal = it->n;
		float sign = dot_product<float,3>(normal, AB);

		if (it == triangles.begin())
			sign_0 = sign;
		else
			is_inside &= (sign_0 * sign > 0);

	}

	return is_inside;
}
