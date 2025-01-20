cmake_minimum_required(VERSION 3.10)
project(7)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB SRC_FILES src/*.cpp)
include_directories(src/)
set_source_files_properties(
    ${SRC_FILES}
    PROPERTIES COMPILE_DEFINITIONS "TEST_TARGET"
)

add_executable(test-7 test/test-7.cpp ${SRC_FILES})
target_link_libraries(test-7 ${GTEST_LIBRARIES} pthread)
