#include "./logging.hpp"
#include "./utils/stringutils.hpp"
#include<iostream>
#include<cstdio>
#include<cstring>
#include<sstream>

int logMessage(std::string msg, std::string logType)
{
	std::string info_s = "[INFO]: ";
	std::string warn_s = "[WARN]: ";
	std::string err_s = "[ERROR]: ";
	std::ostringstream oss;

	if (!(stringEmpty(msg) == 0 || stringEmpty(logType) == 0)) {
		if (compareString(logType, "info") == 0) {
			oss << info_s;
		} else if (compareString(logType, "warn") == 0 || compareString(logType, "warning") == 0) {
			oss << warn_s;
		} else if (compareString(logType, "error") == 0) {
			oss << err_s;
		} else {
			oss << "ERR:UnknownLogType";
		}
		printf("%s%s", oss.rdbuf()->str().c_str(), msg.c_str());
	} else {
		std::cout << "Error displaying LogMessage";
		return 1;
	}
	return 0;
}
