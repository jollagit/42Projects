#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat(void);
	WrongCat(const WrongCat& value);
	WrongCat &operator=(const WrongCat& val);
	~WrongCat(void);
	void makeSound() const;
private:
};

#endif
