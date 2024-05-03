#include "ShrubberyCreationForm.hpp"

// TODO: grades: sign 145, exec 137
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("creation", 145, 137)
{
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
}

bool ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	// TODO: make sure that works as expected
	if (!this->isSigned() && executor.getGrade() > this->getGradeX())
	{
		this->GradeTooLowException();
	}
	return true;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	file.close();
}
