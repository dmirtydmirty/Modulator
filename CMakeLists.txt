cmake_minimum_required(VERSION 3.20)

project(tests)

set(CMAKE_CXX_STANDARD 14)

include_directories(Lib/Include Lib/Include)

add_subdirectory(Lib)

add_library(Modulator ${CMAKE_CURRENT_LIST_DIR}/Source/Modulator.cpp)
target_link_libraries(Modulator Lib)
