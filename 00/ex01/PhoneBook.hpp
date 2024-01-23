#ifndef PhoneBook_HPP
#define PhoneBook_HPP

#include "./Contact.hpp"
#include <iomanip>

class PhoneBook
{
	static const int contact_size = 8;
	int	len;
	Contact contacts[contact_size];

	void	contact_display(void);
	int		contact_old(void);

public:
	PhoneBook(void);
	void	contact_add(void);
	void	contact_search(void);
};

#endif  // PhoneBook_HPP
