#include <iostream>
using namespace std;

int main()
{
	double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
	double *p;

	p = balance;

	cout << "Arrays with pointer p" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "*(p+" << i << ")  : ";
		cout << *(p + i) << endl;
	}

	cout << "Arrays with variable balance" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "*(balance + " << i << ")  :";
		cout << *(balance + i) << endl;
	}
	
	return 0;
}