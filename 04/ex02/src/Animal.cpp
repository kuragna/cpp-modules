#include "../include/Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal defualt constructor called" << std::endl;
}

Animal::Animal(const std::string type)
{
	std::cout << "Animal constructor called" << std::endl;
	this->type = type;
}

Animal::Animal(const Animal &animal)
{
	std::cout << "Animal copy constructor called" << std::endl;
	type = animal.type;
}

Animal	&Animal::operator=(const Animal &animal)
{
	std::cout << "Animal assignment operator called" << std::endl;
	type = animal.type;
	return *this;
}

const std::string &Animal::getType(void) const
{
	return type;
}

void	Animal::makeSound(void) const
{
	std::cout << "[sound]: Animal" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

