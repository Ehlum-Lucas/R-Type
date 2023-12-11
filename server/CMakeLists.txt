cmake_minimum_required(VERSION 3.10)
project(server)

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

set(INCLUDE_DIRS
    ./src/Server
    ./src/Client
    ./src/Components
    ./src/Entity
    ./src/Systems
    ./src/Registry
    ./src/SparseArray
)

include_directories(${INCLUDE_DIRS})

set(SRC
    src/main.cpp
    src/Server/Server.cpp
    src/Systems/position_system.cpp
    src/Systems/control_system.cpp
    src/Systems/serialize_system.cpp
)

add_executable(server ${SRC})
