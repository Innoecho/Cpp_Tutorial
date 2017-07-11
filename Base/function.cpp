#include <iostream>
using namespace std;

// 函数声明
int swap_value(int x, int y);
int swap_address(int *x, int *y);
int swap_reference(int &x, int &y);

int main()
{
	int a = 100;
	int b = 200;

	// test swap_value
	cout << "swap_value : " <<endl;
	cout << "before swap, a = " <<a<<endl;
	cout << "before swap, b = " <<b<<endl;


	swap_value(a, b);

	cout << "after swap, a = " <<a<<endl;
	cout << "after swap, b = " <<b<<endl;
	cout <<endl;

	// test swap_address
	cout << "swap_address: " <<endl;	
	cout << "before swap, a = " <<a<<endl;
	cout << "before swap, b = " <<b<<endl;

	swap_address(&a, &b);

	cout << "after swap, a = " <<a<<endl;
	cout << "after swap, b = " <<b<<endl;
	cout <<endl;

	// test swap_reference
	cout << "swap_reference: " <<endl;	
	cout << "before swap, a = " <<a<<endl;
	cout << "before swap, b = " <<b<<endl;

	swap_reference(a, b);

	cout << "after swap, a = " <<a<<endl;
	cout << "after swap, b = " <<b<<endl;
	cout <<endl;

	return 0;
}

// 函数实现
int swap_value(int x, int y)
{
	int temp;

	temp = x;
	x = y;
	y = temp;

	return 0;
}

int swap_address(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;

	return 0;
}

int swap_reference(int &x, int &y)
{
	int temp;

	temp = x;
	x = y;
	y = temp;

	return 0;
}
