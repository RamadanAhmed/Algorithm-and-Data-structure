cmake_minimum_required(VERSION 3.12)
project(Week1)

set(CMAKE_CXX_STANDARD 14)

add_executable(CheckBrackets check_brackets.cpp)
add_executable(ProcessPackages process_packages.cpp)
add_executable(Stack stack_with_max_naive.cpp)
add_executable(TreeHeight tree-height.cpp)