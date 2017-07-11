#include <iostream>
using namespace std;

int main()
{
	int a = 21;
	int b = 10;
	int c;

	if (a == b)
	{
		cout << "Line 1: a == b" << endl;
	}
	else
	{
		cout << "Line 1: a != b" << endl;
	}

	if (a < b)
	{
		cout << "Line 2: a  < b" << endl;
	}
	else
	{
		cout << "Line 2: a !< b" << endl;
	}

	if (a > b)
	{
		cout << "Line 3: a  > b" << endl;
	}
	else
	{
		cout << "Line 3: a !> b" << endl;
	}

	/* change values of a and b */
	a = 5;
	b = 20;

	if (a <= b)
	{
		cout << "Line 4: a  <= b" << endl;
	}
	if (b >= a)
	{
		cout << "Line 5: b >= a" << endl;
	}
	return 0;
}