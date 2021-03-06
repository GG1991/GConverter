
#include "stl.hpp"
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

int main(void)
{

	const float n1[] = { 0.0, 0.0, -1.0 };
	const float v1[] = {
		3.10000e+1, 4.15500e+1, 1.00000e+0,
		3.10000e+1, 1.00000e+1, 1.00000e+0,
		1.00000e+0, 2.50000e-1, 1.00000e+0
	};
	STL_triangle tri1(v1, n1);

	const float n2[] = { 0.0, 0.0, -1.0 };
	const float v2[] = {
		3.10000e+001, 4.15500e+001, 1.00000e+000,
		6.10000e+001, 2.50000e-001, 1.00000e+000,
		3.10000e+001, 1.00000e+001, 1.00000e+000
	};
	STL_triangle tri2(v2, n2);

	fstream fio;
	fio.open("sample.stl", ios::out); 
	fio << "solid sample" << endl;  

	tri1.write_ascii(fio);
	tri2.write_ascii(fio);

	fio << "endsolid sample" << endl;  
	fio.close(); 

	return 0;
}
