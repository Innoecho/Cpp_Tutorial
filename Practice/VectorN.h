#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

#define epsilon 0.000001

template <class T>
class VectorN
{
private:
	T* p;
	int dim;
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


////////////////////////////////
// Constructor and Destructor //
////////////////////////////////

// 构造函数
template <class T>
VectorN<T>::VectorN(int n)
{
	dim = n;
	p = new T[n];
	zero();
}
// 从数组构造向量
// 黑科技：将数组引用的数组大小声明为模板参数
template <class T>
template <size_t n>
VectorN<T>::VectorN(const T(&num)[n])
{
	dim = n;
	p = new T[dim];
	for (int i = 0; i < dim; ++i)
	{
		p[i] = num[i];
	}
}
// 拷贝构造函数
template <class T>
VectorN<T>::VectorN(const VectorN<T>& v)
{
	dim = v.dim;
	p = new T[dim];
	for (int i = 0; i < dim; ++i)
	{
		p[i] = v.p[i];
	}
}
// 析构函数
template <class T>
VectorN<T>::~VectorN()
{
	delete []p;
}

///////////////////////
// Operator Overload //
///////////////////////

// 重载输出运算符
template <class C>
ostream& operator<<(ostream &output, const VectorN<C>& v)
{
	// 输出格式控制
	output.precision(4);
	output << fixed << showpoint;
	output << "(";
	for (int i = 0; i < v.dim; ++i)
	{
		output << setw(10) << v.p[i] << "," ;
	}
	output << ")";
	return output;
}
// 重载下标运算
template <class T>
T VectorN<T>::operator()(int i) const
{
	if (0 < i && i <= dim)
	{
		return p[i - 1];
	}
	else
	{
		cerr << "error: index over range" << endl;
		exit(-1);
	}
}
// 重载赋值运算符
// 返回引用可以实现连等
template <class T>
VectorN<T>& VectorN<T>::operator=(const VectorN<T>& v)
{
	dim = v.dim;
	p = new T[dim];
	for (int i = 0; i < dim; ++i)
	{
		p[i] = v.p[i];
	}
	return *this;
}
// 重载加法运算
template <class T>
VectorN<T> VectorN<T>::operator+(const VectorN<T>& v) const
{
	VectorN<T> ret(dim);
	for (int i = 0; i < dim; ++i)
	{
		ret.p[i] = p[i] + v.p[i];
	}
	return ret;
}
// 重载数乘运算
template <class T>
VectorN<T> VectorN<T>::operator*(const T& k) const
{
	VectorN<T> ret(dim);
	for (int i = 0; i < dim; ++i)
	{
		ret.p[i] = k * p[i];
	}
	return ret;
}
// 重载数乘运算
template <class C>
VectorN<C> operator*(const C& k, const VectorN<C>& v)
{
	return v * k;
}
// 重载负号运算
template <class T>
VectorN<T> VectorN<T>::operator-() const
{
	return this->operator*(-1);
}
// 重载减法运算
template <class T>
VectorN<T> VectorN<T>::operator-(const VectorN<T>& v) const
{
	return this->operator+(-v);
}
// 重载除法运算
template <class T>
VectorN<T> VectorN<T>::operator/(const T& k) const
{
	return this->operator*(1.0 / k);
}
// 重载加等运算
template <class T>
VectorN<T>& VectorN<T>::operator+=(const VectorN<T>& v)
{
	*this = *this + v;
	return *this;
}
// 重载减等运算
template <class T>
VectorN<T>& VectorN<T>::operator-=(const VectorN<T>& v)
{
	*this = *this - v;
	return *this;
}
// 重载乘等运算
template <class T>
VectorN<T>& VectorN<T>::operator*=(const T& k)
{
	*this = *this * k;
	return *this;
}
// 重载除等运算
template <class T>
VectorN<T>& VectorN<T>::operator/=(const T& k)
{
	*this = *this / k;
	return *this;
}
// 重载内积运算
template <class T>
T VectorN<T>::operator*(const VectorN<T>& v) const
{
	T ret = 0;
	for (int i = 0; i < dim; ++i)
	{
		ret += p[i] * v.p[i];
	}
	return ret;
}
// 重载相等运算
template <class T>
bool VectorN<T>::operator==(const VectorN<T>& v) const
{
	for (int i = 0; i < dim; ++i)
	{
		if (abs(p[i] - v.p[i]) > epsilon)
		{
			return false;
		}
	}
	return true;
}
// 重载不等运算符
template <class T>
bool VectorN<T>::operator!=(const VectorN<T>& v) const
{
	return !(*this == v);
}

//////////////////////
// trivial function //
//////////////////////

// 全零向量
template <class T>
VectorN<T>& VectorN<T>::zero()
{
	for (int i = 0; i < dim; ++i)
	{
		p[i] = 0;
	}
	return *this;
}
// 显示向量
template <class T>
void VectorN<T>::display() const
{
	cout <<  "dim = " << dim << ": ";
	cout.precision(4);
	cout << fixed << showpoint;
	cout << "(";
	for (int i = 0; i < dim; ++i)
	{
		cout << p[i] << "," << setw(10) ;
	}
	cout << ")" << endl;
}
// 向量范数
template <class T>
T VectorN<T>::norm() const
{
	return sqrt(*this * *this);
}
// 向量归一化
template <class T>
VectorN<T>& VectorN<T>::normalize()
{
	*this  = *this / this->norm();
	return *this;
}

int VectorNTest()
{
	double num1[] = {0, 3, 4};
	double num2[] = {1, 3, 5};

	VectorN<double> x(num1), y(num2);

	cout << "    x = " << x << endl;
	cout << "   -x = " << -x << endl;
	cout << "    y = " << y << endl;
	cout << "x + y = " << x + y << endl;
	cout << "x - y = " << x - y << endl;
	cout << "x * 2 = " << 2.0 * x << endl;
	cout << "x / 2 = " << x / 2 << endl;
	cout << "  |x| = " << x.norm() << endl;
	cout << "x/|x| = " << (x.normalize()) << endl;
	cout << "x * y = " << x*y << endl;
	cout << boolalpha;
	cout << "x == y? " << (x == y) << endl;

	return 0;
}