#include "AForm.hpp"

AForm::AForm(void) : gradeS(1), gradeX(1), _signed(false) {}

AForm::AForm(const std::string &_name, int _gradeS, int _gradeX) : name(_name), gradeS(_gradeS), gradeX(_gradeX)
{
	if (gradeS < 1 || gradeX < 1)
	{
		throw GradeTooHighException();
	}
	if (gradeS > 150 || gradeX > 150)
	{
		throw GradeTooLowException();
	}
	this->_signed	= false;
}

AForm::AForm(const AForm &obj) : name(obj.name), gradeS(obj.gradeS), gradeX(obj.gradeX), _signed(obj._signed) {}

AForm	&AForm::operator=(const AForm &obj)
{
	(void) obj;
	return *this;
}

const std::string &AForm::getName(void) const
{
	return this->name;
}

int	AForm::getGradeS(void) const
{
	return this->gradeS;
}

int	AForm::getGradeX(void) const
{
	return this->gradeX;
}

bool	AForm::isSigned(void) const
{
	return this->_signed;
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->gradeS)
	{
		this->_signed = true;
	}
	else throw GradeTooLowException();
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Form::GradeTooLowException";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Form::GradeTooHighException";
}

std::ostream	&operator<<(std::ostream &os, const AForm &obj)
{
	os << obj.getName() 
	   << ", form grades: "
	   << obj.getGradeS()
	   << ", "
	   << obj.getGradeX();
	return os;
}

AForm::~AForm() {}
