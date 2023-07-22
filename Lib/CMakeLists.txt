cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 14)

project(Lib)

set(SOURCE
        ${CMAKE_CURRENT_LIST_DIR}/Source/dsp_module.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Source/Mapper.cpp
        )

find_package(PkgConfig REQUIRED)

pkg_search_module(FFTW REQUIRED fftw3 IMPORTED_TARGET)

include_directories(PkgConfig::FFTW)

link_libraries (PkgConfig::FFTW)

add_library(Lib STATIC ${SOURCE})