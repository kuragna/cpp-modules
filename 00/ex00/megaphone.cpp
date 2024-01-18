#include <iostream>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; i += 1)
	{
		std::string s = argv[i];
		std::string::iterator it;
		for (it = s.begin(); it != s.end(); it += 1)
		{
			*it = std::toupper(*it);
			std::cout << *it;
		}
	}
	std::cout << std::endl;
	return 0;
}
