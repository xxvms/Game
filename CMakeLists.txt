cmake_minimum_required(VERSION 3.8)
project(Game)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Game_map.cpp Game_map.h Cmove_direction.cpp Cmove_direction.h)
add_executable(Game ${SOURCE_FILES})