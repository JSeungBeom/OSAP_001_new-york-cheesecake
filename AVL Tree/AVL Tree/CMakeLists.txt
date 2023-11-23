cmake_minimum_required(VERSION 3.13)
project(AVLTree)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
message("GTest_INCLUDE_DIRS = ${GTest_INCLUDE_DIRS}")

add_library(library_avltree avltree.cpp)

add_executable(mainApp main.cpp)
target_link_libraries(mainApp library_avltree)

add_executable(testRunner test_runner.cpp)
target_link_libraries(testRunner library_avltree ${GTEST_LIBRARIES})