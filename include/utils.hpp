
#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

using namespace std;

template<typename T>
inline void cross_product(const T v1[3], const T v2[3], T v3[3])
{
	v3[0] = v1[1] * v2[2] - v1[2] * v2[1];
	v3[1] = v1[2] * v2[0] - v1[0] * v2[2];
	v3[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

template<typename T,int size>
inline void mvp(const T A[size][size], const T vector[size], T result[size])
{
	for (int i = 0; i < size; ++i) {
		result[i] = 0;
		for (int j = 0; j < size; ++j) {
			result[i] += A[i][j] * vector[j];
		}
	}
}

#endif
