#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("shrubbery creation", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("shrubbery creation", 145, 137)
{
	std::ofstream file;
	const std::string tree[] = {
			"         *" ,
			"        /|\\" ,
			"       /*|O\\" ,
			"      /*/|\\*\\" ,
			"     /X/O|*\\X\\" ,
			"    /*/X/|\\X\\*\\" ,
			"   /O/*/X|*\\O\\X\\" ,
			"  /*/O/X/|\\X\\O\\*\\",
			" /X/O/*/X|O\\X\\*\\O\\",
			"/O/X/*/O/|\\X\\*\\O\\X\\",
			"        |X|      ",
			"        |X|      ",
	};

	const std::string filename = target + "_shrubbery";
	file.open(filename.c_str());
	if (file.is_open())
	{
		for (size_t i = 0; i < sizeof(tree) / sizeof(tree[0]); i += 1)
		{
			file << tree[i] << std::endl;
		}
	}
	file.close();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s) : AForm(s)
{
	operator=(s);
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s)
{
	this->target = s.target;
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!(this->isSigned() && executor.getGrade() < this->getGradeX()))
	{
		throw GradeTooHighException();
	}
}

ShrubberyCreationForm	*ShrubberyCreationForm::clone(const std::string &target) const
{
	return new ShrubberyCreationForm(target);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

