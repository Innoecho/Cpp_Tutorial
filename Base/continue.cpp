#include <iostream>
using namespace std;

int main()
{
	int a = 10;

	do
	{
		if (a == 15)
		{
			a++;
			continue;
		}
		cout << "a = " << a++ << endl;
	} while (a < 20);
	
	return 0;
}