cmake_minimum_required(VERSION 3.21)

set(THIS TEST)

set(TEST_SOURCES
        com/hjk/tp/lista_test.cpp
        com/hjk/tp/estudiante_test.cpp
        com/hjk/tp/materia_test.cpp
        com/hjk/tp/registro_test.cpp
)
add_executable(${THIS} ${TEST_SOURCES})

target_link_libraries(${THIS} PRIVATE gtest_main core)

include(GoogleTest)
gtest_discover_tests(${THIS})
