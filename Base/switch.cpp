#include <iostream>
using namespace std;

int main()
{
	char grade = 'D';

	switch (grade)
	{
	case 'A':
		cout << " Well Done" << endl;
		break;
	case 'B':
	case 'C':
		cout << "Very Good" << endl;
		break;
	case 'D':
		cout << "Pass it" << endl;
		break;
	case 'F':
		cout << "Try again" << endl;
		break;
	default :
		cout << "Invaild Grade" << endl;
	}
	cout << "Your grade is " << grade << endl;
	
	return 0;
}