#include "../include/MateriaSource.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i += 1)
	{
		materias[i] = 0;
	}
	std::cout << "MateriaSource defualt constructor called" << std::endl;	
}

MateriaSource::MateriaSource(const MateriaSource &ms)
{
	std::cout << "MateriaSource constructor called" << std::endl;	
	for (int i = 0; i < 4; i += 1)
	{
		materias[i] = ms.materias[i];
	}
	// TODO: memory leaks
}

MateriaSource &MateriaSource::operator=(const MateriaSource &ms)
{
	std::cout << "MateriaSource assignemnt operator called" << std::endl;
	// TODO: memory leaks
	for (int i = 0; i < 4; i += 1)
	{
		materias[i] = ms.materias[i];
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *am)
{
	int i;

	for (i = 0; i < 4; i += 1)
	{
		if (!materias[i]) break ;
	}
	materias[i] = am;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	AMateria *am = 0;
	if (type == "ice")
	{
		am = new Ice(type);
	}
	else if (type == "cure")
	{
		am = new Cure(type);
	}
	std::cout << "address: `" << am << "` -> " << __FILE__ ":" << __LINE__ << std::endl;
	return am;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i += 1)
	{
		delete materias[i];
	}
	std::cout << "MateriaSource destructor called" << std::endl;
};
