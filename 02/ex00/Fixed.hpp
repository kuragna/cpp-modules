#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	int	number;
	static const int bits = 8;

public:
	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed &fixed);
	Fixed	&operator=(const Fixed &fixed);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif // FIXED_HPP
