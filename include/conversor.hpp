
#ifndef CONVERSOR_HPP
#define CONVERSOR_HPP

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

struct Conversor_ {

	STL_geometry OBJ2STL(OBJ_geometry& _obj_geometry);
};

typedef struct Conversor_ Conversor;

#endif
