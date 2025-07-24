#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <string>
#include <iostream>

class Animal {
public:
	Animal(void);
	Animal(const std::string& type);
	Animal(const Animal& value);
	Animal &operator=(const Animal& val);
	virtual ~Animal(void);
	
	std::string	getType(void) const;
	virtual void makeSound() const = 0;
protected:
	std::string type;
};

#endif