#include "Animal.hpp"

Animal::Animal(void) {
	type = "default";
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string& type) {
	this->type = type;
	std::cout << "Animal string constructor called for: " << this->type << std::endl;
}

Animal::Animal(const Animal& value) {
	this->type = value.type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& val) {
	if (this != &val)
		this->type = val.type;
	std::cout << "Animal copy assignment operator called" << std::endl;
	return *this;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType(void) const {
	return this->type;
}

void	Animal::makeSound() const {
	std::cout << "Generic Animal sound" << std::endl;
}