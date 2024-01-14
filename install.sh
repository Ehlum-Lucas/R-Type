sudo apt install autoconf libtool -y
sudo apt-get install libudev-dev libx11-dev libxrandr-dev libxcursor-dev libgl1-mesa-dev -y
./vcpkg install asio
./vcpkg install sfml
./vcpkg integrate install