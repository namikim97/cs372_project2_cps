cmake_minimum_required(VERSION 3.0)
project(cpsMain)
project(cpsTests)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

# tests
add_executable(cpsTests
        catch.hpp
        cpsTests.cpp
        shapes.cpp shapes.h
        compound.cpp compound.h
        page.cpp page.h)

# main
add_executable(cpsMain
        cps.cpp
        shapes.cpp shapes.h
        compound.cpp compound.h
        page.cpp page.h)