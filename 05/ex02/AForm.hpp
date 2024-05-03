#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	std::string name;
	bool	_signed;
	int		gradeS;
	int		gradeX;
public:
	AForm(void);
	AForm(const std::string &, int, int);
	~AForm();

	virtual bool execute(Bureaucrat const &executor) const = 0;
	const std::string &getName(void) const;
	int		getGradeS(void) const;
	int		getGradeX(void) const;
	bool	isSigned(void) const;
	void	GradeTooLowException(void) const;
	void	GradeTooHighException(void) const;
	void	beSigned(Bureaucrat &b);
	void	signForm(void);
};

std::ostream	&operator<<(std::ostream &os, const AForm &obj);

#endif  // AFORM_HPP
