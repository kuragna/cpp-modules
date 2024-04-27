#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	// TODO: why is constant?
	std::string name;
	bool	_signed;
	int		gradeS;
	int		gradeX;
public:
	Form(const std::string &, int, int);
	~Form();

	const std::string &getName(void) const;
	int		getGradeS(void) const;
	int		getGradeX(void) const;
	bool	isSigned(void) const;
	void	GradeTooLowException(void);
	void	GradeTooHighException(void);
	void	beSigned(Bureaucrat &b);
	void	signForm(void);
};

std::ostream	&operator<<(std::ostream &os, const Form &obj);

#endif  // FORM_HPP
