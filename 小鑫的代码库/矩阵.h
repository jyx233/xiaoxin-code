#ifndef 小鑫的矩阵
#define 小鑫的矩阵
class 矩阵
{
public:
	矩阵() {};//请不要使用无参构造函数
	矩阵(unsigned 行数, unsigned 列数);//初始化为0矩阵
	static 矩阵&  单位矩阵(int 维度);
	~矩阵();
	const unsigned 行数() const ;
	const unsigned 列数() const ;
	double* operator[](const unsigned i);
	const double* operator[](const unsigned i) const ;
	friend 矩阵& operator*(const double k, const 矩阵 A);
	friend 矩阵& operator*(const 矩阵 A, const double k);
	friend 矩阵& operator*(const 矩阵 A, const  矩阵 B);
	friend 矩阵& operator+(const 矩阵 A, const  矩阵 B);
	friend 矩阵& operator-(const 矩阵 A, const 矩阵 B);

	//friend 矩阵& 快速乘法(const 矩阵 A, const  矩阵 B) {};//待续
protected:
	double** 数据;
	unsigned 行;
	unsigned 列;
};

#endif // 小鑫的矩阵