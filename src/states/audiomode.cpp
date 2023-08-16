#include "./audiomode.hpp"
#include "../utils/ytutils.hpp"
#include "../utils/sys.hpp"
#include "../ui/bar.hpp"
#include "../utils/stringutils.hpp"
#include "../logging.hpp"
#include<cstdio>
#include<iostream>
#include<sstream>
#include<string>

static void createAudioModeBanner()
{
	std::cout << "AUDIOMODE - Downloading Audio...\n\n";
	createBar(80);
	std::cout << "\n";
}

int runAudioMode()
{
	std::string link = "";
	std::string quality = "";
	std::string format = "";
	std::string outputName = "";

	sysClearScreen();

	createAudioModeBanner();

	std::cout << "\n[Input Link]: ";
	std::getline(std::cin, link);
	if (stringEmpty(link) == 0) {
		logMessage("\'link\' string cannot be empty or NULL.", "warn");
		return 1;
	}

	std::cout << "[Input Quality (0 - 10; 0 highest, 10 lowest)]: ";
	std::getline(std::cin, quality);
	if (stringEmpty(quality) == 0) {
		logMessage("\'quality\' string cannot be empty or NULL.", "warn");
		return 1;
	} else if (std::stoi(quality) > 10) {
		logMessage("Quality cannot exceed up to 10.", "warn");
		return 1;
	}

	std::cout << "[Audio Format ([mp3: default], ogg, wav)]: ";
	std::getline(std::cin, format);
	if (stringEmpty(format) == 0) {
		logMessage("\'format\' string cannot be empty.", "warn");
		return 1;
	}

	std::cout << "[Output Name]: ";
	std::getline(std::cin, outputName);
	if (stringEmpty(outputName) == 0) {
		logMessage("\'Output name\' cannot be empty.", "warn");
		return 1;
	}

	downloadAudio(link, quality, format, outputName);

	return 0;
}
