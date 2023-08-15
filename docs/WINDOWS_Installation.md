# Building from source
* Install both [FFmpeg](https://www.ffmpeg.org/download.html), [yt-dlp](https://github.com/yt-dlp/yt-dlp/releases/tag/2023.07.06), and [MinGW Compiler](https://sourceforge.net/projects/mingw/)
* Create a folder for FFmpeg and yt-dlp in your C: directory
*  Open ``cmd`` or your terminal to install chocolatey (this will be used to install [make](https://www.gnu.org/software/make/) later on):
```.bat
> Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
```
* Restart ``cmd`` or the terminal and run ``choco install make``, this will install ``make`` which will be used for compiling
---
## MinGW Setup
* With MinGW installed, you now install g++. Go to MinGW Installation Manager then you'll have to install ``mingw32-gcc-g++-bin``

![mingwlol](https://cdn.discordapp.com/attachments/798150104158568448/1140928793201102938/tutorlol.png)

* After ticking that, you'll now press ``Installation > Apply Changes``

![lol2](https://cdn.discordapp.com/attachments/798150104158568448/1140929249650417766/image.png)

* Click on "Apply" then it should start downloading, once done you can safely click on "Close" and close MinGW
---
## Setting Environment Variables
* Go to the folder where you installed ``FFmpeg`` and ``yt-dlp``
* Copy their paths and search up in Windows ``Edit the system environment variables``
* Click on ``Environment Variables``
* Under ``System Variables`` find ``Path``, click on it and press ``Edit``
* Press on ``New`` and paste in each of the directories for FFmpeg and yt-dlp