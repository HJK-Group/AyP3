cmake_minimum_required(VERSION 3.22)

set(THIS core)

set(HEADERS
        com/hjk/tp/list/list.h
)
set(SOURCES
        com/hjk/tp/list/list.c
)
add_library(${THIS} ${HEADERS} ${SOURCES})

target_include_directories(${THIS} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
