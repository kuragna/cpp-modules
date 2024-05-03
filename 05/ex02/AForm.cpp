#include "AForm.hpp"

AForm::AForm(void) {}
AForm::AForm(const std::string &name, int gradeS, int gradeX)
{
	if (gradeS < 0 || gradeX < 0)
	{
		GradeTooHighException();
	}
	if (gradeS > 150 || gradeX > 150)
	{
		GradeTooLowException();
	}
	this->_signed	= false;
	this->name    	= name;
	this->gradeS  	= gradeS; // grade required to sign it
	this->gradeX	= gradeX; // grade required to execute it
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

void	AForm::GradeTooLowException(void) const
{
	throw std::out_of_range("out of range: grade too low");
}

void	AForm::GradeTooHighException(void) const
{
	throw std::out_of_range("out of range: grade too high");
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->gradeS)
	{
		GradeTooLowException();	
	}
	this->_signed = true;
}

std::ostream	&operator<<(std::ostream &os, const AForm &obj)
{
	std::string str = "No";
	if (obj.isSigned())
		str = "Yes";
	os << obj.getName() << ": Grades: " << obj.getGradeS() << " "
		 << obj.getGradeX() << ", " << "signed: " << str;
	return os;
}

AForm::~AForm() {}
