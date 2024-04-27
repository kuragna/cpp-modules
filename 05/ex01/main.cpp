#include "Form.hpp"

int main(void)
{
	try
	{
		// valid grades to form
		//Form f("form", 1, 42);
		//std::cout << f << std::endl; // display form's information
		
		// invalid grades to form
		//Form f2("form2", -1, 42);
		//Form f3("form3", 42, 200);

		// valid grade to sign form
		Form f4("land paper", 42, 1);
		Bureaucrat b(4, "foo");

		f4.beSigned(b);
		b.signForm(f4);
		
		// invalid grade to sign form
		Form f5("land paper", 42, 1);
		Bureaucrat b2(100, "foo");

		f4.beSigned(b2);
		b2.signForm(f4);

	} catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return 1;
	}


	return 0;
}