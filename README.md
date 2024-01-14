![r-type](https://m.media-amazon.com/images/I/911DV9FiRTL.png)
R-Type is a famous game that we had to do with a structured game architecture.

This Epitech project teach us how to develop an ECS, which can be used to develop a new game.
## Getting Started

You can visit the [Wiki](https://github.com/EpitechPromo2026/B-CPP-500-REN-5-2-rtype-lucas.iglesia/wiki) to see how to install, launch and play the game.

If you are a developper, you can also visit the [Wiki](https://github.com/EpitechPromo2026/B-CPP-500-REN-5-2-rtype-lucas.iglesia/wiki) to develop a new game with our ECS or change some point on our game.
## Prerequisites

No prerequisites.
## Installing
### VCPKG

To install vcpkg :
```bash
git clone git@github.com:microsoft/vcpkg.git
```

### Linux
```bash
./vcpkg/bootstrap-vcpkg.sh
export VCPKG_ROOT=/path/to/vcpkg
source ~/.bashrc
```

At the root of the repo
```bash
cp ./install.sh "${VCPKG_ROOT}" && cd "${VCPKG_ROOT}" && ./install.sh
```

### Windows :
```bash
./vcpkg/bootstrap-vcpkg.bat
```
- Go to advanced parameters and add the environnement variable : `VCPKG_ROOT` with the `/path/to/vcpkg`
Restart your computer if needed

At the root of the repo
```bash
cp ./install.bat "${VCPKG_ROOT}" && cd "${VCPKG_ROOT}" && ./install.bat
```


# Play R-Type :

## Start the server for the R-Type

```bash
cd R-Type
mkdir build
cd build
cmake .. && make && ./server
```

## Start the client for the R-Type

```bash
cd R-Type
mkdir build
cd build
cmake .. && make && ./client [IP] (IP: ipv4 of the hosting server)
```

# Play Runner :

```bash
cd Runner
mkdir build
cd build
cmake .. && make && ./runner
```

# Doxygen :

```bash
doxygen Doxyfile
cd doc/html
firefox index.html
```

## Wiki

To access the wiki you can click on this [Wiki](https://github.com/EpitechPromo2026/B-CPP-500-REN-5-2-rtype-lucas.iglesia/wiki).
## Authors

* Lucas Iglesia
* Adrien Picot
* Ariel Chambaz
* Noé Rio
## License

See [LICENSE](https://github.com/EpitechPromo2026/B-CPP-500-REN-5-2-rtype-lucas.iglesia/blob/Readme/LICENSE).
