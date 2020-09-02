#ifndef 小鑫的矩阵
#define 小鑫的矩阵
class 矩阵
{
public:
	矩阵(unsigned 行数, unsigned 列数);//初始化为0矩阵
	const unsigned 行数() const { return 行; };
	const unsigned 列数() const { return 列; };
	double* operator[](const unsigned i) { return 数据[i]; };
	const double* operator[](const unsigned i) const { return 数据[i]; };

private:
	double** 数据;
	unsigned 行;
	unsigned 列;
};

#endif // 小鑫的矩阵