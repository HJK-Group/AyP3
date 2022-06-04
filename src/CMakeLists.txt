cmake_minimum_required(VERSION 3.22)

set(THIS core)

set(HEADERS
    com/hjk/tp/list/list.h
    com/hjk/tp/materia/materia.h
    com/hjk/tp/estudiante/estudiante.h
    com/hjk/tp/list/numerica.h
    com/hjk/tp/list/ordered.h
)

set(SOURCES
    com/hjk/tp/list/list.c
    com/hjk/tp/materia/materia.c
    com/hjk/tp/estudiante/estudiante.c
    com/hjk/tp/list/numerica.c
    com/hjk/tp/list/ordered.c
)

add_library(${THIS} ${HEADERS} ${SOURCES})

target_include_directories(${THIS} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
