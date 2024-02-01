#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	nb = 0;
}

Fixed::Fixed(const int _nb)
{
	std::cout << "Int constructor called" << std::endl;
	nb = _nb * (1 << bits);
}

Fixed::Fixed(const float _nb)
{
	std::cout << "Float constructor called" << std::endl;
	nb = std::roundf(_nb * (1 << bits));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	nb = fixed.nb;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	nb = fixed.nb;
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	return ((float)nb) / (1 << bits);
}

int		Fixed::toInt(void) const
{
	return nb / (1 << bits);
}

int	Fixed::getRawBits(void) const
{
	return nb;
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << (float)fixed.toFloat();
	return os;
}
