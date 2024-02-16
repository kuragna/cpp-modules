#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : virtual public IMateriaSource
{
	static const int materias_size = 4;
	int	materias_len;	
	AMateria *materias[materias_size];
public:

	MateriaSource(void);
	MateriaSource(const MateriaSource &ms);
	MateriaSource &operator=(const MateriaSource &ms);
	~MateriaSource(void);


	void	learnMateria(AMateria *am);
	AMateria	*createMateria(std::string const &type);
};

#endif // I_MATERIA_SOURCE_HPP
