#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "Error: invalid arguments" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe pm(argv + 1);
		pm.info();
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
