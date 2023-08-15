#include "./videomode.hpp"
#include "../utils/ytutils.hpp"
#include "../utils/stringutils.hpp"
#include "../ui/bar.hpp"
#include "../logging.hpp"
#include<string>
#include<cstdio>
#include<iostream>
#include<sstream>

void createVideoModeBanner()
{
	std::cout << "VIDEOMODE - Downloading Video...\n\n";
	createBar(80);
	std::cout << "\n";
}

int runVideoMode()
{
	std::string link = "";
	std::string videoQuality = "";
	std::string videoFormat = "";
	std::string outputName = "";

	sysClearScreen();

	createVideoModeBanner();

	std::cout << "\n[Video Link]: ";
	std::getline(std::cin, link);
	if (stringEmpty(link) == 0) {
		logMessage("\'link\' string cannot be empty.\n", "warn");
		return 1;
	}

	listVideoFormats(link);
	std::cout << "\n[Video Quality]: ";
	std::getline(std::cin, videoQuality);
	if (stringEmpty(videoQuality) == 0) {
		logMessage("\'video quality\' string cannot be empty.", "warn");
		return 1;
	}

	std::cout << "[Video Format ([mp4: default], mov)]: ";
	std::getline(std::cin, videoFormat);
	if (stringEmpty(videoQuality) == 0) {
		logMessage("\'video format\' string cannot be empty.", "warn");
		return 1;
	}

	std::cout << "[Output Name]: ";
	std::getline(std::cin, outputName);
	if (stringEmpty(outputName) == 0) {
		logMessage("\'output name\' string cannot be empty.", "warn");
		return 1;
	}

	downloadVideo(link, videoQuality, videoFormat, outputName);

	return 0;
}
