#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <string>
#include <iostream>

class Brain {
public:
	Brain(void);
	Brain(const std::string& idea);
	Brain(const Brain& value);
	Brain &operator=(const Brain& val);
	~Brain(void);
private:
	std::string ideas[100];
};

#endif