#include "./Contact.hpp"

const std::string Contact::info[] = {
	"index", 
	"first name", 
	"last name", 
	"nickname", 
	"phone number", 
	"darkest secret"
};

bool	is_number(std::string str)
{
	std::string::iterator it;

	for (it = str.begin(); it != str.end(); it += 1)
	{
		if (!std::isdigit(*it))
			return (false);
	}
	return true;
}

Contact	Contact::get_info(void)
{
	Contact 	contact;
	std::string	info;

	for (int i = 0; i < Contact::infos_size;)
	{
		std::cout << "Enter your " << Contact::info[i + 1] << ": ";
		std::getline(std::cin, info);
		if (std::cin.fail() || std::cin.eof())
			break ;
		if (info.empty())
		{
			std::cerr << "Error: input can not be empty" << std::endl;
			continue ;
		}
		if (i == 3 && !is_number(info))
		{
			std::cerr << "Error: invalid phone number: " << info << std::endl;
			continue ;
		}
		contact.infos[i] = info;
		i += 1;
	}
	contact.time_add = std::time(nullptr);
	return contact;
}
