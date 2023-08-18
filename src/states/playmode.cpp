#include "./playmode.hpp"
#include "../utils/stringutils.hpp"
#include "../utils/sys.hpp"
#include "../ui/option.hpp"
#include "../ui/bar.hpp"
#include "../list.hpp"
#include "../logging.hpp"
#include<iostream>
#include<string>
#include<sstream>
#include<vector>

static const int defaultBarSize = 100;

static void generateControls()
{
	std::cout << "\n";
	
	std::vector<std::string> controlsList = {
		"ESC",
		"F",
		"<- / Right",
		"-> / Left",
		"SPACE",
	};
	
	std::vector<std::string> controlsDesc = {
		"Exit & stop the video/audio.",
		"Toggle fullscreen window.",
		"Seek backward 10 seconds.",
		"Seek forward 10 seconds.",
		"Pause the video/audio."
	};
	
	std::cout << "-- VIDEO CONTROLS --\n";
	
	for (size_t i = 0; i < controlsList.size(); ++i) {
		createOption(controlsList[i], controlsDesc[i]);
		if (i < controlsList.size() - 1 && i < controlsDesc.size() - 1) {
			std::cout << "\n";
		}
	}
	
	std::cout << "\n";
}

static void generateBanner()
{
	std::cout << "PLAYMODE - Playing Video...\n\n";
	createBar(defaultBarSize);
	std::cout << "\n\n";
}

static void generateUsage()
{
	std::vector<std::string> usageList = {
		"Play videos and audios. (Uses FFplay)",
		"Look through the directory listing to find and choose the file you want to play.",
		"Supported formats are: [*.mp4, *.mov, *.ogg, *.mp3, *.wav]",
		"To exit, type in \"exit\""
	};
	
	std::cout << "\n";
	createBar(100);
	std::cout << "\n\n-- USAGE OF PLAYMODE --\n\n";
	createBulletList(usageList);
	std::cout << "\n";
}

static void createListingHeader()
{
	std::cout << "[ Listing the local directory for video/audio files... ]";
	std::cout << "\n\n-- LOCAL DIRECTORY LISTING --\n\n";
}

static int listValidFiles(std::vector<std::string>& extList)
{
	if (extList.empty()) {
		return 1;
	} else {
		std::ostringstream oss_ext;
		for (size_t i = 0; i < extList.size(); ++i) {
			#ifndef _WIN32
			oss_ext << "ls -p ./local/*" << extList[i] << " | egrep -v /$"
			#else
			oss_ext << "dir /B .\\local\\*" << extList[i];
			#endif
			sysExecute(oss_ext.rdbuf()->str());
			oss_ext.rdbuf()->str(std::string());
		}
	}
	return 0;
}

int runPlayMode()
{
	std::string coption = "";
	std::string ioption = "";
	std::vector<std::string> validFileExt = {
		".mov",
		".mp4",
		".mp3",
		".wav",
		".ogg"
	};
	int isValidExt = false;
	
	sysClearScreen();
	
	generateBanner();
	createListingHeader();
	listValidFiles(validFileExt);
	generateUsage();

	while (compareString(ioption, "exit") != 0 ) {
		std::cout << "\n[prompt/play]:~$ ";
		
		std::getline(std::cin, coption);
		ioption = coption;
		
		for (size_t i = 0; i < validFileExt.size(); ++i) {
			if (endsWith(ioption, validFileExt[i])) {
				isValidExt = true;
			} else {
				isValidExt = false;
			}
		}
		
		if (!(stringEmpty(ioption)) == 0) {
			if (!(compareString(ioption, "exit")) == 0) {
				if (isValidExt) {
					std::ostringstream oss;
					generateControls();
					oss << "ffplay -loglevel error -noborder -x 1280 -y 720 -loop 0 \"./local/" << ioption << "\"";
					sysExecute(oss.rdbuf()->str());
				} else {
					return 1;
				}
			} else if (compareString(ioption, "list") == 0) {
				createListingHeader();
				listValidFiles(validFileExt);
			}
		} else {
			logMessage("Retrying. String literal cannot be empty or null.", "warn");
		}
	}

	return 0;
}
