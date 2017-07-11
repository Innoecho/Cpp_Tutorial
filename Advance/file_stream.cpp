#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char data[100];

	// open file with write mode
	ofstream outfile;
	outfile.open("file.dat");

	cout << "Writing to the file" <<endl;
	cout << "Enter your name: " <<endl;
	cin.getline(data, 100);

	// write file
	outfile<<data<<endl;

	cout << "Enter your age: " <<endl;
	cin>>data;
	cin.ignore();

	// write file
	outfile<<data<<endl;

	// close file
	outfile.close();

	// open file with read mode
	ifstream infile;
	infile.open("file.dat");

	cout << "Reading from the file" <<endl;
	// read data
	infile >> data;

	// print data
	cout << data <<endl;

	// read data
	infile >> data;

	// print data
	cout << data <<endl;

	// close file
	infile.close();

	return 0;
}