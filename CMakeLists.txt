# set minimum cmake version
cmake_minimum_required(VERSION 3.14)

# project name and language
project(example LANGUAGES CXX)

# require C++14
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_PARALLEL 8)


# CMakeLists.txt (snippet)
if (MSVC)
  # Extra optimizations for release
  # set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2 /GL /DNDEBUG")
  # set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /LTCG")

  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_RELEASE} /W4")

endif()


# testing binary
add_executable(day1t test/day1.cpp advent.hpp day1.hpp)
add_executable(day1 day1.cpp advent.hpp day1.hpp)
add_executable(day2t test/day2.cpp advent.hpp day2.hpp)
add_executable(day2 day2.cpp advent.hpp day2.hpp)
add_executable(day3t test/day3.cpp advent.hpp day3.hpp)
add_executable(day3 day3.cpp advent.hpp day3.hpp)
add_executable(day4t test/day4.cpp advent.hpp day4.hpp)
add_executable(day4 day4.cpp advent.hpp day4.hpp)
add_executable(day5t test/day5.cpp advent.hpp day5.hpp)
add_executable(day5 day5.cpp advent.hpp day5.hpp)
target_include_directories(day1t PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_include_directories(day1 PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_include_directories(day2t PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_include_directories(day2 PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_include_directories(day3t PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_include_directories(day3 PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_include_directories(day4 PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_include_directories(day4t PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_include_directories(day5t PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_include_directories(day5 PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
# enable testing functionality
enable_testing()

# define tests
add_test(NAME day1t COMMAND $<TARGET_FILE:day1t>)
add_test(NAME day2t COMMAND $<TARGET_FILE:day2t>)
add_test(NAME day3t COMMAND $<TARGET_FILE:day3t>)
add_test(NAME day4t COMMAND $<TARGET_FILE:day4t>)
add_test(NAME day5t COMMAND $<TARGET_FILE:day5t>)

