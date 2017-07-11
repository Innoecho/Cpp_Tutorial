#include <iostream>
using namespace std;

// base class
class Shape
{
public:
	void setWidth(double w)
	{
		width = w;
	}
	void setHeight(double h)
	{
		height = h;
	}
protected:
	double width;
	double height;
};

// base class
class PaintCost
{
public:
	double getCost(double area)
	{
		return (area * 70);
	}
};

// derived class
class Rectangle: public Shape, public PaintCost
{
public:
	double getArea()
	{
		return (width * height);
	}
};

int main()
{
	Rectangle Rect;
	double area;

	Rect.setHeight(5.0);
	Rect.setWidth(7.0);

	area = Rect.getArea();

	// print object area
	cout << "Total area : " << area << endl;
	// print total cost
	cout << "Total cost : " << Rect.getCost(area) << endl;

	return 0;
}