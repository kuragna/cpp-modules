#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	static const size_t ideasSize = 100;
	std::string	ideas[ideasSize];
public:
	Brain(void);
	Brain(const Brain &brain);
	Brain	&operator=(const Brain &brain);
	~Brain(void);
};
#endif // BRAIN_HPP
