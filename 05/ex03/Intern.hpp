#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern(void);
	Intern(const Intern &intern);
	Intern	&operator=(const Intern &intern);
	~Intern(void);

	AForm	*makeForm(const std::string &name, const std::string &target);
};
#endif // INTERN_HPP
