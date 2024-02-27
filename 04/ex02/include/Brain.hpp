#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	static size_t const brainSize = 100;
	std::string	ideas[brainSize];
public:
	Brain(void);
	Brain(const Brain &brain);
	Brain	&operator=(const Brain &brain);
	~Brain(void);
};
#endif // BRAIN_HPP
