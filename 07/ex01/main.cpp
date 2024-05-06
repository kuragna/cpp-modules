#include "iter.hpp"
#include <iostream>

#define LEN(arr) sizeof(arr) / sizeof(arr[0])


// NOTE: we can turn `print` function to template
void	print(int n)
{
	std::cout << "int: " << n << std::endl;
}

void	print(float n)
{
	std::cout << "float: " << n << std::endl;
}

void	print(const char *name)
{
	std::cout << "c_str: " << name << std::endl;
}

void	print(char c)
{
	std::cout << "char: " << c << std::endl;
}


int main(void)
{
	// intergers
	int	n[] = {1, 2, 3};
	iter<int>(n, LEN(n), print);

	std::cout << std::endl;

	// float
	float f[] = {2.1f, 100.0f, 42.0f, -1.0f};
	iter<float>(f, LEN(f), print);

	std::cout << std::endl;

	// c_str
	const char *names[] = {"foo", "bar", "baz"};
	iter<const char *>(names, LEN(names), print);

	std::cout << std::endl;

	// characters
	char chars[] = {'x', 'y', 'z'};
	::iter(chars, LEN(chars), print);


	return 0;
}
