#include "./ytutils.hpp"
#include "./sys.hpp"
#include "./contentutils.hpp"
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
		std::ostringstream output_audio;
		output_audio << output_name << "." << format;
		oss_dlaf << "yt-dlp \"" << link << "\" -x --audio-quality " << quality << " --audio-format " << format << " --output " << output_name;
		sysExecute(oss_dlaf.rdbuf()->str());
		printf("Successful download for \"%s\"\n\nMoving to \"local/\" directory. (You may go find this file later on)\n", link.c_str());
		moveOutputToLocal(output_audio.rdbuf()->str());
		sysPause(true, true);
		return 0;
	} else {
		std::cout << "Failed download operation, one or more string literals are empty.";
	}
	return 1;
}

int downloadVideo(std::string link, std::string videoQuality, std::string videoFormat, std::string output_name)
{
	if (!(link.empty() && videoQuality.empty() && videoFormat.empty() && output_name.empty())) {
		std::ostringstream audioFile;
		std::ostringstream videoFile;
		std::ostringstream outputVideo;

		printf("\n=== Downloading Video ===\nLINK: %s\nVIDEO QUALITY: %s\nVIDEO FORMAT: %s\nAUDIO QUALITY: 0 (highest, auto-selected)\nAUDIO FORMAT: wav (auto-selected)\nOUTPUT NAME: %s\n",
			link.c_str(), videoQuality.c_str(), videoFormat.c_str(), output_name.c_str());

		// yt-dlp [LINK] ... quality: [QUALITY] format: [FORMAT] output: [OUTPUT]
		printf("\n[INFO/YTDLCPP]: Downloading Audio File for \"%s\"\n", link.c_str());
		std::ostringstream oss_dlaudio;
		oss_dlaudio << "yt-dlp \"" << link << "\" -x --audio-quality 0 --audio-format wav --output audio_" << output_name << ".wav";
		sysExecute(oss_dlaudio.rdbuf()->str());
		audioFile << "audio_" << output_name << ".wav";

		// yt-dlp [LINK] ... quality: [QUALITY] output: [OUTPUT]
		printf("\n[INFO/YTDLCPP]: Downloading Video File for \"%s\"\n", link.c_str());
		std::ostringstream oss_dlvideo;
		oss_dlvideo << "yt-dlp \"" << link << "\" -f " << videoQuality << " --output video_" << output_name << ".mov";
		sysExecute(oss_dlvideo.rdbuf()->str());
		videoFile << "video_" << output_name << ".mov";

		// Merge process (Uses FFmpeg)
		printf("\n[INFO/YTDLCPP]: Merging audio and video file of \"%s\"...", link.c_str());
		mergeContent(audioFile.rdbuf()->str(), videoFile.rdbuf()->str(), output_name, videoFormat);
		outputVideo << output_name << "." << videoFormat;

		// Remove process (Saves space for users)
		printf("\n[INFO/YTDLCPP]: Removing old video and audio file of \"%s\"", link.c_str());
		removeContent(audioFile.rdbuf()->str(), videoFile.rdbuf()->str());

		// Moves to the accessible "local/" directory
		printf("\n[INFO/YTDLCPP]: Moving output file to \"local/\"...\n");
		moveOutputToLocal(outputVideo.rdbuf()->str());

		printf("\n[INFO/YTDLCPP]: Successfully merged video and audio file of \"%s\" (You can find it in the directory: \"local/\")", link.c_str());

		sysPause(true, true);

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
