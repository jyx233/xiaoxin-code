#include "LU分解.h"
#include <math.h>
#include <iostream>

列主元LU分解::列主元LU分解(矩阵 A)
{
	assert(A.列数() == A.行数());
	unsigned n = A.列数();
	P.设置数组容量(n);
	P.设置数组大小(n, -1);

	LU = A;
	int n = LU.列数(),k;
	double temp;

	for (unsigned i = 0; i < n - 1; i++) {
		unsigned r = i;
		for (unsigned j = i + 1; j < n; j++) {
			if (fabs(LU[j][i]) > fabs(LU[r][i]))
				r = j;
		}
		P[i] = r;
		if (i != r) {
			for (unsigned j = 0; j < n; j++) {
				temp = LU[i][j];
				LU[i][j] = LU[r][j]; 
				LU[r][j] = temp;
			}
		}
		if (!LU[i][i]) { std::cout << "矩阵不可逆"; exit(0); }
		for (unsigned j = i + 1; j < n; j++) {
			LU[j][i] = LU[j][i] / LU[i][i];
			for (k = i + 1; k < n; k++) {
				LU[j][k] = LU[j][k] - LU[j][i] * LU[i][k];
			}
		}
	}
}

double 列主元LU分解::行列式() const 
{
	double 结果 = 1;
	for (unsigned i = 1; i < LU.列数(); i++)
		结果 *= LU[i][i];
	return 结果;

}


向量 列主元LU分解::解方程(向量 X)const
{
	assert(X.行数() == LU.行数());
	int n = X.行数();
	向量 结果(n, 向量::列向量);

	double temp;
	int i = X.行数(), k, r;

	for (k = 0; k < i - 1; k++) {
		r = P[k];
		temp = 结果[k];
		结果[k] = 结果[r];
		结果[r] = temp;
	}

	for (unsigned i = 0; i < n; i++) {
		unsigned j;
		for (j = 0; j < i; j++) {
			结果[i] = 结果[i] - LU[i][j] * 结果[j];
		}
	}


	for (unsigned i = n - 1; i >= 0; i--) {
		unsigned j;
		for (j = i + 1; j < n; j++) {
			结果[i] = 结果[i] - LU[i][j] * 结果[j];
		}
		结果[i] = 结果[i] / LU[i][i];
	}

	return 结果;
}