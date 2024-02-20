#include "Fixed.hpp"

Fixed::Fixed(void)
{
	nb = 0;
}

Fixed::Fixed(const int _nb)
{
	nb = _nb * (1 << bits);
}

Fixed::Fixed(const float _nb)
{
	nb = std::roundf(_nb * (1 << bits));
}

Fixed::Fixed(const Fixed &fixed)
{
	operator=(fixed);
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	nb = fixed.nb;
	return *this;
}

/* ---- comparison operators ---- */
bool	Fixed::operator<(const Fixed &fixed)
{
	return nb < fixed.nb;
}

bool	Fixed::operator<=(const Fixed &fixed)
{
	return nb <= fixed.nb;
}

bool	Fixed::operator>(const Fixed &fixed)
{
	return nb > fixed.nb;
}

bool	Fixed::operator>=(const Fixed &fixed)
{
	return nb >= fixed.nb;
}

bool	Fixed::operator==(const Fixed &fixed)
{
	return nb == fixed.nb;
}

bool	Fixed::operator!=(const Fixed &fixed)
{
	return nb != fixed.nb;
}

/* ---- increment/decrement ---- */
Fixed	Fixed::operator++(void)
{
	++nb;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed fixed = *this;
	nb++;
	return fixed;
}

Fixed	Fixed::operator--(void)
{
	--nb;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed fixed = *this;
	nb--;
	return fixed;
}

/* ---- arithmetic operators ---- */
Fixed	Fixed::operator*(const Fixed &fixed)
{
	return Fixed((float)(nb * fixed.nb) / (1 << bits * 2));
}

Fixed	Fixed::operator+(const Fixed &fixed)
{
	return Fixed((float)(nb + fixed.nb) / (1 << bits));
}

Fixed	Fixed::operator-(const Fixed &fixed)
{
	return Fixed((float)(nb - fixed.nb) / (1 << bits));
}

Fixed	Fixed::operator/(const Fixed &fixed)
{
	return Fixed((float)(nb / fixed.nb));
}

/* ---- min/max ---- */
Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	return (f1 < f2) ? f1 : f2;
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	return (f2 > f1) ? f2 : f1;
}

Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	return min(const_cast<Fixed&>(f1), const_cast<Fixed&>(f2));
}

Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2)
{
	return max(const_cast<Fixed&>(f1), const_cast<Fixed&>(f2));	
}

Fixed::~Fixed(void) {}

float	Fixed::toFloat(void) const
{
	return (float)nb / (1 << bits);
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
	os << fixed.toFloat();
	return os;
}
