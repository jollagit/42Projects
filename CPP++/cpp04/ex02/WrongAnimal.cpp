#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	type = "default";
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) {
	this->type = type;
	std::cout << "WrongAnimal string constructor called for: " << this->type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& value) {
	this->type = value.type;
	std::cout << "WrongAnimal copy consstructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& val) {
	if (this != &val)
		this->type = val.type;
	std::cout << "WrongAnimal copy assignment called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return this->type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Generic WrongAnimal sound" << std::endl;
}