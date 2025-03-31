#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();

	void addContact();
	void searchContact() const;
	void displayContact(int index) const;

private:
	Contact contacts[8];
	int		contactCount;
	int		nextIndex;

	std::string truncate(const std::string& str) const;
};

#endif