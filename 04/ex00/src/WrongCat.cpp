#include "../include/WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WrongCat defualt constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wc) : WrongAnimal(wc)
{
	std::cout << "WrongCat copy constructor" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &wc)
{
	WrongAnimal::operator=(wc);
	std::cout << "WrongCat assignment operator constructor" << std::endl;
	return *this;
}

void	WrongCat::makeSound(void)
{
	std::cout << "[sound]: WrongCat Moaw..Moaw..." << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor" << std::endl;
}
