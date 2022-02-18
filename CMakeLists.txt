cmake_minimum_required(VERSION 3.9)
project(cube VERSION 0.0.0.0 DESCRIPTION "Cube!" LANGUAGES C)

set(C_STANDARD C11)
set(C_STANDARD_REQUIRED True)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
# find_package(SDL2_image REQUIRED)

include(FindPkgConfig)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS} SRC_DIR)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_library(event SHARED ${SRC_DIR}/event.c)
add_library(input SHARED ${SRC_DIR}/input.c)
add_library(render SHARED ${SRC_DIR}/render.c)

add_executable(${PROJECT_NAME} ${SRC_DIR}/main.c)
# add_executable(${PROJECT_NAME} ${SRC_DIR}/test.c)

target_link_libraries(
	${PROJECT_NAME}
	PUBLIC
	${SDL2_LIBRARIES}
	${SDL2IMAGE_LIBRARIES}
	${SDL2TTF_LIBRARIES}
	event
	input
	render
)
