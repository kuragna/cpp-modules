#include <iostream>
#include <iomanip>

class Contact
{
	static const int size = 5;
public:
	std::string infos[size];
	std::time_t time;
	Contact get_info(void);
};

class PhoneBook
{
	int	top;
	Contact contacts[8];
public:

	void	set_top(void)
	{
		top = 0;
	}
	int	get_top(void)
	{
		return top;
	}
	void	add_contact(void);
	int		get_contact_old(void);
	void	search(void);
	void	print_contact(void);
};

bool	is_number(std::string str)
{
	std::string::iterator it;

	for (it = str.begin(); it != str.end(); it += 1)
	{
		if (!isdigit(*it))
			return false;
	}
	return true;
}


int	PhoneBook::get_contact_old(void)
{
	int	idx;
	std::time_t time;

	idx = 0;
	time = contacts[0].time;
	for (int i = 1; i < get_top(); i += 1)
	{
		if (contacts[i].time < time)
		{
			idx = i;
			time = contacts[i].time;
		}
	}
	return idx;
}

void	PhoneBook::print_contact(void)
{
	int	idx;
	std::string str;
	const char	*strs[] = {
		"first name",
		"last name",
		"nickname",
		"phone number",
		"dark secret",
	};

	std::cout << "Enter your index: ";
	idx = get_top();
	// TODO: check for non-digit
	std::getline(std::cin, str);
	if (!is_number(str))
	{
		std::cerr << "Error: `" << str << "`: not a valid index\n";
		return ;
	}
	idx = stoi(str);
	if (idx > get_top() || idx <= 0)
	{
		std::cerr << "Error: `" << idx << "`: " << "not a valid index\n";
		std::cout << "INFO: index range between [1-8]\n";
		return ;
	}
	for (int i = 0; i < 5; i += 1)
	{
		std::cout << strs[i] << " is: " << contacts[idx - 1].infos[i] << "\n";
	}
}

void	PhoneBook::add_contact(void)
{
	int	idx;
	Contact contact;

	idx = get_top();
	if (idx < 8)
	{
		std::cout << idx << std::endl;
		contacts[idx] = contact.get_info();
		top += 1;
	}
	else
	{
		idx = get_contact_old();
		contacts[idx] = contact.get_info();
		std::cout << "INFO: has replaced oldest one by new\n";
		return ;
	}
	std::cout << "INFO: contact has added to the list\n";
}

void	usage(void)
{
	std::cout << "usage:\n";
	std::cout << "     ADD    - add new contact to phone book\n";
	std::cout << "     SEARCH - search a contect in phone book\n";
	std::cout << "     EXIT   - exit program\n";
}

void	PhoneBook::search(void)
{
	std::string s;
	const char	*strs[4] = {
		"index",
		"first name",
		"last name",
		"nickname",
	};



	for (int i = 0; i < 4; i += 1)
	{
		std::cout << std::setw(10) << strs[i];
		if (i != 3)
			std::cout << " | ";
	}
	std::cout << std::endl;
	for (int i = 0; i < get_top(); i += 1)
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
	print_contact();
}


int main(void)
{
	std::string	input;
	PhoneBook 	phone_book;

	phone_book.set_top();
	while (1)
	{
		std::cout << "Type a command: ";
		std::getline(std::cin, input);

		if (!std::cin)
			break ;
		if (input == "ADD")
		{
			phone_book.add_contact();
		}
		else if (input == "SEARCH")
			phone_book.search();
		else if (input == "EXIT")
			break ;
		else
		{
			std::cerr << "Error: unknown command: `" + input + "`" << std::endl;
			usage();
		}
	}
	return 0;
}

Contact	Contact::get_info(void)
{
	Contact contact;
	const char	*infos[] = {
		"first name",
		"last name",
		"nickname",
		"phone number", 
		"darkest secret",
	};
	int i;
	for (i = 0; i < contact.size;)
	{
		std::cout << "Enter your " << infos[i] << ": ";
		std::getline(std::cin, contact.infos[i]);
		if (i == 3)
		{
			if (!is_number(contact.infos[i]))
			{
				std::cerr << "ERROR: " << contact.infos[i] << ": " << "not a valid number\n";
				continue ;
			}
		}
		i += 1;
	}
	contact.time = std::time(nullptr);
	return contact;
}