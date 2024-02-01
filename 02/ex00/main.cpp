
#include "Fixed.hpp"

int main()
{
	Fixed a;								// default
	Fixed b(a);								// copy

	Fixed c;								// default

	c = b;									// assignment

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
