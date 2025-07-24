#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat& value) : Animal(value) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*value.brain);
}

Cat& Cat::operator=(const Cat& val) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &val) {
		Animal::operator=(val);
		delete this->brain;
		this->brain = new Brain(*val.brain);
	}
	return *this;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
	return this->brain;
}