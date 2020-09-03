#include "矩阵.h"
#include<assert.h>
#include<iostream>
矩阵::矩阵()
{
	this->行 = 0;
	this->列 = 0;
	数据 = 0;
}

矩阵::矩阵(unsigned 行数, unsigned 列数)
{
	this->行 = 行数;
	this->列 = 列数;
	数据 = new double* [行];
	for (unsigned i = 0; i < 行; i++) {
		数据[i] = new double[列];
		for (unsigned j = 0; j < 列; i++)
			数据[i][j] = 0;
	}
}

矩阵& 矩阵::单位矩阵(unsigned 维度)
{
	矩阵 实例 = 矩阵(维度, 维度);
	for (unsigned i = 0; i < 维度; i++)
	{
		实例.数据[i][i] = 1;
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
		for (unsigned j = 0; j < A.列; i++)
			结果.数据[i][j] = A.数据[i][j]* k;
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
				结果[i][j] += A.数据[i][k] * B.数据[k][j];
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
		for (unsigned j = 0; j < A.列; j++)
		{
				结果[i][j] = A.数据[i] [j]+ B.数据[i][j];
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
		for (unsigned j = 0; j < A.列; j++)
		{
			结果[i][j] = A.数据[i][j] - B.数据[i][j];
		}
	}
	return 结果;
}

void 矩阵::初等行变换_乘(unsigned n, double k)
{
	assert(n < 行);
	double* p = 数据[n];
	for (unsigned i = 0; i < 列; i++)
		p[i] *= k;
}
void 矩阵::初等行变换_交换(unsigned a, unsigned b)
{
	assert(a < 行&&b<行);
	double temp;
	for (unsigned i = 0; i < 列; i++)
	{
		temp = 数据[a][i];
		数据[a][i] = 数据[b][i];
		数据[b][i] = temp;
	}
}

void 矩阵::初等行变换_消去(unsigned a, double k, unsigned b)
{
	assert(a < 行&& b < 行);
	for (unsigned i = 0; i < 列; i++)
	{
		数据[b][i] += 数据[a][i]*k;
	}
}
矩阵 矩阵::转置()
{
	矩阵 结果(列,行);
	for (unsigned i = 0; i < 行; i++)
	{
		for (size_t j = 0; j < 列; j++)
		{
			结果.数据[j][i] = 数据[i][j];
		}
	}
	return 结果;
}