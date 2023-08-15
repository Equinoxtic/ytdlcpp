#include "./list.hpp"
#include<iostream>
#include<cstdio>

int createBulletList(std::vector<std::string> &listVector)
{
	if (listVector.empty()) {
		return 1;
	} else {
		for (size_t i = 0; i < listVector.size(); ++i) {
			printf(" * %s", listVector[i].c_str());
			if (i < listVector.size() - 1) {
				std::cout << "\n";
			}
		}
	}
	return 0;
}

int createNumericalList(std::vector<std::string> &listVector)
{
	if (listVector.empty()) {
		return 1;
	} else {
		for (size_t i = 0; i < listVector.size(); ++i) {
			printf(" %d. %s", i+1, listVector[i].c_str());
			if (i < listVector.size() - 1) {
				std::cout << "\n";
			}
		}
	}
	return 0;
}
