#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	std::string target;
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &p);
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &p);
	~PresidentialPardonForm(void);

	PresidentialPardonForm	*clone(const std::string &target) const;
	void execute(Bureaucrat const &executor) const;
};
#endif // PRESIDENTIALPARDONFORM_HPP
