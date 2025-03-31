#include "PhoneBook.hpp"
#include <iostream>

int main() {
	PhoneBook phoneBook;
	std::string command;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD") {
			phoneBook.addContact();
		} else if (command == "SEARCH") {
			phoneBook.searchContact();
		} else if (command == "EXIT") {
			break;
		} else {
			std::cout << "Invalid command." << std::endl;
		}
	}
	return 0;
}