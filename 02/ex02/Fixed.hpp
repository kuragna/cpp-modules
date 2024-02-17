#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	int	nb;
	static const int bits = 8;
public:
	Fixed(void);
	Fixed(const int nb);
	Fixed(const float nb);
	Fixed(const Fixed &fixed);
	~Fixed(void);

	Fixed &operator=(const Fixed &fixed);

	/* ---- comparison operators ---- */
	bool  operator<(const Fixed &fixed);
	bool  operator<=(const Fixed &fixed);
	bool  operator>(const Fixed &fixed);
	bool  operator>=(const Fixed &fixed);
	bool  operator==(const Fixed &fixed);
	bool  operator!=(const Fixed &fixed);

	/* ---- arithmetic operators ---- */
	Fixed	operator+(const Fixed &fixed);
	Fixed	operator-(const Fixed &fixed);
	Fixed	operator*(const Fixed &fixed);
	Fixed	operator/(const Fixed &fixed);


	/* ---- increment/decrement ---- */
	Fixed	operator++(int);			// post-increment
	Fixed	operator++(void);			// pre-increment
	Fixed	operator--(int);			// post-decrement
	Fixed	operator--(void);			// pre-decrement

	static Fixed &min(Fixed &f1, Fixed &f2);
	static Fixed &max(Fixed &f1, Fixed &f2);
	static Fixed &min(const Fixed &f1, const Fixed &f2);
	static Fixed &max(const Fixed &f1, const Fixed &f2);


	int		getRawBits(void) const;
	float	toFloat(void) const;
	int	  	toInt(void) const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP
