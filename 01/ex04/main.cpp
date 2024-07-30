
#include <iostream>
#include <fstream>

bool	replace(std::string filename, std::string s1, std::string s2)
{
	std::ifstream instream;
	std::ofstream outstream;

	if (s1.empty())
	{
		std::cerr << "Error: string1 may not be empty" << std::endl;
		return false;
	}
	instream.open(filename.c_str());
	if (!instream.is_open())
	{
		std::cerr << "Error: could not open: " << filename << std::endl;
		return false;
	}
	filename += ".replace";
	outstream.open(filename.c_str());
	if (!outstream.is_open())
	{
		std::cerr << "Error: could not open: " << filename << std::endl;
		return false;
	}
	std::string line;
	while (std::getline(instream, line))
	{
		if (instream.fail())
		{
			std::cerr << "Error: could not read input" << std::endl;
			return false;
		}

		int	pos = line.find(s1);
		while (pos != -1)
		{
			outstream << line.substr(0, pos);
			outstream << s2;
			line = line.substr(pos + s1.length());
			pos = line.find(s1);
		}
		if (pos == -1)
			outstream << line;
		outstream << std::endl;
	}
	return true;
}


int	main(int argc, char **argv)
{
    if ((argc - 1) != 3)
    {
        std::cerr << "Error: invalid argument" << std::endl;
        std::cerr << "Usage: ./a.out filename string1 string2" << std::endl;
        return 1;
	}

	if (!replace(argv[1], argv[2], argv[3]))
		return 1;

	return 0;
}