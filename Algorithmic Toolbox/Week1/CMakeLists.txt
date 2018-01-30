cmake_minimum_required(VERSION 2.8.12)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin/Week1)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")

set (StressTest "StressTest")
set (APlusB "APlusB")
set (MaxPairWiseProduct "MaxPairWiseProduct")

add_executable(${StressTest} "StressTest.cpp")
add_executable(${APlusB} "APlusB.cpp")
add_executable(${MaxPairWiseProduct} "max_pairwise_product.cpp")