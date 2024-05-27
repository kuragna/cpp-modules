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
	this->count += 1;
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

RobotomyRequestForm::~RobotomyRequestForm(void) {}

