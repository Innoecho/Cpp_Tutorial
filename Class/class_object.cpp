#include <iostream>
using namespace std;

class Box
{
private:
	// private member
	double length;
	double width;
	double height;
	double volume;
	double *ptr;
public:
	// static member
	static int objectCount;
	// static function
	static int getCount()
	{
		return objectCount;
	}
	// member function
	double getVolume(void);
	void setLength(double l);
	void setWidth(double w);
	void setHeight(double h);
	// friend function
	friend void printVolume(Box obj);
	// this pointer
	bool compare(Box obj);
	// construct function
	Box(double l, double w, double h);
	// copy construct function
	Box(const Box &obj);
	// destruct function
	~Box();
};

double Box::getVolume(void)
{
	volume = length * width * height;
	return volume;
}
void Box::setLength(double l)
{
	length = l;
}
void Box::setWidth(double w)
{
	width = w;
}
void Box::setHeight(double h)
{
	height = h;
}
void display(Box obj)
{
	cout << "The volume of box is " << obj.getVolume() << endl;
}
// friend function
void printVolume(Box obj)
{
	cout << "The volume of box is " << obj.volume << endl;
}
// this pointer
bool Box::compare(Box obj)
{
	return this->getVolume() > obj.getVolume();
}
// construct function
Box::Box(double l, double w, double h): length(l), width(w), height(h)
{
	cout << "Call construct Function" << endl;
	volume = length * width * height;
	ptr = new double;
	*ptr = volume;
	objectCount++;
}
// copy construct function
Box::Box(const Box &obj)
{
	cout << "Call copy construct Function" << endl;
	length = obj.length;
	width = obj.width;
	height = obj.height;
	volume = obj.volume;
	ptr = new double;
	*ptr = *obj.ptr;
	objectCount++;
}
// destruct function
Box::~Box()
{
	cout << "Call destruct function" << endl;
	objectCount--;
}

int Box::objectCount = 0;

int main()
{
	cout << "Inital Stage Count : " << Box::getCount() << endl;
	Box box1(5.0, 6.0, 7.0);
	Box *ptrbox;

	ptrbox = &box1;

	display(box1);

	ptrbox->setHeight(8.0);

	display(box1);



	if (ptrbox->compare(box1))
	{
		cout << "box1 is bigger than box2" << endl;
	}
	else
	{
		cout << "box1 is not bigger than box2" << endl;
	}

	cout << "Final Stage Count : " << Box::getCount() << endl;

	return 0;
}