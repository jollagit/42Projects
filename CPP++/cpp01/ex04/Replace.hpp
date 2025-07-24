#ifndef REPLACE_HPP
# define REPLACE_HPP
#include <string>

class Replace {
public:
	Replace(std::string filename, std::string s1, std::string s2);
	bool performReplace();
	static std::string replaceOccurrence(const std::string& line, const std::string& s1, const std::string& s2);
private:
	std::string filename;
	std::string s1;
	std::string s2;
};

#endif