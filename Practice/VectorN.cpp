#include "VectorN.h"

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
// 重载负号运算
template <class T>
VectorN<T> VectorN<T>::operator-() const
{
	VectorN<T> ret(dim);
	for (int i = 0; i < dim; ++i)
	{
		ret.p[i] = -p[i];
	}
	return ret;
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
// 重载减法运算
template <class T>
VectorN<T> VectorN<T>::operator-(const VectorN<T>& v) const
{
	VectorN<T> ret(dim);
	for (int i = 0; i < dim; ++i)
	{
		ret.p[i] = p[i] - v.p[i];
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
	VectorN<C> ret(v.dim);
	for (int i = 0; i < v.dim; ++i)
	{
		ret.p[i] = k * v.p[i];
	}
	return ret;
}
// 重载除法运算
template <class T>
VectorN<T> VectorN<T>::operator/(const T& k) const
{
	VectorN<T> ret(dim);
	for (int i = 0; i < dim; ++i)
	{
		ret.p[i] = p[i] / k;
	}
	return ret;
}
// 重载加等运算
template <class T>
VectorN<T>& VectorN<T>::operator+=(const VectorN<T>& v)
{
	for (int i = 0; i < dim; ++i)
	{
		p[i] += v.p[i];
	}
	return *this;
}
// 重载减等运算
template <class T>
VectorN<T>& VectorN<T>::operator-=(const VectorN<T>& v)
{
	for (int i = 0; i < dim; ++i)
	{
		p[i] -= v.p[i];
	}
	return *this;
}
// 重载乘等运算
template <class T>
VectorN<T>& VectorN<T>::operator*=(const T& k)
{
	for (int i = 0; i < dim; ++i)
	{
		p[i] *= k;
	}
	return *this;
}
// 重载除等运算
template <class T>
VectorN<T>& VectorN<T>::operator/=(const T& k)
{
	for (int i = 0; i < dim; ++i)
	{
		p[i] /= k;
	}
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
void VectorN<T>::zero()
{
	for (int i = 0; i < dim; ++i)
	{
		p[i] = 0;
	}
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
	T ret = 0;
	for (int i = 0; i < dim; ++i)
	{
		ret += p[i] * p[i];
	}
	ret = sqrt(ret);
	return ret;
}
// 向量归一化
template <class T>
void VectorN<T>::normalize()
{
	T n = norm();
	for (int i = 0; i < dim; ++i)
	{
		p[i] = p[i] / n;
	}
}


int main()
{
	double num1[] = {0, 3, 4};
	double num2[] = {1, 3, 5};

	VectorN<double> x(num1), y(num2);

	cout << "    x = " << x << endl;
	cout << "   -x = " << -x << endl;
	cout << "    y = " << y << endl;
	cout << "x + y = " << x + y << endl;
	cout << "x - y = " << x - y << endl;
	cout << "x * 2 = " << x * 2 << endl;
	cout << "x / 2 = " << x / 2 << endl;
	cout << "||x|| = " << x.norm() << endl;
	cout << "x * y = " << x*y << endl;
	cout << boolalpha;
	cout << "x == y? " << (x == y) << endl;

	return 0;
}