#include <iostream>
#include <fstream>

bool	replace(std::string filename, std::string s1, std::string s2)
{
	std::ifstream infile;
	std::ofstream outfile;

	if (s1.empty())
	{
		std::cerr << "Error: string1 may not be empty" << std::endl;
		return false;
	}
	infile.open(filename);
	if (!infile.is_open())
	{
		std::cerr << "Error: could not open: " << filename << std::endl;
		return false;
	}

	filename += ".replace";
	outfile.open(filename);
	if (!outfile.is_open())
	{
		std::cerr << "Error: could not open: " << filename << std::endl;
		return false;
	}

	std::string line;
	while (std::getline(infile, line))
	{
		if (infile.fail())
		{
			std::cerr << "Error: could not read input" << std::endl;
			return false;
		}
		int	pos = line.find(s1);
		std::cout << "Pos: " << "`" << pos << "`" << std::endl;
		while (pos != -1)
		{
			outfile << line.substr(0, pos);
			outfile << s2;
			line = line.substr(pos + s1.length());
			pos = line.find(s1);
		}
		if (pos == -1)
			outfile << line;
		outfile << std::endl;
	}
	infile.close();
	outfile.close();
	return true;
}


int	main(int argc, char **argv)
{
    if ((argc - 1) != 3)
    {
        std::cerr << "Error: invalid argument" << std::endl;
        std::cerr << "Usage: ./sed filename string1 string2" << std::endl;
        return 1;
	}
	if (!replace(argv[1], argv[2], argv[3]))
		return 1;
	return 0;
}