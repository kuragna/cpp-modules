
#include "../include/Ice.hpp"

Ice::Ice(void) : AMateria()
{
	type = "ice";
}

Ice::Ice(const std::string &type) : AMateria(type) {}

Ice::Ice(const Ice &ice) : AMateria(ice) {}

Ice	&Ice::operator=(const Ice &ice)
{
	AMateria::operator=(ice);
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
	return (new Ice(*this));
}


Ice::~Ice(void) {}

