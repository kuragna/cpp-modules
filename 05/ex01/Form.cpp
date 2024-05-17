#include "Form.hpp"

Form::Form(void) : gradeS(0), gradeX(0), _signed(false) {}

Form::Form(const std::string &_name, int _gradeS, int _gradeX) : name(_name), gradeS(_gradeS), gradeX(_gradeX)
{
	if (gradeS < 0 || gradeX < 0)
	{
		throw GradeTooHighException();
	}
	if (gradeS > 150 || gradeX > 150)
	{
		throw GradeTooLowException();
	}
	this->_signed	= false;
}

Form::Form(const Form &obj) : name(obj.name), gradeS(obj.gradeS), gradeX(obj.gradeX)
{
	this->_signed = false;
}

Form	&Form::operator=(const Form &obj)
{
	(void) obj;
	return *this;
}

const std::string &Form::getName(void) const
{
	return this->name;
}

int	Form::getGradeS(void) const
{
	return this->gradeS;
}

int	Form::getGradeX(void) const
{
	return this->gradeX;
}

bool	Form::isSigned(void) const
{
	return this->_signed;
}

void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() >= this->gradeS)
	{
		throw GradeTooLowException();	
	}
	this->_signed = true;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form::GradeTooLowException";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form::GradeTooHighException";
}

std::ostream	&operator<<(std::ostream &os, const Form &obj)
{
	os << obj.getName() 
	   << ", form grades: "
	   << obj.getGradeS()
	   << ", "
	   << obj.getGradeX();
	return os;
}

Form::~Form() {}
