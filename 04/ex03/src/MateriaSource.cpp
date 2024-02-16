#include "../include/MateriaSource.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < materias_size; i += 1)
	{
		materias[i] = 0;
	}
	materias_len = 0;
}

MateriaSource::MateriaSource(const MateriaSource &ms)
{
	for (int i = 0; i < materias_len && i < materias_size; i += 1)
	{
		materias[i] = ms.materias[i]->clone();
	}
	materias_len = ms.materias_len;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &ms)
{
	for (int i = 0; i < materias_len && i < materias_size; i += 1)
	{
		materias[i] = ms.materias[i]->clone();
	}
	materias_len = ms.materias_len;
	return *this;
}


void	MateriaSource::learnMateria(AMateria *am)
{
	if (materias_len < materias_size)
	{
		materias[materias_len] = am;
		materias_len += 1;
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < materias_len; i += 1)
	{
		if (materias[i]->getType() == type)
			return materias[i]->clone();
	}
	return 0;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < materias_len && i < materias_size; i += 1)
	{
		delete materias[i];
	}
};
