#include <iostream>
using namespace std;

// base class
class Shape
{
protected:
	double width, height;
public:
	Shape(double w = 0, double h = 0)
	{
		width = w;
		height = h;
	}
	virtual double area() = 0;
};

// derived class
class Rectangle: public Shape
{
public:
	Rectangle(double w = 0, double h = 0): Shape(w, h) {}
	double area()
	{
		double area = width * height;
		cout << "Rectangle class area : " << area << endl;
		return area;
	}
};

// derived class
class Triangle: public Shape
{
public:
	Triangle(double w = 0, double h = 0): Shape(w, h) {}
	double area()
	{
		double area = width * height / 2;
		cout << "Triangle class area : " << area << endl;
		return area;
	}
};

int main()
{
	// use pointer to call object
	Shape *shape;
	Rectangle rec(10, 7);
	Triangle tri(10, 5);

	// pointer of parent class can point to children class
	shape = &rec;
	shape->area();

	shape = &tri;
	shape->area();

	return 0;
}