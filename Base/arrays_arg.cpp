#include <iostream>
using namespace std;

// declaration
double mean(int arr[], int size);

int main()
{
	int balance[5] = {1000, 2, 3, 17, 50};

	double average;

	average = mean(balance, 5);

	cout << "the average is " << average << endl;

	return 0;
}

// realization
double mean(int arr[], int size)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	return double(sum) / size;
}