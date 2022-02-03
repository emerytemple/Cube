cmake_minimum_required(VERSION 3.9)
project(cube VERSION 0.0.0.0 DESCRIPTION "Cube!" LANGUAGES C)

set(C_STANDARD C11)
set(C_STANDARD_REQUIRED True)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
