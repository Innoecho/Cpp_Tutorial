#include <iostream>
#include "VectorN.h"

template <typename T>
class Matrix
{
private:
	int nRow, nCol;
	VectorN<T>* p;
public:

	////////////////////////////////
	// Constructor and Destructor //
	////////////////////////////////

	// trivial constructor
	Matrix<T>() {};
	// constructor by m * n
	Matrix<T>(int m, int n);
	// constructor by 2d array;
	template<size_t m, size_t n>
	Matrix<T>(const T(&num)[m][n]);
	// copy constructor
	Matrix<T>(const Matrix<T> & A);
	// destructor
	~Matrix<T>();

	///////////////////////
	// Operator Overload //
	///////////////////////

	// 重载下标运算符
	T& operator()(int i, int j) const;
	// 重载输出运算符
	template <typename C>
	friend std::ostream& operator<<(std::ostream &output, const Matrix<C>& v);
	// 重载赋值运算符
	Matrix<T>& operator=(const Matrix<T>& v);
	// 重载加法运算
	Matrix<T> operator+(const Matrix<T>& v) const;
	// 重载数乘运算
	Matrix<T> operator*(const T& k) const;
	// 重载数乘运算
	template <typename C>
	friend Matrix<C> operator*(const C& k, const Matrix<C>& v);
	// 重载负号运算
	Matrix<T> operator-() const;
	// 重载减法运算
	Matrix<T> operator-(const Matrix<T>& v) const;
	// 重载除法运算
	Matrix<T> operator/(const T& k) const;
	// 重载加等运算
	Matrix<T>& operator+=(const Matrix<T>& v);
	// 重载减等运算
	Matrix<T>& operator-=(const Matrix<T>& v);
	// 重载乘等运算
	Matrix<T>& operator*=(const T& k);
	// 重载除等运算
	Matrix<T>& operator/=(const T& k);
	// 重载矩阵乘法
	Matrix<T> operator*(const Matrix<T>& v) const;
	// 重载相等运算
	bool operator==(const Matrix<T>& v) const;
	// 重载不等运算符
	bool operator!=(const Matrix<T>& v) const;

	//////////////////////
	// matrix function //
	//////////////////////

	// transpose
	Matrix<T> transpose() const;
	// get row reference
	VectorN<T>& row_ref(int i);
	// get row
	VectorN<T> row(int i) const;
	// get col
	VectorN<T> col(int j) const;

	/////////////////////////////
	// generate special matrix //
	/////////////////////////////

	// n-I matrix
	static Matrix<T> eye(int n);
};

////////////////////////////////
// Constructor and Destructor //
////////////////////////////////

// constructor by m * n
template <typename T>
Matrix<T>::Matrix(int m, int n): nRow(m), nCol(n)
{
	p = new VectorN<T>[nRow];
	for (int i = 0; i < nRow; ++i)
	{
		// 一般情况下不应手动调用init
		p[i].init(nCol);
	}
}
// constructor by 2d array;
template <typename T>
template<size_t m, size_t n>
Matrix<T>::Matrix(const T(&num)[m][n])
{
	nRow = m;
	nCol = n;
	p = new VectorN<T>[nRow];
	for (int i = 0; i < nRow; ++i)
	{
		p[i].init(nCol);
		for (int j = 0; j < nCol; ++j)
		{
			p[i](j + 1) = num[i][j];
		}
	}
}
// copy constructor
template <typename T>
Matrix<T>::Matrix(const Matrix<T> & A)
{
	nRow = A.nRow;
	nCol = A.nCol;
	p = new VectorN<T>[nRow];
	for (int i = 0; i < nRow; ++i)
	{
		p[i].init(nCol);
		p[i] = A.p[i];
	}
}
// destructor
template <typename T>
Matrix<T>::~Matrix()
{
	delete []p;
}

///////////////////////
// Operator Overload //
///////////////////////

