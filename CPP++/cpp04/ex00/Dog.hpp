#ifndef DOG_HPP
# define DOG_HPP
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog(void);
	Dog(const Dog& value);
	Dog &operator=(const Dog& val);
	~Dog(void);
	void makeSound() const;
private:
};

#endif