#include <iostream>
using namespace std;

int main()
{
	int a = 21;
	int b = 10;
	int c;

	c = a + b;
	cout << "Line 1:\t c = " << c << endl;
	c = a - b;
	cout << "Line 2:\t c = " << c << endl;
	c = a * b;
	cout << "Line 3:\t c = " << c << endl;
	c = a / b;
	cout << "Line 4:\t c = " << c << endl;
	c = a % b;
	cout << "Line 5:\t c = " << c << endl;

	int d = 10;
	c = d++;
	cout << "Line 6:\t c = " << c << endl;

	d = 10;
	c = d--;
	cout << "Line 7:\t c = " << c << endl;

	return 0;
}