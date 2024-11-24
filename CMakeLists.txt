cmake_minimum_required(VERSION 3.20)
project(A_STAR)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Google Test
find_package(GTest REQUIRED)

# Shared library for the core functionality
add_library(A_STAR_LIB A_star.cpp)

# Main application
add_executable(A_STAR main.cpp)
target_link_libraries(A_STAR A_STAR_LIB)

# Unit testing executable
add_executable(unit_tests unit_tests.cpp)
target_link_libraries(unit_tests GTest::GTest GTest::Main pthread A_STAR_LIB)
