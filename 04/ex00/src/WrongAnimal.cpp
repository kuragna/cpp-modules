#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal defualt constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wa)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	operator=(wa);
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wa)
{
	std::cout << "WrongAnimal assignemnt operator called" << std::endl;
	type = wa.type;
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
