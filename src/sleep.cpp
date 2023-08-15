#include "./sleep.hpp"

#ifndef _WIN32
#include<unistd.h>
#else
#include<windows.h>
#endif

int sleep(unsigned int t)
{
	if (t >= 0) {
		unsigned int tc = t * 1000;
		#ifdef _WIN32
		Sleep(tc);
		#else
		usleep(tc);
		#endif
		return 0;
	} else {
		return 1;
	}
}

int sleep_ms(unsigned int t_ms)
{
	if (t_ms >= 0) {
		#ifdef _WIN32
		Sleep(t_ms);
		#else
		usleep(t_ms);
		#endif
		return 0;
	} else {
		return 1;
	}
}
