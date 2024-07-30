#include "iter.hpp"
#include <iostream>

#define LEN(arr) sizeof(arr) / sizeof(arr[0])

template<typename T>
void print(T &t)
{
	std::cout << "-> " << t << std::endl;
}


int main(void)
{
	// intergers
	int	n[] = {1, 2, 3};
	iter<int>(n, LEN(n), print);

	std::cout << "-----------" << std::endl;

	// float
	float f[] = {2.1f, 100.0f, 42.0f, -1.0f};
	iter<float>(f, LEN(f), print);

	std::cout << "-----------" << std::endl;

	// c_str
	const char *names[] = {"foo", "bar", "baz"};
	iter<const char *>(names, LEN(names), print);

	std::cout << "-----------" << std::endl;

	// characters
	char chars[] = {'x', 'y', 'z'};
	::iter(chars, LEN(chars), print);

	std::cout << "-----------" << std::endl;

	// string
	const std::string strs[] = {"c/c++", "python", "c#", "rust"};
	::iter(strs, LEN(strs), print);

	return 0;
}
