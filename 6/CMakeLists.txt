cmake_minimum_required(VERSION 3.10)
project(6)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB SRC_FILES src/*.cpp)
include_directories(src/)

add_executable(test-6 test/test-6.cpp ${SRC_FILES})
target_link_libraries(test-6 ${GTEST_LIBRARIES} pthread)
