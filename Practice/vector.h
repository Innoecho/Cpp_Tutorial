#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class vector
{
private:
	double* p;
	int dim = 0;
public:

	////////////////////////////////
	// Constructor and Destructor //
	////////////////////////////////

	// 构造函数，生成n维全零向量
	vector(int n = 0);
	// 构造函数，用数组生成向量
	template<size_t n>
	vector(const double (&array)[n]);
	// 拷贝构造函数
	vector(const vector& v);
	// 析构函数
	~vector();

	///////////////////////
	// Operator Overload //
	///////////////////////

	// 重载输出运算符
	friend ostream& operator<<(ostream &output, const vector& v);
	// 重载括号运算符
	double operator()(int i) const;
	// 重载赋值运算符
	vector& operator=(const vector& v);
	// 重载负号运算
	vector operator-() const;
	// 重载加法运算
	vector operator+(const vector& v) const;
	// 重载减法运算
	vector operator-(const vector& v) const;
	// 重载数乘运算
	vector operator*(const double& k) const;
	// 重载数乘运算
	friend vector operator*(const double& k, const vector& v);
	// 重载除法运算
	vector operator/(const double& k) const;
	// 重载加等运算
	vector& operator+=(const vector& v);
	// 重载减等运算
	vector& operator-=(const vector& v);
	// 重载乘等运算
	vector& operator*=(const double& k);
	// 重载除等运算
	vector& operator/=(const double& k);
	// 重载内积运算
	double operator*(const vector& v) const;
	// 重载相等运算
	bool operator==(const vector& v) const;
	// 重载不等运算符
	bool operator!=(const vector& v) const;

	//////////////////////
	// trivial function //
	//////////////////////

	// 将向量转换为全零向量
	void zero();
	// 显示向量
	void display() const;
	// 向量范数
	double norm() const;
	// 向量归一化
	void normalize();
};