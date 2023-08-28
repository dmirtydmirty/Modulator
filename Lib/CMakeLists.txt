cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 14)

project(Lib)

set(SOURCE
        ${CMAKE_CURRENT_LIST_DIR}/Source/dsp_module.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Source/Mapper.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Source/shaping_impulse.cpp
        )

add_library(Lib STATIC ${SOURCE})

find_package(FFTW3 REQUIRED)

target_include_directories(Lib PUBLIC ${FFTW3_INCLUDE_DIRS})

target_link_libraries(Lib ${FFTW3_LIBRARIES})