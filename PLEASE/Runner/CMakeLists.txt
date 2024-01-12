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
            ../GameEngineLib/src/collide_system.cpp
            ../GameEngineLib/src/controller_system.cpp
            ../GameEngineLib/src/draw_system.cpp
            ../GameEngineLib/src/Entity.cpp
            ../GameEngineLib/src/GameEngine.cpp
            ../GameEngineLib/src/gravity_system.cpp
            ../GameEngineLib/src/onclickloadscene_system.cpp
            ../GameEngineLib/src/position_system.cpp
            ../GameEngineLib/src/quit_system.cpp
            ../GameEngineLib/src/Scene.cpp
            ../GameEngineLib/src/serialize_components.cpp
            ../GameEngineLib/src/spawnwithinput_system.cpp
            ../GameEngineLib/src/TexturesLoader.cpp
            ../GameEngineLib/src/parralax_system.cpp
            ../GameEngineLib/src/parsing.cpp
)

# Ajoutez les fichiers source à la bibliothèque
add_library(gameEngineLib STATIC ${SOURCES})

# Spécifiez les dossiers d'inclusion
target_include_directories(gameEngineLib PUBLIC ../GameEngineLib/include)

# Liez SFML à la bibliothèque
target_link_libraries(gameEngineLib sfml-graphics sfml-window sfml-system sfml-audio)

# Ajoutez l'exécutable runner.cpp
add_executable(runner runner.cpp)

if (WIN32)
    add_custom_command(TARGET client POST_BUILD
		    COMMAND ${CMAKE_COMMAND} -E copy_directory
		    ${sfml_BINARY_DIR}/lib ${CMAKE_BINARY_DIR})
endif()

add_custom_command(TARGET runner POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/assets)

# Liez l'exécutable à la bibliothèque
target_link_libraries(runner gameEngineLib)