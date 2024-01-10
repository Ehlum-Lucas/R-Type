cmake_minimum_required(VERSION 3.10)
project(GameEngineLib)

set(CMAKE_CXX_STANDARD 17)

#Install Asio
# find_package(Asio)

if (NOT Asio_FOUND)
    message(STATUS "Asio not found, downloading...")
    include(FetchContent)
    FetchContent_Declare(
        asio
        GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
        GIT_TAG asio-1-18-1
    )
    FetchContent_GetProperties(asio)
    if (NOT asio_POPULATED)
        FetchContent_Populate(asio)
        include_directories(${asio_SOURCE_DIR}/asio/include)
    endif()
endif()

#Install SFML
if (UNIX)
    message("Compilation Linux")
    find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)
endif()

# if (NOT SFML_FOUND)
#     FetchContent_Declare(
#         sfml
#         GIT_REPOSITORY "https://github.com/SFML/SFML.git"
#         GIT_TAG        "2.6.x"
#     )
#     FetchContent_GetProperties(sfml)
#     if(NOT sfml_POPULATED)
#         message("Fetch sfml")
#         FetchContent_Populate(sfml)
#         message("Print sfml")
#         message(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
#         add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
#     endif()
# endif()

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
