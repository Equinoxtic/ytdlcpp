#include "./stringutils.hpp"
#include<iostream>
#include<cstdio>
#include<cstring>
#include<sstream>

int compareString(std::string ts_a, std::string ts_b)
{
	int res = 1;
	if (ts_a.empty() || ts_b.empty()) {
		return 1;
	} else {
		if (ts_a.compare(ts_b) == 0) {
			res = 0;
		} else {
			res = 1;
		}
	}
	return res;
}

int stringEmpty(std::string t_s)
{
	return ((t_s.empty()) ? 0 : 1);
}

std::string quoteString(std::string s)
{
	std::ostringstream rs;
	if (s.empty()) {
		return "";
	} else {
		rs << "\"" << s << "\"";
	}
	return rs.rdbuf()->str();
}

std::string encloseString(std::string s, std::string op, std::string cl)
{
	std::ostringstream oss;
	if (s.empty() || op.empty() || cl.empty()) {
		return "";
	} else {
		oss << op << s << cl;
	}
	return oss.rdbuf()->str();
}
