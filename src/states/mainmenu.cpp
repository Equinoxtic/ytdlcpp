#include "./mainmenu.hpp"
#include "./audiomode.hpp"
#include "./videomode.hpp"
#include "./playmode.hpp"
#include "../logging.hpp"
#include "../ui/option.hpp"
#include "../ui/bar.hpp"
#include "../utils/sys.hpp"
#include "../utils/stringutils.hpp"
#include "../list.hpp"
#include "../sleep.hpp"
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<string>
#include<conio.h>

static void createMainMenuBanner()
{
	std::cout << "YTDLCPP - YouTube Downloader in C++\n\n";
	createBar(80);
}

static void createMainMenuDescriptions()
{
	std::string repositoryLink = "https://github.com/Equinoxtic/ytdlcpp/tree/master";
	std::vector<std::string> descriptionVector = {
		"Download videos from YouTube.",
		"Extract audio from YouTube videos.",
		"Play downloaded videos and audios. (Uses FFplay)",
		"Open-source and made in C++"
	};
	
	std::cout << "\n\n";
	createBulletList(descriptionVector);
	printf("\n(GitHub Repository): \"%s\"\n\n", repositoryLink.c_str());
	createBar(80);
	std::cout << "\n";
}

static void showMainMenuOptions(bool newline = false, bool listing_mode = false)
{
	std::vector<std::string> option_names = {
		"dl-audio",
		"dl-video",
		"play",
		"help",
		"exit"
	};

	std::vector<std::string> options_descs = {
		"Download Audio",
		"Download Video",
		"Play a video or an audio.",
		"Get help of options",
		"Exit program"
	};

	if (listing_mode) {
		std::cout << "\n-- COMMANDS & USAGE --\n";
	} else {
		std::cout << "\n";
	}

	for (size_t i = 0; i < options_descs.size(); ++i) {
		createOption(option_names[i], options_descs[i]);
		if (i < options_descs.size() - 1 && i < option_names.size() - 1) {
			std::cout << "\n";
		}
	}
	std::cout << "\n";
}

int createMainMenu()
{
	std::string coption = "";
	std::string icoption = "";
	
	createMainMenuBanner();
	createMainMenuDescriptions();
	showMainMenuOptions();

	while(compareString(coption, "exit") != 0) {
		std::cout << "\n[prompt]:~$ ";
		std::getline(std::cin, icoption);
		coption = icoption;
		if (compareString(coption, "dl-audio") == 0) {
			runAudioMode();
		} else if (compareString(coption, "dl-video") == 0) {
			runVideoMode();
		} else if (compareString(coption, "play") == 0) {
			runPlayMode();
		} else if (compareString(coption, "help") == 0) {
			showMainMenuOptions(true, true);
		}

		// if (compareString(coption, "help") != 0) {
		// 	sleep_ms(275); sysClearScreen();
		// }
	}

	return 0;
}
