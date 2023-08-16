# Building from source
* Install [FFmpeg](https://github.com/BtbN/FFmpeg-Builds/releases/download/latest/ffmpeg-n6.0-latest-win64-lgpl-6.0.zip), [yt-dlp](https://github.com/yt-dlp/yt-dlp/releases/download/2023.07.06/yt-dlp_win.zip), and [MinGW Compiler](https://sourceforge.net/projects/mingw/)
* Create a folder for FFmpeg and yt-dlp in your C: directory
* Drag all files from FFmpeg to your FFmpeg directory and do the same for yt-dlp
---
## MinGW Setup
* With MinGW installed, you now install g++. Go to MinGW Installation Manager then you'll have to install ``mingw32-gcc-g++-bin``

![mingwlol](https://cdn.discordapp.com/attachments/798150104158568448/1140928793201102938/tutorlol.png)

* After ticking that, you'll now press ``Installation > Apply Changes``

![lol2](https://cdn.discordapp.com/attachments/798150104158568448/1140929249650417766/image.png)

* Click on "Apply" then it should start downloading, once done you can safely click on "Close" and close MinGW
---
## Setting Environment Variables
* Go to the folder where you installed ``FFmpeg`` (Go to ``FFmpeg/bin/``) and ``yt-dlp``
* Copy their paths and search up in Windows: ``Edit the system environment variables``
* Click on ``Environment Variables``
* Under ``System Variables`` find ``Path``, click on it and press ``Edit``
* Press on ``New`` and paste in each of the directories for ``FFmpeg/bin/`` and ``yt-dlp``
