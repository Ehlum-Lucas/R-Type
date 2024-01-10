cmake_minimum_required(VERSION 3.10)
project(RType)

set(CMAKE_CXX_STANDARD 17)

include_directories(GameEngineLib/include)
add_subdirectory(GameEngineLib)

add_executable(client client.cpp)
add_executable(server server.cpp)

add_custom_command(TARGET client POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/assets)

target_link_libraries(client GameEngineLib)
target_link_libraries(server GameEngineLib)