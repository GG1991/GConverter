
#ifndef GCONVERSOR_HPP
#define GCONVERSOR_HPP

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include "obj.hpp"
#include "stl.hpp"
#include "utils.hpp"

using namespace std;

class GConversor {

	public:
		STL_geometry OBJ2STL(OBJ_geometry& _obj_geometry);
};

#endif
