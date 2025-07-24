#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& value) : WrongAnimal(value) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& val) {
	if (this != &val)
		WrongAnimal::operator=(val);
	std::cout << "WrongCat copy assignment called" << std::endl;
	return *this;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "Wrong Meow! " << std::endl;
}

