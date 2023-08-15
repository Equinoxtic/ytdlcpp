#ifndef OPTION_HPP
#define OPTION_HPP

#include<string>

int createOption(std::string arg_s = "", std::string description = "");
int createNumericalOption(unsigned int arg_i = 0, std::string description = "");

#endif // OPTION_HPP
