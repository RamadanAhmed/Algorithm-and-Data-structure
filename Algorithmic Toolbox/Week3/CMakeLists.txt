cmake_minimum_required(VERSION 2.8.12)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin/Week3)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")

set (Change "Change")
set (CoveringSegment "CoveringSegments")
set (DifferentSummands "DifferentSummands")
set (DotProduct "DotProduct")
set (FractionalKnapsack "FractionalKnapsack")
set (LargestNumber "LargestNumber")

add_executable(${Change} "change.cpp")
add_executable(${CoveringSegment} "covering_segments.cpp")
add_executable(${DifferentSummands} "different_summands.cpp")
add_executable(${DotProduct} "dot_product.cpp")
add_executable(${FractionalKnapsack} "fractional_knapsack.cpp")
add_executable(${LargestNumber} "largest_number.cpp")
