cmake_minimum_required(VERSION 3.21)

set(THIS MAIN)
project(${THIS} C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

enable_testing()

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(${THIS}
        src/com/hjk/tp/print_tester.c)

add_subdirectory(src)
add_subdirectory(test)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

target_link_libraries(${THIS} PRIVATE core)
