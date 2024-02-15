
#include "../include/Ice.hpp"

Ice::Ice(void) : AMateria()
{
	std::cout << "Ice defualt constructor called" << std::endl;
}

Ice::Ice(const std::string &type)
{
	std::cout << "Ice constructor called" << std::endl;
	this->type = type;
}

Ice::Ice(const Ice &ice) : AMateria(ice)
{
	std::cout << "Ice copy constructor called" << std::endl;
	type = ice.type;
}

Ice	&Ice::operator=(const Ice &ice)
{
	AMateria::operator=(ice);
	type = ice.type;
	std::cout << "Ice assignment operator called" << std::endl;
	return *this;
}

std::string const &Ice::getType() const
{
	return type;
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice	*Ice::clone(void) const
{
	Ice *ice = new Ice(*this);
	std::cout << "address: `" << ice << "` -> " << __FILE__ << ":" << __LINE__ << std::endl;
	return (ice);
}


Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
}

