cmake_minimum_required(VERSION 2.8.12)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin/Week2)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")

set (FibonacciHuge "FibonacciHuge")
set (FibonacciLastDigit "FibonacciLastDigit")
set (FibonacciPartialSum "FibonacciPartialSum")
set (FibonacciSumLastDigit "FibonacciSumLastDigit")
set (Fibonacci "Fibonacci")
set (LCM "LCM")
set (GCD "GCD")


add_executable(${FibonacciHuge} "fibonacci_huge.cpp")
add_executable(${FibonacciLastDigit} "fibonacci_last_digit.cpp")
add_executable(${FibonacciPartialSum} "fibonacci_partial_sum.cpp")
add_executable(${FibonacciSumLastDigit} "fibonacci_sum_last_digit.cpp")
add_executable(${Fibonacci} "fibonacci.cpp")
add_executable(${LCM} "lcm.cpp")
add_executable(${GCD} "gcd.cpp")
