cmake_minimum_required(VERSION 3.8)
project(JEB2020)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp checkers.cpp checkers.h)
add_executable(JEB2020 ${SOURCE_FILES})