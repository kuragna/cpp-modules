#include "RobotomyRequestForm.hpp"

int	RobotomyRequestForm::count = 0;

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("robotomy request", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("robotomy request", 72, 45)
{
	std::cout << "trrr...trrr...trrr..." << std::endl;
	if (this->count % 2 == 0)
	{
		std::cout << target << " has been robotomized" << std::endl;
	}
	else
	{
		std::cerr << target << " failed to robotomize" << std::endl;
	}
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &r) : AForm(r)
{
	operator=(r);
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &r)
{
	this->target = r.target;
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!(this->isSigned() && executor.getGrade() < this->getGradeX()))
	{
		throw GradeTooHighException();
	}
}

RobotomyRequestForm	*RobotomyRequestForm::clone(const std::string &target) const
{
	return new RobotomyRequestForm(target);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

