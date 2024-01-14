cmake_minimum_required(VERSION 3.10)
project(runner)

set(CMAKE_CXX_STANDARD 17)

include_directories(../GameEngineLib/include)
add_subdirectory(../GameEngineLib GameEngineLib)

add_executable(runner runner.cpp)

add_custom_command(TARGET runner POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/assets)

target_link_libraries(runner GameEngineLib)
