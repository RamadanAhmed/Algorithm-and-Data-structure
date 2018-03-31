cmake_minimum_required(VERSION 2.8.12)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin/Week3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")

add_executable(BinarySearch binary_search.cpp)
add_executable(Closest closest.cpp)
add_executable(Inversion inversions.cpp)
add_executable(MajorityElement majority_element.cpp)
add_executable(PointsSegments points_and_segments.cpp)
add_executable(Sorting sorting.cpp)
