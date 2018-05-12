cmake_minimum_required(VERSION 2.8.12)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin/Week3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")

add_executable(Change change_dp.cpp)
add_executable(EditDistance edit_distance.cpp)
add_executable(LongestCommonSubsequenceTwo lcs2.cpp)
add_executable(LongestCommonSubsequenceThree lcs3.cpp)
add_executable(PrimitiveCalculator primitive_calculator.cpp)