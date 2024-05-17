#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	std::string target;
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &s);
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &s);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm *clone(const std::string &target) const;
	void execute(Bureaucrat const &executor) const;
};
#endif // SHRUBBERY_CREATION_FORM_HPP
