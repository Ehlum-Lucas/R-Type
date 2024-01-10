cmake_minimum_required(VERSION 3.10)
project(GameEngine)

set(CMAKE_CXX_STANDARD 17)

# #Install Asio
# find_package(Asio)

# if (NOT Asio_FOUND)
#     message(STATUS "Asio not found, downloading...")
#     include(FetchContent)
#     FetchContent_Declare(
#         asio
#         GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
#         GIT_TAG asio-1-18-1
#     )
#     FetchContent_GetProperties(asio)
#     if (NOT asio_POPULATED)
#         FetchContent_Populate(asio)
#         include_directories(${asio_SOURCE_DIR}/asio/include)
#     endif()
# endif()

#Install SFML
if (UNIX)
    message("Compilation Linux")
    find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)
endif()

if (NOT SFML_FOUND)
    FetchContent_Declare(
        sfml
        GIT_REPOSITORY "https://github.com/SFML/SFML.git"
        GIT_TAG        "2.6.x"
    )
    FetchContent_GetProperties(sfml)
    if(NOT sfml_POPULATED)
        message("Fetch sfml")
        FetchContent_Populate(sfml)
        message("Print sfml")
        message(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
        add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
    endif()
endif()

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
)

# Ajoutez les fichiers source à la bibliothèque
add_library(gameEngineLib STATIC ${SOURCES})

# Spécifiez les dossiers d'inclusion
target_include_directories(gameEngineLib PUBLIC include)

# Liez SFML à la bibliothèque
target_link_libraries(gameEngineLib sfml-graphics sfml-window sfml-system sfml-audio)

# Ajoutez l'exécutable client.cpp
add_executable(client client.cpp)

# Ajoutez l'exécutable server.cpp
add_executable(server server.cpp)

if (WIN32)
    add_custom_command(TARGET client POST_BUILD
		    COMMAND ${CMAKE_COMMAND} -E copy_directory
		    ${sfml_BINARY_DIR}/lib ${CMAKE_BINARY_DIR})
endif()

add_custom_command(TARGET client POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/assets)

# Liez l'exécutable à la bibliothèque
target_link_libraries(client gameEngineLib)
target_link_libraries(server gameEngineLib)