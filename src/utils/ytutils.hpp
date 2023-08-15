#ifndef YTUTILS_HPP
#define YTUTILS_HPP

#include<string>
#include<iostream>
#include "./sys.hpp"

int downloadAudio(std::string link = "", std::string quality = "", std::string format = "", std::string output_name = "");
int downloadVideo(std::string link = "", std::string videoQuality = "", std::string videoFormat = "", std::string output_name = "");
int listVideoFormats(std::string link = "");

#endif // YTUTILS_HPP
