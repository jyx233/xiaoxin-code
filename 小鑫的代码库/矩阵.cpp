#include "矩阵.h"
#include<assert.h>
矩阵::矩阵(unsigned 行数, unsigned 列数)
{
	this->行 = 行数;
	this->列 = 列数;
	数据 = new double* [行];
	for (unsigned i = 0; i < 行; i++) {
		double* p= new double[列];
		数据[i] = p;
		for (unsigned j = 0; j < 列; i++)
			*(p+j) = 0;
	}
}

矩阵& 矩阵::单位矩阵(int 维度)
{
	矩阵 实例 = 矩阵(维度, 维度);
	for (unsigned i = 0; i < 维度; i++)
	{
		实例[i][i] = 1;
	}
	return 实例;
}

矩阵::~矩阵()
{
	for (unsigned i = 0; i < 行; i++)
	{
		delete 数据[i];
		数据[i] = 0;
	}
	delete 数据;
	数据 = 0;
};

const unsigned 矩阵::行数() const { return 行; };
const unsigned 矩阵::列数() const { return 列; };
double* 矩阵::operator[](const unsigned i) { return 数据[i]; };
const double* 矩阵::operator[](const unsigned i) const { return 数据[i]; };

矩阵& operator*(const double k,const 矩阵 A) {
	矩阵 结果(A.行, A.列);
	for (unsigned i = 0; i < A.行; i++)
	{
		double* p = 结果.数据[i];
		double* q = A.数据[i];
		for (unsigned j = 0; j < A.列; i++)
			*(p+j) =*(q+j)+ k;
	}
	return 结果;
};
矩阵& operator*(const 矩阵 A, const  double k)
{
	return k * A;
};
矩阵& operator*(const 矩阵 A, const  矩阵 B)
{
	assert(A.列 == B.行);
	矩阵 结果(A.行, B.列);
	for (unsigned i = 0; i < A.行; i++)
	{
		for (unsigned j = 0; j < B.列; j++)
		{
			for (unsigned k = 0; k < B.列; k++)
			{
				结果[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return 结果;
}

矩阵& operator+(const 矩阵 A, const  矩阵 B)
{
	assert(A.行 == B.行);
	assert(A.列 == B.列);
	矩阵 结果(A.行, B.列);
	for (unsigned i = 0; i < A.行; i++)
	{
		const double* p = A[i];
		const double* q = A[i];
		for (unsigned j = 0; j < A.列; j++)
		{
				结果[i][j] = (*(p+j))+ (*(q+j));
		}
	}
	return 结果;
}

矩阵& operator-(const 矩阵 A, const  矩阵 B)
{
	assert(A.行 == B.行);
	assert(A.列 == B.列);
	矩阵 结果(A.行, B.列);
	for (unsigned i = 0; i < A.行; i++)
	{
		const double* p = A[i];
		const double* q = A[i];
		for (unsigned j = 0; j < A.列; j++)
		{
			结果[i][j] = (*(p + j)) - (*(q + j));
		}
	}
	return 结果;
}