#include "Form.hpp"

Form::Form(const std::string &name, int gradeS, int gradeX)
{
	if (gradeS < 0 || gradeX < 0)
	{
		GradeTooHighException();
	}
	if (gradeS > 150 || gradeX > 150)
	{
		GradeTooLowException();
	}
	this->_signed = false;
	this->name     = name;
	this->gradeS   = gradeS; // grade required to sign it
	this->gradeX	 = gradeX; // grade required to execute it
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

void	Form::GradeTooLowException(void)
{
	throw std::out_of_range("out of range: grade too low");
}

void	Form::GradeTooHighException(void)
{
	throw std::out_of_range("out of range: grade too high");
}

void	Form::beSigned(Bureaucrat &b)
{
	const int bGrade = b.getGrade();

	if (bGrade > this->gradeS)
	{
		GradeTooLowException();	
	}
	this->_signed = true;
}

std::ostream	&operator<<(std::ostream &os, const Form &obj)
{
	std::string str = "No";
	if (obj.isSigned())
		str = "Yes";
	os << obj.getName() << ", Grades: " << obj.getGradeS() << " "
		 << obj.getGradeX() << ", " << "signed: " << str;
	return os;
}

Form::~Form() {}
