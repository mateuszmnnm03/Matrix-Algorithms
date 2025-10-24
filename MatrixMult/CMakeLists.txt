cmake_minimum_required(VERSION 4.0)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

set(EIGEN3_INCLUDE_DIR "C:/Users/Mateusz/Downloads/eigen-5.0.0/eigen-5.0.0")

include_directories(${EIGEN3_INCLUDE_DIR})

set(SOURCE_FILES
        main.cpp
        strassen.cpp
)

add_executable(untitled main.cpp
        strassen.cpp
        strassen.h
        ai_method.cpp
        ai_method.h)
