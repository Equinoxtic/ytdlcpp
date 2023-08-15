#include "./option.hpp"
#include "../utils/stringutils.hpp"
#include<iostream>
#include<cstdio>
#include<sstream>

void createOption_s(std::string main_s, std::string desc)
{
	if (!(main_s.empty() && desc.empty())) {
		printf("%s: %s", encloseString(main_s, "[", "]").c_str(), quoteString(desc).c_str());
	}
}

int createOption(std::string arg_s, std::string description)
{
	if (arg_s.empty() && description.empty()) {
		std::cout << "FAILED TO CREATE OPTION";
		return 1;
	} else {
		createOption_s(arg_s, description);
	}
	return 0;
}

int createNumericalOption(unsigned int arg_i, std::string description)
{
	if (arg_i < 0 && description.empty()) {
		std::cout << "FAILED TO CREATE NUMERICAL OPTION";
		return 1;
	} else {
		std::ostringstream os;
		os << arg_i;
		createOption_s(os.rdbuf()->str(), description);
	}
	return 0;
}
