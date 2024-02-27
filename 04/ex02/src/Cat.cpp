#include "../include/Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat defualt constructor called" << std::endl;
	brain = new Brain();
}

Cat::Cat(const std::string &type)
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = type;
	brain      = new Brain();
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	type  = cat.type;
	brain = new Brain(*cat.brain);
}

Cat	&Cat::operator=(const Cat &cat)
{
	Animal::operator=(cat);
	std::cout << "Cat assignemnt operator called" << std::endl;
	type 	= cat.type;
	*brain	= *cat.brain;
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "[sound]: Meaw.. Meaw.. Meaw..!" << std::endl;
}

Cat::~Cat(void)
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

