#include <iostream>
#include <exception>
using namespace std;

struct MyException: public exception
{
	const char* what() const throw()
	{
		return "C++ Exception";
	}
};

double division(int a, int b)
{
	if (b == 0)
	{
		throw "Division by zero condition! ";
	}
	return (a / b);
}

int main()
{
	int x = 50;
	int y = 0;
	double z = 0;

	try
	{
		z = division(x, y);
		cout << z << endl;
	}
	catch (const char* msg)
	{
		cerr << msg << endl;
	}

	try
	{
		throw MyException();
	}
	catch (MyException e)
	{
		cout << "MyException Caught" << endl;
		cout << e.what() << endl;
	}

	return 0;
}