#include "vector.h"
#define epsilon 0.000001


////////////////////////////////
// Constructor and Destructor //
////////////////////////////////

// 构造函数
vector::vector(int n)
{
	dim = n;
	p = new double[n];
	zero();
}
// 从数组构造向量
// 黑科技：将数组引用的数组大小声明为模板参数
template<size_t n>
vector::vector(const double (&num)[n])
{
	dim = n;
	p = new double[dim];
	for (int i = 0; i < dim; ++i)
	{
		p[i] = num[i];
	}
}
// 拷贝构造函数
vector::vector(const vector& v)
{
	dim = v.dim;
	p = new double[dim];
	for (int i = 0; i < dim; ++i)
	{
		p[i] = v.p[i];
	}
}
// 析构函数
vector::~vector()
{
	delete []p;
}

///////////////////////
// Operator Overload //
///////////////////////

// 重载输出运算符
ostream& operator<<(ostream &output, const vector& v)
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
double vector::operator()(int i) const
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
vector& vector::operator=(const vector& v)
{
	dim = v.dim;
	p = new double[dim];
	for (int i = 0; i < dim; ++i)
	{
		p[i] = v.p[i];
	}
	return *this;
}
// 重载负号运算
vector vector::operator-() const
{
	vector ret(dim);
	for (int i = 0; i < dim; ++i)
	{
		ret.p[i] = -p[i];
	}
	return ret;
}
// 重载加法运算
vector vector::operator+(const vector& v) const
{
	vector ret(dim);
	for (int i = 0; i < dim; ++i)
	{
		ret.p[i] = p[i] + v.p[i];
	}
	return ret;
}
// 重载减法运算
vector vector::operator-(const vector& v) const
{
	vector ret(dim);
	for (int i = 0; i < dim; ++i)
	{
		ret.p[i] = p[i] - v.p[i];
	}
	return ret;
}
// 重载数乘运算
vector vector::operator*(const double& k) const
{
	vector ret(dim);
	for (int i = 0; i < dim; ++i)
	{
		ret.p[i] = k * p[i];
	}
	return ret;
}
// 重载数乘运算
vector operator*(const double& k, const vector& v)
{
	vector ret(v.dim);
	for (int i = 0; i < v.dim; ++i)
	{
		ret.p[i] = k * v.p[i];
	}
	return ret;
}
// 重载除法运算
vector vector::operator/(const double& k) const
{
	vector ret(dim);
	for (int i = 0; i < dim; ++i)
	{
		ret.p[i] = p[i] / k;
	}
	return ret;
}
// 重载加等运算
vector& vector::operator+=(const vector& v)
{
	for (int i = 0; i < dim; ++i)
	{
		p[i] += v.p[i];
	}
	return *this;
}
// 重载减等运算
vector& vector::operator-=(const vector& v)
{
	for (int i = 0; i < dim; ++i)
	{
		p[i] -= v.p[i];
	}
	return *this;
}
// 重载乘等运算
vector& vector::operator*=(const double& k)
{
	for (int i = 0; i < dim; ++i)
	{
		p[i] *= k;
	}
	return *this;
}
// 重载除等运算
vector& vector::operator/=(const double& k)
{
	for (int i = 0; i < dim; ++i)
	{
		p[i] /= k;
	}
	return *this;
}
// 重载内积运算
double vector::operator*(const vector& v) const
{
	double ret = 0;
	for (int i = 0; i < dim; ++i)
	{
		ret += p[i] * v.p[i];
	}
	return ret;
}
// 重载相等运算
bool vector::operator==(const vector& v) const
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
bool vector::operator!=(const vector& v) const
{
	return !(*this == v);
}

//////////////////////
// trivial function //
//////////////////////

// 全零向量
void vector::zero()
{
	for (int i = 0; i < dim; ++i)
	{
		p[i] = 0;
	}
}
// 显示向量
void vector::display() const
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
double vector::norm() const
{
	double ret = 0;
	for (int i = 0; i < dim; ++i)
	{
		ret += p[i] * p[i];
	}
	ret = sqrt(ret);
	return ret;
}
// 向量归一化
void vector::normalize()
{
	double n = norm();
	for (int i = 0; i < dim; ++i)
	{
		p[i] = p[i] / n;
	}
}


int main()
{
	double num1[] = {0, 3, 4};
	double num2[] = {1, 3, 5};

	vector x(num1), y(num2);

	cout << "    x = " << x << endl;
	cout << "   -x = " << -x << endl;
	cout << "    y = " << y << endl;
	cout << "x + y = " << x + y << endl;
	cout << "x - y = " << x - y << endl;
	cout << "2 * x = " << 2 * x << endl;
	cout << "x / 2 = " << x / 2 << endl;
	cout << "||x|| = " << x.norm() << endl;
	cout << "x * y = " << x*y << endl;
	cout << boolalpha;
	cout << "x == y? " << (x == y) << endl;

	return 0;
}