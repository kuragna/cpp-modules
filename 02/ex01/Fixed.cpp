#include "Fixed.hpp"

Fixed::Fixed()
{
	i = 0;
	f = 0.0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int _i)
{
	i = _i;
	f = 0.0;
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float _f)
{
	f = _f;
	i = 0;
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &fixed)
{
	i = fixed.i;
	f = fixed.f;
	std::cout << "Copy constructor called\n";
}

Fixed	&Fixed::operator=(Fixed const &fixed)
{
	i = fixed.i;
	f = fixed.f;
	std::cout << "Copy assignment operator called\n";
	return *this;
}

std::ostream	&operator<<(std::ostream &os, Fixed const &fixed)
{
	// TODO: fix zero value
	if (fixed.i == 0)
		std::cout << fixed.f * 1.0;
	else
		std::cout << fixed.i;
	return os;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

void	Fixed::setRawBits(int const raw)
{
	i = raw;
	std::cout << "setRawBits member function called\n";
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return i;
}

float	Fixed::toFloat(void) const
{
	return ((float)i / (float)(1 << b));
}

int		Fixed::toInt(void) const
{
	if (i == 0)
		return roundf(f);
	return i;
}
