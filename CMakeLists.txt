# set minimum cmake version
cmake_minimum_required(VERSION 3.14)

# project name and language
project(example LANGUAGES CXX)

# require C++14
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_PARALLEL 8)


# testing binary
add_executable(day1t test/day1.cpp advent.hpp day1.hpp)
add_executable(day1 day1.cpp advent.hpp day1.hpp)
add_executable(day2t test/day2.cpp advent.hpp day2.hpp)
add_executable(day2 day2.cpp advent.hpp day2.hpp)
add_executable(day3t test/day3.cpp advent.hpp day3.hpp)
add_executable(day3 day3.cpp advent.hpp day3.hpp)


target_include_directories(day1t PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_include_directories(day1 PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_include_directories(day2t PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_include_directories(day2 PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_include_directories(day3t PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_include_directories(day3 PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)


# enable testing functionality
enable_testing()

# define tests
add_test(NAME day1t COMMAND $<TARGET_FILE:day1t>)
add_test(NAME day2t COMMAND $<TARGET_FILE:day2t>)
add_test(NAME day3t COMMAND $<TARGET_FILE:day3t>)


