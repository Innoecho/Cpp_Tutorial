#include "Matrix.h"

int main()
{
	// VectorNTest();

	double num[3][3] = {{1, 2, 3},
						{4, 5, 7},
						{7, 8, 9}};

	Matrix<double> A(num);
	Matrix<double> B = A.transpose();
	Matrix<double> C = Matrix<double>::eye(3);

	std::cout << "A = " << std::endl;
	std::cout << A << std::endl;
	std::cout << "-A = " << std::endl;
	std::cout << -A << std::endl;
	std::cout << "B = " << std::endl;
	std::cout << B << std::endl;
	std::cout << "C = " << std::endl;
	std::cout << C << std::endl;
	std::cout << "A + B = " << std::endl;
	std::cout << A + B << std::endl;
	std::cout << "A - B = " << std::endl;
	std::cout << A - B << std::endl;
	std::cout << "2 * A = " << std::endl;
	std::cout << 2.0 * A << std::endl;
	std::cout << "A / 2 = " << std::endl;
	std::cout << A / 2 << std::endl;
	std::cout << "A * B = " << std::endl;
	std::cout << A * B << std::endl;

	return 0;
}