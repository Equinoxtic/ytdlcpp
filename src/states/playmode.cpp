#include "./playmode.hpp"
#include "../utils/stringutils.hpp"
#include "../utils/sys.hpp"
#include "../ui/option.hpp"
#include<iostream>
#include<string>
#include<sstream>
#include<vector>

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
	
	std::cout << "Listing the local directory for video/audio files...\n\n";
	
	#ifndef _WIN32
	sysExecute("ls ./local/*.mov && ls ./local/*.mp4");
	#else
	sysExecute("dir .\\local\\*.mov & dir .\\local\\*.mp4");
	#endif
	
	std::cout << "\n: ";
	
	std::getline(std::cin, coption);
	ioption = coption;
	
	for (size_t i = 0; i < validFileExt.size(); ++i) {
		if (endsWith(ioption, validFileExt[i])) {
			isValidExt = true;
		}
	}
	
	if (isValidExt) {
		std::ostringstream oss;
		generateControls();
		oss << "ffplay -loglevel quiet -noborder -x 1280 -y 720 -loop 0 \"./local/" << ioption << "\"";
		sysExecute(oss.rdbuf()->str());
	} else {
		return 1;
	}
	
	sysPause(true, false);
	
	return 0;
}
