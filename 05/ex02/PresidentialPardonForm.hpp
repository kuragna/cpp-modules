#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	std::string target;
public:
	PresidentialPardonForm(const std::string &target);
	bool execute(Bureaucrat const &executor) const;
	~PresidentialPardonForm(void);
};

#endif  // PRESIDENTIAL_PARDON_FORM_HPP
