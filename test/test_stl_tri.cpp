#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

struct stl_tri_ {

	double v[9];
	double n[3];

	stl_tri_()
	{
		memset(v, 0.0, 9 * sizeof(double));
		memset(n, 0.0, 3 * sizeof(double));
	}

	stl_tri_(const double _v[9], const double _n[3])
	{
		memcpy(v, _v, 9 * sizeof(double));
		memcpy(n, _n, 3 * sizeof(double));
	}

	void write_ascii(fstream& _fio)
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
};

typedef struct stl_tri_ stl_tri;

int main(void)
{

	const double n1[] = { 0.0, 0.0, -1.0 };
	const double v1[] = {
		3.10000e+1, 4.15500e+1, 1.00000e+0,
		3.10000e+1, 1.00000e+1, 1.00000e+0,
		1.00000e+0, 2.50000e-1, 1.00000e+0,
	};
	stl_tri tri1(v1, n1);

	const double n2[] = { 0.0, 0.0, -1.0 };
	const double v2[] = {
		3.10000e+001, 4.15500e+001, 1.00000e+000,
		6.10000e+001, 2.50000e-001, 1.00000e+000,
		3.10000e+001, 1.00000e+001, 1.00000e+000
	};
	stl_tri tri2(v2, n2);

	fstream fio;
	fio.open("sample.stl", ios::out); 
	fio << "solid sample" << endl;  

	tri1.write_ascii(fio);
	tri2.write_ascii(fio);

	fio << "endsolid sample" << endl;  
	fio.close(); 

	return 0;
}
