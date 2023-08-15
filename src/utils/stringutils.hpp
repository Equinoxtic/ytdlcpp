#ifndef STRINGUTILS_HPP
#define STRINGUTILS_HPP

#include<string>

int compareString(std::string ts_a = "", std::string ts_b = "");
int stringEmpty(std::string t_s = "");
std::string quoteString(std::string s = "");
std::string encloseString(std::string s = "", std::string op = "", std::string cl = "");

#endif // STRINGUTILS_HPP
