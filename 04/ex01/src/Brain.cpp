#include "../include/Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain defualt constructor called" << std::endl; 
}

Brain::Brain(const Brain &brain)
{
	(void) brain;
	std::cout << "Brain constructor called" << std::endl;
	// TODO: copy brain.ideas to ideas
	//ideas = brain.ideas;
}

Brain	&Brain::operator=(const Brain &brain)
{
	(void) brain;
	std::cout << "Brain assignment operator called" << std::endl;
	//ideas = brean.ideas;
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

