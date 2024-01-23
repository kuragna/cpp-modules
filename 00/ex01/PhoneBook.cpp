
#include "./PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	len = 0;
}

int	PhoneBook::contact_old(void)
{
	int			index;
	std::time_t	time;

	index = 0;
	time = contacts[0].time_add;
	for (int i = 0; i < len; i += 1)
	{
		if (contacts[i].time_add < time)
		{
			time = contacts[i].time_add;
			index = i;
		}
	}
	return index;
}

void	PhoneBook::contact_display(void)
{
	int			index;
	std::string	input;

	std::cout << "Enter your index: ";
	std::getline(std::cin, input);
	if (std::cin.fail() || std::cin.eof())
		return ;
	if (!is_number(input))
	{
		std::cerr << "Error: invalid index: " << input << std::endl;
		std::cout << "Info: index must be between [1-8]" << std::endl;
		return ;
	}
	index = std::stoi(input);
	if (index > contact_size || index <= 0)
	{
		std::cerr << "Error: out of range: " << index << std::endl;
		std::cout << "Info: index must be between [1-8]" << std::endl;
		return ;
	}
	if (index > len)
	{
		std::cout << "Info: there is no contact at index: " << index << std::endl;
		return ;
	}
	std::cout << "──────────────── Contact infos ───────────────────────" << std::endl;
	for (int i = 0; i < Contact::infos_size; i += 1)
	{
		int len = Contact::info[i + 1].length();
		std::cout << Contact::info[i + 1] << ": " << std::setw(len - 14);
		std::cout << contacts[index - 1].infos[i] << std::endl;
	}
	std::cout << "──────────────────────────────────────────────────────" << std::endl;
}

void	PhoneBook::contact_add(void)
{
	Contact	contact;
	contact = contact.get_info();

	if (std::cin.fail() || std::cin.eof())
		return ;
	if (len < contact_size)
	{
		contacts[len] = contact;
		len += 1;
	}
	else
	{
		int	index = contact_old();
		if (index == -1)
			return ;
		contacts[index] = contact;
	}
	std::cout << "Info: contact added to phone book" << std::endl;
}

void	PhoneBook::contact_search(void)
{
	std::string s;

	if (len == 0)
	{
		std::cout << "Info: Phone book is empty use ADD command to add a new contact" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i += 1)
	{
		std::cout << std::setw(10) << Contact::info[i];
		if (i != 3)
			std::cout << " | ";
	}
	std::cout << std::endl;
	for (int i = 0; i < len; i += 1)
	{
		std::cout << std::setw(10) << i + 1;
		for (int j = 0; j < 3; j += 1)
		{
			std::cout << " | ";
			s = contacts[i].infos[j];
			if (s.length() >= 10)
			{
				std::cout << std::setw(9) << s.substr(0, 9);
				std::cout << ".";
			}
			else
				std::cout << std::setw(10) << s;
		}
		std::cout << std::endl;
	}
	contact_display();
}
