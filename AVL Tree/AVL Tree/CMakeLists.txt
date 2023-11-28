cmake_minimum_required(VERSION 3.13)
project(AVLTreeSet)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
message("GTest_INCLUDE_DIRS = ${GTest_INCLUDE_DIRS}")

add_library(lib src/avl_tree_set.cc)

add_executable(mainApp src/main.cc)
target_link_libraries(mainApp lib)

add_executable(testRunner src/test_runner.cc)
target_link_libraries(testRunner lib ${GTEST_LIBRARIES})