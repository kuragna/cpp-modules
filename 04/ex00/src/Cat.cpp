#include "../include/Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat defualt constructor called" << std::endl;
}

Cat::Cat(const std::string &type) : Animal(type)
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = type;
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	type = cat.type;
}

Cat	&Cat::operator=(const Cat &cat)
{
	Animal::operator=(cat);
	std::cout << "Cat assignemnt operator called" << std::endl;
	type = cat.type;
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "[sound]: Meow.. Meow.. Meow..!" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

