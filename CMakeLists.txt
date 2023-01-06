cmake_minimum_required(VERSION 3.24)
project(kapture-2 C)

set(CMAKE_C_STANDARD 11)

find_package(SDL REQUIRED)
include_directories(~/Prog/lib/SDL-1.2.15/include)

add_executable(kapture-2 sources/main.c headers/constant.h sources/game.c headers/game.h sources/display.c headers/display.h sources/tools.c headers/tools.h)
target_link_libraries(kapture-2 ${SDL_LIBRARIES})
