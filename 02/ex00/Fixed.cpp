#include "Fixed.hpp"

Fixed::Fixed()
{
	a = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &fixed)
{
	a = fixed.a;
	std::cout << "Copy constructor called\n";
}

Fixed	&Fixed::operator=(Fixed &)
{
	std::cout << "Copy assignment operator called\n";
	getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

void	Fixed::setRawBits(int const raw)
{
	a = raw;
	std::cout << "not impelemented yet\n";
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return a;
}
