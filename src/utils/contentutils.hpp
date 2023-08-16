#ifndef CONTENTUTILS_HPP
#define CONTENTUTILS_HPP

#include<string>

int mergeContent(std::string audio_f = "", std::string video_f = "", std::string output = "", std::string format = "");
int removeContent(std::string audio_f = "", std::string video_f = "");
int moveOutputToLocal(std::string output = "");
int playOutput(std::string output = "");

#endif // CONTENTUTILS_HPP
