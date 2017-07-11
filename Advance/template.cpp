#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <class T> class Stack
{
private:
	vector<T> elems;
public:
	void push(T const&);
	void pop();
	T top() const;
	bool empty() const
	{
		return elems.empty();
	}
};

template <class T> void Stack<T>::push(T const &elem)
{
	elems.push_back(elem);
}

template <class T> void Stack<T>::pop()
{
	if (empty())
		throw out_of_range("Stack<>::pop(): empty stack");
	elems.pop_back();
}

template <class T> T Stack<T>::top() const
{
	if (empty())
		throw out_of_range("Stack<>::pop(): empty stack");
	return elems.back();
}

int main()
{
	try
	{
		Stack<int> stack;
		int count = 10;

		cout << "push order: " << endl;
		for (int i = 0; i < count; ++i)
		{
			cout << i << "  ";
			stack.push(i);
		}
		cout << endl;
		cout << "pop order: " << endl;
		do
		{
			cout << stack.top() << "  ";
			stack.pop();
		} while (!stack.empty());
		cout << endl;
	}
	catch (exception const& e)
	{
		cerr << "Exception: " << e.what() << endl;
		return 0;
	}
}