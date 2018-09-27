cmake_minimum_required(VERSION 2.7)
project(OpenGL)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic -Wno-unused-result")

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})
add_executable(OpenGL main.cpp figures.h figures.cpp parkinglot.h parkinglot.cpp carparking.cpp carparking.h display.cpp display.h)
target_link_libraries(OpenGL ${GLUT_LIBRARY} ${OPENGL_LIBRARY} m)

