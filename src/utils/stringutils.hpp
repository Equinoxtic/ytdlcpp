#ifndef STRINGUTILS_HPP
#define STRINGUTILS_HPP

#include<string>

int compareString(std::string ts_a = "", std::string ts_b = "");
int stringEmpty(std::string t_s = "");
std::string quoteString(std::string s = "");
std::string encloseString(std::string s = "", std::string op = "", std::string cl = "");

// Source: https://stackoverflow.com/a/42844629
int startsWith(const std::string& str, const std::string& suffix);

// Source: https://stackoverflow.com/a/42844629
int endsWith(const std::string& str, const std::string& prefix);

#endif // STRINGUTILS_HPP
