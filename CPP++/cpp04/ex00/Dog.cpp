#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& value) : Animal(value.type) {
	std::cout << "Dog copy constuctor called" << std::endl;
}

Dog& Dog::operator=(const Dog& val) {
	if (this != &val)
		Animal::operator=(val);
	std::cout << "Dog copy assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}