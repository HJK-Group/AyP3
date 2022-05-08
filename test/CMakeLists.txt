cmake_minimum_required(VERSION 3.22)

set(THIS TEST)

set(TEST_SOURCES
        com/hjk/tp/test.cpp
)
add_executable(${THIS} ${TEST_SOURCES})

target_link_libraries(${THIS} PRIVATE gtest_main core)

include(GoogleTest)
gtest_discover_tests(${THIS})
