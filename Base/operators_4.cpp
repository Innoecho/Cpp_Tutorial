#include <iostream>
using namespace std;

int main()
{
	// 60 = 0011 1100
	unsigned int a = 60;
	// 13 = 0000 1101
	unsigned int b = 13;
	int c = 0;

	// 12 = 0000 1100
	c = a & b;
	cout << "Line 1 : c = " << c << endl;

	// 61 = 0011 1101
	c = a | b;
	cout << "Line 2 : c = " << c << endl;

	// 49 = 0011 0001
	c = a ^ b;
	cout << "Line 3 : c = " << c << endl;

	// -61 = 1100 0011
	c = ~a;
	cout << "Line 4 : c = " << c << endl;

	// 240 = 1111 0000
	c = a << 2;
	cout << "Line 5 : c = " << c << endl;

	// 15 = 0000 1111
	c = a >> 2;
	cout << "Line 6 : c = " << c << endl;

	return 0;
}