#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &intern)
{
	(void) intern;
}

Intern	&Intern::operator=(const Intern &intern)
{
	(void) intern;
	return *this;
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i += 1)
	{
		if (names[i] == name)
		{
			std::cout << "Intern creates '" << name << "'" << std::endl;
			switch (i)
			{
			case 0: return new ShrubberyCreationForm(target);
			case 1: return new RobotomyRequestForm(target);
			case 2: return new PresidentialPardonForm(target);
			}
		}
	}
	std::cerr << "Intern could not create '" << name << "'" << std::endl;
	return 0;
}

Intern::~Intern(void) {}

