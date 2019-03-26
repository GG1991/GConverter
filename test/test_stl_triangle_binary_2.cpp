#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class STL_triangle {

	public:
		float n[3];
		float v[9];
		uint16_t num = 0;

		STL_triangle(const float _v[9], const float _n[3])
		{
			memcpy(v, _v, 9 * sizeof(float));
			memcpy(n, _n, 3 * sizeof(float));
		}
};

int main(void)
{

	const float n1[] = { 0.0, 0.0, -1.0 };
	const float v1[] = {
		0.00000e0, 0.00000e0, 0.00000e0,
		1.00000e0, 0.00000e0, 0.00000e0,
		0.00000e0, 1.00000e0, 0.00000e0
	};
	STL_triangle tri1(v1, n1);

	const float n2[] = { 0.0, 0.0, -1.0 };
	const float v2[] = {
		0.00000e0, 0.00000e0, 0.00000e0,
		0.00000e0, 1.00000e0, 0.00000e0,
		-1.00000e0, 0.00000e0, 0.00000e0
	};
	STL_triangle tri2(v2, n2);

	fstream fio;

	char head[80];
	string header_info = "GConvert-output";
	strncpy(head, header_info.c_str(), sizeof(head) - 1);
	uint32_t Ntriangles = 2;

	/********/

	fio.open("test_1.stl", ios::out | ios::binary);
	fio.write(head, sizeof(head));
	fio.write((char*)(&Ntriangles), sizeof(uint32_t));

	fio.write((char*)(tri1.n), sizeof(tri1.n));
	fio.write((char*)(tri1.v), sizeof(tri1.v));
	fio.write((char*)&tri1.num, sizeof(tri1.num));
	fio.write((char*)(tri2.n), sizeof(tri2.n));
	fio.write((char*)(tri2.v), sizeof(tri2.v));
	fio.write((char*)&tri2.num, sizeof(tri2.num));

	fio.close();

	/********/

	fio.open("test_2.stl", ios::out | ios::binary);
	fio.write(head, sizeof(head));
	fio.write((char*)(&Ntriangles), sizeof(uint32_t));

	fio.write((char*)(&tri1), sizeof(tri1));
	fio.write((char*)(&tri2), sizeof(tri2));

	fio.close();

	return 0;
}
