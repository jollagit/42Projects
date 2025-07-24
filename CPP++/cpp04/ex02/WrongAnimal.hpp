#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
#include <string>
#include <iostream>

class WrongAnimal {
public:
	WrongAnimal(void);
	WrongAnimal(const std::string& type);
	WrongAnimal(const WrongAnimal& value);
	WrongAnimal &operator=(const WrongAnimal& val);
	~WrongAnimal(void);
	
	std::string getType(void) const;
	void makeSound() const;
protected:
	std::string type;
};

#endif