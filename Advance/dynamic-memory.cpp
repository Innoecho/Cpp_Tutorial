#include <iostream>
using namespace std;

#include <iomanip>
using std::setw;

class Matrix
{
	double **p;
	int row, col;
public:
	Matrix(int m, int n);
	~Matrix();
	double operator()(int m, int n);
	void display();
};

Matrix::Matrix(int m, int n): row(m), col(n)
{
	cout << "Create Matrix" << endl;
	p = new double *[row];
	for (int i = 0; i < row; ++i)
	{
		p[i] = new double[col];
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			p[i][j] = i * row + j;
		}
	}
}

Matrix::~Matrix()
{
	cout << "Delete Matrix" << endl;
	for (int i = 0; i < row; ++i)
	{
		delete []p[i];
	}
	delete []p;
}

void Matrix::display()
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << setw(5) << p[i][j] ;
		}
		cout << endl;
	}
}

double Matrix::operator()(int m, int n)
{
	if (0 < m && m <= row && 0 < n && n <= col)
	{
		return p[m - 1][n - 1];
	}
	else
	{
		cerr << "Error: Index over range" << endl;
		exit(-1);
	}
}

int main()
{
	Matrix A(4, 4);

	A.display();
	cout << A(1, 4) << endl;
	cout << A(2, 3) << endl;

	return 0;
}