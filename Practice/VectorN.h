#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

#define epsilon 0.000001

template <typename T>
class VectorN
{
private:
	T* p;
	int nDim;
public:

	////////////////////////////////
	// Constructor and Destructor //
	////////////////////////////////

	// 构造函数
	VectorN<T>() {}
	// 从维数构造向量
	VectorN<T>(int n);
	// 从数组构造向量
	// 黑科技：将数组引用的数组大小声明为模板参数
	template<size_t n>
	VectorN<T>(const T(&num)[n]);
	// 拷贝构造函数
	VectorN<T>(const VectorN<T>& v);
	// 析构函数
	~VectorN<T>();

	///////////////////////
	// Operator Overload //
	///////////////////////

	// 重载下标运算符
	T& operator()(int i) const;
	// 重载输出运算符
	template <typename C>
	friend std::ostream& operator<<(std::ostream &output, const VectorN<C>& v);
	// 重载赋值运算符
	VectorN<T>& operator=(const VectorN<T>& v);
	// 重载加法运算
	VectorN<T> operator+(const VectorN<T>& v) const;
	// 重载数乘运算
	VectorN<T> operator*(const T& k) const;
	// 重载数乘运算
	template <typename C>
	friend VectorN<C> operator*(const C& k, const VectorN<C>& v);
	// 重载负号运算
	VectorN<T> operator-() const;
	// 重载减法运算
	VectorN<T> operator-(const VectorN<T>& v) const;
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

	// 当采用默认构造函数时，调用此方法为其分配空间
	VectorN<T>& init(int n);
	template <size_t n>
	VectorN<T>& init(const T (&num)[n]);
	// 向量范数
	T norm() const;
	// 向量归一化
	VectorN<T>& normalize();
};


////////////////////////////////
// Constructor and Destructor //
////////////////////////////////

// 构造函数
template <typename T>
VectorN<T>::VectorN(int n)
{
	init(n);
}
// 从数组构造向量
// 黑科技：将数组引用的数组大小声明为模板参数
template <typename T>
template <size_t n>
VectorN<T>::VectorN(const T (&num)[n])
{
	init(num);
}
// 拷贝构造函数
template <typename T>
VectorN<T>::VectorN(const VectorN<T>& v)
{
	nDim = v.nDim;
	p = new T[nDim];
	for (int i = 0; i < nDim; ++i)
	{
		p[i] = v.p[i];
	}
}
// 析构函数
template <typename T>
VectorN<T>::~VectorN()
{
	delete []p;
}

///////////////////////
// Operator Overload //
///////////////////////

