#include <iostream>
using namespace std;

const int SIZE = 10;

class safearray
{
private:
	int arr[SIZE];
public:
	safearray()
	{
		register int i;
		for (int i = 0; i < SIZE; ++i)
		{
			arr[i] = i;
		}
	}
	int &operator[](int i)
	{
		if(i>SIZE)
		{
			cout << "index over range" <<endl;
			return arr[0];
		}
		return arr[i];
	}
};

int main()
{
	safearray A;

	cout << A[2] <<endl;
	cout << A[5] <<endl;
	cout << A[12] <<endl;
	
	return 0;
}