#include "PhoneBook.hpp"
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : contactCount(0), nextIndex(0) {}

void PhoneBook::addContact(){
	Contact contact;
	std::string input;

	std::cout << "First name: ";
	std::getline(std::cin, input);
	if (input.empty()) return;
	contact.setFirstName(input);

	std::cout << "Last Name: ";
	std::getline(std::cin, input);
	if (input.empty()) return;
	contact.setLastName(input);

	std::cout << "Nickname: ";
	std:getline(std::cin, input);
	if (input.empty()) return;
	contact.setNickname(input);

	std::cout << "Phone Number: ";
	std::getline(std::cin, input);
	if (input.empty()) return;
	contact.setPhoneNumber(input);

	std::cout << "Darkest Secret: ";
	std::getline(std::cin, input);
	if (input.empty()) return;
	contact.setDarkestSecret(input);

	contacts[nextIndex] = contact;
	nextIndex = (nextIndex + 1) % 8;
	if (contactCount < 8) contactCount++;
}

void PhoneBook::searchContact() const {
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < contactCount; ++i){
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
				  << std::setw(10) << truncate(contacts[i].getLastName()) << "|"
				  << std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;
	}
	std::cout << "Enter index to view: ";
	int index;
	if (!(std::cin >> index) || index < 0 || index >= contactCount) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index" << std::endl;
	} else {
		std::cin.ignore();
		contacts[index].printContactDetails();
	}
}

std::string PhoneBook::truncate(const std::string& str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::displayContact(int index) const {
	if (index >= 0 && index < contactCount)
		contacts[index].printContactDetails();
	else
		std::cout << "Invalid index." << std::endl;
}