
#include "gconversor.hpp"

STL_geometry GConversor::OBJ2STL(OBJ_geometry& _obj_geometry)
{
	STL_geometry stl_geometry;

	for(vector<Obj_Face>::iterator it = _obj_geometry.faces.begin(); it != _obj_geometry.faces.end(); ++it) {

		Obj_Face face = *it;

		for (int i = 0; i < face.v.size() - 2; ++i) {

			float stl_v[9];

			// The first node is the same for the triangles
			double *coord = _obj_geometry.vertices[face.v[0] - 1].coord;
			for (int d = 0; d < 3; ++d) {
				stl_v[0 * 3 + d] = (float)coord[d];
			}

			// The others two go in rotation
			for (int n = 1; n < 3; ++n) {
				double *coord = _obj_geometry.vertices[face.v[i + n] - 1].coord;
				for (int d = 0; d < 3; ++d) {
					stl_v[n * 3 + d] = (float)coord[d];
				}
			}

			const float v1[3] = {
				stl_v[1 * 3 + 0] - stl_v[0 * 3 + 0],
				stl_v[1 * 3 + 1] - stl_v[0 * 3 + 1],
				stl_v[1 * 3 + 2] - stl_v[0 * 3 + 2]
			};

			const float v2[3] = {
				stl_v[2 * 3 + 0] - stl_v[0 * 3 + 0],
				stl_v[2 * 3 + 1] - stl_v[0 * 3 + 1],
				stl_v[2 * 3 + 2] - stl_v[0 * 3 + 2]
			};

			float stl_n[3];
			cross_product<float>(v1, v2, stl_n);

			STL_triangle stl_triangle (stl_v, stl_n);
			stl_geometry.add_triangle(stl_triangle);
		}
	}
	cout << "Triangles added : " << stl_geometry.triangles.size() << endl;

	return stl_geometry;
}
