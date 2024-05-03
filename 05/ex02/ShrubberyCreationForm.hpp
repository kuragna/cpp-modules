#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	std::string target;
	std::ofstream file;
public:
	ShrubberyCreationForm(const std::string &target);
	bool execute(Bureaucrat const &executor) const;
	~ShrubberyCreationForm();
};

#endif  // SHRUBBERY_CREATION_FORM_HPP
