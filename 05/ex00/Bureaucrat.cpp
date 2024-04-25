#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(int grade)
{
    this->name  = "foo";

    if (grade < 0 || grade > 150)
    {
        throw std::runtime_error("out of range");
    }
    // TODO: exception
    this->grade = grade;
}

std::string &Bureaucrat::getName(void)
{
    return this->name;
}

int Bureaucrat::getGrade(void)
{
    return this->grade;
}

void    Bureaucrat::increment(void)
{
    this->grade += 1;
    if (this->grade > 150)
    {
        throw std::runtime_error("icrement");
    }
}
void    Bureaucrat::decrement(void)
{
    this->grade -= 1;
    if (this->grade < 0)
    {
        throw std::runtime_error("decrement");
    }
}

void    Bureaucrat::GradeTooLowException(void)
{
    assert(__FUNCTION__ && 0);
}

void    Bureaucrat::GradeTooHighException(void)
{
    assert(__FUNCTION__ && 0);
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}