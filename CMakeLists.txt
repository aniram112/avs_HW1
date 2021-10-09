# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 20)

# project name and language
project(task1 LANGUAGES CXX)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES
        # Headers
        rnd.h
        container.h
        cypher.h
        numbers.h
        cyclic.h
        symbols.h

        # Sources
        container.cpp
        main.cpp
        cypher.cpp
        numbers.cpp
        cyclic.cpp
        symbols.cpp)

add_executable(task01 ${SOURCE_FILES})
