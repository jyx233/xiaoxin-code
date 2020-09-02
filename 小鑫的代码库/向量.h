#pragma once
#include "矩阵.h"
class 向量 :
    public 矩阵
{
public:
    enum 向量类型 {行向量,列向量} 类型;

    向量(unsigned n, 向量类型 类型=列向量);
};

