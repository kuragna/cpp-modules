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
	if (this->isSigned())
	{
		if (executor.getGrade() < this->getGradeX())
		{
			std::cout << "'" << executor.getName() << "' executed " << this->getName() << std::endl;
		}
		else throw GradeTooLowException();
	}
	else
	{
		std::cout << "'" << executor.getName() << "' couldn't execute " << this->getName() 
				  << " because is not signed" << std::endl;
	}
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

