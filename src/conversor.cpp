
#include "conversor.hpp"

STL_geometry Conversor::OBJ2STL(OBJ_geometry& _obj_geometry)
{
	STL_geometry stl_geometry;

	STL_triangle stl_triangle;
	
	for(vector<Face>::iterator it = _obj_geometry.faces.begin(); it != _obj_geometry.faces.end(); ++it) {
		
	}

	return stl_geometry;
}
