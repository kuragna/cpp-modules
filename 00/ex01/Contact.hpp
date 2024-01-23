#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
public:
	static const int infos_size = 5;
	static const std::string info[];
	std::string	infos[infos_size];

	std::time_t	time_add;
	Contact		get_info(void);

};

bool	is_number(std::string str);

#endif // CONTACT_HPP
