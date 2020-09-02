#include "向量.h"
向量::向量(unsigned n, 向量类型 类型)
{
	this->类型 == 类型;
	if (类型 == 列向量) 
	{
		行 = n;
		列 = 1;
		数据 = new double* [行];
		for (unsigned i = 0; i < 行; i++) {
			double* p = new double;
			数据[i] = p;
			*p = 0;
		}
	}
	else
	{
		行 = 1;
		列 = n;
		double* p= new double[列];
		for (unsigned i = 0; i < 列; i++) {
			*(p+i)= 0;
		}
		数据 = &p;
	}
}