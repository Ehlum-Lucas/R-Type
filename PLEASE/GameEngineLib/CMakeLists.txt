cmake_minimum_required(VERSION 3.10)
project(GameEngineLib)

set(CMAKE_CXX_STANDARD 17)

include($ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)

find_package(asio CONFIG REQUIRED)

find_package(SFML COMPONENTS graphics window system audio REQUIRED)

# Spécifiez les fichiers source
set(SOURCES
            src/collide_system.cpp
            src/controller_system.cpp
            src/draw_system.cpp
            src/Entity.cpp
            src/GameEngine.cpp
            src/gravity_system.cpp
            src/onclickloadscene_system.cpp
            src/position_system.cpp
            src/quit_system.cpp
            src/Scene.cpp
            src/serialize_components.cpp
            src/spawnwithinput_system.cpp
            src/TexturesLoader.cpp
            src/parralax_system.cpp
            src/parsing.cpp
)

include_directories(include)

# Ajoutez les fichiers source à la bibliothèque
add_library(GameEngineLib ${SOURCES})

# Liez SFML à la bibliothèque
target_link_libraries(GameEngineLib sfml-graphics sfml-window sfml-system sfml-audio)
target_link_libraries(GameEngineLib asio::asio)