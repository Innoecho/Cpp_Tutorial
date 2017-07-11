#include <iostream>
using namespace std;

int main()
{
	int a = 10;

	do
	{
		cout << "a = " << a++ << endl;
		if (a > 15) break;
	} while (a < 20);
	return 0;
}