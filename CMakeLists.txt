cmake_minimum_required(VERSION 3.21)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c job.h Maquinas.h maquinas.c job.c)
