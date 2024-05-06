
#include <iostream>

template<class T>
class Base
{
public:
	Base(void) {
		std::cout << "constructor" << std::endl;
	}
	void	print(T n)
	{
		std::cout << n << std::endl;
	}
};
