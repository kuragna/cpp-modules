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
	Fixed &operator=(const Fixed &fixed);
	~Fixed(void);

	int		getRawBits(void) const;
	float	toFloat(void) const;
	int	  	toInt(void) const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP
