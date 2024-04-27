#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int grade, const std::string &name)
{
	if (grade < 0)
	{
		GradeTooHighException();
	}
	if (grade > 150)
	{
		GradeTooLowException();
	}
	this->grade = grade;
	this->name  = name;
}

const std::string &Bureaucrat::getName(void) const
{
    return this->name;
}

int Bureaucrat::getGrade(void) const
{
    return this->grade;
}

void    Bureaucrat::increment(void)
{
    this->grade -= 1;
		if (this->grade < 0)
		{
			GradeTooHighException();
		}
}
void    Bureaucrat::decrement(void)
{
    this->grade += 1;
		if (this->grade > 150)
		{
			GradeTooLowException();
		}
}

void    Bureaucrat::GradeTooLowException(void)
{
		throw std::out_of_range("out of range: grade too low");
}

void    Bureaucrat::GradeTooHighException(void)
{
		throw std::out_of_range("out of range: grade too high");
}

Bureaucrat::~Bureaucrat() {}


std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}