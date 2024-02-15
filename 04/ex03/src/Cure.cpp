#include "../include/Cure.hpp"

Cure::Cure(void) : AMateria()
{
	std::cout << "Cure defualt constructor called" << std::endl;
}

Cure::Cure(const std::string &type) : AMateria(type)
{
	std::cout << "Cure constructor called" << std::endl;
	this->type = type;
}

Cure::Cure(const Cure &cure) : AMateria(cure)
{
	std::cout << "Cure copy constructor called" << std::endl;
	type = cure.type;
}

Cure	&Cure::operator=(const Cure &cure)
{
	std::cout << "Cure assignment operator called" << std::endl;
	AMateria::operator=(cure);
	type = cure.type;
	return *this;
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
std::string const &Cure::getType() const
{
	return type;
}

Cure	*Cure::clone(void) const
{
	Cure *cure = new Cure(*this);
	std::cout << "address: `" << cure << "` -> " << __FILE__  << ":" << __LINE__ << std::endl;
	return (cure);
}


Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}

