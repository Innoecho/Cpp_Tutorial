#include <iostream>
using namespace std;

int main()
{
	int a = 5;
	int b = 20;
	int c;

	if (a && b)
	{
		cout << "Line 1 : Condition is True" << endl;
	}

	if (a || b)
	{
		cout << "Line 2 : Condition is True" << endl;
	}

	// change values of a and b
	a = 0;
	b = 10;

	if (a && b)
	{
		cout << "Line 3 : Condition is True" << endl;
	}
	else
	{
		cout << "Line 4 : Condition is not True" << endl;
	}

	if (!(a && b))
	{
		cout << "Line 5 : Condition is True" << endl;
	}
	return 0;
}