#include <iostream>
#include <string>

int	main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string* p = &str;
	std::string& ref = str;
	std::cout << "memory address of the string: " << &str << std::endl;
	std::cout << "memory address of the pointer: " << p << std::endl;
	std::cout << "memory address of the reference: " << &ref << std::endl;
	std::cout << "value of the string: " << str << std::endl;
	std::cout << "value of the pointer: " << *p << std::endl;
	std::cout << "value of the reference: " << ref << std::endl;
	return 0;
}