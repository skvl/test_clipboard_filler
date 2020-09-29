cmake_minimum_required(VERSION 3.14)
project(test-clipboard-filler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /std:c++latest")

add_executable(test main.cpp)