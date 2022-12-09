cmake_minimum_required(VERSION 3.23)
project(aoc22)

set(CMAKE_CXX_STANDARD 23)

add_executable(aoc22 main.cpp day1/day1.h day2/day2.h day3/day3.h day4/day4.h day5/day5.h day6/day6.h day7/day7.h day8/day8.h)
target_link_libraries(aoc22)
