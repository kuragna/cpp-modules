#include "../include/Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain defualt constructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain constructor called" << std::endl;
	operator=(brain);
}

Brain	&Brain::operator=(const Brain &brain)
{
	std::cout << "Brain assignment operator called" << std::endl;
	for (size_t i = 0; i < ideasSize; i += 1)
	{
		ideas[i] = brain.ideas[i];
	}
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}
