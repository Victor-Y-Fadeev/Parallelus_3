cmake_minimum_required(VERSION 3.9)
project(Differential_equation C)

set(CMAKE_C_STANDARD 11)

add_executable(Differential_equation main.c include/Data.h include/Logic.h src/Logic.c src/Data.c)