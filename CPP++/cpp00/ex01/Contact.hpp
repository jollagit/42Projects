#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {
public:
	void getData();
	void displayTruncateIndex(int index);
	void printContactDetail();
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	std::string truncate(const std::string& str) const;
};

#endif