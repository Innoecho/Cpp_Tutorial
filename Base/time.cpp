#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	// current time
	time_t now = time(0);

	// convert now to string
	char *dt = ctime(&now);

	cout << "Local date and time : " << dt << endl;

	// convert now to struct tm
	tm *gmtm = gmtime(&now);
	dt = asctime(gmtm);
	cout << "UTC date and time : " << dt << endl;

	cout << "Number of sec since January 1, 1970 : " << now << endl;

	tm *ltm = localtime(&now);

	cout << "Year : " << 1900 + ltm->tm_year << endl;
	cout << "Month : " << 1 + ltm->tm_mon << endl;
	cout << "Day : " << ltm->tm_mday << endl;
	cout << "Time : " << ltm->tm_hour << " : ";
	cout << ltm->tm_min << " : ";
	cout << ltm->tm_sec << endl;

	return 0;
}