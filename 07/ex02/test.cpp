
#include <iostream>
#include "test.hpp"


int main()
{
	Base<const char *> a;

	a.print("test");
	return 0;
}