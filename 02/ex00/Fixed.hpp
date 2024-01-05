#include <iostream>

class Fixed
{
	int	a;
	static const int b = 8;
	public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed &operator=(Fixed &);
	~Fixed();
	void	setRawBits(int const raw);
	int		getRawBits(void) const;
};
