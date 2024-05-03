#include "PresidentialPardonForm.hpp"

// TODO: grades: sign 25, exec 5
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential", 25, 5)
{
	std::cout << "'" << target << "': has been pardoned by Zaphod Beeblebrox" << std::endl;
}


bool PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	// TODO: make sure that works as expected
	if (!this->isSigned() && executor.getGrade() > this->getGradeX())
	{
		this->GradeTooLowException();
	}
	return true;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}
