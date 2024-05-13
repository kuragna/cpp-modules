#include "Bureaucrat.hpp"

int main(void)
{
	// valid grade
	try {
		Bureaucrat b(42, "foo");
		std::cout << b << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;

	// invalid grade, grade too high
	try {
		Bureaucrat b(-1, "bar");
		std::cout << b << std::endl;


	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;

	// invalid grade, grade too low
	try {
		Bureaucrat b2(200, "bar");
		std::cout << b2 << std::endl;
		
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;

	// valid increment and decrement
	try {
		Bureaucrat br(43, "foo");
		std::cout << br << std::endl;
		br.increment();
		std::cout << br << std::endl;
		br.decrement();
		std::cout << br << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;

	// invalid increment
	try {
		Bureaucrat b(0, "baz");
		std::cout << b << std::endl;
		b.increment();
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;

	// invalid decrement
	try {

		Bureaucrat b2(150, "baz");
		std::cout << b2 << std::endl;
		b2.decrement();
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}