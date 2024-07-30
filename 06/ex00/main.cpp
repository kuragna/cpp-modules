#include "ScalarConverter.hpp"
#include "Data.hpp"

// TODO: fix non output


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: no input is provided" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}