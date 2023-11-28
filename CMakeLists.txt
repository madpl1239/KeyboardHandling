# CMakeLists.txt for handlekbd
# 02-11-2022 by madpl

cmake_minimum_required(VERSION 3.26)
project(handleKbd)

add_definitions(-Os -march=native -std=c++23)
file(GLOB_RECURSE SOURCE ./source/*.cpp ./source/*.hpp)
find_package(SFML 2.5 REQUIRED COMPONENTS graphics)

set(SFML_LIBS sfml-graphics)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE})
target_link_libraries(${CMAKE_PROJECT_NAME} ${SFML_LIBS})
