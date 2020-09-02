#include "矩阵.h"
矩阵::矩阵(unsigned 行数, unsigned 列数)
{
	this->行 = 行数;
	this->列 = 列数;
	数据 = new double* [行];
	for (int i = 0; i < 行; i++)
		数据[i] = new double[列];
	for (int i = 0; i < 行; i++)
		for (int j = 0; j < 列; i++)
			数据[i][j] = 0;
};
矩阵::~矩阵()
{
	for (int i = 0; i < 行; i++)
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
