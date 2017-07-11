#include <iostream>

// function declaration
void func(void);

// global variable
static int count = 10;

int main()
{
	while (count--)
	{
		func();
	}
	return 0;
}

// function defination
void func(void)
{
	// local static variable
	static int i = 5;
	i++;
	std::cout << "i = " << i;
	std::cout << "\tcount = " << count << std::endl;
}