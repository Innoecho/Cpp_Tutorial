#include <iostream>
#include <string>
using namespace std;

class printData
{
public:
	void print(int i)
	{
		cout << "Printing int : " << i << endl;
	}
	void print(double f)
	{
		cout << "Printing double : " << f << endl;
	}
	void print(string s)
	{
		cout << "Printing string : " << s << endl;
	}
};

int main()
{
	printData pd;

	pd.print(5);
	pd.print(5.0);
	pd.print("Hello World");

	return 0;
}