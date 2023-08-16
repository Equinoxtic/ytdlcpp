#include "./contentutils.hpp"
#include "./stringutils.hpp"
#include "../logging.hpp"
#include "./sys.hpp"
#include<sstream>

int mergeContent(std::string audio_f, std::string video_f, std::string output, std::string format)
{
	if ((stringEmpty(audio_f) || stringEmpty(video_f) || stringEmpty(output) || stringEmpty(format)) == 0) {
		logMessage("Failed to merge content. One or more string literals are empty.", "error");
		return 1;
	} else {
		// ffmpeg ... -i [VIDEO_F] -i [AUDIO_F] ... [OUTPUT_NAME]
		std::ostringstream oss;
		oss << "ffmpeg -loglevel quiet -i \"" << video_f << "\" -i \"" << audio_f << "\" -shortest \"" << output << "." << format << "\"";
		sysExecute(oss.rdbuf()->str());
	}
	return 0;
}

int removeContent(std::string audio_f, std::string video_f)
{
	if ((stringEmpty(audio_f) || stringEmpty(video_f)) == 0) {
		logMessage("Failed to remove content. One or two string literals are empty.", "error");
		return 1;
	} else {
		// remove -force [VIDEO] & remove -force [AUDIO]
		std::ostringstream oss;
		#ifndef _WIN32
		oss << "rm -rf \"" << video_f << "\" && rm -rf \"" << audio_f << "\"";
		#else
		oss << "del /f \"" << video_f << "\" & del /f \"" << audio_f << "\"";
		#endif
		sysExecute(oss.rdbuf()->str());
	}
	return 0;
}

int moveOutputToLocal(std::string output)
{
	if (stringEmpty(output) == 0) {
		logMessage("Failed to move Output File. One or two string literals are empty.", "error");
		return 1;
	} else {
		// move [OUTPUT_F] [LOCAL_DIR]
		std::ostringstream oss;
		oss << "mv \"" << output << "\" local/";
		sysExecute(oss.rdbuf()->str());
	}
	return 0;
}

int playOutput(std::string output)
{
	if (stringEmpty(output) == 0) {
		logMessage("Failed to play Output File. String literal is empty.", "error");
		return 1;
	} else {
		// ffplay [LOCAL_DIR]/[OUTPUT_F]
		std::ostringstream oss;
		oss << "ffplay \"./local/" << output << "\"";
	}
	return 0;
}
