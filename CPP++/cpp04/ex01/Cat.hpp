#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
	Cat(void);
	Cat(const Cat& value);
	Cat &operator=(const Cat& val);
	~Cat(void);
	void makeSound() const;
	Brain* getBrain() const;
private:
	Brain* brain;
};

#endif