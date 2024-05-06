#include "Array.hpp"
#include <iostream>

#if 0
class Base
{
	int	size;
	int	*_addr;
public:
	Base() {
		this->size = 1;
		this->_addr = new int[1]();
	}
	Base(int n)
	{
		this->size = n;
		this->_addr = new int[n]();
	}
	Base(const Base &obj)
	{
		this->size = obj.size;
		//delete[] this->_addr;
		//this->_addr = new int[this->size]();
		for (int i = 0; i < this->size; i += 1)
		{
			this->_addr[i] = obj._addr[i];
		}
	}
	~Base()
	{
		delete[] this->_addr;
	}
};
#endif

int main(void)
{
	// 8 bytes
	Array<int> a(2);

	// 4 bytes
	Array<int> b(a);







	// using int()
	// allocate single elements and initialized
	//int	*a = new int(-1);

	// using int[]
	// allocate n elements without initialize
	//int	*b = new int[2];


	//Array<int> a(10);

	return 0;
}