// 重载下标运算符
template <typename T>
T& Matrix<T>::operator()(int i, int j) const
{
	if (0 < i && i <= nRow && 0 < j && j <= nCol)
	{
		return p[i - 1](j);
	}
	else
	{
		std::cerr << "error: index over range" << std::endl;
		exit(-1);
	}
}
// 重载输出运算符
template <typename C>
std::ostream& operator<<(std::ostream &output, const Matrix<C>& v)
{
	// 输出格式控制
	output.precision(4);
	output << std::fixed << std::showpoint;
	for (int i = 1; i <= v.nRow; ++i)
	{
		for (int j = 1; j <= v.nCol; ++j)
		{
			output << std::setw(10) << v(i, j) << "," ;
		}
		output << std::endl;
	}
	return output;
}
// 重载赋值运算符
template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& v)
{
	if (nRow != v.nRow || nCol != v.nCol)
	{
		std::cerr << "error: dim does not match" << std::endl;
		exit(-1);
	}
	for (int i = 0; i < nRow; ++i)
	{
		p[i] = v.p[i];
	}
	return *this;
}
// 重载加法运算
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& v) const
{
	if (nRow != v.nRow || nCol != v.nCol)
	{
		std::cerr << "error: dim does not match" << std::endl;
		exit(-1);
	}
	Matrix<T> ret(nRow, nCol);
	for (int i = 0; i < nRow; ++i)
	{
		ret.p[i] = p[i] + v.p[i];
	}
	return ret;
}
// 重载数乘运算
template <typename T>
Matrix<T> Matrix<T>::operator*(const T& k) const
{
	Matrix<T> ret(nRow, nCol);
	for (int i = 0; i < nRow; ++i)
	{
		ret.p[i] = p[i] * k;
	}
	return ret;
}
// 重载数乘运算
template <typename C>
Matrix<C> operator*(const C& k, const Matrix<C>& v)
{
	return v * k;
}
// 重载负号运算
template <typename T>
Matrix<T> Matrix<T>::operator-() const
{
	return this->operator*(-1);
}
// 重载减法运算
template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& v) const
{
	return this->operator+(-v);
}
// 重载除法运算
template <typename T>
Matrix<T> Matrix<T>::operator/(const T& k) const
{
	return this->operator*(1.0 / k);
}
// 重载加等运算
template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& v)
{
	return *this = *this + v;
}
// 重载减等运算
template <typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& v)
{
	return *this = *this - v;
}
// 重载乘等运算
template <typename T>
Matrix<T>& Matrix<T>::operator*=(const T& k)
{
	return *this = *this * k;
}
// 重载除等运算
template <typename T>
Matrix<T>& Matrix<T>::operator/=(const T& k)
{
	return *this = *this / k;
}
// 重载矩阵乘法
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& v) const
{
	if(nCol != v.nRow)
	{
		std::cerr << "error: dim does not match" << std::endl;
		exit(-1);
	}
	Matrix<T> ret(nRow, v.nCol);
	for (int i = 1; i <= nRow; ++i)
	{
		for (int j = 1; j <= v.nCol; ++j)
		{
			ret(i, j) = this->row(i)*v.col(j);
		}
	}
	return ret;
}

//////////////////////
// matrix function //
//////////////////////

// transpose
template <typename T>
Matrix<T> Matrix<T>::transpose() const
{
	Matrix<T> v_t(nCol, nRow);
	for (int i = 1; i <= nCol; ++i)
	{
		v_t.p[i-1] = this->col(i);
	}
	return v_t;
}
// get row reference
template <typename T>
VectorN<T>& Matrix<T>::row_ref(int i)
{
	return p[i-1];
}
// get row reference
template <typename T>
VectorN<T> Matrix<T>::row(int i) const
{
	return p[i-1];
}
// get col
template <typename T>
VectorN<T> Matrix<T>::col(int j) const
{
	VectorN<T> ret(nRow);
	for (int i = 1; i <= nRow; ++i)
	{
		ret(i) = p[i-1](j);
	}
	return ret;
}

/////////////////////////////
// generate special matrix //
/////////////////////////////

// n-I matrix
template <typename T>
Matrix<T> Matrix<T>::eye(int n)
{
	Matrix<T> I(n, n);
	for (int i = 1; i <= n; ++i)
	{
		I(i,i) = 1;
	}
	return I;
}