#include "Intern.hpp"

Intern::Intern(void)
{
	this->forms[0] = new ShrubberyCreationForm();
	this->forms[1] = new RobotomyRequestForm();
	this->forms[2] = new PresidentialPardonForm();
}

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
	for (int i = 0; i < 3; i += 1)
	{
		if (name == this->forms[i]->getName())
		{
			std::cout << "Intern creates '" << name << "'" << std::endl;
			return forms[i]->clone(target);
		}
	}
	std::cerr << "Intern could not create '" << name << "'" << std::endl;
	return 0;
}

Intern::~Intern(void)
{
	for (int i = 0; i < 3; i += 1)
	{
		delete this->forms[i];
	}
}

