#pragma once
#ifndef 小鑫的数组
#define 小鑫的数组
/*
"元素类型"需包含默认构造函数
若"元素类型"的成员变量包含指针,请重载拷贝构造函数以防止数据的浅拷贝
*/
template <class 元素类型> 
class 数组
{
public:
	数组();
	数组(unsigned n);
	数组(unsigned n, const 元素类型 默认值);
	数组(数组<元素类型> &另一个数组);


	元素类型& operator[](const unsigned i) { return 数据[i]; };
	const 元素类型& operator[](const unsigned i) const { return 数据[i]; };

	//当调用该函数时数组大小增加时,不保证新增值已被初始化
	void 设置数组大小(unsigned n);

	//若元素数目增加,则新增值为默认值
	void 设置数组大小(unsigned n, const 元素类型 默认值);

	void 清除();

	//设置数组的真实容量,该过程会自动完成
	//除了数组大小不会发生改变的情形外,不建议调用该函数
	void 设置数组容量(unsigned n);


	void 结尾添加元素(元素类型 X);
	void 插入元素(unsigned n, const 元素类型 X);//顺序容器不建议插入元素
	元素类型  删除末尾元素();

	const unsigned 数组大小()const { return 数组大小; };
	const unsigned 数组容量()const { return 容量; };

private:
	元素类型* 数据;
	unsigned 元素数目;
	unsigned 容量;

};

#endif // !小鑫的数组