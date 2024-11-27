cmake_minimum_required(VERSION 3.20)
project(Software_ing C)

set(CMAKE_C_STANDARD 99)

add_executable(Software_ing
        main.c
        io.c
        processing.c
)

include_directories(${CMAKE_SOURCE_DIR})
