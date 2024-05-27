#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : grade(1) {}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.name), grade(obj.grade) {}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj)
{
	this->grade = obj.grade;
	return *this;	
}

Bureaucrat::Bureaucrat(int _grade, const std::string &_name) : name(_name), grade(_grade)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
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
	if (this->grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
}
void    Bureaucrat::decrement(void)
{
    this->grade += 1;
	if (this->grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat::GradeTooLowException";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat::GradeTooHighException";
}

void	Bureaucrat::signForm(AForm &form)
{
	if (form.isSigned())
	{
		std::cout << "'"
				  << this->name
				  << "' couldn't sign '"
				  << form.getName()
				  << "' because it's signed" << std::endl;
		return ;
	}
	if (this->grade <= form.getGradeS())
	{
		form.beSigned(*this);
		std::cout << "'" << this->name << "' signed '" << form.getName() << "'" << std::endl;
	}
	else
	{
		std::cout << "'"
				  <<  this->name
				  << "' couldn't sign "
				  << form.getName()
				  << " because grade too low" << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	if (form.isSigned())
	{
		if (this->grade < form.getGradeX())
		{
			std::cout << "'" << this->name << "' executed " << form.getName() << std::endl;
		}
		else
		{
			std::cout << "'" << this->name  << "' couldn't execute " << form.getName()
				  << " because grade is low" << std::endl;
		}
	}
	else
	{
		std::cout << "'" << this->name << "' couldn't execute " << form.getName()
				  << " because is not signed" << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}

Bureaucrat::~Bureaucrat() {}