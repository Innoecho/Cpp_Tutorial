#include <iostream>
#include <vector>

using namespace std;

class Obj
{
	static int i;
public:
	void f() const {cout << i++ << endl;}
};

int Obj::i = 1;

class ObjContainer
{
	vector <Obj*> a;
public:
	void add(Obj* obj)
	{
		a.push_back(obj);
	}
	friend class SmartPointer;
};

class SmartPointer
{
	ObjContainer oc;
	int index;
public:
	SmartPointer(ObjContainer &objc)
	{
		oc = objc;
		index = 0;
	}
	bool operator++()
	{
		if (index >= oc.a.size()) return false;
		if (oc.a[++index] == 0) return false;
		return true;
	}
	bool operator++(int)
	{
		return operator++();
	}
	Obj *operator->() const
	{
		if (!oc.a[index])
		{
			cout << "Zero value" << endl;
			return (Obj*)0;
		}
		return oc.a[index];
	}
};

int main()
{
	const int size = 10;
	Obj o[size];
	ObjContainer oc;
	for (int i = 0; i < size; ++i)
	{
		oc.add(&o[i]);
	}
	SmartPointer sp(oc);
	do
	{
		sp->f();
	} while (sp++);

	return 0;
}