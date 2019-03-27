cmake_minimum_required(VERSION 3.0)
project(cppToPostScript)
project(cppToPostScriptTests)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

# tests
add_executable(cppToPostScriptTests
        catch.hpp
        cps.cpp
        cps.h cpsTests.cpp)

# main
add_executable(cppToPostScript
        cps.cpp
        cps.h)