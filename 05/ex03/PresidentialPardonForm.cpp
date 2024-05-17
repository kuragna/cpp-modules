#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("presidential pardon", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("presidential pardon", 25, 5)
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p) : AForm(p)
{
	operator=(p);
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &p)
{
	this->target = p.target;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!(this->isSigned() && executor.getGrade() < this->getGradeX()))
	{
		throw GradeTooHighException();
	}
}

PresidentialPardonForm	*PresidentialPardonForm::clone(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

