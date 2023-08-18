#include "./sys.hpp"
#include<iostream>
#include<conio.h>

int sysExecute(std::string command)
{
	if (!command.empty()) {
		const char *cs_cmd = command.c_str();
		system(cs_cmd);
		return 0; // Stop here
	} else {
		printf("\nCommand string literal cannot be empty.");
	}

	printf("\nCommand cannot be executed.");

	return 1;
}

int sysClearScreen()
{
	#ifndef _WIN32
	system("clear");
	#else
	system("cls");
	#endif
	return 0;
}

int sysPause(bool showMessage, bool clearScreen)
{
	if (showMessage) {
		std::cout << "\n\nPress any key to continue... ";
	}
	getch();
	if (clearScreen) {
		#ifndef _WIN32
		system("clear");
		#else
		system("cls");
		#endif
	}
	return 0;
}
