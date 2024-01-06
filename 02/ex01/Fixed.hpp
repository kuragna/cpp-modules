#include <iostream>
#include <cmath>

class Fixed
{
	int		i;
	float	f;
	static const int b = 8;
	public:
	Fixed();
	Fixed(const int i);
	Fixed(const float f);
	Fixed(const Fixed &fixed);
	Fixed &operator=(Fixed const &fixed);
	friend std::ostream &operator<<(std::ostream &os, Fixed const &fixed);
	~Fixed();
	void	setRawBits(int const raw);
	int		getRawBits(void) const;
	float	toFloat(void) const;
	int		toInt(void) const;
};