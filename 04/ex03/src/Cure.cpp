#include "../include/Cure.hpp"

Cure::Cure(void) : AMateria()
{
	type = "cure";
}

Cure::Cure(const std::string &type) : AMateria(type)
{
	this->type = type;
}

Cure::Cure(const Cure &cure) : AMateria(cure)
{
	type = cure.type;
}

Cure	&Cure::operator=(const Cure &cure)
{
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
	return new Cure(*this);
}


Cure::~Cure(void) {}

