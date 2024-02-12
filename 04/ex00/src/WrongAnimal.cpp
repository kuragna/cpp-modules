#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal defualt constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wa)
{
	(void) wa;
	std::cout << "WrongAnimal copy constructor called" << std::endl;	
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wa)
{
	(void) wa;
	std::cout << "WrongAnimal assignemnt operator called" << std::endl;
	return *this;
}

void	WrongAnimal::makeSound(void)
{
	std::cout << "[sound]: WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}
