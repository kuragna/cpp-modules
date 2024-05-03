#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	std::string target;
public:
	RobotomyRequestForm(const std::string &target);
	bool execute(Bureaucrat const &executor) const;
	~RobotomyRequestForm(void);
};

#endif  // ROBOTOMY_REQUEST_FORM_HPP
