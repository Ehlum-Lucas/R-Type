cmake_minimum_required(VERSION 3.10)
project(GameEngine)

#Install Asio
find_package(Asio)

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
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

if (NOT SFML_FOUND)
    message(STATUS "SFML not found, downloading...")
    include(FetchContent)
    FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG        2.6.x
    )
    FetchContent_MakeAvailable(SFML)
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
            src/shoot_system.cpp
            src/Server.cpp
            src/serialize_components.cpp
            src/spawnwithinput_system.cpp
)

# Ajoutez les fichiers source à la bibliothèque
add_library(gameEngineLib STATIC ${SOURCES})

# Spécifiez les dossiers d'inclusion
target_include_directories(gameEngineLib PUBLIC include)

# Trouvez SFML
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# Liez SFML à la bibliothèque
target_link_libraries(gameEngineLib sfml-graphics sfml-audio)

# Ajoutez l'exécutable client.cpp
add_executable(client client.cpp)

# Ajoutez l'exécutable server.cpp
add_executable(server server.cpp)

# Liez l'exécutable à la bibliothèque
target_link_libraries(client gameEngineLib)
target_link_libraries(server gameEngineLib)
target_link_libraries(server sfml-graphics sfml-window sfml-system sfml-audio)