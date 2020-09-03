#include "数组.h"
#include<assert.h>
template<class 元素类型>
数组<元素类型>::数组()
{
	元素数目 = 0;
	容量 = 10;
	数据 = new 元素类型[10];
}

template<class 元素类型>
数组<元素类型>::数组(unsigned n)
{
	元素数目 = n;
	容量 = 3 * n /2 > 20 ? 3 * n / 2 : 20;;
	数据 = new 元素类型[容量];
}

template<class 元素类型>
数组<元素类型>::数组(unsigned n, const  元素类型 默认值)
{
	元素数目 = n;
	容量 = 3 * n/2 >20 ?3*n/2:20;
	数据 = new 元素类型(默认值)[容量];
}

template<class 元素类型>
数组<元素类型>::数组(数组<元素类型> &另一个数组)
{
	容量 = 另一个数组.容量;
	元素数目 = 另一个数组.元素数目;
	数据 = new 元素类型[容量];
	for (int i = 0; i < 元素数目; i++)
		数据[i] = 另一个数组.数据[i];
}

template<class 元素类型>
void 数组<元素类型>::设置数组大小(unsigned n)
{
	if (n > 容量)
		this->设置数组容量(3 * n/2);
	元素数目 = n;
}

template<class 元素类型>
void 数组<元素类型>::设置数组大小(unsigned n, const 元素类型 默认值)
{
	if (n > 容量)
		this->设置数组容量(3 * n / 2);
	for (size_t i = 元素数目; i <n ; i++)
	{
		数据[i] = 默认值;
	}
	元素数目 = n;
}


template<class 元素类型>
void 数组<元素类型>::设置数组容量(unsigned n)
{
	元素类型* 新数组 = new 元素类型[n];
	for (size_t i = 0; i < 元素数目; i++)
	{
		新数组[i] = 数据[i];
	}
	delete 数据;
	数据 = 新数组;
}

template<class 元素类型>
void 数组<元素类型>::插入元素(unsigned n, const  元素类型 X)
{
	if (数组大小 == 容量)
		设置数组容量(2 * 容量);
	for (unsigned i = 数组大小; i > n; i--)
		数据[i] = 数据[i - 1];
	数据[n] = X;
	数组大小++;
}


template<class 元素类型>
void 数组<元素类型>::结尾添加元素(元素类型 X)
{
	if (元素数目 < 容量)
		设置数组容量(容量*2);
	数据[元素数目] = X;
	元素数目++;
}

template<class 元素类型>
元素类型  数组<元素类型>::删除末尾元素()
{
	assert(元素数目 > 0);
	元素类型 末尾元素(数据[元素数目 - 1]);
	元素数目--;
}


template<class 元素类型>
void 数组<元素类型>::清除()
{
	数组大小 = 0;
}