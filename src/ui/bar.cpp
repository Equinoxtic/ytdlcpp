#include "./bar.hpp"
#include "../utils/stringutils.hpp"
#include<iostream>

int createBar(int len)
{
	for (int i = 0; i < len; ++i) {
		std::cout << "-";
	}
	return 0;
}

int createBar_s(std::string s, int len)
{
	if (stringEmpty(s) == 0) {
		return 1;
	} else {
		for (int i = 0; i < len; ++i) {
			std::cout << s;
		}
	}
	return 0;
}
