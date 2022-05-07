cmake_minimum_required(VERSION 3.22)

set(THIS source)

project(${THIS} C)

set(CMAKE_C_STANDARD 17)

set(HEADERS )
set(SOURCES
    src/main.c
)

add_executable(${THIS} ${HEADERS} ${SOURCES})
