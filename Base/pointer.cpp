#include <iostream>
using namespace std;

int main()
{
	int var = 20;
	int *ip;

	ip = &var;

	cout << "Value of var variable : " ;
	cout << var << endl;

	cout << "Address of ip pointer : " ;
	cout << ip << endl;

	cout << "Value of ip pointer : " ;
	cout << *ip << endl;

	return 0;
}