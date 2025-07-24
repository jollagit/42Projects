#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();

	void	addContact();
	void	searchContact();
	void	displayContact(int index);
private:
	Contact contacts[8];
	int		contactCount;
	int		nextIndex;

};

#endif