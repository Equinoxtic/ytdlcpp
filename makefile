GXX=g++
MAIN_FILE=main.cpp
OUTPUT_FILE=bin/ytdlcpp.exe
SOURCE_FILES= src/utils/sys.hpp \
		src/utils/sys.cpp \
		src/utils/ytutils.hpp \
		src/utils/ytutils.cpp \
		src/utils/stringutils.cpp \
		src/utils/stringutils.hpp \
		src/states/audiomode.hpp \
		src/states/audiomode.cpp \
		src/states/videomode.hpp \
		src/states/videomode.cpp \
		src/states/mainmenu.cpp \
		src/states/mainmenu.hpp \
		src/ui/option.cpp \
		src/ui/option.hpp \
		src/ui/bar.cpp \
		src/ui/bar.hpp \
		src/list.cpp \
		src/list.hpp \
		src/sleep.cpp \
		src/sleep.hpp \
		src/logging.cpp \
		src/logging.hpp \
		common.hpp

build:
	$(GXX) $(MAIN_FILE) -std=c++2a -Wall $(SOURCE_FILES) -o $(OUTPUT_FILE)
