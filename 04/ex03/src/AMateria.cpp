#include "../include/AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << "AMateria defualt constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &aMateria)
{
	type = aMateria.type;
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria	&AMateria::operator=(const AMateria &aMateria)
{
	type = aMateria.type;
	return *this;
}

std::string const &AMateria::getType() const
{
	return type;
}

void	AMateria::use(ICharacter &target)
{
	std::cout << target.getName() << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

