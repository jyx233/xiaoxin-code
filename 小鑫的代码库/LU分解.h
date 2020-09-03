#pragma once
#include "矩阵分解.h"
#include"数组.h"
/*
* 将矩阵分解为PLU的形式
* 其中P为置换矩阵,L为单位下三角矩阵,U为上三角矩阵
*/
class 列主元LU分解 :
    public 矩阵分解
{
public:
    列主元LU分解(矩阵 A);

    double 行列式()const;

    向量 解方程(向量 X)const;
private:
    矩阵 LU;
    数组<int> P; 
};

