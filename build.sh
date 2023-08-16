# Build script

echo "Building and running \"ytdlcpp...\""
mkdir -p bin/
mkdir -p bin/local/
make
./bin/ytdlcpp.exe
