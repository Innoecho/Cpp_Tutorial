#include <iostream>
#include <string>

using namespace std;

struct Books
{
	string title;
	string author;
	string subject;
	int id;
};

void printBook(Books *book);
void setBook(Books *book, string title, string author, string subject, int id);

int main()
{
	Books book1;
	Books book2;
	setBook(&book1, "C++", "Runoob", "Program Language", 12345);
	setBook(&book2, "CSS", "Runoob", "Front-End", 12346);

	printBook(&book1);
	printBook(&book2);

	return 0;
}

void printBook(Books *book)
{
	cout << "Title : " << book->title << endl;
	cout << "Author : " << book->author << endl;
	cout << "Subject : " << book->subject << endl;
	cout << "ID : " << book->id << endl;
	cout << endl;
}

void setBook(Books *book, string title, string author, string subject, int id)
{
	book->title = title;
	book->author = author;
	book->subject = subject;
	book->id = id;
}