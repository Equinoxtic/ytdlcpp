#ifndef SYS_HPP
#define SYS_HPP

#include<cstdio>
#include<string>

int sysExecute(std::string command);
int sysClearScreen();
int sysPause(bool showMessage = true, bool clearScreen = true);

#endif // SYS_HPP
