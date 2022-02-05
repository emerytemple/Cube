cmake_minimum_required(VERSION 3.9)
project(cube VERSION 0.0.0.0 DESCRIPTION "Cube!" LANGUAGES C)

set(C_STANDARD C11)
set(C_STANDARD_REQUIRED True)

find_package(SDL2 REQUIRED)

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

include_directories(${SDL2_INCLUDE_DIRS} SRC_DIR)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_library(event SHARED ../src/event.c)

add_executable(${PROJECT_NAME} ../src/main.c)

target_link_libraries(
	${PROJECT_NAME}
	PUBLIC
	${SDL2_LIBRARIES}
	event
)
