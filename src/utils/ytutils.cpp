#include "./ytutils.hpp"
#include "../sleep.hpp"
#include<cstdio>
#include<sstream>
#include<cstring>

int downloadAudio(std::string link, std::string quality, std::string format, std::string output_name)
{
	if (!link.empty() && !quality.empty() && !format.empty() && !output_name.empty()) {
		printf("\n=== Downloading Audio ===\nLINK: %s\nQUALITY: %s\nFILE FORMAT: %s\nOUTPUT NAME: %s\n", link.c_str(), quality.c_str(), format.c_str(), output_name.c_str());
		// yt-dlp [LINK] ... quality: [QUALITY] format: [FORMAT] output [OUTPUT]
		std::ostringstream oss_dlaf;
		oss_dlaf << "yt-dlp \"" << link << "\" -x --audio-quality " << quality << " --audio-format " << format << " --output " << output_name;
		sysExecute(oss_dlaf.rdbuf()->str());
		printf("Successful download for \"%s\"\nReturning...\n", link.c_str());
		sleep_ms(1050);
		return 0;
	} else {
		std::cout << "Failed download operation, one or more string literals are empty.";
	}
	return 1;
}

int downloadVideo(std::string link, std::string videoQuality, std::string videoFormat, std::string output_name)
{
	if (!(link.empty() && videoQuality.empty() && videoFormat.empty() && output_name.empty())) {
		std::string audioFile = "audio_" + output_name + ".wav";
		std::string videoFile = "video_" + output_name + ".mov";
		std::string outputVideo = output_name + "." + videoFormat;

		printf("\n=== Downloading Video ===\nLINK: %s\nVIDEO QUALITY: %s\nVIDEO FORMAT: %s\nAUDIO QUALITY: 0 (highest, auto-selected)\nAUDIO FORMAT: wav (auto-selected)\nOUTPUT NAME: %s\n",
			link.c_str(), videoQuality.c_str(), videoFormat.c_str(), output_name.c_str());

		// yt-dlp [LINK] ... quality: [QUALITY] output: [OUTPUT]
		printf("\n[INFO/YTDLCPP]: Downloading Video File for \"%s\"\n", link.c_str());
		std::ostringstream oss_dlvideo;
		oss_dlvideo << "yt-dlp \"" << link << "\" -f " << videoQuality << " --output video_" << output_name << ".mov";
		sysExecute(oss_dlvideo.rdbuf()->str());
		
		// yt-dlp [LINK] ... quality: [QUALITY] format: [FORMAT] output: [OUTPUT]
		printf("\n[INFO/YTDLCPP]: Downloading Audio File for \"%s\"\n", link.c_str());
		std::ostringstream oss_dlaudio;
		oss_dlaudio << "yt-dlp \"" << link << "\" -x --audio-quality 0 --audio-format wav --output audio_" << output_name << ".wav";
		sysExecute(oss_dlaudio.rdbuf()->str());

		// ffmpeg ... -i [VIDEO] -i [AUDIO] ... [OUTPUT]
		printf("\n[INFO/YTDLCPP]: Merging audio and video file of \"%s\"...\n", link.c_str());
		std::ostringstream oss_mergevideo;
		oss_mergevideo << "ffmpeg -loglevel quiet -i \"" << videoFile << "\" -i \"" << audioFile << "\" -shortest \"" << output_name << "." << videoFormat << "\"";
		sysExecute(oss_mergevideo.rdbuf()->str());

		// remove -force [VIDEO] & remove -force [AUDIO]
		// EXTRA NOTE: Doing this to save users space
		printf("\n[INFO/YTDLCPP]: Removing old video and audio file of \"%s\"\n", link.c_str());
		std::ostringstream oss_rmvidaud;
		#ifndef _WIN32
		oss_rmvidaud << "rm -rf " << videoFile << " && rm -rf " << audioFile;
		#else
		oss_rmvidaud << "del /f " << videoFile << " & del /f " << audioFile;
		#endif
		sysExecute(oss_rmvidaud.rdbuf()->str());

		printf("\n[INFO/YTDLCPP]: Successfully merged video and audio file of \"%s\"\nReturning...\n", link.c_str());

		sleep_ms(1050);

		return 0;
	} else {
		std::cout << "Failed download operation, one or more string literals are empty.";
	}
	return 1;
}

int listVideoFormats(std::string link)
{
	if (!link.empty()) {
		printf("\n=== Listing video formats ===\nLINK: %s\n", link.c_str());
		// yt-dlp [LINK] -list-formats
		std::ostringstream lsvidf;
		lsvidf << "yt-dlp \"" << link << "\" --list-formats";
		sysExecute(lsvidf.rdbuf()->str());
		return 0;
	} else {
		std::cout << "Failed operation, string literal cannot be empty.";
	}
	return 1;
}
