#include "./PhoneBook.hpp"

void	usage(void)
{
	std::cout << "Usage:" << std::endl;
	std::cout << "       ADD	- Add a new contact to phonebook" << std::endl;
	std::cout << "       SEARCH	- Search a specific contact" << std::endl;
	std::cout << "       EXIT	- Quite the phonebook" << std::endl;
}

int main()
{
	PhoneBook	phonebook;
	std::string	input;

	while (1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, input);
		if (std::cin.fail() || std::cin.eof())
			break ;
		if (input == "ADD")
		{
			phonebook.contact_add();
		}
		else if (input == "SEARCH")
		{
			phonebook.contact_search();
		}
		else if (input == "EXIT")
			break ;
		else
		{
			std::cout << "Error: invalid command: " << input << std::endl;
			usage();
		}
	}
	return 0;
}
