#include <iostream>
#include <cstring>

using namespace std;

#define DEBUG
#define MIN(a,b) ((a)<(b)?a:b)

int main()
{
	int i = 100, j = 30;

#ifdef DEBUG
	cerr << "Trace: Inside main()" << endl;
#endif

	cout << "The minimum is " << MIN(i, j) << endl;

#ifdef DEBUG
	cerr << "Trace: Coming out of main()" << endl;
#endif

	char str[100] = "";
	strcat(str, __DATE__);
	strcat(str, "  ");
	strcat(str, __TIME__);
	cout << "Compile at " <<str<<endl;
	return 0;
}