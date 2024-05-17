#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : grade(0) {}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.name), grade(obj.grade) {}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj)
{
	this->grade = obj.grade;
	return *this;	
}

Bureaucrat::Bureaucrat(int _grade, const std::string &_name) : name(_name), grade(_grade)
{
	if (grade < 0)
	{
		throw GradeTooHighException();
	}
	if (grade > 150)
	{
		throw GradeTooLowException();
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
	if (this->grade < 0)
	{
		throw GradeTooHighException();
	}
}
void    Bureaucrat::decrement(void)
{
    this->grade += 1;
	if (this->grade > 150)
	{
		throw GradeTooLowException();
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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}

Bureaucrat::~Bureaucrat() {}