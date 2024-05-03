#include "RobotomyRequestForm.hpp"

// TODO: grades: sign 72, exec 45
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy", 72, 45)
{
	for (int i = 0; i < 3; i +=  1)
	{
		std::cout << "tr..tr..tr" << std::endl;
	}
	std::cout << "'" << target << "': has been robotomized" << std::endl;
	// TODO: how it failed?
}

bool	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	// TODO: make sure that works as expected
	if (!this->isSigned() && executor.getGrade() > this->getGradeX())
	{
		this->GradeTooLowException();
	}
	return true;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}
