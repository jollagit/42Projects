#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

std::string Contact::truncate(const std::string& str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void 	Contact::getData() {
	std::string input;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	while (input.empty()){
		std::cout << "First name cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	this->firstName = input;
	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	while (input.empty()){
		std::cout << "Last name cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	this->lastName = input;
	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	while (input.empty()){
		std::cout << "Nickname cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	this->nickName = input;
	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	while (input.empty()){
		std::cout << "Phone number cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	this->phoneNumber = input;
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	while (input.empty()){
		std::cout << "Darkest secret cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	this->darkestSecret = input;
}

void	Contact::displayTruncateIndex(int index) {
	std::cout << std::setw(10) << index << "|"
			  << std::setw(10) << truncate(firstName) << "|"
			  << std::setw(10) << truncate(lastName) << "|"
			  << std::setw(10) << truncate(nickName) << std::endl;
}

void	Contact::printContactDetail() {
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: "	<< lastName << std::endl;
	std::cout << "Nickname: " << nickName << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

