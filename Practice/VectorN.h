#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define epsilon 0.000001

template <class T>
class VectorN
{
private:
	T* p;
	int dim = 0;
public:

	////////////////////////////////
	// Constructor and Destructor //
	////////////////////////////////

	// 构造函数
	VectorN<T>(int n);
	// 从数组构造向量
	// 黑科技：将数组引用的数组大小声明为模板参数
	template<size_t n>
	VectorN<T>(T const(&num)[n]);
	// 拷贝构造函数
	VectorN<T>(const VectorN<T>& v);
	// 析构函数
	~VectorN<T>();

	///////////////////////
	// Operator Overload //
	///////////////////////

	// 重载输出运算符
	template <class C>
	friend ostream& operator<<(ostream &output, const VectorN<C>& v);
	// 重载括号运算符
	T operator()(int i) const;
	// 重载赋值运算符
	VectorN<T>& operator=(const VectorN<T>& v);
	// 重载负号运算
	VectorN<T> operator-() const;
	// 重载加法运算
	VectorN<T> operator+(const VectorN<T>& v) const;
	// 重载减法运算
	VectorN<T> operator-(const VectorN<T>& v) const;
	// 重载数乘运算
	VectorN<T> operator*(const T& k) const;
	// 重载数乘运算
	template <class C>
	friend VectorN<C> operator*(const C& k, const VectorN<C>& v);
	// {
	// 	VectorN<T> ret(v.dim);
	// 	for (int i = 0; i < v.dim; ++i)
	// 	{
	// 		ret.p[i] = k * v.p[i];
	// 	}
	// 	return ret;
	// }
	// 重载除法运算
	VectorN<T> operator/(const T& k) const;
	// 重载加等运算
	VectorN<T>& operator+=(const VectorN<T>& v);
	// 重载减等运算
	VectorN<T>& operator-=(const VectorN<T>& v);
	// 重载乘等运算
	VectorN<T>& operator*=(const T& k);
	// 重载除等运算
	VectorN<T>& operator/=(const T& k);
	// 重载内积运算
	T operator*(const VectorN<T>& v) const;
	// 重载相等运算
	bool operator==(const VectorN<T>& v) const;
	// 重载不等运算符
	bool operator!=(const VectorN<T>& v) const;

	//////////////////////
	// trivial function //
	//////////////////////

	// 将向量转换为全零向量
	VectorN<T>& zero();
	// 显示向量
	void display() const;
	// 向量范数
	T norm() const;
	// 向量归一化
	VectorN<T>& normalize();
};