// 重载下标运算
template <typename T>
T& VectorN<T>::operator()(int i) const
{
	if (0 < i && i <= nDim)
	{
		return p[i - 1];
	}
	else
	{
		std::cerr << "error: index over range" << std::endl;
		exit(-1);
	}
}
// 重载输出运算符
template <typename C>
std::ostream& operator<<(std::ostream &output, const VectorN<C>& v)
{
	// 输出格式控制
	output.precision(4);
	output << std::fixed << std::showpoint;
	output << "(";
	for (int i = 1; i <= v.nDim; ++i)
	{
		output << std::setw(10) << v(i) << "," ;
	}
	output << ")";
	return output;
}
// 重载赋值运算符
// 返回引用可以实现连等
template <typename T>
VectorN<T>& VectorN<T>::operator=(const VectorN<T>& v)
{
	if (nDim != v.nDim)
	{
		std::cerr << "error: dim does not match" << std::endl;
		exit(-1);
	}
	for (int i = 0; i < nDim; ++i)
	{
		p[i] = v.p[i];
	}
	return *this;
}
// 重载加法运算
template <typename T>
VectorN<T> VectorN<T>::operator+(const VectorN<T>& v) const
{
	VectorN<T> ret(nDim);
	for (int i = 0; i < nDim; ++i)
	{
		ret.p[i] = p[i] + v.p[i];
	}
	return ret;
}
// 重载数乘运算
template <typename T>
VectorN<T> VectorN<T>::operator*(const T& k) const
{
	VectorN<T> ret(nDim);
	for (int i = 0; i < nDim; ++i)
	{
		ret.p[i] = k * p[i];
	}
	return ret;
}
// 重载数乘运算
template <typename C>
VectorN<C> operator*(const C& k, const VectorN<C>& v)
{
	return v * k;
}
// 重载负号运算
template <typename T>
VectorN<T> VectorN<T>::operator-() const
{
	return this->operator*(-1);
}
// 重载减法运算
template <typename T>
VectorN<T> VectorN<T>::operator-(const VectorN<T>& v) const
{
	return this->operator+(-v);
}
// 重载除法运算
template <typename T>
VectorN<T> VectorN<T>::operator/(const T& k) const
{
	return this->operator*(1.0 / k);
}
// 重载加等运算
template <typename T>
VectorN<T>& VectorN<T>::operator+=(const VectorN<T>& v)
{
	return *this = *this + v;
}
// 重载减等运算
template <typename T>
VectorN<T>& VectorN<T>::operator-=(const VectorN<T>& v)
{
	return *this = *this - v;
}
// 重载乘等运算
template <typename T>
VectorN<T>& VectorN<T>::operator*=(const T& k)
{
	return *this = *this * k;
}
// 重载除等运算
template <typename T>
VectorN<T>& VectorN<T>::operator/=(const T& k)
{
	return *this = *this / k;
}
// 重载内积运算
template <typename T>
T VectorN<T>::operator*(const VectorN<T>& v) const
{
	T ret = 0;
	for (int i = 0; i < nDim; ++i)
	{
		ret += p[i] * v.p[i];
	}
	return ret;
}
// 重载相等运算
template <typename T>
bool VectorN<T>::operator==(const VectorN<T>& v) const
{
	for (int i = 0; i < nDim; ++i)
	{
		if (abs(p[i] - v.p[i]) > epsilon)
		{
			return false;
		}
	}
	return true;
}
// 重载不等运算符
template <typename T>
bool VectorN<T>::operator!=(const VectorN<T>& v) const
{
	return !(*this == v);
}

//////////////////////
// trivial function //
//////////////////////

// 当采用默认构造函数时，调用此方法为其分配空间
template <typename T>
VectorN<T>& VectorN<T>::init(int n)
{
	nDim = n;
	p = new T[nDim];
	for (int i = 0; i < nDim; ++i)
	{
		p[i] = 0;
	}
	return *this;
}
// 当采用默认构造函数时，调用此方法为其分配空间
template <typename T>
template <size_t n>
VectorN<T>& VectorN<T>::init(const T (&num)[n])
{
	nDim = n;
	p = new T[nDim];
	for (int i = 0; i < nDim; ++i)
	{
		p[i] = num[i];
	}
	return *this;
}
// 向量范数
template <typename T>
T VectorN<T>::norm() const
{
	return sqrt(*this * *this);
}
// 向量归一化
template <typename T>
VectorN<T>& VectorN<T>::normalize()
{
	return *this  = *this / this->norm();
}

int VectorNTest()
{
	double num1[] = {0, 3, 4};
	double num2[] = {1, 3, 5};

	VectorN<double> x(num1), y(num2);

	std::cout << "    x = " << x << std::endl;
	std::cout << "   -x = " << -x << std::endl;
	std::cout << "    y = " << y << std::endl;
	std::cout << "x + y = " << x + y << std::endl;
	std::cout << "x - y = " << x - y << std::endl;
	std::cout << "x * 2 = " << 2.0 * x << std::endl;
	std::cout << "x / 2 = " << x / 2 << std::endl;
	std::cout << "  |x| = " << x.norm() << std::endl;
	std::cout << "x/|x| = " << (x.normalize()) << std::endl;
	std::cout << "x * y = " << x*y << std::endl;
	std::cout << std::boolalpha;
	std::cout << "x == y? " << (x == y) << std::endl;

	return 0;
}