cmake_minimum_required(VERSION 3.10)
project(NumerovMethod)

set(CMAKE_C_STANDARD 99)

add_executable(numerov_program main.c numerov_method.c)
target_link_libraries(numerov_program m)
