cmake_minimum_required(VERSION 2.8.12)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin/)

set(WEEK1 "Week1")
set(WEEK2 "Week2")
set(WEEK3 "Week3")
set(WEEK4 "Week4")
set(WEEK5 "Week5")


option(BuildWeek1 "Enable Building Week1 code" OFF)
option(BuildWeek2 "Enable Building Week1 code" OFF)
option(BuildWeek3 "Enable Building Week1 code" OFF)
option(BuildWeek4 "Enable Building Week1 code" OFF)
option(BuildWeek5 "Enable Building Week1 code" OFF)

if(BuildWeek1)
    add_subdirectory(${WEEK1})
endif()

if(BuildWeek2)
    add_subdirectory(${WEEK2})
endif()

if(BuildWeek3)
    add_subdirectory(${WEEK3})
endif()

if(BuildWeek4)
    add_subdirectory(${WEEK4})
endif()

if(BuildWeek5)
    add_subdirectory(${WEEK5})
endif()
