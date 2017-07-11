#include <iostream>
using namespace std;

int main()
{
	int a = 100;
	int b = 200;

	switch (a)
	{
	case 100:
		cout << "Extern switch" << endl;
		switch (b)
		{
		case 200:
			cout << "Intern switch" << endl;
		}
	}
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	return 0;
}