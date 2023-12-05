cmake_minimum_required(VERSION 3.10)
project(client)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pthread")

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
find_package(SFML)

if (NOT SFML_FOUND)
    message(STATUS "SFML not found, downloading...")
    include(FetchContent)
    FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG        2.5.1
    )
    FetchContent_MakeAvailable(SFML)
endif()

set (INCLUDE_DIRS
    ./src/Client
    ./src/Object    
)

include_directories(${INCLUDE_DIRS})

set(SRC
    ./src/main.cpp
    ./src/Object/Object.cpp
)

add_executable(client ${SRC})
target_link_libraries(client sfml-graphics sfml-window sfml-system sfml-audio)
