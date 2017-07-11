#include <iostream>
using namespace std;

int main()
{
	auto max = [](int num1, int num2) {return num1 > num2 ? num1 : num2;};

	int a = 100;
	int b = 200;
	int ret;

	ret = max(a, b);

	cout << "max value is :  " << ret << endl;

	return 0;
}